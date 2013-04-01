#pragma once
#pragma once
#include "Scale.h"
#include <vector>

class NoteGenerator
{
private:
//	static Note getNextNote(Note* prevNotes);
//	static int trendIndex;
	enum Movement
	{
		DOWN=-1,CONST=0,UP=1
	};
public:
	static std::vector<Note> generateNotes(Scale scale,std::vector<Note> notesWithDurations);
};



//int NoteGenerator::trendIndex=0;
