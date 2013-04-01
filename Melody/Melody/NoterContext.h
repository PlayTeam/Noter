#pragma once
#include "Note.h"
#include <map>
#include <vector>
class NoterContext
{
public:
	NoterContext(void);
	~NoterContext(void);
	typedef std::map<NoteName,double> NoteFreq;
	
	static NoteFreq freqMap;
	static const int tempo=120;
private:
//	static NoteName createNameMap();

	static NoteFreq createFreqMap();
};