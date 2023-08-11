#include "ChangeBookingWIn.h"

ChangeBookingWIn::ChangeBookingWIn(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	this->id = id;
	char str[30];
	char doctor[20];
	char date[20];
	int time;
	int n = 0;

	//获取信息
	list<booking *> l;
	list<booking *>::iterator it;
	CTool::getTakeNumber(l);
	it = l.begin();
	advance(it,id);
	strcpy(doctor,(*it)->doctor);
	strcpy(date,(*it)->date);
	time = (*it)->time;

	//得到排队人数
	for(it = l.begin();it != l.end();it++)
	{
		if(strcmp(doctor,(*it)->doctor)==0&&time>=(*it)->time&&strcmp(date,(*it)->date)==0&&strcmp("等待就诊",(*it)->state)==0)
			n++;
	}
	sprintf(str,"提示：当前排队%d人",n);
	Contorl *c1 = new CLable(15,13,5,5,str);
	Contorl *c2 = new CBun(15,17,5,3,"取号");
	Contorl *c3 = new CBun(25,17,5,3,"取消预约");
	Contorl *c4 = new CBun(35,17,5,3,"返回");
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

	//信息修改
	if(n == 1)
	{
		advance(it,id);
		if(strcmp((*it)->state,"未就诊") == 0)
		{
			strcpy((*it)->state,"等待就诊");
		}
		CTool::setTakeNumber(l);
		PopUp tempwin(15,15,20,15,"修改成功");
		tempwin.showWin();
		tempwin.runWin();
		return 10;
	}else if(n == 2)
	{
		advance(it,id);
		if(strcmp((*it)->state,"等待就诊") == 0)
		{
			strcpy((*it)->state,"未就诊");
		}
		CTool::setTakeNumber(l);
		CTool::setTakeNumber(l);
		PopUp tempwin(15,15,20,15,"修改成功");
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