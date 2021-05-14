#pragma once

#include <iostream>
#include <vector>
using namespace std;

class �ah
{
private:
	float puan = 100;
	int kSay�;
	char kHarf;
public:
	�ah() {}
	�ah(int, char);
	bool tehditHesapla(int, char);
	float puanHesapla(bool);
	vector<pair<int, char>> hamleTehdit(int, char, vector<pair<int, char>>);
};
�ah::�ah(int kSay�, char kHarf) {
	this->kSay� = kSay�;
	this->kHarf = kHarf;
}

bool �ah::tehditHesapla(int mSay�, char mHarf) {
	if ((kSay� == mSay� + 1 || kSay� == mSay� - 1) && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if (kSay� == mSay� && (kHarf == mHarf - 1 || kHarf == mHarf + 1)) return true;
	else if (kHarf == mHarf && (kSay� == mSay� - 1 || kSay� == mSay� + 1)) return true;
	else return false;
}

vector<pair<int, char>> �ah::hamleTehdit(int mSay�, char mHarf, vector<pair<int, char>> bo�luk) {
	vector<pair<int, char>> hamleler;
	for (int x = 0; x < bo�luk.size(); x++)
	{
		if (bo�luk[x].first == mSay� + 1 && bo�luk[x].second == mHarf) hamleler.emplace_back(mSay� + 1, mHarf);
		else if (bo�luk[x].first == mSay� - 1 && bo�luk[x].second == mHarf) hamleler.emplace_back(mSay� - 1, mHarf);
		else if (bo�luk[x].first == mSay� && bo�luk[x].second == mHarf + 1) hamleler.emplace_back(mSay�, mHarf + 1);
		else if (bo�luk[x].first == mSay� && bo�luk[x].second == mHarf - 1) hamleler.emplace_back(mSay�, mHarf - 1);
		else if (bo�luk[x].first == mSay� + 1 && bo�luk[x].second == mHarf - 1) hamleler.emplace_back(mSay� + 1, mHarf - 1);
		else if (bo�luk[x].first == mSay� + 1 && bo�luk[x].second == mHarf + 1) hamleler.emplace_back(mSay� + 1, mHarf + 1);
		else if (bo�luk[x].first == mSay� - 1 && bo�luk[x].second == mHarf - 1) hamleler.emplace_back(mSay� - 1, mHarf - 1);
		else if (bo�luk[x].first == mSay� - 1 && bo�luk[x].second == mHarf + 1) hamleler.emplace_back(mSay� - 1, mHarf + 1);
	}
	return hamleler;
}


float �ah::puanHesapla(bool tehdit) {
	if (tehdit == true) return puan / 2;
	else return puan;
}

