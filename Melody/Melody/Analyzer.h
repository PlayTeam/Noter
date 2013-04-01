#pragma once
#include "Note.h"
#include <vector>
class Analyzer
{
private:
	int bars;
	vector<Note> notes;
	void addNote(char ch);
	void checkBar(char ch);
	void clearDoubleRests();
	void shuffle();
	void fulfill();
	string vowels;

	int getRestDuration();
	NotationElement::NoteDuration getRandomDuration();
public:
	vector<Note> analyzeDurations(string s);
	Analyzer();
	~Analyzer();
};

