#ifndef  Department_H
#define  Department_H

#include <stdio.h>
#include <string.h>

class Department 
{
public:
	int username;
	char name[20];
	char message[255];

	Department();
	Department(int username,char *name,char *message);
};

#endif