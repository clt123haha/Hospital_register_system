#include "ChangeDoctorWin.h"

ChangeDoctorWin::ChangeDoctorWin(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	this->id = id;
	char str[30];
	sprintf(str,"ҽ��ID: %d",id);


	Contorl *c1 = new CLable(15,11,5,5,"��ʾ���޸�ְλ");
	Contorl *c2 = new CLable(20,13,5,5,str);
	Contorl *c3 = new CLable(20,16,5,5,"ְλ��");
	Contorl *c4 = new CCombobox(30,15,6,3,"ר��");
	Contorl *c5 = new CBun(20,18,5,3,"ȷ��");
	Contorl *c6 = new CBun(35,18,5,3,"����");


	CBun bun1(30,15,6,3,"ר��");
	CBun bun2(30,17,6,3,"����ҽ��");
	CBun bun3(30,19,6,3,"������ҽʦ");
	CBun bun4(30,21,6,3,"����ҽʦ");


	((CCombobox *)c4)->addBun(bun1);
	((CCombobox *)c4)->addBun(bun2);
	((CCombobox *)c4)->addBun(bun3);
	((CCombobox *)c4)->addBun(bun4);


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int ChangeDoctorWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();


	if(n == 3)
	{
		advance(p,3);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 4)
	{
		CTool::getDoctor(user);
		advance(p,3);
		strcpy(user[id]->posts,(*p)->content);
		CTool::write(user);
		PopUp tempwin(15,15,20,15,"�޸ĳɹ�");
		tempwin.showWin();
		tempwin.runWin();
		return 10;
	}else if(n == 5)
	{
		return 10;
	}
	return -1;
}

int ChangeDoctorWin::runWin()
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