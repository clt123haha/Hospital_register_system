#include "EnrollWin.h"
#pragma warning(disable : 4786)

EnrollWin::EnrollWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(30,5,5,5,"注册界面");
	Contorl *c2 = new CEdit(10,10,20,3,"手机号",0,20,1);
	Contorl *c3 = new CEdit(10,15,20,3,"验证码",0,10,1);
	Contorl *c4 = new CBun(40,20,5,3,"获取验证码");
	Contorl *c5 = new CBun(15,30,5,3,"确认");
	Contorl *c6 = new CBun(40,30,5,3,"取消");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int EnrollWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 1)
	{
		advance(p,1);
		(*p)->runContorl();
	}else if(n == 2)
	{
		advance(p,2);
		(*p)->runContorl();
	}else if(n==3)
	{
		advance(p,3);
		CTool::gotoxy(15,(*p)->y);
		CTool::getCaptcha((*p)->input);
	}else if(n==4)
	{
		int username=0;
		char temp[6];
		char phone[20];
		map<int,CUser *>::iterator it;
		CTool::getPATIENT(user);
		it = user.end();
		it--;


		username = (it->second)->username +1;
		CUser *u = new CUser(username,"user","123456",1);


		advance(p,1);
		strcpy(phone,(*p)->input);
		if(strlen(phone) != 11)
		{
			PopUp tempwin(15,15,20,15,"请输入正确手机号");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		if(strcmp((*p)->input,"")==0)
		{
			PopUp tempwin(15,15,20,15,"手机号不可为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		CTool::getPATIENT(this->user);
		for(it = user.begin(); it != user.end(); it++)
		{
			CUser *tempuser = it->second;
			if(strcmp(tempuser->phone,phone)==0)
				break;
		}
		if(it != user.end())
		{
			PopUp tempwin(15,15,20,15,"该手机号码已经存在");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		p++;
		if(strcmp((*p)->input,"")==0)
		{
			PopUp tempwin(15,15,20,15,"验证码不可为空");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(temp,(*p)->input);
		if(strcmp((*p)->input,"")==0)
		{
			PopUp tempwin(15,15,20,15,"请获取验证码");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		p++;
		if(strcmp((*p)->input,temp) != 0)
		{
			PopUp tempwin(15,15,20,15,"验证码错误");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}

		user[username] = u;
		FILE * fp;
		fp = fopen ("./data/PATIENT.txt", "a");
		if(fp == NULL)
		{
			PopUp tempwin(15,15,20,15,"文件打开时发生错误");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return 0;
		}


		fprintf(fp,"%d %s %s %d %s %s\n",username,"user","123456",1,phone,"none");
		fclose(fp);
		PopUp tempwin(15,15,20,15,"注册成功");
		tempwin.showWin();
		tempwin.runWin();
		return 2;
	}else if(n == 5)
	{
		return 0;
	}
	
	return -1;
}

int EnrollWin::runWin()
{
	int temp;
	list<Contorl *>::iterator p;
	while(true)
	{
		p = arr.begin();
		advance(p,3);
		CTool::gotoxy(15,(*p)->y);
		printf("验证码为%s",(*p)->input);
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}	
	return 0;

}

