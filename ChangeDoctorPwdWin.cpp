#include "ChangeDoctorPwdWin.h"

ChangeDoctorPwdWin::ChangeDoctorPwdWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,10,20,5,"��ӭxx����");
	Contorl *c3 = new CLable(10,10,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CLable(10,13,8,3,"�ֻ����룺xxxxx");
	Contorl *c5 = new CEdit(10,17,20,3,"ԭ����  ",1,20,0);
	Contorl *c6 = new CEdit(10,21,20,3,"������  ",1,20,0);
	Contorl *c7 = new CEdit(10,25,20,3,"ȷ������",1,20,0);
	Contorl *c8 = new CBun(15,30,5,3,"ȷ��");
	Contorl *c9 = new CBun(40,30,5,3,"ȡ��");


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

int ChangeDoctorPwdWin::doaction(int n)
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
		CTool::getDoctor(user);
		CUser *temp = user[global::uid];


		advance(p,4);
		if(strlen((*p)->input)==0)
		{
			PopUp tempwin(15,15,20,15,"ԭ���벻��Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
		}
		if(strcmp((*p)->input,temp->password) != 0)
		{
			PopUp tempwin(15,15,20,15,"�������");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}


		p++;
		strcpy(ch,(*p)->input);
		if(strlen((*p)->input)==0)
		{
			PopUp tempwin(15,15,20,15,"�����벻��Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
		}


		p++;
		if(strlen((*p)->input)==0)
		{
			PopUp tempwin(15,15,20,15,"�ظ����벻��Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
		}


		if(strcmp((*p)->input,ch) != 0)
		{
			PopUp tempwin(15,15,20,15,"���벻һ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}

		strcpy(temp->password,ch);
		user[global::uid] = temp;
		map<int, CUser *>::iterator it;
		CTool::write(user);

		PopUp tempwin(15,15,20,15,"�޸ĳɹ�");
		tempwin.showWin();
		tempwin.runWin();

		return 12;
	}else if(n == 8)
	{
		return 12;
	}
	return -1;
}

int ChangeDoctorPwdWin::runWin()
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