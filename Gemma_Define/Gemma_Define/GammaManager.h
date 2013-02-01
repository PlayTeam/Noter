#include <string>
using namespace std;


struct Gamma {
	int _gamma_type;
	int  _mood;
};

class GammaManager
{
public:
	GammaManager(void);
	~GammaManager(void);
	static Gamma* getGamma (string &text);
};



int getNote (string &text);