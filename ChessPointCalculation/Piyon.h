#pragma once

class Piyon
{
private:
	float puan = 1;
	int kSayý;
	char kHarf;
	char kRenk;
public:
	Piyon(){}
	Piyon(int, char, char);
	bool tehditHesapla(int, char);
	float puanHesapla(bool);
};
Piyon::Piyon(int kSayý, char kHarf, char kRenk) {
	this->kSayý = kSayý;
	this->kHarf = kHarf;
	this->kRenk = kRenk;
}

bool Piyon::tehditHesapla(int mSayý, char mHarf) {
	if ( kRenk == 'b' && kSayý == mSayý - 1 && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if (kRenk == 's' && kSayý == mSayý + 1 && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else return false;
}

float Piyon::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

