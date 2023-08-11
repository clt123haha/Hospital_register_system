#include "CMainWin.h"

CMainWin::CMainWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CBun(10,10,20,5,"ע�᡾1��");
	Contorl *c3 = new CBun(10,15,20,5,"��¼��2��");
	Contorl *c4 = new CBun(10,20,20,5,"�˳���3��");
	Contorl *c5 = new CLable(20,25,10,5,"ѧ��:OMO025321");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
}

int CMainWin::doaction(int n)
{
	if(n == 1)
	{
		return 1;
	}else if(n == 2)
	{
		return 2;
	}else if(n == 3)
	{
		char ch;
		CTool::drawLineBackgroud(x+10,y+10,20,5);
		CTool::gotoxy(x+12,y+11);
		printf("�����˳��밴�س���,�����˳��밴esc");
		while(true)
		{
			ch = getch();
			if(ch == 27)
			{
				this->showWin();
				break;
			}
			else if(ch == 13)
				return -1;

		}
		return -2;
	}
	return 0;
}

int CMainWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -2)
			return temp;
	}
	return 0;
}