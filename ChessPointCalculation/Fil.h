#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Fil
{
private:
	float puan = 3;
	int kSay�;
	char kHarf;
public:
	Fil(){}
	Fil(int, char);
	bool tehditHesapla(int, char, vector<pair<int, char>>);
	float puanHesapla(bool);
};
Fil::Fil(int kSay�, char kHarf) {
	this->kSay� = kSay�;
	this->kHarf = kHarf;
}

bool Fil::tehditHesapla(int mSay�, char mHarf, vector<pair<int, char>> bo�luk) {
	int count = 0;
	for (int i = 1; (mSay�-i > 0 || mSay�+i < 9); i++)
	{
		if ((kSay� == mSay� - i || kSay� == mSay� + i) && (kHarf == mHarf - i || kHarf == mHarf + i))
		{
			for (int x = 0; x < bo�luk.size(); x++)
			{
				if (mSay� < kSay� && (bo�luk[x].first > mSay� && bo�luk[x].first < kSay�))
				{
					if ((bo�luk[x].second == mHarf - (bo�luk[x].first - mSay�)) && (mHarf > kHarf))
						count++;
					else if ((bo�luk[x].second == mHarf + (bo�luk[x].first - mSay�)) && (mHarf < kHarf))
						count++;
				}
				else if (mSay� > kSay� && (bo�luk[x].first > kSay� && bo�luk[x].first < mSay�))
				{
					if ((bo�luk[x].second == mHarf - (mSay� - bo�luk[x].first)) && (mHarf > kHarf))
						count++;
					else if ((bo�luk[x].second == mHarf + (mSay� - bo�luk[x].first)) && (mHarf < kHarf))
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

