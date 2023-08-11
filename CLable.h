#ifndef  CLable_H
#define  CLable_H

#include "Contorl.h"

class CLable : public Contorl
{
public:
	CLable(int x,int y,int width,int height,char *content);
	void showContorl();
	void runContorl();
};

#endif