#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class IftPerfectionWin : public CWin
{
public:
	IftPerfectionWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};