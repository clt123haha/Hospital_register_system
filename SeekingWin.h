#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class SeekingWin : public CWin
{
public:
	int bid;
	SeekingWin(int x,int y,int width,int height,int id);
	int doaction(int n);
	int runWin();
};