#ifndef  AdminWin_H
#define  AdminWin_H

#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class AdminWin : public CWin
{
public:
	AdminWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};

#endif