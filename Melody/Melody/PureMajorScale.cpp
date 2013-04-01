#include "PureMajorScale.h"


PureMajorScale::PureMajorScale(void)
{
	this->mode=Scale::MAJOR;
	this->formula=std::string("2212221");
}

PureMajorScale::PureMajorScale(string text)
{
	
	this->mode=Scale::MAJOR;
	this->formula=std::string("2212221");
	this->tonicNote=getNote(text);
}


PureMajorScale::~PureMajorScale(void)
{
}


PureMajorScale::PureMajorScale(NoteName n)
{
	this->mode=Scale::MAJOR;
	this->tonicNote=n;
	this->formula=std::string("2212221");
}