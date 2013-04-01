#pragma once
#include "NoterContext.h"
#include <string>
class NotationElement
{
public:
	static enum NoteType
	{
		NOTE=1,REST
	};
	static enum NoteDuration
	{
		HALF=2,QUARTER=4,EIGHTH=8,SIXTEENTH=16
	};
	
	virtual std::string getName()=0;
	NoteType getNoteType()
	{
		return type;
	}
	NoteDuration getDuration()
	{
		return duration;
	}
protected:
	NoteDuration duration;
	NoteType type;
};