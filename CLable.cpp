#include "CLable.h"

CLable::CLable(int x,int y,int width,int height,char *content):Contorl(x,y,width,height,content,LABLE)
{

}

void CLable::showContorl()
{
	CTool::gotoxy(x,y);
	printf("%s",this->content);
}

void CLable::runContorl()
{}