#include "SeekingWin.h"
#pragma warning(disable : 4786)

SeekingWin::SeekingWin(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	bid = id;
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx����Ա");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CLable(10,15,20,3,"ԤԼ������");
	Contorl *c5 = new CEdit(10,20,20,6,"���������",0,255,0);
	Contorl *c6 = new CBun(15,30,5,3,"ȷ��");
	Contorl *c7 = new CBun(40,30,5,3,"����");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
}

int SeekingWin::doaction(int n)
{
	CTool::getPATIENT(user);
	list<booking *> l;
	list<booking *>::iterator it;
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 4)
	{
		advance(p,4);
		(*p)->runContorl();
	}else if(n == 5)
	{
		advance(p,4);
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"��������Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
		}

		//��Ϣ�޸�
		CTool::getTakeNumber(l);
		for(it = l.begin();it != l.end();it++)
		{
			if((*it)->id == bid)
			{
				strcpy((*it)->message_a,(*p)->input);
				strcpy((*it)->state,"�Ѿ���");
				break;
			}
		}
		CTool::setTakeNumber(l);

		PopUp tempwin(15,15,20,15,"�ɹ�");
		tempwin.showWin();
		tempwin.runWin();
		this->showWin();
		return 0;
		
	}else if(n == 6)
	{
		return 3;
	}
	return -1;
}

int SeekingWin::runWin()
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