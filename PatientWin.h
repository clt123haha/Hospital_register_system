#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class PatientWin : public CWin
{
public:
	PatientWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};