#ifndef  CTable_H
#define  CTable_H

#include "Contorl.h"
#include "Vaccine.h"
#include <list.h>

class CTable : public Contorl
{
public:
	list<string> arr;
	int row;
	int line;
	CTable(int x,int y,int width,int height,char *content,int row,int line);
	void showContorl();
	void runContorl(list<string> user);
	void addstring(string s);
};

#endif