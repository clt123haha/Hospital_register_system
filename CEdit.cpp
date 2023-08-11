#include "CEdit.h"


CEdit::CEdit(int x,int y,int width,int height,char *content,int status,int max,int inputType):Contorl(x,y,width,height,content,EDIT)
{
	this->status = status;
	this->max = max;
	this->inputType = inputType;
	strcpy(this->input, "");
}

void CEdit::showContorl()
{
	CTool::drawLineBackgroud(x+strlen(this->content),y,width,height);
	CTool::gotoxy(x,y);
	printf("%s",this->content);
	CTool::gotoxy(x+strlen(this->content)+3,y+1);
	if(this->status == 0)
	{
	printf("%s",this->input);
	}
	else
	{
		for(int i=0;i<strlen(input);i++)
			printf("*");
	}
}

void CEdit::runContorl()
{
	char ch;
	CTool::gotoxy(x+strlen(this->content)+strlen(this->input)+3,y+1);
	int n = strlen(this->input);
	while(true)
	{	
		ch = getch();
		if(ch == 8 && strlen(this->input) >0)
		{
			printf("\b \b");		
			input[--n] = '\0';
			continue;
		}
		if(ch == 13)
		{
			return;
		}
		if(n+1>=this->max)
		{
			continue;
		}
		
		if(this->inputType == 0)  //没有限制
		{
			if(ch == 8)
				continue;
			if(this->status == 0 )
			{
				printf("%c",ch);
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}else if(this->status == 1)
			{
				printf("*");
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}
		}else if(this->inputType == 1 && (ch >= '0' && ch <= '9' )) //只有数字
		{
			if(this->status == 0 )
			{
				printf("%c",ch);
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}else if(this->status == 1)
			{
				printf("*");
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}
		}else if(this->inputType == 2 && ((ch <= 'z' && ch >= 'a' )|| (ch <= 'Z' && ch >= 'A'))) //只有字母
		{
			if(this->status == 0 )
			{
				printf("%c",ch);
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}else if(this->status == 1)
			{
				printf("*");
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}
		}else if(this->inputType == 3 && ((ch<='9'&&ch>='0')||(ch<='z'&&ch>='a')||(ch<='Z'&&ch>='A'))) //字母/数字
		{
			if(this->status == 0 )
			{
				printf("%c",ch);
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}else if(this->status == 1)
			{
				printf("*");
				this->input[n] = ch;
				this->input[++n] = '\0';
				continue;
			}
		}

	}
}