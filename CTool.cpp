#include "CTool.h"
#include<windows.h>
#include< conio.h>
using namespace std; 

int userid = 0;
void CTool::gotoxy(int x, int y)
 {
	 HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	 COORD coord = {x, y};

	 SetConsoleCursorPosition(hOut, coord);
}

void CTool::drawLineBackgroud(int startx,int starty,int row,int line){
	int  i,j;
	for(i=0;i<line;i++)
	{	
		if(i==0)
		{
			gotoxy(startx,starty+i);
			for(j=0;j<row;j++)
			{
				if(j==0)
					printf("┌");
				else if(j==row-1)
					printf("┐");
				else
					printf("─");
			}			
		}
		else if(i==line-1)
		{
			gotoxy(startx,starty+i);
			for(j=0;j<row;j++)
				{
				if(j==0)
					printf("└");
				else if(j==row-1)
					printf("┘");
				else
					printf("─");
				}	
		}
		else
		{
			gotoxy(startx,starty+i);
			for(j=0;j<row;j++)		
			{
				if(j==0||j==row-1)
					printf("│");
				else
					printf("  ");
			}		
		} 	
	}			
}

int CTool::getkey()
{
	char key;
	key = getch();
	if(key == -32)
	{
		key = getch();
		if(key == 72)
		{
			return UP;
		}
		if(key == 80)
			return DOWN;
		if(key == 75)
			return LEFT;
		if(key == 77)
			return RIGHT;
	}
	if(key == 13)
		return ENTER;
	if(key == 27)
		return BACK;
	return key;
}

void CTool::getPATIENT(map<int,CUser *> &arr)
{
	FILE* fp = fopen("./data/PATIENT.txt", "r+");
	if(fp == NULL)
	{
		printf("sorry\n");
		return;
	}
	CUser *temp  = new CUser();
	while (fscanf(fp, "%d%s%s%d%s%s", &(temp->username),temp->name,temp->password,&(temp->type),temp->phone,temp->idcard) != -1){
		arr[temp->username] = temp;
		temp  = new CUser();
    }
    fclose(fp);
}

void CTool::getDoctor(map<int,CUser *> &arr)
{
	FILE* fp = fopen("./data/DOCTOR.txt", "r+");
	if(fp == NULL)
	{
		printf("sorry\n");
		return;
	}
	CUser *temp  = new CUser();
	while (fscanf(fp, "%d%s%s%s%s%s%s",&(temp->username),temp->name,temp->password,temp->department,temp->posts,temp->hospital,temp->message) != -1){
		arr[temp->username] = temp;
		temp  = new CUser();
    }
    fclose(fp);
}

void CTool::getAdmin(map<int,CUser *> &arr)
{
	FILE* fp = fopen("./data/ADMIN.txt", "r+");
	if(fp == NULL)
	{
		printf("sorry\n");
		return;
	}
	CUser *temp  = new CUser();
	while (fscanf(fp, "%d%s%s%d", &(temp->username),temp->name,temp->password,&(temp->type)) != -1){
		arr[temp->username] = temp;
		temp->type = 3;
		CUser *temp  = new CUser();
    }
    fclose(fp);
}

void CTool::getCaptcha(char *arr)
{
	srand((unsigned)time(NULL));
	for(int i=0;i<6;i++)
	{
		arr[i] = '0'+rand()%10;
	}
	arr[6] = '\0';
}



int CTool::turn(char *ch)
{

	int n=0;
	for(int i=0;i<strlen(ch);i++)
	{
		n *= 10;
		n += ch[i] -'0';
	}
	return n;
}

//重写医生文件
void CTool::write(map<int,CUser *> user){
	FILE * fp;
	fp = fopen ("./data/DOCTOR.txt", "w");
	if(fp == NULL)
	{
		printf("sorry");
		getch();
	}
	map<int,CUser *>::iterator it;
    for (it = user.begin(); it != user.end(); it++) {
        CUser *temp = it->second;
		fprintf(fp,"%d %s %s %s %s %s %s\n",temp->username,temp->name,temp->password,temp->department,temp->posts,temp->hospital,temp->message);
    }
	fclose(fp);
}

void CTool::getDepartment(map<int,Department *> &arr)
{
	FILE* fp = fopen("./data/Department.txt", "r+");
	if(fp == NULL)
	{
		printf("sorry\n");
		return;
	}
	Department *temp  = new Department();
	while (fscanf(fp, "%d%s%s", &(temp->username),temp->name,temp->message) != -1){
		arr[temp->username] = temp;
		temp  = new Department();
    }
    fclose(fp);
}

void CTool::getTakeNumber(list<booking *> &l)
{
	FILE* fp = fopen("./data/TakeNubmer.txt", "r+");
	if(fp == NULL)
	{
		printf("sorry\n");
		return;
	}
	booking *temp  = new booking();
	while (fscanf(fp, "%d%d%s%d%s%s%s%s%s%s", &(temp->id),&(temp->user),temp->date,&(temp->time),temp->hospital,temp->department,temp->doctor,temp->state,temp->message_b,temp->message_a) != -1){
		l.push_back(temp);
		temp  = new booking();
    }
	
	
    fclose(fp);
}

void CTool::setTakeNumber(list<booking *> l)
{
	FILE* fp = fopen("./data/TakeNubmer.txt", "w+");
	if(fp == NULL)
	{
		printf("sorry\n");
		return;
	}
	std::list<booking *>::iterator p=l.begin(); 
	for(;p!=l.end();p++)
	{
		fprintf(fp,"%d %d %s %d %s %s %s %s %s %s\n",(*p)->id,(*p)->user,(*p)->date,(*p)->time,(*p)->hospital,(*p)->department,(*p)->doctor,(*p)->state,(*p)->message_b,(*p)->message_a);
	}
	
    fclose(fp);
}

void CTool::setuserid(int id)
{
	userid = id;
}

int CTool::getuserid()
{
	return userid;
}

void CTool::getTomorrow(Date &today,char *ch) {
	int flag = (today.year % 4 == 0 && today.year % 100 != 0) || today.year % 400 == 0;
	today.day++;


	switch (today.month) {
		case 1:case 3:case 5:case 7:case 8:case 10:
		case 12: {
			if (today.day == 32) {
				today.month++;
				today.day = 1;
			}
			break;
		}
		case 4:case 6:case 9:case 11: {
			if (today.day == 31) {
				today.month++;
				today.day = 1;
			}
			break;
		}
		case 2: {
			if (flag == 1 && today.day == 30) {
				today.month++;
				today.day = 1;
			}
			if (flag == 0 && today.day == 29) {
				today.month++;
				today.day = 1;
			}
		}
	}


	if(today.month == 13){
		today.year++;
		today.month=1;
	}


	sprintf(ch,"%04d%02d%02d",today.year,today.month,today.day);
}

