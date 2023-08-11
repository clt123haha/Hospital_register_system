#ifndef  global_H
#define  global_H

#include "CTool.h"
#include "CWin.h"



class global
{
public:
	static int uid;
	static list<CWin *> l;
	static void setl(list<CWin *> &l2);
	static void setusername();
	static void setdoctorname();
	static void setadminname();
};

#endif