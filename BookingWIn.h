#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class BookingWin : public CWin
{
public:
	BookingWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};