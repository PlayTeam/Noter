#pragma once
#include "Scale.h"
class PureMajorScale:
	public Scale
{
public:
	PureMajorScale(void);
	~PureMajorScale(void);

	PureMajorScale(NoteName n);
	PureMajorScale(string text);
};