#include "SearchDoctorWin.h"
#pragma warning(disable : 4786)

SearchDoctorWin::SearchDoctorWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx����Ա");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CEdit(10,15,10,3,"������ҽ��ID:   ",0,20,0);
	Contorl *c5 = new CBun(50,15,5,3,"��ѯ");
	Contorl *c6 = new CTable(5,19,30,10,"changeDOctor",4,6);
	Contorl *c7 = new CBun(15,30,5,3,"����");
	Contorl *c8 = new CLable(40,31,8,3,"������ҳ");


	((CTable *)c6)->addstring("ҽ��ID");
	((CTable *)c6)->addstring("ҽ������");
	((CTable *)c6)->addstring("ְλ");
	((CTable *)c6)->addstring("��������");
	((CTable *)c6)->addstring("����ҽԺ");
	((CTable *)c6)->addstring("���");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
}

int SearchDoctorWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 3)
	{
		advance(p,3);
		(*p)->runContorl();
	}else if(n == 4)
	{
		advance(p,3);
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"ҽ��ID����Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		list<string> stringlist;
		char ch[20];
		map<int,CUser *>::iterator it;
		CTool::getDoctor(user);
		int use = CTool::turn((*p)->input);


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
					stringlist.push_back(temp->name);
					stringlist.push_back(temp->posts);
					stringlist.push_back(temp->department);
					stringlist.push_back("ʡ��ҽԺ");
					stringlist.push_back(temp->message);
				}
			}
		}
		else
		{
			CUser *temp = user[use];
			sprintf(ch,"%d",use);
			string s(ch);
			stringlist.push_back(s);
			stringlist.push_back(temp->name);
			stringlist.push_back(temp->posts);
			stringlist.push_back(temp->department);
			stringlist.push_back("ʡ��ҽԺ");
			stringlist.push_back(temp->message);
		}


		if(stringlist.size() == 0)
		{
			PopUp tempwin(15,15,20,15,"���Ϊ������������");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		advance(p,2);
		Contorl *table = *p;
		((CTable *)table)->runContorl(stringlist);
		if(strcmp((*p)->input,"DE") == 0)
		{
			return 19;
		}
		system("cls");
		this->showWin();
	}else if(n == 6)
		return 8;
	return -1;
}

int SearchDoctorWin::runWin()
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