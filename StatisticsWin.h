#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class StatisticsWin : public CWin
{
public:
	StatisticsWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};