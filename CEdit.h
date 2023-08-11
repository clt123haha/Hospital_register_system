#ifndef  CEdit_H
#define  CEdit_H

#include "Contorl.h"
#include< conio.h> 
#include <string.h>

class CEdit : public Contorl
{
public:
	int status;
	int max;
	int inputType;
	CEdit(int x,int y,int width,int height,char *content,int status,int max,int inputType);
	void showContorl();
	void runContorl();

};

#endif