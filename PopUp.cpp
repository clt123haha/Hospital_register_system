#include "PopUp.h"
#pragma warning(disable : 4786)

PopUp::PopUp(int x,int y,int width,int height,char *ch) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(25,20,5,5,ch);
	this->addContorl(c1);
}

int PopUp::doaction(int n)
{

	return -1;
}

int PopUp::runWin()
{	
	getch();
	return 0;
}
