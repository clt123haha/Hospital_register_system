#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class SearchDepartmentWin : public CWin
{
public:
	SearchDepartmentWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};