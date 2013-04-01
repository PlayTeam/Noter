#include "HarmonicMinorScale.h"


// тон-полутон-тон-тон-полутон-полтора тона-полутон.

HarmonicMinorScale::~HarmonicMinorScale(void)
{
}

HarmonicMinorScale::HarmonicMinorScale(void)
{
	this->mode=Scale::MINOR;
	this->formula=std::string("2212221");
}

HarmonicMinorScale::HarmonicMinorScale(string text)
{
	this->mode=Scale::MINOR;
	this->formula=std::string("2212221");
	this->tonicNote=getNote(text);
}


HarmonicMinorScale::HarmonicMinorScale(NoteName n)
{
	this->mode=Scale::MAJOR;
	this->tonicNote=n;
	this->formula=std::string("2122131");
}


