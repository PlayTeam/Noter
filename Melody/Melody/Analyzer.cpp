#include "Analyzer.h"
#include <algorithm>
#include <time.h>
#include <iostream>





void Analyzer::addNote(char ch)
{
	if(vowels.find(ch)!=string::npos)
	{
		notes.push_back(Note(getRandomDuration(),false));
	}
}
void Analyzer::checkBar(char ch)
{
	if (ch==' ')
	{
		bars++;
		notes.push_back(Note(getRandomDuration(), true));
	}
}
void Analyzer::clearDoubleRests()
{
	unsigned int i=0; 
	while (i<notes.size()-2)
	{
		if (notes[i].isRest() && notes [i+1].isRest()) 
		{
			notes.erase(notes.begin()+i+1);
		}
		else i++;
	}
}
void Analyzer::shuffle()
{
	std::random_shuffle( notes.begin(), notes.end() );
}
void Analyzer::fulfill()
{
	float sum = (float)bars;
	for (unsigned int i=0; i<notes.size();i++)
	{
		sum -= (float)1/(int)notes[i].getDuration();
	}
}
int Analyzer::getRestDuration()
{
	return NotationElement::EIGHTH;
}

NotationElement::NoteDuration Analyzer::getRandomDuration()
{
	srand(time(NULL));
	int power=pow(2.0,rand()%2+3);
	cout << "power: " << power;

	return (NotationElement::NoteDuration)power;
}

vector<Note> Analyzer::analyzeDurations(string s)
{
	for(unsigned int i=0;i<s.length();i++)
	{
		addNote(s[i]);
		checkBar(s[i]);
	}
	shuffle();
	clearDoubleRests();
	return notes;
}

Analyzer::Analyzer()
{
	bars=0;
	vowels="aeiouAEIOU";
	notes=vector<Note>();
}
Analyzer::~Analyzer()
{
	free(&notes);
}
