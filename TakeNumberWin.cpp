#include "TakeNumberWin.h"
#pragma warning(disable : 4786)

TakeNumberWin::TakeNumberWin(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	this->id = global::uid;
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx�û�");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CEdit(8,15,6,3,"����ԤԼ����",0,20,0);
	Contorl *c5 = new CEdit(33,15,6,3,"��  ",0,20,0);
	Contorl *c6 = new CBun(50,15,5,3,"��ѯ");
	Contorl *c7 = new CTable(8,19,35,10,"takenumber",4,7);
	Contorl *c8 = new CBun(15,30,5,3,"����");
	Contorl *c9 = new CLable(40,31,8,3,"������ҳ");


	((CTable *)c7)->addstring("ԤԼ���");
	((CTable *)c7)->addstring("ԤԼʱ��");
	((CTable *)c7)->addstring("����ʱ��");
	((CTable *)c7)->addstring("ԤԼҽԺ");
	((CTable *)c7)->addstring("ԤԼ����");
	((CTable *)c7)->addstring("ԤԼҽ��");
	((CTable *)c7)->addstring("����״̬");


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

int TakeNumberWin::doaction(int n)
{

	list<Contorl *>::iterator p;
	list<string> stringlist;
	std::list<booking *>::iterator it;
	list<booking *> l;
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
		CTool::getTakeNumber(l);
		char temp[20];
		advance(p,3);
		strcpy(temp,(*p)->input);
		p++;
		if(strcmp(temp,(*p)->input)>=0)
		{
			PopUp tempwin(15,15,20,15,"ʱ�䲻��ȷ");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}

		//��ѯʱ����ڵ���Ϣ
		else
	{
			for(it = l.begin();it != l.end();it++)
			{

				if((*it)->user == global::uid&&strcmp((*it)->date,(*p)->input)<=0&&strcmp(temp,(*it)->date)<=0&&(strcmp((*it)->state,"δ����")==0||strcmp((*it)->state,"�ȴ�����")==0 ))
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
			if(stringlist.size() > 0)
			((CTable *)*p)->runContorl(stringlist);
			else
			{
				PopUp tempwin(15,15,20,15,"��ѯ���Ϊ������������");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -1;
			}
			this->showWin();
		}
	}else if(n == 7)
	{
		system("cls");
		return 3;
	}
	return -1;
}

int TakeNumberWin::runWin()
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