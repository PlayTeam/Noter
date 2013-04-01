#ifndef H_NOTENAME
#define H_NOTENAME

#define CASE(M) case M: return #M;

enum NoteName {C=1,Cis,D,Dis,E,F,Fis,G,Gis,A,Ais,B};

inline const char* GET_NAME(NoteName m)
{
  switch(m)
  {
    CASE(C)
    CASE(Cis)
    CASE(D)
    CASE(Dis)
    CASE(E)
	CASE(F)
	CASE(Fis)
	CASE(G)
	CASE(Gis)
	CASE(A)
	CASE(Ais)
	CASE(B)
    default:
       return "<<not defined>>";
  }
}

#endif