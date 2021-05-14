#pragma once

#include "Kale.h"
#include "Fil.h"

class Vezir
{
private:
	float puan = 9;
	int kSayý;
	char kHarf;
public:
	Vezir() {}
	Vezir(int, char);
	bool tehditHesapla(int, char, vector<pair<int, char>>);
	float puanHesapla(bool);
};
Vezir::Vezir(int kSayý, char kHarf) {
	this->kSayý = kSayý;
	this->kHarf = kHarf;
}

bool Vezir::tehditHesapla(int mSayý, char mHarf, vector<pair<int, char>> boþluk) {
	Kale kKale(kSayý, kHarf);
	Fil kFil(kSayý, kHarf);
	if (kKale.tehditHesapla(mSayý, mHarf, boþluk) == true || kFil.tehditHesapla(mSayý, mHarf, boþluk) == true) return true;
	else return false;
}

float Vezir::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

