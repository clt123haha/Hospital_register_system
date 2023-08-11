#include "CUser.h"

CUser::CUser()
{
	strcpy(this->name,"user");
	strcpy(this->password,"123456");
	strcpy(this->phone,"none");
	strcpy(this->idcard,"none");
	strcpy(this->department,"none");
	strcpy(this->posts,"none");
	strcpy(this->message,"none");
	time[0] = 0;
	time[1] = 0;
	time[2] = 0;
}

CUser::CUser(int username,char *name,char *password,int type)
{
	this->username = username;
	strcpy(this->name,name);
	strcpy(this->password,password);
	this->type = type;
	strcpy(this->name,"user");
	strcpy(this->password,"123456");
	strcpy(this->phone,"none");
	strcpy(this->idcard,"none");
	strcpy(this->department,"none");
	strcpy(this->posts,"none");
	strcpy(this->message,"none");
	time[0] = 0;
	time[1] = 0;
	time[2] = 0;
}