// Gemma_Define.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "GammaManager.h"
#include "LeftHandTrack.h"
#include <iostream>
#include <string>
using namespace std;
int _tmain(int argc, _TCHAR* argv[])
{
	string text;

	LeftHandTrack::tratata();

	cout <<"Input string: ";
	getline(cin,text);

	Gamma *gamma;
	gamma = GammaManager::getGamma(text);
	if (gamma->_mood) {
		cout << gamma->_gamma_type <<", minor";
	} else {
		cout << gamma->_gamma_type <<", major";
	}
	free(gamma);
	return 0;
}

