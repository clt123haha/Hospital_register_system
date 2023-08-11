#include "VaccineAppointmentWin.h"


VaccineAppointmentWin::VaccineAppointmentWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
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
	Contorl *c6 = new CLable(15,16,5,3,"选择试剂");
	Contorl *c7 = new CCombobox(25,16,10,3,"第一试剂");
	Contorl *c8 = new CLable(15,19,5,3,"选择厂家");
	Contorl *c9 = new CCombobox(25,19,10,3,"北京生物");
	Contorl *c10 = new CLable(15,22,5,3,"选择时间");
	Contorl *c11 = new CCombobox(25,22,5,3,time1);
	Contorl *c12 = new CCombobox(40,22,5,3,"9:00-10:00");
	Contorl *c13 = new CBun(15,30,5,3,"确认");
	Contorl *c14 = new CBun(40,30,5,3,"取消");

	
	//下拉框的按钮
	CBun bun1(25,15,10,3,"省立医院");
	CBun bun2(25,24,5,3,time1);
	CBun bun3(25,26,5,3,time2);
	CBun bun4(25,28,5,3,time3);
	CBun bun5(40,24,5,3,"9:00-10:00");
	CBun bun6(40,26,5,3,"10:00-11:00");
	CBun bun7(40,28,5,3,"11:00-12:00");
	CBun bun8(25,18,10,3,"第一试剂");
	CBun bun9(25,20,10,3,"第二试剂");
	CBun bun10(25,21,10,3,"北京生物");
	CBun bun11(25,23,10,3,"北京科兴");



	((CCombobox *)c5)->addBun(bun1);
	((CCombobox *)c11)->addBun(bun2);
	((CCombobox *)c11)->addBun(bun3);
	((CCombobox *)c11)->addBun(bun4);
	((CCombobox *)c12)->addBun(bun5);
	((CCombobox *)c12)->addBun(bun6);
	((CCombobox *)c12)->addBun(bun7);
	((CCombobox *)c7)->addBun(bun8);
	((CCombobox *)c7)->addBun(bun9);
	((CCombobox *)c9)->addBun(bun10);
	((CCombobox *)c9)->addBun(bun11);


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
}

int VaccineAppointmentWin::doaction(int n)
{
	list<Vaccine *> l;
	list<Vaccine *> ::iterator it;
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
	}else if(n == 8){
		advance(p,8);
		(*p)->runContorl();
		this->showWin();
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
	}else if(n==12)
	{
		p = arr.begin();
		int n;
		char doctor[20];
		char date[20];
		char de[20];
		char ho[20];
		char time[20];
		char message[255];

		FILE* fp = fopen("./data/Vaccine.txt", "r+");
		if(fp == NULL)
		{
			PopUp tempwin(15,15,20,15,"文件无法打开");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		Vaccine *temp  = new Vaccine();
		while (fscanf(fp, "%d%s%s%s%s%s%s", &(temp->uid),temp->hospital,temp->batch,temp->factory,temp->date,temp->time,temp->status) != -1){
			l.push_back(temp);
		}
		fclose(fp);

		//获取信息
		advance(p,4);
		strcpy(ho,(*p)->content);
		advance(p,2);
		strcpy(de,(*p)->content);
		advance(p,2);
		strcpy(doctor,(*p)->content);
		advance(p,2);
		strcpy(date,(*p)->content);
		p++;
		strcpy(time,(*p)->content);
		p++;

		for(it = l.begin();it != l.end(); it++)
		{
			if(strcmp(time,(*it)->time)==0&& strcmp(doctor,(*it)->factory)==0 && strcmp(date,(*it)->date)==0 && strcmp(de,(*it)->batch)==0 &&(*it)->uid == global::uid)
				n++;
		}

		//若该时间的条件符合就可以预约
		if(n < 30)
		{
			Vaccine *temp = new Vaccine();
			strcpy(temp->date,date);
			strcpy(temp->time,time);
			strcpy(temp->factory,doctor);
			strcpy(temp->hospital,ho);
			strcpy(temp->batch,de);
			temp->uid = global::uid;
			l.push_back(temp);
			FILE* fp = fopen("./data/Vaccine.txt", "a");
			if(fp == NULL)
			{
				PopUp tempwin(15,15,20,15,"文件无法打开");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -1;
			}
			fprintf(fp,"%d %s %s %s %s %s %s\n",temp->uid,temp->hospital,temp->batch,temp->factory,temp->date,temp->time,"已预约接种");
			fclose(fp);
		}
		else
		{
			PopUp tempwin(15,15,20,15,"预约名额不足");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}

		PopUp tempwin(15,15,20,15,"成功");
		tempwin.showWin();
		tempwin.runWin();
		return 23;
	}else if(n==13)
	{
		return 17;
	}
	return -1;
}

int VaccineAppointmentWin::runWin()
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