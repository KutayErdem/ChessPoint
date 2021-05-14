#pragma once

class At
{
private:
	float puan = 3;
	int kSayý;
	char kHarf;
public:
	At(){}
	At(int, char);
	bool tehditHesapla(int, char);
	float puanHesapla(bool);
};
At::At(int kSayý, char kHarf) {
	this->kSayý = kSayý;
	this->kHarf = kHarf;
}

bool At::tehditHesapla(int mSayý, char mHarf) {
	if ((kSayý == mSayý - 2 || kSayý ==mSayý + 2) && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if ((kSayý == mSayý - 1 || kSayý == mSayý + 1) && (kHarf == mHarf - 2 || kHarf == mHarf + 2)) return true;
	else return false;
}

float At::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

