# Microsoft Developer Studio Project File - Name="medical" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=medical - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "medical.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "medical.mak" CFG="medical - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "medical - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "medical - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "medical - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x804 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "medical - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x804 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "medical - Win32 Release"
# Name "medical - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\AdminWin.cpp
# End Source File
# Begin Source File

SOURCE=.\BookingWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CBun.cpp
# End Source File
# Begin Source File

SOURCE=.\CCombobox.cpp
# End Source File
# Begin Source File

SOURCE=.\CEdit.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangeBookingWIn.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangeDoctorPwdWin.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangeDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\ChangePwdWin.cpp
# End Source File
# Begin Source File

SOURCE=.\CLable.cpp
# End Source File
# Begin Source File

SOURCE=.\CMainWin.cpp
# End Source File
# Begin Source File

SOURCE=.\Contorl.cpp
# End Source File
# Begin Source File

SOURCE=.\CreatDoctor.cpp
# End Source File
# Begin Source File

SOURCE=.\CTable.cpp
# End Source File
# Begin Source File

SOURCE=.\CTool.cpp
# End Source File
# Begin Source File

SOURCE=.\CUser.cpp
# End Source File
# Begin Source File

SOURCE=.\CWin.cpp
# End Source File
# Begin Source File

SOURCE=.\DEDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\Department.cpp
# End Source File
# Begin Source File

SOURCE=.\DoctorBookingWin.cpp
# End Source File
# Begin Source File

SOURCE=.\DoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\EnrollWin.cpp
# End Source File
# Begin Source File

SOURCE=.\global.cpp
# End Source File
# Begin Source File

SOURCE=.\IftPerfectionWin.cpp
# End Source File
# Begin Source File

SOURCE=.\LoginWin.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\NewDepartmentWin.cpp
# End Source File
# Begin Source File

SOURCE=.\PatientWin.cpp
# End Source File
# Begin Source File

SOURCE=.\PersonCenterWin.cpp
# End Source File
# Begin Source File

SOURCE=.\PopUp.cpp
# End Source File
# Begin Source File

SOURCE=.\ReservationWin.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchDepartmentWin.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchDoctorWin.cpp
# End Source File
# Begin Source File

SOURCE=.\SearchUserWin.cpp
# End Source File
# Begin Source File

SOURCE=.\SeekingWin.cpp
# End Source File
# Begin Source File

SOURCE=.\StatisticsWin.cpp
# End Source File
# Begin Source File

SOURCE=.\TakeNumberWin.cpp
# End Source File
# Begin Source File

SOURCE=.\UserBookingWin.cpp
# End Source File
# Begin Source File

SOURCE=.\VaccineAppointmentWin.cpp
# End Source File
# Begin Source File

SOURCE=.\VaccineSearchWin.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\AdminWin.h
# End Source File
# Begin Source File

SOURCE=.\booking.h
# End Source File
# Begin Source File

SOURCE=.\BookingWIn.h
# End Source File
# Begin Source File

SOURCE=.\CBun.h
# End Source File
# Begin Source File

SOURCE=.\CCombobox.h
# End Source File
# Begin Source File

SOURCE=.\CEdit.h
# End Source File
# Begin Source File

SOURCE=.\ChangeBookingWin.h
# End Source File
# Begin Source File

SOURCE=.\ChangeDoctorPwdWin.h
# End Source File
# Begin Source File

SOURCE=.\ChangeDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\ChangePwdWin.h
# End Source File
# Begin Source File

SOURCE=.\CLable.h
# End Source File
# Begin Source File

SOURCE=.\CMainWin.h
# End Source File
# Begin Source File

SOURCE=.\Contorl.h
# End Source File
# Begin Source File

SOURCE=.\CreatDoctor.h
# End Source File
# Begin Source File

SOURCE=.\CTable.h
# End Source File
# Begin Source File

SOURCE=.\CTool.h
# End Source File
# Begin Source File

SOURCE=.\CUser.h
# End Source File
# Begin Source File

SOURCE=.\CWin.h
# End Source File
# Begin Source File

SOURCE=.\Date.h
# End Source File
# Begin Source File

SOURCE=.\DEDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\Department.h
# End Source File
# Begin Source File

SOURCE=.\DoctorBookingWin.h
# End Source File
# Begin Source File

SOURCE=.\DoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\EnrollWin.h
# End Source File
# Begin Source File

SOURCE=.\global.h
# End Source File
# Begin Source File

SOURCE=.\IftPerfectionWin.h
# End Source File
# Begin Source File

SOURCE=.\LoginWin.h
# End Source File
# Begin Source File

SOURCE=.\NewDepartmentWin.h
# End Source File
# Begin Source File

SOURCE=.\PatientWin.h
# End Source File
# Begin Source File

SOURCE=.\PersonCenterWin.h
# End Source File
# Begin Source File

SOURCE=.\PopUp.h
# End Source File
# Begin Source File

SOURCE=.\ReservationWin.h
# End Source File
# Begin Source File

SOURCE=.\SearchDepartmentWin.h
# End Source File
# Begin Source File

SOURCE=.\SearchDoctorWin.h
# End Source File
# Begin Source File

SOURCE=.\SearchUserWin.h
# End Source File
# Begin Source File

SOURCE=.\SeekingWin.h
# End Source File
# Begin Source File

SOURCE=.\StatisticsWin.h
# End Source File
# Begin Source File

SOURCE=.\TakeNumberWin.h
# End Source File
# Begin Source File

SOURCE=.\UserBookingWin.h
# End Source File
# Begin Source File

SOURCE=.\Vaccine.h
# End Source File
# Begin Source File

SOURCE=.\VaccineAppointmentWin.h
# End Source File
# Begin Source File

SOURCE=.\VaccineSearchWin.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
