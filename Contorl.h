#ifndef  Contorl_H
#define  Contorl_H

#define LABLE 1
#define BUN 2
#define EDIT 3
#define Combobox 4
#define POPUP 5
#include <stdio.h>
#include <string.h>
#include "CTool.h"


class Contorl
{
public:
	int x;
	int y;
	int width;
	int height;
	char content[50];
	char input[20];
	int type;
	Contorl(int x,int y,int width,int height,char *content,int type);
	Contorl();
	virtual void runContorl();
	virtual void showContorl();
};

#endif