#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class DoctorWin : public CWin
{
public:
	DoctorWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};