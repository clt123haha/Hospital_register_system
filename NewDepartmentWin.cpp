#include "NewDepartmentWin.h"

NewDepartmentWin::NewDepartmentWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	map<int,Department *> l;
	map<int,Department *>::iterator p;
	char id[20];
	CTool::getDepartment(l);
	p = l.end();
	p--;
	Department *temp = p->second;
	sprintf(id,"科室ID：K%d",temp->username+1);
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx患者");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CLable(10,15,8,3,id);
	Contorl *c5 = new CEdit(10,20,20,3,"科室名称:  ",0,20,0);
	Contorl *c6 = new CEdit(10,25,20,5,"科室说明:  ",0,255,0);
	Contorl *c7 = new CBun(15,30,5,3,"确认");
	Contorl *c8 = new CBun(40,30,5,3,"取消");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
	
}

int NewDepartmentWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 4)
	{
		advance(p,4);
		(*p)->runContorl();
	}
	else if(n == 5)
	{
		advance(p,5);
		(*p)->runContorl();
	}else if(n == 6)
	{
		map<int,Department *> l;
		map<int,Department *>::iterator it;
		int id;
		CTool::getDepartment(l);
		it = l.end();
		it--;
		Department *temp = it->second;
		id = temp->username +1 ;
		temp = new Department();
		temp->username = id;

		advance(p,4);
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"输入不可为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(temp->name,(*p)->input);

		p++;
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"输入不可为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(temp->message,(*p)->input);


		l[id] = temp;
		FILE* fp = fopen("./data/Department.txt", "w");
		if(fp == NULL)
		{
			PopUp tempwin(15,15,20,15,"文件打开失败");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		for(it = l.begin();it != l.end(); it++)
		{
			temp = it->second;
			fprintf(fp,"%d   %s   %s\n",temp->username,temp->name,temp->message);
		}
		fclose(fp);

		PopUp tempwin(15,15,20,15,"新增成功");
		tempwin.showWin();
		tempwin.runWin();
		this->showWin();

		char idnow[20];
		sprintf(idnow,"新增ID：K%d",id+1);
		p = arr.begin();
		advance(p,3);
		strcpy((*p)->content,idnow);

		return 11;
	}else if(n == 7)
		return 11;
	return -1;
}

int NewDepartmentWin::runWin()
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