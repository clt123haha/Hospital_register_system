#include "Vaccine.h"
#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class VaccineSearchWin : public CWin
{
public:
	VaccineSearchWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};
