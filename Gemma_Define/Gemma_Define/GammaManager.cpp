#include "stdafx.h"
#include <stdlib.h>
#include <ctime>
#include "GammaManager.h"
#include "Gammas_constants.h"
using namespace std;


GammaManager::GammaManager(void)
{
}


GammaManager::~GammaManager(void)
{
}

Gamma* GammaManager::getGamma (string &text)
{
	Gamma *currentGamma = (Gamma*)malloc(1);
	srand(time(NULL));
	currentGamma->_mood = rand()%2;
	int note = getNote(text);
	currentGamma->_gamma_type = (note + currentGamma->_mood * 9)%12;
	return currentGamma;
}

int getNote (string &text)
{
	int notes[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int maxNotes[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	for(int i = 0;i < text.length();i++) {
		int l = text[i]%12;
		notes[l] = notes[l] + 1;
	}
	
	int sumOfNotes = 0;
	int currentSumOfNotes;
	int countOfMaxSumNotes;
	int indexOfNote;

	for (int i = 0; i < 12; i++) {

		int positionOfNote = i;
		currentSumOfNotes = 0;

		for (int j = 0; j < 7; j++) {
			positionOfNote = (positionOfNote + major[j])%12;
			currentSumOfNotes = currentSumOfNotes + notes[positionOfNote];
		}

		if (currentSumOfNotes > sumOfNotes) {
			sumOfNotes = currentSumOfNotes;
			indexOfNote = i;
			countOfMaxSumNotes = 1;

			for (int k = 0; k < 12; k++) {
				if (k == indexOfNote) {
					maxNotes[k] = 1;
				} else {
					maxNotes[k] = 0;
				}
			}

		} else if (currentSumOfNotes == sumOfNotes) {
			countOfMaxSumNotes++;
			maxNotes[i] = 1;
		}
	}

	if (countOfMaxSumNotes == 1) {
		return indexOfNote;
	} else {
		srand(time(NULL));
		int currentIndexOfNote = rand()%countOfMaxSumNotes + 1;
		int counter = 0;
		int i;
		for (i = 0; i < 12; i++) {
			if (maxNotes[i] == 1) {
				counter++;
			}
			if (counter == currentIndexOfNote) {
				break;
			}
		}
		return i + 1;
	}	
}
