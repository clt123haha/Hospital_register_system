#include "DEDoctorWin.h"
#pragma warning(disable : 4786)

DEDoctorWin::DEDoctorWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(25,17,5,5,"提示：用户不存在");
	Contorl *c2 = new CBun(28,20,5,3,"重新输入");
	Contorl *c3 = new CBun(28,25,5,3,"新增医生");
	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	
}

int DEDoctorWin::doaction(int n)
{
	if(n == 1)
		return 10;
	else if(n == 2)
		return 18;
	return -1;
}

int DEDoctorWin::runWin()
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