#include "SeekingWin.h"
#pragma warning(disable : 4786)

SeekingWin::SeekingWin(int x,int y,int width,int height,int id) : CWin(x,y,width,height)
{
	bid = id;
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx管理员");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CLable(10,15,20,3,"预约描述：");
	Contorl *c5 = new CEdit(10,20,20,6,"就诊表述：",0,255,0);
	Contorl *c6 = new CBun(15,30,5,3,"确定");
	Contorl *c7 = new CBun(40,30,5,3,"返回");


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
			PopUp tempwin(15,15,20,15,"描述不可为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
		}

		//信息修改
		CTool::getTakeNumber(l);
		for(it = l.begin();it != l.end();it++)
		{
			if((*it)->id == bid)
			{
				strcpy((*it)->message_a,(*p)->input);
				strcpy((*it)->state,"已就诊");
				break;
			}
		}
		CTool::setTakeNumber(l);

		PopUp tempwin(15,15,20,15,"成功");
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