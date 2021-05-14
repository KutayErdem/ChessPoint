#pragma once

#include "Piyon.h"
#include "At.h"
#include "Fil.h"
#include "Kale.h"
#include "Vezir.h"
#include "�ah.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TasBilgisi
{
private:
	char k�saltma;
	char renk;
	
	bool ta�_tehdidi;
	float ta�_puan�;
public:
	int konum_say�;
	char konum_harf;
	TasBilgisi(char, char, int, char);
	char getK�saltma();
	char getRenk();
	
	void setTehdit(bool);
	bool getTehdit();

	TasBilgisi kar��Tehdit(vector<pair<int, char>>, TasBilgisi);
	float puanAl();
};

TasBilgisi::TasBilgisi(char k�saltma, char renk, int konum_say�, char konum_harf) {
	this->k�saltma = k�saltma;
	this->renk = renk;
	this->konum_say� = konum_say�;
	this->konum_harf = konum_harf;
	this->ta�_tehdidi = false;
	this->ta�_puan� = 0;
}

char TasBilgisi::getK�saltma() { return k�saltma; }
char TasBilgisi::getRenk() { return renk; }
bool TasBilgisi::getTehdit() { return ta�_tehdidi; }
void TasBilgisi::setTehdit(bool ta�_tehdidi) { this->ta�_tehdidi = ta�_tehdidi; }

TasBilgisi TasBilgisi::kar��Tehdit(vector<pair<int, char>> bo�lar, TasBilgisi mevcutTa�) {
	if (k�saltma == 'p') {
		Piyon kPiyon(konum_say�, konum_harf, renk);
		mevcutTa�.ta�_tehdidi = kPiyon.tehditHesapla(mevcutTa�.konum_say�, mevcutTa�.konum_harf);
	}
	else if (k�saltma == 'a') {
		At kAt(konum_say�, konum_harf);
		mevcutTa�.ta�_tehdidi = kAt.tehditHesapla(mevcutTa�.konum_say�, mevcutTa�.konum_harf);
	}
	else if (k�saltma == 'f') {
		Fil kFil(konum_say�, konum_harf);
		mevcutTa�.ta�_tehdidi = kFil.tehditHesapla(mevcutTa�.konum_say�, mevcutTa�.konum_harf, bo�lar);
	}
	else if (k�saltma == 'k') {
		Kale kKale(konum_say�, konum_harf);
		mevcutTa�.ta�_tehdidi = kKale.tehditHesapla(mevcutTa�.konum_say�, mevcutTa�.konum_harf, bo�lar);
	}
	else if (k�saltma == 'v') {
		Vezir kVezir(konum_say�, konum_harf);
		mevcutTa�.ta�_tehdidi = kVezir.tehditHesapla(mevcutTa�.konum_say�, mevcutTa�.konum_harf, bo�lar);
	}
	else if (k�saltma == 's') {
		�ah k�ah(konum_say�, konum_harf);
		mevcutTa�.ta�_tehdidi = k�ah.tehditHesapla(mevcutTa�.konum_say�, mevcutTa�.konum_harf);
	}
	return mevcutTa�;
}

float TasBilgisi::puanAl() {
	if (k�saltma == 'p') {
		Piyon mPiyon;
		ta�_puan� = mPiyon.puanHesapla(ta�_tehdidi);
	}
	else if (k�saltma == 'a') {
		At mAt;
		ta�_puan� = mAt.puanHesapla(ta�_tehdidi);
	}
	else if (k�saltma == 'f') {
		Fil mFil;
		ta�_puan� = mFil.puanHesapla(ta�_tehdidi);
	}
	else if (k�saltma == 'k') {
		Kale mKale;
		ta�_puan� = mKale.puanHesapla(ta�_tehdidi);
	}
	else if (k�saltma == 'v') {
		Vezir mVezir;
		ta�_puan� = mVezir.puanHesapla(ta�_tehdidi);
	}
	else if (k�saltma == 's') {
		�ah m�ah;
		ta�_puan� = m�ah.puanHesapla(ta�_tehdidi);
	}
	return ta�_puan�;
}


