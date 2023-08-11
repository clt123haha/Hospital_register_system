#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class DEDoctorWin : public CWin
{
public:
	DEDoctorWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};