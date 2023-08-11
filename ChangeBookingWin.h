#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class ChangeBookingWIn : public CWin
{
public:
	int id;
	ChangeBookingWIn(int x,int y,int width,int height,int id);
	int doaction(int n);
	int runWin();
};