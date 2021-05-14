#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Þah
{
private:
	float puan = 100;
	int kSayý;
	char kHarf;
public:
	Þah() {}
	Þah(int, char);
	bool tehditHesapla(int, char);
	float puanHesapla(bool);
	vector<pair<int, char>> hamleTehdit(int, char, vector<pair<int, char>>);
};
Þah::Þah(int kSayý, char kHarf) {
	this->kSayý = kSayý;
	this->kHarf = kHarf;
}

bool Þah::tehditHesapla(int mSayý, char mHarf) {
	if ((kSayý == mSayý + 1 || kSayý == mSayý - 1) && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if (kSayý == mSayý && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if (kHarf == mHarf && (kSayý == mSayý - 1 || kSayý == mSayý + 1)) return true;
	else return false;
}

vector<pair<int, char>> Þah::hamleTehdit(int mSayý, char mHarf, vector<pair<int, char>> boþluk) {
	vector<pair<int, char>> hamleler;
	for (int x = 0; x < boþluk.size(); x++)
	{
		if (boþluk[x].first == mSayý + 1 && boþluk[x].second == mHarf) hamleler.emplace_back(mSayý + 1, mHarf);
		else if (boþluk[x].first == mSayý - 1 && boþluk[x].second == mHarf) hamleler.emplace_back(mSayý - 1, mHarf);
		else if (boþluk[x].first == mSayý && boþluk[x].second == mHarf + 1) hamleler.emplace_back(mSayý, mHarf + 1);
		else if (boþluk[x].first == mSayý && boþluk[x].second == mHarf - 1) hamleler.emplace_back(mSayý, mHarf - 1);
		else if (boþluk[x].first == mSayý + 1 && boþluk[x].second == mHarf - 1) hamleler.emplace_back(mSayý + 1, mHarf - 1);
		else if (boþluk[x].first == mSayý + 1 && boþluk[x].second == mHarf + 1) hamleler.emplace_back(mSayý + 1, mHarf + 1);
		else if (boþluk[x].first == mSayý - 1 && boþluk[x].second == mHarf - 1) hamleler.emplace_back(mSayý - 1, mHarf - 1);
		else if (boþluk[x].first == mSayý - 1 && boþluk[x].second == mHarf + 1) hamleler.emplace_back(mSayý - 1, mHarf + 1);
	}
	return hamleler;
}


float Þah::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

