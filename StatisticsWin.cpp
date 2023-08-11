#include "StatisticsWin.h"
#pragma warning(disable : 4786)

StatisticsWin::StatisticsWin(int x,int y,int width,int height) : CWin(x,y,width,height)
{
	Contorl *c1 = new CLable(20,5,5,5,"欢迎来到医疗预约系统");
	Contorl *c2 = new CLable(10,10,20,5,"欢迎xx管理员");
	Contorl *c3 = new CLable(30,10,20,5,"日期：2023.7.13");
	Contorl *c4 = new CEdit(10,13,5,3,"请输入就诊月份",0,5,1);
	Contorl *c5 = new CBun(40,13,5,3,"查询");
	Contorl *c6 = new CTable(15,17,20,10,"",4,2);
	Contorl *c7 = new CBun(15,30,5,3,"导出数据");
	Contorl *c8 = new CBun(25,30,5,3,"返回");
	Contorl *c9 = new CLable(40,31,8,3,"←→翻页");


	((CTable *)c6)->addstring("就诊时间");
	((CTable *)c6)->addstring("就诊人数");


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

int StatisticsWin::doaction(int n)
{
	list<Contorl *>::iterator p;
	map<int,int>::iterator it2;
	map<int,int> l2;
	list<string> l3;
	char month[5]="0",all[10] = "0";
	p = arr.begin();
	if(n == 3)
	{
		advance(p,3);
		(*p)->runContorl();
	}else if(n == 4)
	{
		char ch[10] = "0",year[5]="0",day[5]="0";
		list<booking *> l;
		list<booking *>::iterator it;
		CTool::getTakeNumber(l);

		advance(p,3);
		strcpy(month,(*p)->input);

		time_t now = time(NULL);
		tm* tm_t = localtime(&now);
		sprintf(all,"%d%s",tm_t->tm_year + 1900,month);

		for(it = l.begin();it != l.end(); it++)
		{
			strncpy(ch,(*it)->date,6);
			strncpy(year,(*it)->date,4);
			strncpy(day,(*it)->date+6,2);
			if(strcmp(ch,all) == 0)
			{
				int temp = CTool::turn(ch)*100 + CTool::turn(day);
				if(l2.count(temp) == 0)
				{
					l2[temp] = 1;
				}
				else
					l2[temp] += 1;
			}
		}

		for(it2 = l2.begin();it2 != l2.end(); it2++)
		{
			char time[10],count[5];
			sprintf(time,"%d",it2->first);
			sprintf(count,"%d",it2->second);
			string str1(time),str2(count);
			l3.push_back(str1);
			l3.push_back(str2);
		}

		if(l3.size() == 0)
		{
			PopUp tempwin(15,15,20,15,"结果为空请重新输入");
			tempwin.showWin();
			tempwin.runWin();
			this->showWin();
			return -1;
		}
		p = arr.begin();
		advance(p,5);
		((CTable *)*p)->runContorl(l3);
		this->showWin();
		return -1;
	}else if(n == 6)
	{
		char filename[20];
		char ch[10] = "0",year[5]="0",day[5]="0";
		list<booking *> l;
		list<booking *>::iterator it;
		advance(p,3);
		strcpy(month,(*p)->input);
		time_t now = time(NULL);
		tm* tm_t = localtime(&now);
		sprintf(all,"%d%s",tm_t->tm_year + 1900,month);
		sprintf(filename,"./data/%s.txt",all);

		CTool::getTakeNumber(l);
		for(it = l.begin();it != l.end(); it++)
		{
			strncpy(ch,(*it)->date,6);
			strncpy(year,(*it)->date,4);
			strncpy(day,(*it)->date+6,2);
			if(strcmp(ch,all) == 0)
			{
				int temp = CTool::turn(ch)*100 + CTool::turn(day);
				if(l2.count(temp) == 0)
				{
					l2[temp] = 1;
				}
				else
					l2[temp] += 1;
			}
		}

		FILE* fp = fopen(filename, "w");
		for(it2 = l2.begin();it2 != l2.end(); it2++)
		{
			if(fp == NULL)
			{
				PopUp tempwin(15,15,20,15,"文件无法打开");
				tempwin.showWin();
				tempwin.runWin();
				this->showWin();
				return -1;
			}
			fprintf(fp,"%d  %d\n",it2->first,it2->second);
		}
		fclose(fp);

		PopUp tempwin(15,15,20,15,"导出成功");
		tempwin.showWin();
		tempwin.runWin();
		return 8;
	}
	else if(n == 7)
		return 8;
	return -1;
}

int StatisticsWin::runWin()
{
	userid = global::uid;
	int temp;
	while(true)
	{
		temp = this->doaction(this->chooseContorl());
		if(temp != -1)
			return temp;
	}
	return 0;
}