#include "SearchDepartmentWin.h"
#pragma warning(disable : 4786)

SearchDepartmentWin::SearchDepartmentWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx管理员");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CEdit(10,15,10,3,"请输入科室ID：",0,20,0);
	Contorl *c5 = new CBun(44,15,4,3,"查询");
	Contorl *c6 = new CTable(13,19,21,10,"de",4,3);
	Contorl *c7 = new CBun(15,30,5,3,"返回");
	Contorl *c8 = new CLable(40,31,8,3,"←→翻页");
	Contorl *c9 = new CBun(53,15,5,3,"新增科室");


	((CTable *)c6)->addstring("科室ID");
	((CTable *)c6)->addstring("科室名称");
	((CTable *)c6)->addstring("科室说明");


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

int SearchDepartmentWin::doaction(int n)
{
	map<int,Department *> user;
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 3)
	{
		advance(p,3);
		(*p)->runContorl();
	}else if(n == 4)
	{
		advance(p,3);
		list<string> stringlist;
		char ch[20];
		map<int,Department *>::iterator it;

		if(strlen((*p)->input) == 0)
		{
			
			PopUp tempwin(15,15,20,15,"输入不可为空");
			tempwin.showWin();
			tempwin.runWin();
			return -1;
		}


		CTool::getDepartment(user);
		int use = CTool::turn((*p)->input);

		//查询功能
		if(user.find(use) == user.end())
		{
			for (it = user.begin(); it != user.end(); it++) {
				sprintf(ch,"%d",it->first);
				if(strstr(ch,(*p)->input) != NULL)
				{
					Department *temp = it->second;
					sprintf(ch,"%d",it->first);
					string s(ch);
					stringlist.push_back(s);
					stringlist.push_back(temp->name);
					stringlist.push_back(temp->message);
				}
			}
		}
		else
		{
			Department *temp = user[use];
			sprintf(ch,"%d",use);
			string s(ch);
			stringlist.push_back(s);
			stringlist.push_back(temp->name);
			stringlist.push_back(temp->message);
		}

		//为空提示
		if(stringlist.size() == 0)
		{
			
			PopUp tempwin(15,15,20,15,"不存在该科室请重新输入");
			tempwin.showWin();
			tempwin.runWin();
			return -1;
		}


		advance(p,2);
		Contorl *table = *p;
		((CTable *)table)->runContorl(stringlist);
		this->showWin();
	}else if(n == 6)
		return 8;
	else if(n == 8)
		return 20;
	return -1;
}

int SearchDepartmentWin::runWin()
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