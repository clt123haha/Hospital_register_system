#include "Contorl.h"

Contorl::Contorl(int x,int y,int width,int height,char *content,int type)
{
	this->x = x;
	this->y = y;
	this->width = width;
	this->height = height;
	this->type = type;
	strcpy(this->content, content);
	strcpy(this->input, "");
}

Contorl::Contorl()
{
	
}

void Contorl::showContorl()
{

}

void Contorl::runContorl()
{}

