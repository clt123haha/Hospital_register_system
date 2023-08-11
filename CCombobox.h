#ifndef  CCombobox_H
#define  CCombobox_H

#include "Contorl.h"
#include "CBun.h"

class CCombobox : public Contorl
{
public:
	CCombobox(int x,int y,int width,int height,char *content);
	list<CBun> list;
	void showContorl();
	void drawCCombobox();
	void changeContent();
	void addBun(CBun t);
	void runContorl();
};

#endif