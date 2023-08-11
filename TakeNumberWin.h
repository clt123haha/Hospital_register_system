#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class TakeNumberWin : public CWin
{
public:
	int id;
	TakeNumberWin(int x,int y,int width,int height,int id);
	int doaction(int n);
	int runWin();
};