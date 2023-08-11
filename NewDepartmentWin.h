#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class NewDepartmentWin : public CWin
{
public:
	NewDepartmentWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};