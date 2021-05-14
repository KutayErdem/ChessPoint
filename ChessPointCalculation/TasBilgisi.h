#pragma once

#include "Piyon.h"
#include "At.h"
#include "Fil.h"
#include "Kale.h"
#include "Vezir.h"
#include "Þah.h"

#include <iostream>
#include <vector>
#include <string>

using namespace std;

class TasBilgisi
{
private:
	char kýsaltma;
	char renk;
	
	bool taþ_tehdidi;
	float taþ_puaný;
public:
	int konum_sayý;
	char konum_harf;
	TasBilgisi(char, char, int, char);
	char getKýsaltma();
	char getRenk();
	
	void setTehdit(bool);
	bool getTehdit();

	TasBilgisi karþýTehdit(vector<pair<int, char>>, TasBilgisi);
	float puanAl();
};

TasBilgisi::TasBilgisi(char kýsaltma, char renk, int konum_sayý, char konum_harf) {
	this->kýsaltma = kýsaltma;
	this->renk = renk;
	this->konum_sayý = konum_sayý;
	this->konum_harf = konum_harf;
	this->taþ_tehdidi = false;
	this->taþ_puaný = 0;
}

char TasBilgisi::getKýsaltma() { return kýsaltma; }
char TasBilgisi::getRenk() { return renk; }
bool TasBilgisi::getTehdit() { return taþ_tehdidi; }
void TasBilgisi::setTehdit(bool taþ_tehdidi) { this->taþ_tehdidi = taþ_tehdidi; }

TasBilgisi TasBilgisi::karþýTehdit(vector<pair<int, char>> boþlar, TasBilgisi mevcutTaþ) {
	if (kýsaltma == 'p') {
		Piyon kPiyon(konum_sayý, konum_harf, renk);
		mevcutTaþ.taþ_tehdidi = kPiyon.tehditHesapla(mevcutTaþ.konum_sayý, mevcutTaþ.konum_harf);
	}
	else if (kýsaltma == 'a') {
		At kAt(konum_sayý, konum_harf);
		mevcutTaþ.taþ_tehdidi = kAt.tehditHesapla(mevcutTaþ.konum_sayý, mevcutTaþ.konum_harf);
	}
	else if (kýsaltma == 'f') {
		Fil kFil(konum_sayý, konum_harf);
		mevcutTaþ.taþ_tehdidi = kFil.tehditHesapla(mevcutTaþ.konum_sayý, mevcutTaþ.konum_harf, boþlar);
	}
	else if (kýsaltma == 'k') {
		Kale kKale(konum_sayý, konum_harf);
		mevcutTaþ.taþ_tehdidi = kKale.tehditHesapla(mevcutTaþ.konum_sayý, mevcutTaþ.konum_harf, boþlar);
	}
	else if (kýsaltma == 'v') {
		Vezir kVezir(konum_sayý, konum_harf);
		mevcutTaþ.taþ_tehdidi = kVezir.tehditHesapla(mevcutTaþ.konum_sayý, mevcutTaþ.konum_harf, boþlar);
	}
	else if (kýsaltma == 's') {
		Þah kÞah(konum_sayý, konum_harf);
		mevcutTaþ.taþ_tehdidi = kÞah.tehditHesapla(mevcutTaþ.konum_sayý, mevcutTaþ.konum_harf);
	}
	return mevcutTaþ;
}

float TasBilgisi::puanAl() {
	if (kýsaltma == 'p') {
		Piyon mPiyon;
		taþ_puaný = mPiyon.puanHesapla(taþ_tehdidi);
	}
	else if (kýsaltma == 'a') {
		At mAt;
		taþ_puaný = mAt.puanHesapla(taþ_tehdidi);
	}
	else if (kýsaltma == 'f') {
		Fil mFil;
		taþ_puaný = mFil.puanHesapla(taþ_tehdidi);
	}
	else if (kýsaltma == 'k') {
		Kale mKale;
		taþ_puaný = mKale.puanHesapla(taþ_tehdidi);
	}
	else if (kýsaltma == 'v') {
		Vezir mVezir;
		taþ_puaný = mVezir.puanHesapla(taþ_tehdidi);
	}
	else if (kýsaltma == 's') {
		Þah mÞah;
		taþ_puaný = mÞah.puanHesapla(taþ_tehdidi);
	}
	return taþ_puaný;
}


