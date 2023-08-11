#include "ReservationWin.h"
#pragma warning(disable : 4786)

ReservationWin::ReservationWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx管理员");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CBun(15,15,5,3,"预约门诊");
	Contorl *c5 = new CBun(15,25,5,3,"疫苗接种列表");
	Contorl *c6 = new CBun(40,15,5,3,"预约疫苗");
	Contorl *c7 = new CBun(40,25,5,3,"返回");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
}

int ReservationWin::doaction(int n)
{
	if(n == 6)
		return 3;
	else if(n == 3)
		return 7;
	else if(n == 5)
		return 22;
	else if(n == 4)
		return 23;
	return -1;
}

int ReservationWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 0;
}