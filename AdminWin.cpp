#include "AdminWin.h"
#pragma warning(disable : 4786)

AdminWin::AdminWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"����Ա������");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx����Ա");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CBun(15,15,8,3,"�û�����");
	Contorl *c5 = new CBun(15,20,8,3,"���ҹ���");
	Contorl *c6 = new CBun(15,25,8,3,"�˳�");
	Contorl *c7 = new CBun(40,15,8,3,"ҽ������");
	Contorl *c8 = new CBun(40,20,8,3,"����ͳ��");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
}

int AdminWin::doaction(int n)
{

	//������ת
	if(n == 3)
		return 9;

	else if(n == 5)
		return 2;

	else if(n == 4)
		return 11;

	else if(n == 6)
		return 10;
	else if(n == 7)
		return 21;
}

int AdminWin::runWin()
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