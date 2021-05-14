#pragma once

class Piyon
{
private:
	float puan = 1;
	int kSay�;
	char kHarf;
	char kRenk;
public:
	Piyon(){}
	Piyon(int, char, char);
	bool tehditHesapla(int, char);
	float puanHesapla(bool);
};
Piyon::Piyon(int kSay�, char kHarf, char kRenk) {
	this->kSay� = kSay�;
	this->kHarf = kHarf;
	this->kRenk = kRenk;
}

bool Piyon::tehditHesapla(int mSay�, char mHarf) {
	if ( kRenk == 'b' && kSay� == mSay� - 1 && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if (kRenk == 's' && kSay� == mSay� + 1 && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else return false;
}

float Piyon::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

