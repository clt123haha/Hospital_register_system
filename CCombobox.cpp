#include "CCombobox.h"
#pragma warning(disable : 4786)

CCombobox::CCombobox(int x,int y,int width,int height,char *content):Contorl(x,y,width,height,content,Combobox)
{
	
}

void CCombobox::showContorl()
{
	CTool::drawLineBackgroud(x,y,width,height);
	CTool::gotoxy(x+(width-strlen(this->content)/2),y+1);
	printf("%s",this->content);
	CTool::gotoxy(x+width*2-3,y+1);
	printf("¨‹");
}

void CCombobox::drawCCombobox()
{
	std::list<CBun>::iterator p = list.begin();
	while(p != list.end())
	{
		p->showContorl();
		p++;
	}
}


void CCombobox::changeContent()
{
	char mark;
	std::list<CBun>::iterator p = list.begin();
	while(true)
	{	
	std::list<CBun>::iterator p = list.begin();
	while(true)
	{
		CTool::gotoxy(p->x,p->y);
		mark = CTool::getkey();
		if(mark == DOWN)
		{
			while(true)
			{
				p++;
				if(p == list.end())
					p = list.begin();
				if(p->type != LABLE) 
					break;
			}
		}else if(mark == UP)
		{
			while(true)
			{
				if(p == list.begin())
					p = list.end();
				p--;
				if(p->type != LABLE) 
					break;
			}
		
		}else if(mark == ENTER)
		{
			strcpy(this->content,p->content);
			strcpy(this->input,p->input);
			return;
		}else if(mark == BACK)
		{
	
		}
		
	}
	}
}

void CCombobox::addBun(CBun t)
{
	list.push_back(t);
}

void CCombobox::runContorl()
{
	this->drawCCombobox();
	this->changeContent();
}
