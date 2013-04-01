#pragma once
#include "Note.h"
#include <string>
#include <vector>

using namespace std;
class Scale
{

public:
	Scale(void);
	Scale(NoteName n);
	~Scale(void);
	static enum Mode{MINOR=0,MAJOR};
	std::vector<NoteName> getAvailableNotes();
	NoteName* getAvailableNotesAsArray();
	Mode getMode()
	{
		return mode;
	}
	NoteName getTonicNote()
	{
		return tonicNote;
	}
protected:
	std::string formula;
	Mode mode;
	NoteName tonicNote;
	NoteName getNote(string text);
};