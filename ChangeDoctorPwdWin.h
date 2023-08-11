#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class ChangeDoctorPwdWin : public CWin
{
public:
	ChangeDoctorPwdWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};