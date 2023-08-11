#ifndef  PopUp_H
#define  PopUp_H

#include "CWin.h"

class PopUp : public CWin
{
public:
	PopUp(int x,int y,int width,int height,char *ch);
	int doaction(int n);
	int runWin();
};

#endif