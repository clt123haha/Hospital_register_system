#ifndef CTool_H
#define CTool_H

#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdio.h>
#include "Date.h"
#include <ctime>
//using namespace std;
#include<vector>
#include<list>
#include<map>
#include <ctime>
#include <time.h>
#include <stdlib.h>
#include <vector>
#include "CUser.h"
#include "Department.h"
#include "booking.h"
using namespace std;
#include <fstream>
#include<cstdio>
#define DOWN 1
#define UP 2
#define ENTER 3
#define BACK 4
#define LEFT 5
#define RIGHT 6

class CTool
{
public:	
//	static int uid;
	static void gotoxy(int x, int y);
	static void drawLineBackgroud(int startx,int starty,int row,int line);
	static int getkey();
	static void getPATIENT(map<int,CUser *> &arr);
	static void getCaptcha(char *arr);
	static void getAdmin(map<int,CUser *> &arr);
	static void getDoctor(map<int,CUser *> &arr);
	static void getDepartment(map<int,Department *> &arr);
	static void getTakeNumber(list<booking *> &l);
	static void setTakeNumber(list<booking *> l);
	static int turn(char *ch);
	static void write(map<int,CUser *> user);
	static void setuserid(int id);
	static int getuserid();
	static void getTomorrow(Date &today,char *ch);
};

#endif