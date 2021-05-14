#pragma once

#include "Kale.h"
#include "Fil.h"

class Vezir
{
private:
	float puan = 9;
	int kSay�;
	char kHarf;
public:
	Vezir() {}
	Vezir(int, char);
	bool tehditHesapla(int, char, vector<pair<int, char>>);
	float puanHesapla(bool);
};
Vezir::Vezir(int kSay�, char kHarf) {
	this->kSay� = kSay�;
	this->kHarf = kHarf;
}

bool Vezir::tehditHesapla(int mSay�, char mHarf, vector<pair<int, char>> bo�luk) {
	Kale kKale(kSay�, kHarf);
	Fil kFil(kSay�, kHarf);
	if (kKale.tehditHesapla(mSay�, mHarf, bo�luk) == true || kFil.tehditHesapla(mSay�, mHarf, bo�luk) == true) return true;
	else return false;
}

float Vezir::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

