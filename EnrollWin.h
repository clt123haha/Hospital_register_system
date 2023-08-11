#include "CWin.h"
#include "global.h"
#include "PopUp.h"


class EnrollWin : public CWin
{
public:
	EnrollWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};