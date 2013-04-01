#pragma once
#include "Scale.h"

class HarmonicMinorScale:
	public Scale
{
public:
	HarmonicMinorScale(void);
	~HarmonicMinorScale(void);

	HarmonicMinorScale(string text);
	
	HarmonicMinorScale(NoteName n);

};