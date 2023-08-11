#include "PersonCenterWin.h"
#pragma warning(disable : 4786)

PersonCenterWin::PersonCenterWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx用户");
	Contorl *c3 = new CLable(30,10,20,5,"");
	Contorl *c4 = new CBun(15,15,8,3,"信息完善");
	Contorl *c5 = new CBun(15,20,8,3,"返回");
	Contorl *c6 = new CBun(40,15,8,3,"修改密码");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int PersonCenterWin::doaction(int n)
{
	if(n == 3)
		return 5;
	if(n==4)
		return 3;
	if(n==5)
		return 6;
	return -1;
}

int PersonCenterWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 3;
}