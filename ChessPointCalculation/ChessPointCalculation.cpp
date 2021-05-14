#include "TasBilgisi.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <dirent.h> 

using namespace std;

vector<pair<float, float>> result;
void hesap(string path)
{
    fstream infile;
    vector<TasBilgisi> Taşlar;
    vector<pair<int, char>> Boşlar;

    int satır = 8;
    char sutun = 'a' - 1;

    float toplamSiyah = 0, toplamBeyaz = 0;

    infile.open("Inputs\\" + path, ios::in); 
    if (infile.is_open()) {
        string kısa_isim;
        while (infile >> kısa_isim) {
            if (kısa_isim != " ") {
                sutun++;
                if (kısa_isim != "xx") {
                    TasBilgisi Taş(kısa_isim[0], kısa_isim[1], satır, sutun);
                    Taşlar.push_back(Taş);
                }
                else if (kısa_isim == "xx")
                    Boşlar.emplace_back(satır, sutun);
                if (sutun == 'h') {
                    satır--;
                    sutun = 'a' - 1;
                }
            }
        }

        infile.close();
    }
    vector<TasBilgisi> tempTaşlar = Taşlar;
    for (int i = 0; i < Taşlar.size(); i++) {
        bool enAzBirTehdit = false;
        for (int j = 0; j < Taşlar.size(); j++)
        {
            bool şahEnAzBir = false;
            bool açmaz = false;
            if (Taşlar[i].getRenk() == 's' && Taşlar[j].getRenk() == 'b')
                Taşlar[i] = Taşlar[j].karşıTehdit(Boşlar, Taşlar[i]);
            else if (Taşlar[i].getRenk() == 'b' && Taşlar[j].getRenk() == 's')
                Taşlar[i] = Taşlar[j].karşıTehdit(Boşlar, Taşlar[i]);

            if (Taşlar[j].getKısaltma() == 's' && Taşlar[i].getTehdit() == true) {
                TasBilgisi temp = Taşlar[j];
                temp.konum_sayı = Taşlar[i].konum_sayı;
                temp.konum_harf = Taşlar[i].konum_harf;
                temp.setTehdit(false);
                for (int a = 0; a < Taşlar.size(); a++)
                {
                    if (temp.getRenk() == 's' && Taşlar[a].getRenk() == 'b')
                        temp = Taşlar[a].karşıTehdit(Boşlar, temp);
                    else if (temp.getRenk() == 'b' && Taşlar[a].getRenk() == 's')
                        temp = Taşlar[a].karşıTehdit(Boşlar, temp);

                    if (temp.getTehdit() == true) şahEnAzBir = true;
                }
            }
            else if (Taşlar[i].getTehdit() == true) {
                TasBilgisi temp = Taşlar[j];
                temp.konum_sayı = Taşlar[i].konum_sayı;
                temp.konum_harf = Taşlar[i].konum_harf;
                for (int a = 0; a < tempTaşlar.size(); a++)
                {
                    tempTaşlar[a].setTehdit(false);
                    if (temp.getRenk() == 's' && tempTaşlar[a].getRenk() == 'b' && tempTaşlar[a].getKısaltma() == 's')
                        tempTaşlar[a] = temp.karşıTehdit(Boşlar, tempTaşlar[a]);
                    else if (temp.getRenk() == 'b' && tempTaşlar[a].getRenk() == 's' && tempTaşlar[a].getKısaltma() == 's')
                        tempTaşlar[a] = temp.karşıTehdit(Boşlar, tempTaşlar[a]);

                    if (tempTaşlar[a].getTehdit() == true) açmaz = true;
                }
            }

            if (Taşlar[i].getTehdit() == true && şahEnAzBir == false && açmaz == false) enAzBirTehdit = true;

        }
        Taşlar[i].setTehdit(enAzBirTehdit);
        if (Taşlar[i].getRenk() == 's') toplamSiyah += Taşlar[i].puanAl();
        else if (Taşlar[i].getRenk() == 'b') toplamBeyaz += Taşlar[i].puanAl();

    }
    result.emplace_back(toplamSiyah, toplamBeyaz);
}

bool has_suffix(const string& s, const string& suffix)
{
    return (s.size() >= suffix.size()) && equal(suffix.rbegin(), suffix.rend(), s.rbegin());
}

int main() {
    fstream outfile;
    struct dirent* entry;
    DIR* dir = opendir("Inputs");
    if (dir == NULL) {
        return 0;
    }
    int i = 0;
    outfile.open("Output\\sonuçlar.txt", ios::out);
    if (outfile.is_open()) outfile << "Tahta Dosya Adı          Sonuçlar\n";
    while ((entry = readdir(dir)) != NULL) {
        if (has_suffix(entry->d_name, ".txt") == true) {
            hesap(entry->d_name);
            stringstream ss1, ss2;
            ss1 << result[i].first;
            ss2 << result[i].second;
            outfile << entry->d_name << "               " << "Siyah:" << ss1.str() << " , " << "Beyaz:" << ss2.str() << endl;
            i++;
        }
    }
    outfile.close();
    closedir(dir);
    return 0;
}

                