#include "Vaccine.h"
#include "CWin.h"
#include "global.h"
#include "PopUp.h"

class VaccineAppointmentWin : public CWin
{
public:
	VaccineAppointmentWin(int x,int y,int width,int height);
	int doaction(int n);
	int runWin();
};
