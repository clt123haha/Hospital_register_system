#include "BookingWin.h"
#pragma warning(disable : 4786)

BookingWin::BookingWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	map<int,Department *> l;
	map<int,Department *>::iterator p;
	char time1[20],time2[20],time3[20];
	int n = 0;
	Date today;

	//得到今天明天后天的日期
	time_t time_now = ::time(0);
	tm *ltm = localtime(&time_now);
	today.year = 1900 + ltm->tm_year;
	today.month = 1 + ltm->tm_mon;
	today.day = ltm->tm_mday;
	sprintf(time1,"%04d%02d%02d",today.year,today.month,today.day);
	CTool::getTomorrow(today,time2);
	CTool::getTomorrow(today,time3);


	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx患者");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CLable(15,13,5,3,"选择医院");
	Contorl *c5 = new CCombobox(25,13,10,3,"省立医院");
	Contorl *c6 = new CLable(15,16,5,3,"选择科室");
	Contorl *c7 = new CCombobox(25,16,10,3,"");
	Contorl *c8 = new CLable(15,19,5,3,"选择医生");
	Contorl *c9 = new CCombobox(25,19,10,3,"");
	Contorl *c10 = new CLable(15,22,5,3,"选择时间");
	Contorl *c11 = new CCombobox(25,22,5,3,time1);
	Contorl *c12 = new CCombobox(40,22,5,3,"9:00 - 10:00");
	Contorl *c13 = new CEdit(15,25,20,5,"描述",0,255,0);
	Contorl *c14 = new CBun(15,30,5,3,"确认");
	Contorl *c15 = new CBun(40,30,5,3,"取消");

	
	//下拉框的按钮
	CBun bun1(25,15,10,3,"省立医院");
	CBun bun2(25,24,5,3,time1);
	CBun bun3(25,26,5,3,time2);
	CBun bun4(25,28,5,3,time3);
	CBun bun5(40,24,5,3,"9:00 -  10:00");
	CBun bun6(40,26,5,3,"10:00 - 11:00");
	CBun bun7(40,28,5,3,"11:00 - 12:00");

	//得到科室信息并添加到科室的下拉框
	CTool::getDepartment(l);
	for(p=l.begin();p!=l.end();p++)
	{
		Department *temp = p->second;
		((CCombobox *)c7)->addBun(CBun(25,18+2*n,10,3,temp->name));
		n++;
	}


	((CCombobox *)c5)->addBun(bun1);
	((CCombobox *)c11)->addBun(bun2);
	((CCombobox *)c11)->addBun(bun3);
	((CCombobox *)c11)->addBun(bun4);
	((CCombobox *)c12)->addBun(bun5);
	((CCombobox *)c12)->addBun(bun6);
	((CCombobox *)c12)->addBun(bun7);


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
	this->addContorl(c9);
	this->addContorl(c10);
	this->addContorl(c11);
	this->addContorl(c12);
	this->addContorl(c13);
	this->addContorl(c14);
	this->addContorl(c15);
}

int BookingWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 4)
	{
		advance(p,4);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 6)
	{
		advance(p,6);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 8)
	{
		advance(p,6);
		char department[20];
		//获取科室信息
		strcpy(department,(*p)->content);
		advance(p,2);
		Contorl *con = *p;
		CTool::getDoctor(user);
		map<int, CUser *>::iterator it;
		int n = 0;

		//根据科室获取医生信息
		for (it = user.begin(); it != user.end(); it++) 
		{
			CUser *temp = it->second;
			if(strcmp(department,temp->department) == 0)
			{
				CBun t(25,21+2*n,10,3,temp->name);
				char ch_temp[20];  
				sprintf(ch_temp, "%d", temp->username);
				strcpy(t.input,ch_temp);
				((CCombobox *)con)->addBun(t);
				n++;
			}
		}
		if(n > 0)
		{
			(*p)->runContorl();
			this->showWin();
		}

	}else if(n == 10)
	{
		advance(p,10);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 11)
	{
		advance(p,11);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 12)
	{
		advance(p,12);
		(*p)->runContorl();
	}else if(n==13)
	{
		p = arr.begin();
		int n;
		char doctor[20];
		char date[20];
		char de[20];
		char ho[20];
		char message[255];
		int time;
		list<booking *> l;
		CTool::getTakeNumber(l);

		//获取信息
		list<booking *>::iterator it;
		advance(p,4);
		strcpy(ho,(*p)->content);
		advance(p,2);
		strcpy(de,(*p)->content);
		advance(p,2);
		strcpy(doctor,(*p)->content);
		advance(p,2);
		strcpy(date,(*p)->content);
		p++;
		if(strcmp((*p)->content,"9:00 - 10:00")==0 )
			time = 9;
		else if(strcmp((*p)->content,"10:00 - 11:00")==0 )
			time = 10;
		else if(strcmp((*p)->content,"11:00 - 12:00")==0 )
			time = 11;
		p++;
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"不可为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(message,(*p)->input);
		for(it = l.begin();it != l.end(); it++)
		{
			if(time == (*it)->time && strcmp(doctor,(*it)->doctor)==0 && strcmp(date,(*it)->date)==0 && strcmp(de,(*it)->department)==0)
				n++;
		}

		//若该时间的条件符合就可以预约
		if(n <= 2)
		{
			booking *temp = new booking();
			it = l.end();
			it--;
			temp->id = (*it)->id +1;
			temp->user = global::uid;
			strcpy(temp->date,date);
			temp->time = time;
			strcpy(temp->doctor,doctor);
			strcpy(temp->hospital,ho);
			strcpy(temp->department,de);
			strcpy(temp->state,"未就诊");
			strcpy(temp->message_b,message);
			strcpy(temp->message_a,"none");
			l.push_back(temp);
			CTool::setTakeNumber(l);
		}
		else
		{
			PopUp tempwin(15,15,20,15,"预约名额不足");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}

		return 3;
	}else if(n==14)
	{
		return 3;
	}
	return -1;
}

int BookingWin::runWin()
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

