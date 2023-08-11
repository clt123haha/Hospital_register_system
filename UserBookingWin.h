#include "CWin.h"
#include "global.h"

class UserBookingWin : public CWin
{
public:
	UserBookingWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};