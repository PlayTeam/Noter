#include "NoterContext.h"
#include "ScaleDefiner.h"
#include "Analyzer.h"
#include "Note.h"
#include "PureMajorScale.h"
#include "HarmonicMinorScale.h"
#include "NoteGenerator.h"
#include <iostream>


using namespace std;

void main()
{
//	NotationElement* n1=new Note(NotationElement::HALF,NoteName::Ais);

	/*
	Scale* s=new HarmonicMinorScale(NoteName::Cis);

//	cout << n1->getName() << endl;

	std::vector<NoteName> notes=s->getAvailableNotes();

	for(std::vector<NoteName>::iterator it=notes.begin();it!=notes.end();++it)
	{
		cout << GET_NAME(*it) << " | ";
	}
	*/
	cout << endl;

	NoterContext context=NoterContext();

	string str_to_check;

	std::getline(std::cin,str_to_check);

//	cin >> str_to_check;

	Analyzer an=Analyzer();

	std::vector<Note> calculatedNotes=an.analyzeDurations(str_to_check);

	Scale* scale=ScaleDefiner::getScale(str_to_check);

	cout << GET_NAME(scale->getTonicNote());
	
	std::vector<Note> melody=NoteGenerator::generateNotes(*scale,calculatedNotes);
	
	for(std::vector<Note>::iterator it=melody.begin();it!=melody.end();++it)
	{
		(*it).play();
	}
	
	system("PAUSE");

}