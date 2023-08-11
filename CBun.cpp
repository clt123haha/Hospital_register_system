#include "CBun.h"
#pragma warning(disable : 4786)

CBun::CBun(int x,int y,int width,int height,char *content):Contorl(x,y,width,height,content,BUN)
{

}

void CBun::showContorl()
{
	CTool::drawLineBackgroud(x,y,width,height);
	CTool::gotoxy(x+(width-strlen(this->content)/2),y+1);
	printf("%s",this->content);
}

void CBun::runContorl()
{}