#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Fil
{
private:
	float puan = 3;
	int kSayý;
	char kHarf;
public:
	Fil(){}
	Fil(int, char);
	bool tehditHesapla(int, char, vector<pair<int, char>>);
	float puanHesapla(bool);
};
Fil::Fil(int kSayý, char kHarf) {
	this->kSayý = kSayý;
	this->kHarf = kHarf;
}

bool Fil::tehditHesapla(int mSayý, char mHarf, vector<pair<int, char>> boþluk) {
	int count = 0;
	for (int i = 1; (mSayý-i > 0 || mSayý+i < 9); i++)
	{
		if ((kSayý == mSayý - i || kSayý == mSayý + i) && (kHarf == mHarf - i || kHarf == mHarf + i))
		{
			for (int x = 0; x < boþluk.size(); x++)
			{
				if (mSayý < kSayý && (boþluk[x].first > mSayý && boþluk[x].first < kSayý))
				{
					if ((boþluk[x].second == mHarf - (boþluk[x].first - mSayý)) && (mHarf > kHarf))
						count++;
					else if ((boþluk[x].second == mHarf + (boþluk[x].first - mSayý)) && (mHarf < kHarf))
						count++;
				}
				else if (mSayý > kSayý && (boþluk[x].first > kSayý && boþluk[x].first < mSayý))
				{
					if ((boþluk[x].second == mHarf - (mSayý - boþluk[x].first)) && (mHarf > kHarf))
						count++;
					else if ((boþluk[x].second == mHarf + (mSayý - boþluk[x].first)) && (mHarf < kHarf))
						count++;
				}
			}
			if (count == i - 1) return true;
			return false;
		}
	}
	return false;
}

float Fil::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

