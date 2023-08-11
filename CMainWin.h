#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class CMainWin : public CWin
{
public:
	CMainWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};