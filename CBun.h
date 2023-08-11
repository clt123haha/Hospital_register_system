#ifndef  CBun_H
#define  CBun_H

#include "Contorl.h"

class CBun : public Contorl
{
public:
	CBun(int x,int y,int width,int height,char *content);
	void showContorl();
	void runContorl();
};

#endif

