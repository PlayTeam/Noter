#pragma once
#include "ScaleDefiner.h"
#include "PureMajorScale.h"
#include "HarmonicMinorScale.h"
#include <time.h>

Scale* ScaleDefiner::getScale(string text)
{
	int mode=rand()%2;
	Scale* currentScale;

	switch(mode)
	{
		case Scale::MAJOR:
			{
				
				currentScale=new PureMajorScale(text);
				break;
			}
		case Scale::MINOR:
			{
				
				currentScale=new HarmonicMinorScale(text);
			}
	}

	return currentScale;
}