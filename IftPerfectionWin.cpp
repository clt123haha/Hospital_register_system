#include "IftPerfectionWin.h"
#pragma warning(disable : 4786)

IftPerfectionWin::IftPerfectionWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx����");
	Contorl *c3 = new CLable(30,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CLable(10,15,8,3,"�ֻ����룺xxxxx");
	Contorl *c5 = new CEdit(10,20,20,3,"����    ",0,10,0);
	Contorl *c6 = new CEdit(10,25,20,3,"���֤��",1,20,0);
	Contorl *c7 = new CBun(15,30,5,3,"ȷ��");
	Contorl *c8 = new CBun(40,30,5,3,"ȡ��");


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
}

int IftPerfectionWin::doaction(int n)
{
	CTool::getPATIENT(user);
	user[1001] = new CUser(1001,"user","123456",1);
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
	}
	
	else if(n == 6)
	{
		CUser *temp = user[global::uid];
		advance(p,4);


		if(strcmp((*p)->input,"") != 0)
			strcpy(temp->name,(*p)->input);
		else
		{
			PopUp tempwin(15,15,20,15,"���벻��Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		p++;
		if(strcmp((*p)->input,"") != 0)
			strcpy(temp->idcard,(*p)->input);
		else
		{
			PopUp tempwin(15,15,20,15,"���벻��Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		if(strlen(temp->idcard) != 18)
		{
			PopUp tempwin(15,15,20,15,"��������ȷ��ʽ�����֤��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


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
		PopUp tempwin(15,15,20,15,"�޸ĳɹ�");
		tempwin.showWin();
		tempwin.runWin;
		global::setusername();
		return 3;
	}


	else if(n == 7)
	{
		return 4;

	}
	return -1;
}

int IftPerfectionWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 2;
}