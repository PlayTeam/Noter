#include "Scale.h"
#include <time.h>
#include <iostream>
using namespace std;

Scale::Scale(void)
{
}
/*
Scale::Scale(string text)
{
	this->tonicNote=getNote(text);
}

*/
Scale::Scale(NoteName n)
{
	this->tonicNote=n;
}


Scale::~Scale(void)
{
}

NoteName* Scale::getAvailableNotesAsArray()
{
	NoteName* notes=new NoteName[formula.length()];
//	std::vector<NoteName> notes;
	NoteName temp=tonicNote;

	notes[0]=tonicNote;
//	notes.push_back(tonicNote);

	for(unsigned int i=0;i<formula.length()-1;i++)
	{
		int semitones=formula[i]-48;
		temp=NoteName(temp+semitones);
		if(temp>12)
		{
			temp=NoteName(temp%12);
		}
		notes[i+1]=temp;
//		notes.push_back(temp);
	}

	return notes;
}


std::vector<NoteName> Scale::getAvailableNotes()
{
	std::vector<NoteName> notes;
	NoteName temp=tonicNote;

	notes.push_back(tonicNote);

	for(unsigned int i=0;i<formula.length()-1;i++)
	{
		int semitones=formula[i]-48;
		temp=NoteName(temp+semitones);
		if(temp>12)
		{
			temp=NoteName(temp%12);
		}
		notes.push_back(temp);
	}

	return notes;
}

NoteName Scale::getNote(string text)
{
	int notes[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	int maxNotes[12] = {0,0,0,0,0,0,0,0,0,0,0,0};
	for(unsigned int i = 0;i < text.length();i++) {
		int l = text[i]%12;
		notes[l] = notes[l] + 1;
	}
	
	int sumOfNotes = 0;
	int currentSumOfNotes;
	int countOfMaxSumNotes;
	int indexOfNote;

	for (unsigned int i = 0; i < 12; i++) {

		int positionOfNote = i;
		currentSumOfNotes = 0;

		for (unsigned int j = 0; j < 7; j++) {
			positionOfNote = (positionOfNote + formula[j])%12;
			currentSumOfNotes = currentSumOfNotes + notes[positionOfNote];
		}

		if (currentSumOfNotes > sumOfNotes) {
			sumOfNotes = currentSumOfNotes;
			indexOfNote = i;
			countOfMaxSumNotes = 1;

			for (unsigned int k = 0; k < 12; k++) {
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
		return (NoteName)(indexOfNote + 1);
	} else {
		srand(time(NULL));
		int currentIndexOfNote = rand()%countOfMaxSumNotes + 1;
		int counter = 0;
		unsigned int i;
		for (i = 0; i < 12; i++) {
			if (maxNotes[i] == 1) {
				counter++;
			}
			if (counter == currentIndexOfNote) {
				break;
			}
		}
		return (NoteName)(i + 1);
	}
}