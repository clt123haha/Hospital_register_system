#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class SearchUserWin : public CWin
{
public:
	SearchUserWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};