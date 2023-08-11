#include "CreatDoctor.h"

CreatDoctor::CreatDoctor(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	map<int,Department *>::iterator p;
	map<int,CUser *>::iterator p2;
	map<int,Department *> l;

	//�õ�����ID
	CTool::getDepartment(l);
	CTool::getDoctor(user);
	p2 = user.end();
	p2--;
	CUser *temp = p2->second;
	char name[20];
	sprintf(name,"ҽ��id��   D%d",temp->username+1);
	int  n = 0;


	Contorl *c1 = new CLable(20,5,5,5,"��ӭ����ҽ��ԤԼϵͳ");
	Contorl *c2 = new CLable(10,8,20,5,"��ӭxx����Ա");
	Contorl *c3 = new CLable(30,8,20,5,"���ڣ�2023.7.13");
	Contorl *c4 = new CLable(15,11,20,5,name);
	Contorl *c5 = new CLable(15,13,5,3,"ѡ��ҽԺ");
	Contorl *c6 = new CCombobox(25,13,10,3,"ʡ��ҽԺ");
	Contorl *c7 = new CLable(15,16,5,3,"ѡ�����");
	Contorl *c8 = new CCombobox(25,16,10,3,"���");
	Contorl *c9 = new CEdit(15,19,10,3,"ҽ������  ",0,20,0);
	Contorl *c10 = new CLable(15,22,5,3,"ҽ��ְλ");
	Contorl *c11 = new CCombobox(25,22,10,3,"");
	Contorl *c12 = new CEdit(15,25,10,5,"���      ",0,20,0);
	Contorl *c13 = new CBun(15,30,5,3,"ȷ��");
	Contorl *c14 = new CBun(40,30,5,3,"ȡ��");


	CBun bun1(25,15,10,3,"ʡ��ҽԺ");
	CBun bun2(25,18,10,3,"���");
	CBun bun3(25,20,10,3,"�ڿ�");
	CBun bun4(25,22,10,3,"����");
	CBun bun5(25,24,10,3,"ר��");
	CBun bun6(25,26,10,3,"����ҽʦ");
	CBun bun7(25,28,10,3,"������ҽʦ");
	CBun bun8(25,30,10,3,"����ҽʦ��");


	((CCombobox *)c6)->addBun(bun1);
	((CCombobox *)c8)->addBun(bun2);
	((CCombobox *)c8)->addBun(bun3);
	((CCombobox *)c8)->addBun(bun4);
	((CCombobox *)c11)->addBun(bun5);
	((CCombobox *)c11)->addBun(bun6);
	((CCombobox *)c11)->addBun(bun7);
	((CCombobox *)c11)->addBun(bun8);


	//��ȡ������Ϣ������������
	for(p=l.begin();p!=l.end();p++)
	{
		Department *temp = p->second;
		((CCombobox *)c8)->addBun(CBun(25,18+2*n,10,3,temp->name));
		n++;
	}


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
	this->addContorl(c7);
	this->addContorl(c8);
	this->addContorl(c9);
	this->addContorl(c10);
	this->addContorl(c11);
	this->addContorl(c12);
	this->addContorl(c13);
	this->addContorl(c14);
}

int CreatDoctor::doaction(int n)
{
	list<Contorl *>::iterator p;
	p = arr.begin();
	if(n == 4)
	{
		advance(p,4);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 6)
	{
		advance(p,6);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 7)
	{
		advance(p,7);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 9)
	{
		advance(p,9);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 8)
	{
		advance(p,8);
		(*p)->runContorl();
	}else if(n == 10)
	{
		advance(p,10);
		(*p)->runContorl();
		this->showWin();
	}else if(n == 11)
	{
		advance(p,11);
		(*p)->runContorl();
	}else if(n == 12)
	{
		CTool::getDoctor(user);
		map<int,CUser *>::iterator it;
		it = user.end();
		it--;
		int username = it->first + 1;
		CUser *newuser = new CUser;
		newuser->username = username;
		strcpy(newuser->password,"123456");
		p = arr.begin();


		advance(p,8);
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"��������Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(newuser->name,(*p)->input);


		p = arr.begin();
		advance(p,5);
		strcpy(newuser->hospital,(*p)->content);


		p++;
		p++;
		if(strlen((*p)->content) == 0)
		{
			PopUp tempwin(15,15,20,15,"���Ҳ���Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(newuser->department,(*p)->input);


		advance(p,3);	
		if(strlen((*p)->content) == 0)
		{
			PopUp tempwin(15,15,20,15,"ְλ����Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		strcpy(newuser->posts,(*p)->content);


		p = arr.begin();
		advance(p,11);
		strcpy(newuser->message,(*p)->input);
		if(strlen((*p)->input) == 0)
		{
			PopUp tempwin(15,15,20,15,"��鲻��Ϊ��");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}

		user[newuser->username] = newuser;
		CTool::write(user);
		//�����ļ�

		char idnow[20];
		sprintf(idnow,"����ID��K%d",newuser->username+1);
		p = arr.begin();
		advance(p,3);
		strcpy((*p)->content,idnow);


		return 10;
	}else if(n == 13)
	{
		return 10;
	}
	return -1;
}

int CreatDoctor::runWin()
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