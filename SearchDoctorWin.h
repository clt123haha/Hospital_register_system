#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class SearchDoctorWin : public CWin
{
public:
	SearchDoctorWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};