#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class ChangePwdWin : public CWin
{
public:
	ChangePwdWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};