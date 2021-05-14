#pragma once

#include <iostream>
#include <vector>
using namespace std;

class Kale
{
private:
	float puan = 5;
	int kSay�;
	char kHarf;
public:
	Kale() {}
	Kale(int, char);
	bool tehditHesapla(int, char, vector<pair<int, char>>);
	float puanHesapla(bool);
};
Kale::Kale(int kSay�, char kHarf) {
	this->kSay� = kSay�;
	this->kHarf = kHarf;
}

bool Kale::tehditHesapla(int mSay�, char mHarf, vector<pair<int, char>> bo�luk) {
	int count = 0;
		if (kSay� == mSay� || kHarf == mHarf)
		{
			for (int x = 0; x < bo�luk.size(); x++)
			{
				if (mSay� == kSay� && (bo�luk[x].first == mSay�))
				{
					if ((mHarf > kHarf) && (bo�luk[x].second > kHarf && bo�luk[x].second < mHarf))
						count++;
					else if ((mHarf < kHarf) && (bo�luk[x].second < kHarf && bo�luk[x].second > mHarf))
						count++;
				}
				else if (mHarf == kHarf && (bo�luk[x].second == mHarf))
				{
					if ((mSay� > kSay�) && (bo�luk[x].first > kSay� && bo�luk[x].first < mSay�))
						count++;
					else if ((mSay� < kSay�) && (bo�luk[x].first < kSay� && bo�luk[x].first > mSay�))
						count++;
				}
			}
			if (count == abs(mSay� - kSay�) - 1) return true;
			else if (count == (int)abs(mHarf - kHarf) - 1) return true;
			return false;
		}

	return false;
}

float Kale::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

