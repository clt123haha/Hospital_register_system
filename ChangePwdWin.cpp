#include "ChangePwdWin.h"

ChangePwdWin::ChangePwdWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx患者");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CLable(10,13,8,3,"手机号码：xxxxx");
	Contorl *c5 = new CEdit(10,17,20,3,"原密码  ",1,20,0);
	Contorl *c6 = new CEdit(10,21,20,3,"新密码  ",1,20,0);
	Contorl *c7 = new CEdit(10,25,20,3,"确认密码",1,20,0);
	Contorl *c8 = new CBun(15,30,5,3,"确认");
	Contorl *c9 = new CBun(40,30,5,3,"取消");


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

int ChangePwdWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 4)
	{
		advance(p,4);
		(*p)->runContorl();
	}else if(n == 5)
	{
		advance(p,5);
		(*p)->runContorl();
	}else if(n == 6)
	{
		advance(p,6);
		(*p)->runContorl();
	}else if(n == 7)
	{
		char ch[20];
		CTool::getPATIENT(user);
		CUser *temp = user[global::uid];


		advance(p,4);
		if(strcmp((*p)->input,temp->password) != 0)
		{
			PopUp tempwin(15,15,20,15,"密码错误");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		p++;
		strcpy(ch,(*p)->input);


		p++;
		if(strcmp((*p)->input,ch) != 0)
		{
			PopUp tempwin(15,15,20,15,"密码不一致");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(temp->password,ch);


		user[global::uid] = temp;
		map<int, CUser *>::iterator it;
		FILE* fp = fopen("./data/PATIENT.txt", "w+");
		if(fp == NULL)
		{
			printf("sorry\n");
			return -1;
		}
		for (it = user.begin(); it != user.end(); it++) {
			temp = it->second;
			fprintf(fp,"%d %s %s %d %s %s\n",temp->username,temp->name,temp->password,temp->type,temp->phone,temp->idcard);	
		}
		fclose(fp);


		PopUp tempwin(15,15,20,15,"修改成功");
		tempwin.showWin();
		tempwin.runWin();
		this->showWin();


		return 4;
	}else if(n == 8)
	{
		return 4;
	}
	return -1;
}

int ChangePwdWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 4;
}