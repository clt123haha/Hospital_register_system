#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class LoginWin : public CWin
{
public:
	LoginWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};