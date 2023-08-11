#include "PatientWin.h"
#pragma warning(disable : 4786)



PatientWin::PatientWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	char time[20];
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx用户");
	Contorl *c3 = new CLable(30,10,20,5,"");
	Contorl *c4 = new CBun(15,15,8,3,"个人中心");
	Contorl *c5 = new CBun(15,20,8,3,"取号");
	Contorl *c6 = new CBun(15,25,8,3,"退出");
	Contorl *c7 = new CBun(40,15,8,3,"预约管理");
	Contorl *c8 = new CBun(40,20,8,3,"就诊信息");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
}

int PatientWin::doaction(int n)
{
	if(n == 3)
	{
		return 4;
	}else if(n == 4)
	{
		return 14;
	}else if(n == 5)
	{
		return 2;
	}else if(n == 6)
	{
		return 17;
	}else if(n == 7)
	{
		return 13;
	}
	return -1;
}

int PatientWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 2;
}