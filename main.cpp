#include "CBun.h"
#include "CTool.h"
#include "CMainWin.h"
#include "EnrollWin.h"
#include "AdminWin.h"
#include "LoginWin.h"
#include "DoctorWin.h"
#include "PatientWin.h"
#include "CCombobox.h"
#include "PopUp.h"
#include "PersonCenterWin.h"
#include "IftPerfectionWin.h"
#include "ChangePwdWin.h"
#include "BookingWin.h"
#include "CreatDoctor.h"
#include "CTable.h"
#include "SearchUserWin.h"
#include "AdminWin.h"
#include "SearchDoctorWin.h"
#include "SearchDepartmentWin.h"
#include "ChangeDoctorWin.h"
#include "TakeNumberWin.h"
#include "ChangeBookingWIn.h"
#include "UserBookingWin.h"
#include "DoctorBookingWin.h"
#include "SeekingWin.h"
#include "ChangeDoctorPwdWin.h"
#include "ReservationWin.h"
#include "global.h"
#include "PopUp.h"
#include "DEDoctorWin.h"
#include "NewDepartmentWin.h"
#include "StatisticsWin.h"
#include "VaccineAppointmentWin.h"
#include "VaccineSearchWin.h"
#include <string.h>
#include <stdio.h>
#pragma warning(disable : 4786)



int main()
{
	list<CWin *> winlist;
	std::list<CWin *>::iterator now;
	int nextWin;
	CWin *win1 = new CMainWin(5,5,30,30);
	CWin *win2 = new EnrollWin(5,5,30,30);
	CWin *win3 = new LoginWin(5,5,30,30);
	CWin *win4 = new PatientWin(5,5,30,30);
	CWin *win5 = new PersonCenterWin(5,5,30,30);
	CWin *win6 = new IftPerfectionWin(5,5,30,30);
	CWin *win7 = new ChangePwdWin(5,5,30,30);
	CWin *win8 = new BookingWin(5,5,30,30);
	CWin *win9 = new AdminWin(5,5,30,30);
	CWin *win10 = new SearchUserWin(5,5,30,30);
	CWin *win11 = new SearchDoctorWin(5,5,30,30);
	CWin *win12 = new SearchDepartmentWin(5,5,30,30);
	CWin *win13 = new DoctorWin(5,5,30,30);
	CWin *win14 = new UserBookingWin(5,5,40,30);
	CWin *win15 = new TakeNumberWin(5,5,40,30,0);
	CWin *win16 = new ChangeDoctorPwdWin(5,5,30,30);
	CWin *win17 = new DoctorBookingWin(5,5,30,30);
	CWin *win18 = new ReservationWin(5,5,30,30);
	CWin *win19 = new CreatDoctor(5,5,30,30);
	CWin *win20 = new DEDoctorWin(15,15,20,15);
	CWin *win21 = new NewDepartmentWin(5,5,30,30);
	CWin *win22 = new StatisticsWin(5,5,30,30);
	CWin *win23 = new VaccineAppointmentWin(5,5,30,30);
	CWin *win24 = new VaccineSearchWin(5,5,40,30);
	winlist.push_back(win1);
	winlist.push_back(win2);
	winlist.push_back(win3);
	winlist.push_back(win4);
	winlist.push_back(win5);
	winlist.push_back(win6);
	winlist.push_back(win7);
	winlist.push_back(win8);
	winlist.push_back(win9);
	winlist.push_back(win10);
	winlist.push_back(win11);
	winlist.push_back(win12);
	winlist.push_back(win13);
	winlist.push_back(win14);
	winlist.push_back(win15);
	winlist.push_back(win16);
	winlist.push_back(win17);
	winlist.push_back(win18);
	winlist.push_back(win19);
	winlist.push_back(win20);
	winlist.push_back(win21);
	winlist.push_back(win22);
	winlist.push_back(win23);
	winlist.push_back(win24);
	global::setl(winlist);
	now = winlist.begin();
	while(true)
	{
		(*now)->showWin();
		nextWin = (*now)->runWin();
		now = winlist.begin();
		if(nextWin == -1)
			break;
		now = winlist.begin();
		advance(now,nextWin);
		
	}
	return 0;
}




