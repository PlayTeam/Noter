#include "NoterContext.h"


NoterContext::NoterContext(void)
{

}


NoterContext::~NoterContext(void)
{
}
/*
void NoterContext::initialize()
{
	freqMap=createFreqMap();
}
*/
/*
NoterContext::NoteName NoterContext::createNameMap()
{
	NoteName result;
	result[Note::C]="C";
	result[Note::Cis]="C#";
	result[Note::D]="D";
	result[Note::Dis]="D#";
	result[Note::E]="E";
	result[Note::F]="F";
	result[Note::Fis]="Fis";
	result[Note::G]="G";
	result[Note::Gis]="Gis";
	result[Note::A]="A";
	result[Note::Ais]="Ais";
	result[Note::B]="B";

	return result;
}
*/

NoterContext::NoteFreq NoterContext::createFreqMap()
{
	NoteFreq result;
	result[NoteName::C]=261.63;
	result[NoteName::Cis]=277.18;
	result[NoteName::D]=293.66;
	result[NoteName::Dis]=311.13;
	result[NoteName::E]=329.63;
	result[NoteName::F]=349.23;
	result[NoteName::Fis]=369.99;
	result[NoteName::G]=392.00;
	result[NoteName::Gis]=415.30;
	result[NoteName::A]=440;
	result[NoteName::Ais]=466.16;
	result[NoteName::B]=493.88;

	return result;
}

NoterContext::NoteFreq NoterContext::freqMap(NoterContext::createFreqMap());

//NoterContext::NoteName NoterContext::nameMap(NoterContext::createNameMap());