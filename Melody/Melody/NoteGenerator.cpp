#include "NoteGenerator.h"
#include <iostream>
#include <time.h>
#define _USE_MATH_DEFINES
#include <cmath>
#define PI 3.1415926535897932384626433832795
#define COEF 4


std::vector<Note> NoteGenerator::generateNotes(Scale scale,std::vector<Note> notesWithDurations)
{
	unsigned int melodyLength=notesWithDurations.size();

	NoteName* availableNotes=scale.getAvailableNotesAsArray();

	std::vector<Note> melody;

	Note tonicNote=Note(notesWithDurations[0].getDuration(),scale.getTonicNote());

	melody.push_back(tonicNote);

	for(unsigned int i=1;i<3;i++)
	{
		int randomNoteIndex=rand()%7;
		Note newNote=Note(notesWithDurations[i].getDuration(),availableNotes[randomNoteIndex]);
		melody.push_back(newNote);
	}



	for(unsigned int i=3;i<melodyLength;i++)
	{
		int randomNoteIndex=rand()%7;
		Note newNote=Note(notesWithDurations[i].getDuration(),availableNotes[randomNoteIndex]);

		cout << "================" << endl;
		cout << "New note: " << notesWithDurations[i].getDuration() << "-" << GET_NAME(availableNotes[randomNoteIndex]) << endl;
		cout << endl;

		melody.push_back(newNote);
	}

	return melody;
}
/*
Note NoteGenerator::getNextNote(Note* prevNotes)
{
	int n1=prevNotes[0].getSystemName();
	int n2=prevNotes[1].getSystemName();
	int n3=prevNotes[0].getSystemName();

	int result1=(n3>n1)?1:((n3==n1)?0:-1);
	int result2=(n2>n1)?1:((n2==n1)?0:-1);
	int result3=(n3>n2)?1:((n3==n2)?0:-1);

	int prevIndex=NoteGenerator::trendIndex;

	NoteGenerator::trendIndex+=result1*9 + result2*3 + result3;

	Note nextNote;

	int random=1+rand()%100;

	int choice;


	if(random<33)
	{
		choice=-1;
	}
	else if(random<66)
	{
		choice=0;
	}
	else
	{
		choice=1;
	}
	

	float probDown=getMovement(-1,NoteGenerator::trendIndex);
	float probConst=getMovement(0,NoteGenerator::trendIndex);
	float probUp=getMovement(1,NoteGenerator::trendIndex);

	if(random<probDown)
	{
		choice=-1;
	}
	else if(random>probUp)
	{
		random=1;
	}
	else
	{
		random=0;
	}


}
	*/
int getMovement(int move,int trendIndex)
{
	srand(time(NULL));
	float probability=(PI/2 - atan(double(4*move-trendIndex)))/PI;
	return 0;
}


