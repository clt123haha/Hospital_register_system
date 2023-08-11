#include "SearchUserWin.h"
#pragma warning(disable : 4786)

SearchUserWin::SearchUserWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx����Ա");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CEdit(10,15,10,3,"�������û��˺ţ�",0,20,0);
	Contorl *c5 = new CBun(50,15,5,3,"��ѯ");
	Contorl *c6 = new CTable(15,19,20,10,"Table",4,2);


	Contorl *c7 = new CBun(15,30,5,3,"����");
	Contorl *c8 = new CLable(40,31,8,3,"������ҳ");
	((CTable *)c6)->addstring("�˺�");
	((CTable *)c6)->addstring("�����Ϣ");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
}

int SearchUserWin::doaction(int n)
{
	CTool::getPATIENT(user);
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
		map<int,CUser *>::iterator it;
		CTool::getPATIENT(user);
		int use = CTool::turn((*p)->input);


		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"��ѯ�û��˺Ų���Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		if(user.find(use) == user.end())
		{
			for (it = user.begin(); it != user.end(); it++) {
				sprintf(ch,"%d",it->first);
				if(strstr(ch,(*p)->input) != NULL)
				{
					CUser *temp = it->second;
					sprintf(ch,"%d",it->first);
					string s(ch);
					stringlist.push_back(s);
					stringlist.push_back(temp->idcard);
				}
			}
		}
		else
		{
			CUser *temp = user[use];
			sprintf(ch,"%d",use);
			string s(ch);
			stringlist.push_back(s);
			stringlist.push_back(temp->idcard);
		}
		if(stringlist.size() == 0)
		{
			PopUp tempwin(15,15,20,15,"���Ϊ�գ����������������ѯ���û��˺�");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		advance(p,2);
		Contorl *table = *p;
		((CTable *)table)->runContorl(stringlist);
		this->showWin();
	}else if(n == 6)
		return 8;
	return -1;
}

int SearchUserWin::runWin()
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