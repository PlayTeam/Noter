#include "StdAfx.h"
#include "LeftHandTrack.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include <algorithm>
#include <iostream>
using namespace std;

#define MIN_DURATION 8 // 1/16 - min duration
LeftHandTrack::LeftHandTrack(void)
{
}


LeftHandTrack::~LeftHandTrack(void)
{
}

int LeftHandTrack::numberOfBars()
{
	return 1 + rand()%2;
}

int LeftHandTrack::getRandomDuration()
{
	
	int arrDur[] = {1,2,4};
	return arrDur[rand()%3];
}

void LeftHandTrack::tratata ()
{
	srand(time(NULL));
	cout<<"first notes: ";
	int *cur = LeftHandTrack::arrOfFirstNotes(4);
	cout<<"\n";
	int lenghtOfUniquePart = MIN_DURATION * LeftHandTrack::numberOfBars(); 
	int curLenght = 0;
	int *arrOfDurations = new int [0];
	int counter = 0;
	cout<<"durations: ";
	while (curLenght < lenghtOfUniquePart) {

		int *curArr = new int [counter + 1];
		copy(arrOfDurations,arrOfDurations + counter, curArr);
		delete [] arrOfDurations;
		arrOfDurations = curArr;

		int nextDuration = LeftHandTrack::getRandomDuration();
		while (curLenght + nextDuration > lenghtOfUniquePart) 
		{
			nextDuration = nextDuration/2;
		}

		arrOfDurations[counter] = nextDuration;
		cout<<arrOfDurations[counter]<<" ";
		counter++;
		curLenght = curLenght + nextDuration;		
	}
	cout<<"\n";
	cout<<"intervals: ";
	LeftHandTrack::arrOfIntervals(counter+1);
}

int* LeftHandTrack::arrOfIntervals(int durCount)
{
	int *arrInter = new int [durCount];
	arrInter[0] = 0;
	for (int i = 1; i < durCount-1; i++)
	{
		if (rand()%2) {
			arrInter[i] = rand()%5;
		} else {
			arrInter[i] = -rand()%5;
		}
		
		cout<<arrInter[i]<<" ";
	}
	return arrInter;
}

int* LeftHandTrack::arrOfFirstNotes(int numberOfRepeatingUniqueParts)
{
	srand(time(NULL));
	int *arrNotes = new int [numberOfRepeatingUniqueParts];
	arrNotes[0] = 1;
	for (int i = 1; i < numberOfRepeatingUniqueParts; i++)
	{
		int numbOfSteps = rand()%5;
		int l = rand()%2;
		if (!l) {
			numbOfSteps = - numbOfSteps;
		}
		int correct =(arrNotes[i-1] + 4 * numbOfSteps)%7;
		if (correct <= 0) {
			correct = 1 + (correct + 8)%7;
		}
		arrNotes[i] =  correct;
		cout<<correct<<" ";
	}
	return arrNotes;
}