#include "DoctorBookingWin.h"
#pragma warning(disable : 4786)

DoctorBookingWin::DoctorBookingWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx管理员");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CTable(15,15,21,10,"doctorbooking",4,3);
	Contorl *c5 = new CBun(15,30,5,3,"返回");
	Contorl *c6 = new CLable(40,31,8,3,"←→翻页");


	((CTable *)c4)->addstring("编号");
	((CTable *)c4)->addstring("就诊用户ID");
	((CTable *)c4)->addstring("状态");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int DoctorBookingWin::doaction(int n)
{
	list<Contorl *>::iterator it;
	it = arr.begin();
	if(n == 3)
	{
		advance(it,3);
		list<booking *> l;
		list<string> strlist;
		map<int,CUser *> l2;
		list<booking *>::iterator p;
		list<string>::iterator s;
		CTool::getTakeNumber(l);
		CTool::getDoctor(l2);
		char name[20];
		strcpy(name,l2[this->userid]->name);


		for(p = l.begin();p != l.end();p++)
		{
			if(strcmp(name,(*p)->doctor)==0&&(strcmp("等待就诊",(*p)->state)==0||strcmp("已就诊",(*p)->state)==0))
			{
				char c1[10];
				char c2[10];
				sprintf(c1,"%d",(*p)->id);
				sprintf(c2,"%d",(*p)->user);
				strlist.push_back(c1);
				strlist.push_back(c2);
				strlist.push_back((*p)->state);
			}
		}

		((CTable *)*it)->runContorl(strlist);
		this->showWin();
	}else if(n == 4)
	{
		return 12;
	}
	return -1;
}

int DoctorBookingWin::runWin()
{
	userid = global::uid;
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 0;
}