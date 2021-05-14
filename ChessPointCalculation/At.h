#pragma once

class At
{
private:
	float puan = 3;
	int kSay�;
	char kHarf;
public:
	At(){}
	At(int, char);
	bool tehditHesapla(int, char);
	float puanHesapla(bool);
};
At::At(int kSay�, char kHarf) {
	this->kSay� = kSay�;
	this->kHarf = kHarf;
}

bool At::tehditHesapla(int mSay�, char mHarf) {
	if ((kSay� == mSay� - 2 || kSay� ==mSay� + 2) && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if ((kSay� == mSay� - 1 || kSay� == mSay� + 1) && (kHarf == mHarf - 2 || kHarf == mHarf + 2)) return true;
	else return false;
}

float At::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

