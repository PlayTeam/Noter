#pragma once

class LeftHandTrack
{
public:
	LeftHandTrack(void);
	~LeftHandTrack(void);
	static	void tratata (void);
private:
static int numberOfBars(void);	// number of bars in unique part. Unique part includes durations of notes. 
							//Intervals are const. Unique part will repeats with another first notes.

static int getRandomDuration(void);

static int* arrOfIntervals(int durCount);

static int* arrOfFirstNotes(int numberOfRepeatingUniqueParts);

};


