#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class PersonCenterWin : public CWin
{
public:
	PersonCenterWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};