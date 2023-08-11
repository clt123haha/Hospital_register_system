#include "Department.h"
#pragma warning(disable : 4786)

Department::Department()
{
	strcpy(name,"");
	strcpy(message,"");
}


Department::Department(int username,char *name,char *message)
{
	this->username = username;
	strcpy(this->name,name);
	strcpy(this->message,message);
}