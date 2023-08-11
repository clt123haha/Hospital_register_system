#include "UserBookingWin.h"
#pragma warning(disable : 4786)

UserBookingWin::UserBookingWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx用户");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CEdit(8,15,6,3,"输入预约日期",0,20,0);
	Contorl *c5 = new CEdit(33,15,6,3,"至  ",0,20,0);
	Contorl *c6 = new CBun(50,15,5,3,"查询");
	Contorl *c7 = new CTable(8,19,35,10,"userbooking",4,7);
	Contorl *c8 = new CBun(15,30,5,3,"返回");
	Contorl *c9 = new CLable(40,31,8,3,"←→翻页");


	((CTable *)c7)->addstring("预约编号");
	((CTable *)c7)->addstring("预约时间");
	((CTable *)c7)->addstring("就诊时间");
	((CTable *)c7)->addstring("预约医院");
	((CTable *)c7)->addstring("预约科室");
	((CTable *)c7)->addstring("预约医生");
	((CTable *)c7)->addstring("就诊状态");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
	this->addContorl(c9);
}

int UserBookingWin::doaction(int n)
{

	list<Contorl *>::iterator p;
	list<string> stringlist;
	std::list<booking *>::iterator it;
	list<booking *> l;
	CTool::getTakeNumber(l);
	p = arr.begin();
	if(n == 3)
	{
		advance(p,3);
		(*p)->runContorl();
	}else if(n == 4)
	{
		advance(p,4);
		(*p)->runContorl();
	}else if(n == 5)
	{
		char temp[20];
		advance(p,3);
		strcpy(temp,(*p)->input);
		p++;
		if(strcmp(temp,(*p)->input)>=0)
		{
			printf("时间不正确");
			getch();
		}

		//查询信息
		else
	{
			for(it = l.begin();it != l.end();it++)
			{
				if((*it)->user == global::uid&&strcmp((*it)->date,(*p)->input)<=0&&strcmp(temp,(*it)->date)<=0&&(strcmp((*it)->state,"等待就诊")==0 ||strcmp((*it)->state,"已就诊")==0 ))
				{
					char c1[10];
					sprintf(c1,"K%d",(*it)->id);	
					string s1(c1);
					stringlist.push_back(s1);
					stringlist.push_back((*it)->date);
					if((*it)->time == 8)
						stringlist.push_back("8 - 9");
					else if((*it)->time == 9)
						stringlist.push_back("9 - 10");
					else if((*it)->time == 10)
						stringlist.push_back("10 - 11");
					else if((*it)->time == 11)
						stringlist.push_back("11 - 12");
					stringlist.push_back((*it)->hospital);
					stringlist.push_back((*it)->department);
					stringlist.push_back((*it)->doctor);
					stringlist.push_back((*it)->state);
				}
			}


			advance(p,2);
			((CTable *)*p)->runContorl(stringlist);
			system("cls");
			this->showWin();
		}
	}else if(n == 7)
		return 3;
	return -1;
}

int UserBookingWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
		{
			system("cls");
			return temp;
		}
	}
	return 0;
}