#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class CreatDoctor : public CWin
{
public:
	CreatDoctor(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};