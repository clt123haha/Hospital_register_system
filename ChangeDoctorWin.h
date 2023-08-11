#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class ChangeDoctorWin : public CWin
{
public:
	int id;
	ChangeDoctorWin(int x,int y,int width,int height,int id);
	int doaction(int n);
	int runWin();
};