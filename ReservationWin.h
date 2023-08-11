#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class ReservationWin : public CWin
{
public:
	ReservationWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};