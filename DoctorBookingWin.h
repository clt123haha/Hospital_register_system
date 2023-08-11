#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class DoctorBookingWin : public CWin
{
public:
	DoctorBookingWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};