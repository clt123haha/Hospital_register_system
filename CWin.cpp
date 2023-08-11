#include "CWin.h"

CWin::CWin()
{
	n = 0;
}

CWin::CWin(int x,int y,int width,int height)
{
	this->x = x;
	this->y  =y;
	this->width = width;
	this->height = height;
	n = 0;
}

void CWin::addContorl(Contorl *contorl)
{
	arr.push_back(contorl);
}

void CWin::showWin()
{
	system("cls");
	CTool::drawLineBackgroud(x,y,width,height);
	list<Contorl *>::iterator p;
	for(p = arr.begin();p!=arr.end();p++)
	{
		(*p)->showContorl();
	}
}




int CWin::chooseContorl()
{
	char mark;
	list<Contorl *>::iterator p = arr.begin();
	list<CLable *>::iterator p2;
	while(p != arr.end())
	{
		if((*p)->type != LABLE) 
			break;
		p++;
	}
	while(true)
	{
		CTool::gotoxy((*p)->x,(*p)->y);
		mark = CTool::getkey();
		if(mark == DOWN)
		{
			while(true)
			{
				p++;
				if(p == arr.end())
					p = arr.begin();
				if((*p)->type != LABLE) 
					break;
			}
		}else if(mark == UP)
		{
			while(true)
			{
				if(p == arr.begin())
					p = arr.end();
				p--;
				if((*p)->type != LABLE) 
					break;
			}
		
		}else if(mark == ENTER)
		{
			return std::distance(arr.begin(), p);
		}else if(mark == BACK)
		{
			//这里可以根据需要做出相关决策
			//system("cls");
		}
		
	}
	return 0;
}

int CWin::doaction(int n)
{
	return 0;
}

int CWin::runWin()
{

	return 0;
}