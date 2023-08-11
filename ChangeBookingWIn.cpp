#include "ChangeBookingWIn.h"

ChangeBookingWIn::ChangeBookingWIn(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	this->id = id;
	char str[30];
	char doctor[20];
	char date[20];
	int time;
	int n = 0;

	//��ȡ��Ϣ
	list<booking *> l;
	list<booking *>::iterator it;
	CTool::getTakeNumber(l);
	it = l.begin();
	advance(it,id);
	strcpy(doctor,(*it)->doctor);
	strcpy(date,(*it)->date);
	time = (*it)->time;

	//�õ��Ŷ�����
	for(it = l.begin();it != l.end();it++)
	{
		if(strcmp(doctor,(*it)->doctor)==0&&time>=(*it)->time&&strcmp(date,(*it)->date)==0&&strcmp("�ȴ�����",(*it)->state)==0)
			n++;
	}
	sprintf(str,"��ʾ����ǰ�Ŷ�%d��",n);
	Contorl *c1 = new CLable(15,13,5,5,str);
	Contorl *c2 = new CBun(15,17,5,3,"ȡ��");
	Contorl *c3 = new CBun(25,17,5,3,"ȡ��ԤԼ");
	Contorl *c4 = new CBun(35,17,5,3,"����");
	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
}

int ChangeBookingWIn::doaction(int n)
{
	list<booking *> l;
	list<booking *>::iterator it;
	list<Contorl *>::iterator p;
	CTool::getTakeNumber(l);
	it = l.begin();
	p = arr.begin();

	//��Ϣ�޸�
	if(n == 1)
	{
		advance(it,id);
		if(strcmp((*it)->state,"δ����") == 0)
		{
			strcpy((*it)->state,"�ȴ�����");
		}
		CTool::setTakeNumber(l);
		PopUp tempwin(15,15,20,15,"�޸ĳɹ�");
		tempwin.showWin();
		tempwin.runWin();
		return 10;
	}else if(n == 2)
	{
		advance(it,id);
		if(strcmp((*it)->state,"�ȴ�����") == 0)
		{
			strcpy((*it)->state,"δ����");
		}
		CTool::setTakeNumber(l);
		CTool::setTakeNumber(l);
		PopUp tempwin(15,15,20,15,"�޸ĳɹ�");
		tempwin.showWin();
		tempwin.runWin();
		return 10;
	}else if(n == 3)
	{
		return 10;
	}
	return -1;
}

int ChangeBookingWIn::runWin()
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