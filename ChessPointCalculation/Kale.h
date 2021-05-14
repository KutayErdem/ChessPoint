#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Kale
{
private:
	float puan = 5;
	int kSayý;
	char kHarf;
public:
	Kale() {}
	Kale(int, char);
	bool tehditHesapla(int, char, vector<pair<int, char>>);
	float puanHesapla(bool);
};
Kale::Kale(int kSayý, char kHarf) {
	this->kSayý = kSayý;
	this->kHarf = kHarf;
}

bool Kale::tehditHesapla(int mSayý, char mHarf, vector<pair<int, char>> boþluk) {
	int count = 0;
		if (kSayý == mSayý || kHarf == mHarf)
		{
			for (int x = 0; x < boþluk.size(); x++)
			{
				if (mSayý == kSayý && (boþluk[x].first == mSayý))
				{
					if ((mHarf > kHarf) && (boþluk[x].second > kHarf && boþluk[x].second < mHarf))
						count++;
					else if ((mHarf < kHarf) && (boþluk[x].second < kHarf && boþluk[x].second > mHarf))
						count++;
				}
				else if (mHarf == kHarf && (boþluk[x].second == mHarf))
				{
					if ((mSayý > kSayý) && (boþluk[x].first > kSayý && boþluk[x].first < mSayý))
						count++;
					else if ((mSayý < kSayý) && (boþluk[x].first < kSayý && boþluk[x].first > mSayý))
						count++;
				}
			}
			if (count == abs(mSayý - kSayý) - 1) return true;
			else if (count == (int)abs(mHarf - kHarf) - 1) return true;
			return false;
		}

	return false;
}

float Kale::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

