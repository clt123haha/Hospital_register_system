#include "CTable.h"
#include "ChangeDoctorWin.h"
#include "ChangeBookingWIn.h"
#include "SeekingWin.h"
#include "DEDoctorWin.h"
#include "PopUp.h"

CTable::CTable(int x,int y,int width,int height,char *content,int row,int line):Contorl(x,y,width,height,content,BUN)
{
	this->row = row;
	this->line = line;
}

void CTable::showContorl()
{
	CTool::drawLineBackgroud(x,y,width,height);
	int h = height/row;
	int l = (width/line)*2;
	list<string >::iterator it;
	int n = 0;
	for(int i=1;i<line;i++)
	{
		CTool::gotoxy(x + i*l,y);
		printf("┬");
		CTool::gotoxy(x + i*l,y+height-1);
		printf("┴");
		for(int j = 1;j<height-1;j++)
		{
			CTool::gotoxy(x + i*l,y+j);
			printf("│");
			
		}
	}
	for(i=1;i<row;i++)
	{
		CTool::gotoxy(x,y+i*h);
		printf("├ ");
		CTool::gotoxy(x+width*2-2,y+i*h);
		printf("┤");
		for(int j = 1;j<width-1;j++)
		{
			if((j*2)%l == 0)
			{
				CTool::gotoxy(x + j*2,y+i*h);
				printf("┼");
			}
			else{
				CTool::gotoxy(x + j*2,y+i*h);
				printf("─");
			}
		}
	}
    for (it = arr.begin(); it != arr.end(); it++) {
		string s1 = *it;
		CTool::gotoxy(x + n*l+2,y+1);
		n++;
		copy(s1.begin(), s1.end(),std::ostream_iterator<char>(cout, ""));
    }
	CTool::gotoxy(x+this->width,y+this->height);
	printf("1/");
}

void CTable::runContorl(list<string> user)
{
	list<string>::iterator p = user.begin();
	int page,pnow = 1,rowp = row -1,now = 1,h = height/row,l = (width/line)*2,size = user.size();


	if(page == 0)
		page = 1;
	if((user.size()/line)%rowp != 0)
		page = size/rowp/line + 1;
	else
		page = size/rowp/line;


	CTool::gotoxy(x+this->width,y+this->height);
	printf("1/%d",page);


	for(int i=1;i<=rowp;i++)
	{
		
		for(int j=0;j<line;j++)
		{
			if(p == user.end())
				break;
			CTool::gotoxy(x+2+l*j,y+1+h*i);
			copy(p->begin(), p->end(),std::ostream_iterator<char>(cout, ""));
			p++;
		}
		if(p == user.end())
				break;
	}

	//按上下左右键来进行操作
	CTool::gotoxy(x+1,y+h);
	while(true)
	{
		int mark = CTool::getkey();
		if(mark == BACK)
			break;
		else if(mark == DOWN)
		{
			now++;
			if(now > row-1)
				now = 1;
			CTool::gotoxy(x+1,y+h*now);
		}else if(mark == UP)
		{
			now--;
			if(now <= 0)
				now = row-1;
			CTool::gotoxy(x+1,y+h*now);

		//因为win中有使用CTable，不能引窗口类，采用现画
		}else if(mark == LEFT)
		{
			if(pnow == 1)
			{
				CTool::drawLineBackgroud(x+8,y+2,12,5);
				CTool::gotoxy(x+11,y+4);
				printf("已经是第一页");
				getch();
				this->showContorl();


				p = user.begin();
				advance(p,(pnow-1)*rowp*line);
				for(int i=1;i<=rowp;i++)
				{
					if(p == user.end())
							break;
					for(int j=0;j<line;j++)
					{
						if(p == user.end())
							break;
						CTool::gotoxy(x+2+l*j,y+1+h*i);
						copy(p->begin(), p->end(),std::ostream_iterator<char>(cout, ""));
						p++;
					}
				}


				CTool::gotoxy(x+this->width,y+this->height);
				printf("%d/%d",pnow,page);
				CTool::gotoxy(x+1,y+h);
				continue;
			}


			pnow -= 1;
			this->showContorl();
			p = user.begin();
			advance(p,(pnow-1)*size);
			for(int i=1;i<=rowp;i++)
			{
		
				for(int j=0;j<line;j++)
				{
					if(p == user.end())
						break;
					CTool::gotoxy(x+2+l*j,y+1+h*i);
					copy(p->begin(), p->end(),std::ostream_iterator<char>(cout, ""));
					p++;
				}
					if(p == user.end())
						break;
			}
			CTool::gotoxy(x+this->width,y+this->height);
			printf("%d/%d",pnow,page);
			CTool::gotoxy(x+1,y+h);
		}else if(mark == RIGHT)
		{
			if(pnow == page)
			{
				CTool::drawLineBackgroud(x+8,y+2,12,5);
				CTool::gotoxy(x+11,y+4);
				printf("已经是最后一页");
				getch();
				this->showContorl();


				p = user.begin();
				advance(p,(pnow-1)*rowp*line);
				for(int i=1;i<=rowp;i++)
				{
					if(p == user.end())
							break;
					for(int j=0;j<line;j++)
					{
						if(p == user.end())
							break;
						CTool::gotoxy(x+2+l*j,y+1+h*i);
						copy(p->begin(), p->end(),std::ostream_iterator<char>(cout, ""));
						p++;
					}
				}


				CTool::gotoxy(x+this->width,y+this->height);
				printf("%d/%d",pnow,page);
				CTool::gotoxy(x+1,y+h);
				continue;
			}
			pnow += 1;
			this->showContorl();
			p = user.begin();
			advance(p,(pnow-1)*rowp*line);
			for(int i=1;i<=rowp;i++)
			{
				if(p == user.end())
						break;
				for(int j=0;j<line;j++)
				{
					if(p == user.end())
						break;
					CTool::gotoxy(x+2+l*j,y+1+h*i);
					copy(p->begin(), p->end(),std::ostream_iterator<char>(cout, ""));
					p++;
				}
			}
			CTool::gotoxy(x+this->width,y+this->height);
			printf("%d/%d",pnow,page);
			CTool::gotoxy(x+1,y+h);
		}else if(mark == ENTER)
		{
			//根据content打开不同窗口
			if(strcmp(this->content,"changeDOctor")==0)
			{
				map<int ,CUser *> u;
				map<int ,CUser *>::iterator t;
				CTool::getDoctor(u);
				t = u.begin();
				int m = now-1 + (row-1)*(pnow-1);
				if((m +1) * line <= user.size())
				{
					advance(t,m);
					ChangeDoctorWin win(13,10,20,12,t->first);
					win.showWin();
					win.runWin();
					break;
				}
				else
				{
					strcpy(this->input,"DE");
					break;
				}
			}
			else if(strcmp(this->content,"takenumber")==0)
			{
				list<booking *> l;
				list<booking *>::iterator t;
				CTool::getTakeNumber(l);
				t = l.begin();
				int m = now-1 + (row-1)*(pnow-1);
				if((m +1) * line <= user.size())
				{
					ChangeBookingWIn win(13,10,20,12,m);
					win.showWin();
					win.runWin();
				}
				getch();
				break;
			}else if(strcmp(this->content,"doctorbooking")==0)
			{
				list<booking *> l;
				list<booking *> l2;
				map<int,CUser *> l3;
				map<int,CUser *>::iterator t2;
				list<booking *>::iterator t;
				CTool::getTakeNumber(l);
				CTool::getDoctor(l3);
				t = l.begin();
				for(;t!=l.end();t++)
				{
					if(strcmp(l3[global::uid]->name,(*t)->doctor) == 0 && strcmp(l3[global::uid]->department,(*t)->department) == 0 &&(strcmp("等待就诊",(*t)->state)==0||strcmp("已就诊",(*t)->state)==0))
					{
						booking *temp = *t;
						l2.push_back(temp);
					}
				}
				t = l2.begin();
				int m = now-1 + (row-1)*(pnow-1);
				if((m +1) * line <= user.size())
				{
					advance(t,m);
					if(strcmp((*t)->state,"等待就诊") == 0)
					{
						char ch[255];
						char ch2[20];
						char time[30];
						SeekingWin win(5,5,30,30,(*t)->id);
						list<Contorl *>::iterator p;
						p = win.arr.begin();
						p++;
						sprintf(ch2,"欢迎%s医生",l3[global::uid]->name);
						strcpy((*p)->content,ch2);
						p++;
						time_t time_now = ::time(0);
						tm *ltm = localtime(&time_now);
						sprintf(time,"日期：%d - %d - %d",1900 + ltm->tm_year,1 + ltm->tm_mon,ltm->tm_mday);
						strcpy((*p)->content,time);
						p++;
						sprintf(ch,"预约描述：%s",(*t)->message_b);
						strcpy((*p)->content,ch);
						win.showWin();
						win.runWin();
					}
				}
				system("cls");
				break;
			}else if(strcmp(this->content,"VaccineSearchWin")==0)
			{
				list<Vaccine *> l;
				list<Vaccine *>::iterator t;
				FILE* fp = fopen("./data/Vaccine.txt", "r");
				if(fp == NULL)
				{
					CTool::drawLineBackgroud(x+8,y+2,12,5);
					CTool::gotoxy(x+11,y+4);
					printf("文件无法打开");
					getch();
					this->showContorl();
				}
				Vaccine *temp  = new Vaccine();
				while (fscanf(fp, "%d%s%s%s%s%s%s", &(temp->uid),temp->hospital,temp->batch,temp->factory,temp->date,temp->time,temp->status) != -1){
					if(temp->uid == global::uid)
					{
						l.push_back(temp);
					}
				}
				fclose(fp);
				if(l.size() == 0)
				{
					CTool::drawLineBackgroud(x+8,y+2,12,5);
					CTool::gotoxy(x+11,y+4);
					printf("文件无法打开");
					getch();
					break;
				}
				t = l.begin();
				int m = now-1 + (row-1)*(pnow-1);
				if((m +1) * line <= user.size())
				{
					advance(t,m);
					if(strcmp((*t)->status,"已预约接种") == 0)
					{
						l.erase(t);
						FILE* fp = fopen("./data/Vaccine.txt", "w");
						if(fp == NULL)
						{
							CTool::drawLineBackgroud(x+8,y+2,12,5);
							CTool::gotoxy(x+11,y+4);
							printf("文件无法打开");
							getch();
							this->showContorl();
						}
						for(t = l.begin();t != l.end();t++)
							fprintf(fp,"%d %s %s %s %s %s %s\n",(*t)->uid,(*t)->hospital,(*t)->batch,(*t)->factory,(*t)->date,(*t)->time,(*t)->status);
						fclose(fp);
						CTool::drawLineBackgroud(x+8,y+2,12,5);
						CTool::gotoxy(x+11,y+4);
						printf("成功");
						getch();
						break;
					}
					else
					{
						CTool::drawLineBackgroud(x+8,y+2,12,5);
						CTool::gotoxy(x+11,y+4);
						printf("不可操作");
						getch();
						this->showContorl();
					}
				}
				system("cls");
				break;
			}

		}
	}
	
}

void CTable::addstring(string s)
{
	arr.push_back(s);
}