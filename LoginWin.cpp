#include "LoginWin.h"
#pragma warning(disable : 4786)

LoginWin::LoginWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(30,5,5,5,"登录界面");
	Contorl *c2 = new CEdit(10,10,20,3,"账号",0,20,3);
	Contorl *c3 = new CEdit(10,15,20,3,"密码",1,10,3);
	Contorl *c4 = new CCombobox(10,20,5,5,"角色");
	Contorl *c5 = new CBun(15,30,5,3,"登录");
	Contorl *c6 = new CBun(40,30,5,3,"返回");
	CBun bun1(10,22,5,3,"用户");
	CBun bun2(10,24,5,3,"医生");
	CBun bun3(10,26,5,3,"管理员");

	((CCombobox *)c4)->addBun(bun1);
	((CCombobox *)c4)->addBun(bun2);
	((CCombobox *)c4)->addBun(bun3);


	this->addContorl(c1);
	this->addContorl(c2);
	this->addContorl(c3);
	this->addContorl(c4);
	this->addContorl(c5);
	this->addContorl(c6);
}

int LoginWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	map<int,CUser *>::iterator it;
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
		(*p)->runContorl();
		system("cls");
		this->showWin();
	}else if(n==4)
	{
		advance(p,3);
		if(strcmp((*p)->content,"角色") == 0)
		{
			PopUp tempwin(15,15,20,15,"请选择登录身份");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -2;
		}


		else if(strcmp((*p)->content,"用户") == 0) 
		{
			int username = 0;
			CTool::getPATIENT(this->user);


			p = arr.begin();
			p++;
			if(strlen((*p)->input) == 0)
			{
				PopUp tempwin(15,15,20,15,"账号不可为空");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}

			//判断账号是否正确
			for(it=user.begin();it != user.end();it++)
			{
				CUser *t = it->second;
				if(strcmp(t->phone,(*p)->input) == 0)
				{
					username = t->username;
					break;
				}
			}


			if(username == 0)
			{
				PopUp tempwin(15,15,20,15,"没有这个账号，请注册");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return 1;
			}


			p++;
			if(strlen((*p)->input) == 0)
			{
				PopUp tempwin(15,15,20,15,"密码不可为空");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			//判断密码是否正确
			if(strcmp(user[username]->password,(*p)->input) != 0)
			{
				PopUp tempwin(15,15,20,15,"密码错误");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return 1;
			}

			global::uid = username;
			global::setusername();
			return 3;
		}
		else if(strcmp((*p)->content,"医生") == 0)
		{
			char cusername[10];
			int username;
			CTool::getDoctor(user);


			p = arr.begin();
			p++;
			if(strlen((*p)->input) == 0)
			{
				PopUp tempwin(15,15,20,15,"账号不可为空");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			if((*p)->input[0] != 'D')
			{
				PopUp tempwin(15,15,20,15,"请输入正确格式的账号");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			strncpy(cusername,(*p)->input+1,strlen((*p)->input));
			username = CTool::turn(cusername);
			if(user.find(username) == user.end())
			{
				PopUp tempwin(15,15,20,15,"没有这个账号");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}


			p++;
			if(strlen((*p)->input) == 0)
			{
				PopUp tempwin(15,15,20,15,"密码不可为空");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			if(strcmp(user[username]->password,(*p)->input) != 0)
			{
				PopUp tempwin(15,15,20,15,"密码错误");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			global::uid = username;
			global::setdoctorname();
			return 12;
		}
		else if(strcmp((*p)->content,"管理员") == 0)
		{
			
			int username;
			CTool::getAdmin(user);


			p = arr.begin();
			p++;
			username =CTool::turn((*p)->input);
			if(strlen((*p)->input) == 0)
			{
				PopUp tempwin(15,15,20,15,"账号不可为空");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			if(user.find(username) == user.end())
			{
				PopUp tempwin(15,15,20,15,"没有这个账号");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}


			p++;
			if(strlen((*p)->input) == 0)
			{
				PopUp tempwin(15,15,20,15,"密码不可为空");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}
			if(strcmp(user[username]->password,(*p)->input) != 0)
			{
				PopUp tempwin(15,15,20,15,"密码错误");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -2;
			}


			global::uid = username;
			global::setadminname();
			return 8;


		}
		return 0;
	
	}else if(n==5)
	{
		return 0;
	}
	return -2;
}

int LoginWin::runWin()
{
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -2)
			return temp;
	}
	return 0;
}
