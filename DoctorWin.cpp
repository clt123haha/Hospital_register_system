#include "DoctorWin.h"
#pragma warning(disable : 4786)

DoctorWin::DoctorWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxxҽ��");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CBun(15,15,8,3,"��������");
	Contorl *c5 = new CBun(15,20,8,3,"�˳�");
	Contorl *c6 = new CBun(40,15,8,3,"������Ϣ��ѯ");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int DoctorWin::doaction(int n)
{
	if(n == 3)
		return 15;
	else if(n==4)
		return 2;
	else if(n==5)
		return 16;
	return -1;
}

int DoctorWin::runWin()
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
