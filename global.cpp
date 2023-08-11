#include "global.h"
#pragma warning(disable : 4786)

int global::uid = 0;

list<CWin *> global::l;

void global::setl(list<CWin *> &l2)
{
	l = l2;
}

void global::setusername()
{
	map<int,CUser *> user;
	list<Contorl *>::iterator p;
	CTool::getPATIENT(user);
	char phone[30];
	std::list<CWin *>::iterator it = global::l.begin();
	advance(it,3);
	for(;it!=l.end();it++)
	{
		char name[20];
		char time[20];
		sprintf(name,"欢迎%s用户",user[uid]->name);
		p = (*it)->arr.begin();
		advance(p,1);
		strcpy((*p)->content,name);
		time_t time_now = ::time(0);
		tm *ltm = localtime(&time_now);
		sprintf(time,"日期：%d - %d - %d",1900 + ltm->tm_year,1 + ltm->tm_mon,ltm->tm_mday);
		p++;
		strcpy((*p)->content,time);
	}
	it = global::l.begin();
	advance(it,5);
	p = (*it)->arr.begin();
	advance(p,3);
	sprintf(phone,"手机号码：%s",user[uid]->phone);
	strcpy((*p)->content,phone);
	it++;
	p = (*it)->arr.begin();
	advance(p,3);
	strcpy((*p)->content,phone);
}

void global::setdoctorname()
{
	map<int,CUser *> user;
	list<Contorl *>::iterator p;
	char name[20];
	char time[20];
	CTool::getDoctor(user);
	std::list<CWin *>::iterator it = global::l.begin();
	advance(it,3);
	for(;it!=l.end();it++)
	{
		sprintf(name,"欢迎%s医生",user[uid]->name);
		p = (*it)->arr.begin();
		advance(p,1);
		strcpy((*p)->content,name);
		time_t time_now = ::time(0);
		tm *ltm = localtime(&time_now);
		sprintf(time,"日期：%d - %d - %d",1900 + ltm->tm_year,1 + ltm->tm_mon,ltm->tm_mday);
		p++;
		strcpy((*p)->content,time);
	}
	sprintf(name,"账号 ：D%d",user[global::uid]->username);
	it = l.begin();
	advance(it,15);
	p = (*it)->arr.begin();
	advance(p,3);
	strcpy((*p)->content,name);
}

void global::setadminname()
{
	map<int,CUser *> user;
	CTool::getAdmin(user);
	char name[20];
	char time[20];
	list<Contorl *>::iterator p;
	std::list<CWin *>::iterator it = global::l.begin();
	advance(it,3);
	for(;it!=l.end();it++)
	{
		sprintf(name,"欢迎%s管理员",user[uid]->name);
		p = (*it)->arr.begin();
		advance(p,1);
		strcpy((*p)->content,name);
		time_t time_now = ::time(0);
		tm *ltm = localtime(&time_now);
		sprintf(time,"日期：%d - %d - %d",1900 + ltm->tm_year,1 + ltm->tm_mon,ltm->tm_mday);
		p++;
		strcpy((*p)->content,time);
	}
	it = l.begin();
	advance(it,19);
	p = (*it)->arr.begin();
	advance(p,1);
	strcpy((*p)->content,"重新输入");
	advance(p,1);
	strcpy((*p)->content,"新增医生");
}