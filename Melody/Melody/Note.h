#pragma once
#include "NoteName.h"

#include "NotationElement.h"


using namespace std;

class Note:
	public NotationElement
{
private:
	NoteName name;
	float frequency;
	bool isARest;
	int octave;
	long getDurationInMillis();
public:
	Note(void);
	Note(NoteDuration duration,NoteName name);
	Note(NoteDuration duration,bool isRest);
	~Note(void);

	bool isRest();

	NoteName getSystemName();

	virtual std::string getName();

	float getFrequency();
	void play();

	void setName(NoteName name);

	int getOctave();
};