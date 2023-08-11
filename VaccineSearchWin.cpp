#include "VaccineSearchWin.h"

#pragma warning(disable : 4786)

VaccineSearchWin::VaccineSearchWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx管理员");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CTable(10,15,36,10,"VaccineSearchWin",4,6);
	Contorl *c5 = new CBun(15,30,5,3,"返回");
	Contorl *c6 = new CLable(40,31,8,3,"←→翻页");


	((CTable *)c4)->addstring("接种/预约时间");
	((CTable *)c4)->addstring("接种批次");
	((CTable *)c4)->addstring("疫苗厂家");
	((CTable *)c4)->addstring("接种医院");
	((CTable *)c4)->addstring("状态");
	((CTable *)c4)->addstring("操作");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int VaccineSearchWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	list<Vaccine *> l;
	list<string> strlist;
	list<Vaccine *> ::iterator it;
	if(n == 3)
	{
		advance(p,3);
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
			if(temp->uid == global::uid)
			{
				l.push_back(temp);
			}
		}
		fclose(fp);
		

		for(it = l.begin();it != l.end();it++)
		{
				strlist.push_back((*it)->date);
				strlist.push_back((*it)->batch);
				strlist.push_back((*it)->factory);
				strlist.push_back((*it)->hospital);
				strlist.push_back((*it)->status);
				strlist.push_back("取消预约");
		}
		if(strlist.size() == 0)
		{
			PopUp tempwin(15,15,20,15,"查询结果为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;	
		}
		((CTable *)*p)->runContorl(strlist);
		this->showWin();
	}else if(n == 4)
	{
		return 17;
	}
	return -1;
}

int VaccineSearchWin::runWin()
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