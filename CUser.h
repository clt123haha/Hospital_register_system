#ifndef  CUser_H
#define  CUser_H

#include <stdio.h>
#include <string.h>

#define PATIENT 1
#define DOCTOR 2
#define ADMIN 3

class CUser 
{
public:
	int username;
	char name[20];
	char password[20];
	char phone[20];
	char idcard[20];
	char department[10];
	char posts[10];
	int time[3];
	int type;
	char message[255];
	char hospital[20];
	CUser();
	CUser(int username,char *name,char *password,int type);
};

#endif