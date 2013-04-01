#include "Note.h"
#include "NoterContext.h"
#include <windows.h>
#include <iostream>


Note::Note(void)
{
	this->type=NoteType::NOTE;
	this->isARest=false;
}

Note::Note(NoteDuration duration,NoteName name)
{
	this->type=NoteType::NOTE;
	this->duration=duration;
	this->name=name;
	this->isARest=false;
	std::map<NoteName,double>::iterator value=NoterContext::freqMap.find(name); 
	this->frequency=value->second;
}

Note::Note(NoteDuration duration,bool isRest)
{
	this->type=NoteType::NOTE;
	this->duration=duration;
	this->isARest=isRest;
}


Note::~Note(void)
{
}

std::string Note::getName()
{
	return GET_NAME(name);
}

float Note::getFrequency()
{
	return frequency;
}

bool Note::isRest()
{
	return isARest;
}

void Note::play()
{
	
	if (isARest)
	{
		cout << "Beeping a " << duration << " rest" << endl;
		Beep(0,100);
	}
	else
	{
		cout << "Beeping " << frequency << " " << GET_NAME(name) << endl;
		long dur=1000*getDurationInMillis();
		Beep(frequency,dur);
//		Sleep(duration-100);
	}
}

void Note::setName(NoteName name)
{
	this->name=name;
}

long Note::getDurationInMillis()
{//TODO: note duration calculation
	switch(duration)
	{
		case QUARTER:
			{
				return (long)60/NoterContext::tempo;
			}
		case EIGHTH:
			{
				return (long)60/(0.5*NoterContext::tempo);
			}
		case SIXTEENTH:
			{
				return (long)60/(0.25*NoterContext::tempo);
			}
	}
}

int Note::getOctave()
{
	return octave;
}

NoteName Note::getSystemName()
{
	return name;
}