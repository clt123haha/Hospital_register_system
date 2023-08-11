#ifndef  CWin_H
#define  CWin_H

#include<list>
using namespace std;
#include<algorithm>
#include "CTool.h"
#include<typeinfo>
#include "CBun.h"
#include "CLable.h"
#include "CEdit.h"
#include "Contorl.h"
#include "CCombobox.h"
#include "CTable.h"
#include "Department.h"
#include "TakeNumber.h"
#include<ctime>
#include<conio.h> 
class CWin
{
public:
	int x;
	int y;
	int width;
	int height;
	int n;
	int userid;
	int type;
	list<Contorl *> arr;
	map<int,CUser *> user;
	CWin();
	CWin(int x,int y,int width,int height);
	void addContorl(Contorl *contorl);
	virtual void showWin();
	int chooseContorl();
	virtual int doaction(int n);
	virtual int runWin();
};

#endif