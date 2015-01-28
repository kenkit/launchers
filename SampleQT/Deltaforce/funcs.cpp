#include "funcs.h"
#include <fstream>
#include "windows.h"
#include "time.h"



#define CONTRACTS
int registration=0;
using namespace std;
double days;
double seconds,first_run_date=0,expire_date=0,days_remaining;

char orig[16] = {
    0x4D, 0x5A, 0x90, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00
};

char fake[16] = {
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
};


void write_file(char*filename,char* data)
{

ofstream is(filename,ios::binary | ios::out | ios::in);

if (!is)
    ;
is.seekp(0, ios::beg);
is.write(data, sizeof(data));
is.close();
}
void launch_app()
{
         #ifdef D_FORCE
           system("attrib +s +h dfbhd.exe");
            write_file("dfbhd.exe",orig);
            write_file("dfbhdlc.exe",orig);
            write_file("dfbhdmed.exe",orig);

            system("dfbhd.exe");

            write_file("dfbhd.exe",fake);
            write_file("dfbhdlc.exe",fake);
            write_file("dfbhdmed.exe",fake);
        #endif

        #ifdef TEKKEN
           system("attrib +s +h ePSXe.exe");
           write_file("ePSXe.exe",orig);

           system("ePSXe.exe   -loadbin Tekken.iso -nogui -noaudiocd");

           write_file("ePSXe.exe",fake);
        #endif // TEKKEN

        #ifdef NINJA
           system("attrib +s +h ePSXe.exe");
           write_file("ePSXe.exe",orig);

           system("ePSXe.exe -loadbin Ninja.img -nogui -noaudiocd");

           write_file("ePSXe.exe",fake);
        #endif // NINJA

        #ifdef U_GROUND
           system("attrib +s +h Undeground.exe");
           write_file("Undeground.exe",orig);
           system("Undeground.exe");
           write_file("Undeground.exe",fake);
        #endif
        #ifdef METAL

            system("attrib +s +h ePSXe.exe");
            write_file("ePSXe.exe",orig);

            system("ePSXe.exe -loadbin Metal.bin -nogui -noaudiocd");

            write_file("ePSXe.exe",fake);
        #endif // METAL

        #ifdef TOMB-R

            system("attrib +s +h ePSXe.exe");
            write_file("ePSXe.exe",orig);

            system("ePSXe.exe -loadbin Tomb.bin -nogui -noaudiocd");

            write_file("ePSXe.exe",fake);
        #endif // TOMB-R
        #ifdef HITMAN

            system("attrib +s +h hitman2.exe");

            write_file("hitman2.exe",orig);
            write_file("RenderD3D.dll",orig);
            write_file("RenderOpenGL.dll",orig);


            system("hitman2.exe");

            write_file("RenderD3D.dll",fake);
            write_file("RenderOpenGL.dll",fake);
            write_file("hitman2.exe",fake);
        #endif // HITMAN

        #ifdef CONTRACTS

           system("attrib +s +h hitmancontracts.exe");

           write_file("hitmancontracts.exe",orig);
          // write_file("RenderD3D.dll",orig);
           write_file("RenderOpenGL.dll",orig);


           system("hitmancontracts.exe");

           //write_file("RenderD3D.dll",fake);
           write_file("RenderOpenGL.dll",fake);
           write_file("hitmancontracts.exe",fake);
#endif // HITMAN
        #ifdef NFSEN

        system("attrib +s +h NFS2SEN.exe");

        system("taskkill /F /IM explorer.exe");


        write_file("NFS2SEN.exe",orig);
        write_file("SHELL.DLL",orig);
        write_file("DSETUP.DLL",orig);


        system("NFS2SEN.exe");

        write_file("NFS2SEN.exe",fake);
        write_file("SHELL.DLL",fake);
        write_file("DSETUP.DLL",fake);
        system("start explorer.exe");


        #endif // NFS
        #ifdef IGI

        system("attrib +s +h IGI.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("IGI.exe",orig);
       // write_file("SHELL.DLL",orig);
       // write_file("DSETUP.DLL",orig);


        system("IGI.exe");

        write_file("IGI.exe",fake);
       // write_file("SHELL.DLL",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");


#endif // NFS

#ifdef GTA_VC
        system("attrib +s +h gta-vc.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("gta-vc.exe",orig);

        write_file("Mss32.dll",orig);
       // write_file("DSETUP.DLL",orig);


        system("gta-vc.exe");

        write_file("gta-vc.exe",fake);
        write_file("Mss32.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // GTA_VC
#ifdef MOSTWTD
        system("attrib +s +h speed.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("speed.exe",orig);

        write_file("server.dll",orig);
       // write_file("DSETUP.DLL",orig);


        system("speed.exe");

        write_file("speed.exe",fake);
        write_file("server.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // GTA_VC
#ifdef CALL_DUTY
        system("attrib +s +h CoDMP.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("CoDMP.exe",orig);

        write_file("gamex86.dll",orig);
       // write_file("DSETUP.DLL",orig);


        system("CoDMP.exe");

        write_file("CoDMP.exe",fake);
        write_file("gamex86.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // CALL_DUTY

#ifdef DESERT_STORM
        system("attrib +s +h DesertStorm.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("DesertStorm.exe",orig);

        write_file("FrontEnd.dll",orig);
       // write_file("DSETUP.DLL",orig);


        system("DesertStorm.exe");

        write_file("DesertStorm.exe",fake);
        write_file("FrontEnd.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // CALL_DUTY

#ifdef MAX_PAYNE
        system("attrib +s +h MaxPayne2.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("MaxPayne2.exe",orig);

        write_file("eax.dll",orig);
        write_file("KF2MFC.dll",orig);

       // write_file("DSETUP.DLL",orig);


        system("MaxPayne2.exe");

        write_file("MaxPayne2.exe",fake);
        write_file("eax.dll",fake);
        write_file("KF2MFC.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // MAX_PAYNE
#ifdef TRANSFORMERS
        system("attrib +s +h Transformers.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("Transformers.exe",orig);

        write_file("binkw32.dll",orig);
        write_file("d3dx9_31.dll",orig);

       // write_file("DSETUP.DLL",orig);


        system("Transformers.exe");

        write_file("Transformers.exe",fake);
        write_file("binkw32.dll",fake);
        write_file("d3dx9_31.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // TRANSFORMERS
#ifdef FREEDOM
        system("attrib +s +h Freedom.exe");

        //system("taskkill /F /IM explorer.exe");


        write_file("Freedom.exe",orig);

        write_file("Msvcp60.dll",orig);
        write_file("jpegdll.dll",orig);

       // write_file("DSETUP.DLL",orig);


        system("Freedom.exe");

        write_file("Msvcp60.dll",fake);
        write_file("binkw32.dll",fake);
        write_file("jpegdll.dll",fake);
        //write_file("DSETUP.DLL",fake);
        //system("start explorer.exe");
#endif // TRANSFORMERS

}
long Funcs::currentDate() {
    time_t     now = time(0);
    char       buf[80];
    long seconds ;
    struct tm y2k;
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    time(&now);  /* get current time; same as: timer = time(NULL)  */
    seconds = difftime(now,mktime(&y2k));
    return seconds/86400;
}
long currentDates() {
    time_t     now = time(0);
    char       buf[80];
    long seconds ;
    struct tm y2k;
    y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
    y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;
    time(&now);  /* get current time; same as: timer = time(NULL)  */
    seconds = difftime(now,mktime(&y2k));
    return seconds/86400;
}
void Funcs:: manual_reg(int code)
{
if (registration!=1)
{
    days=currentDate();
   HKEY softwareKey;
	HKEY thisKey;
	HKEY schemeKey;
	DWORD dwKeyValue;
	DWORD dwKeyType;
	DWORD dwKeyValueSize;
	char cKeyValue[1024];
dwKeyValue = 1024;

	if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return;
	#ifdef D_FORCE
	if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef TEKKEN
    if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return;
    #endif // TEKKEN
    #ifdef U_GROUND
    if (RegCreateKey(softwareKey,"Uground", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef NINJA
    if (RegCreateKey(softwareKey,"NINJA", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef TOMB-R
    if (RegCreateKey(softwareKey,"TombR", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef HITMAN
    if (RegCreateKey(softwareKey,"Hitman", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef CONTRACTS
    if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef NFSEN
    if (RegCreateKey(softwareKey,"NFSEN", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef IGI
    if (RegCreateKey(softwareKey,"IGI", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef GTA_VC
    if (RegCreateKey(softwareKey,"GTA_VC", &thisKey) != ERROR_SUCCESS) return;
    #endif // GTA_VC
    #ifdef MOSTWTD
    if (RegCreateKey(softwareKey,"MOST_WTD", &thisKey) != ERROR_SUCCESS) return;
    #endif // GTA_VC

    #ifdef CALL_DUTY
    if (RegCreateKey(softwareKey,"CALL_DUTY", &thisKey) != ERROR_SUCCESS) return;
    #endif // GTA_VC
    #ifdef DESERT_STORM
    if (RegCreateKey(softwareKey,"DESERT_STORM", &thisKey) != ERROR_SUCCESS) return;
    #endif // DESERT_STORM
    #ifdef MAX_PAYNE
    if (RegCreateKey(softwareKey,"MAX_PAYNE", &thisKey) != ERROR_SUCCESS) return;
    #endif // MAX_PAYNE
    #ifdef TRANSFORMERS
    if (RegCreateKey(softwareKey,"TRANSFORMERS", &thisKey) != ERROR_SUCCESS) return;
    #endif // TRANSFORMERS
    #ifdef FREEDOM
    if (RegCreateKey(softwareKey,"FREEDOM", &thisKey) != ERROR_SUCCESS) return;
    #endif // TRANSFORMERS


    if (code==10)
    {
    dwKeyValue = 728764768;
	RegSetValueEx(thisKey, "Reg_stat",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
	//cout<<"Your have been registered for full version successfully!\n";
	//cout<<"Please close and start the game or application again.\n";
    }
    else if(code==20)
    {

      //  cout<<"Your have been registered for 10 day trial version successfully!\n";
      //  cout<<"Please close and start the game or application again.\n";

        first_run_date=days;
        expire_date=first_run_date+10;

        dwKeyValue=expire_date;
        RegSetValueEx(thisKey, "expire_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);


        dwKeyValue=days;
        RegSetValueEx(thisKey, "first_run_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
    }

	RegCloseKey(softwareKey);
//    Stealth(1);
    //exit(1);

}
else
    ;//already_registered();
}
void Funcs::LoadVars()
{
    days=currentDate();
	HKEY softwareKey;
	HKEY thisKey;
	HKEY schemeKey;

	if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return;
	#ifdef D_FORCE
	if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return;
    #endif
 	#ifdef TEKKEN
	if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef U_GROUND
    if (RegCreateKey(softwareKey,"Uground", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef NINJA
    if (RegCreateKey(softwareKey,"NINJA", &thisKey) != ERROR_SUCCESS) return;
    #endif

    #ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef TOMB-R
    if (RegCreateKey(softwareKey,"TombR", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef HITMAN
    if (RegCreateKey(softwareKey,"Hitman", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef CONTRACTS
    if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef NFSEN
    if (RegCreateKey(softwareKey,"NFSEN", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef IGI
    if (RegCreateKey(softwareKey,"IGI", &thisKey) != ERROR_SUCCESS) return;
    #endif.
    #ifdef GTA_VC
    if (RegCreateKey(softwareKey,"GTA_VC", &thisKey) != ERROR_SUCCESS) return;
    #endif // GTA_VC
    #ifdef  MOSTWTD
    if (RegCreateKey(softwareKey,"MOST_WTD", &thisKey) != ERROR_SUCCESS) return;
    #endif // GTA_VC
    #ifdef  CALL_DUTY
    if (RegCreateKey(softwareKey,"CALL_DUTY", &thisKey) != ERROR_SUCCESS) return;
    #endif // GTA_VC
    #ifdef  DESERT_STORM
    if (RegCreateKey(softwareKey,"DESERT_STORM", &thisKey) != ERROR_SUCCESS) return;
    #endif // DESERT_STORM
    #ifdef  MAX_PAYNE
    if (RegCreateKey(softwareKey,"MAX_PAYNE", &thisKey) != ERROR_SUCCESS) return;
    #endif // MAX_PAYNE
     #ifdef  TRANSFORMERS
    if (RegCreateKey(softwareKey,"TRANSFORMERS", &thisKey) != ERROR_SUCCESS) return;
    #endif // TRANSFORMERS
     #ifdef  FREEDOM
    if (RegCreateKey(softwareKey,"FREEDOM", &thisKey) != ERROR_SUCCESS) return;
    #endif // TRANSFORMERS


	DWORD dwKeyValue;
	DWORD dwKeyType;
	DWORD dwKeyValueSize;
	char cKeyValue[1024];


	//*********************************
	//load all the user-defined schemes
	//*********************************

		FILETIME lasttime;
		dwKeyValue = 1024;

	//dwKeyValue = 728764768;
	//RegSetValueEx(thisKey, "Reg_stat",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);


	dwKeyValueSize = 4;
	if (RegQueryValueEx(thisKey, "Reg_stat",0,&dwKeyType, (unsigned char *)&dwKeyValue, &dwKeyValueSize)==ERROR_SUCCESS)
		if (dwKeyValue==728764768)
            {
                //cout<<"You are registered for full version\n";
                registration=1;
            }
    if (RegQueryValueEx(thisKey, "first_run_date",0,&dwKeyType, (unsigned char *)&dwKeyValue, &dwKeyValueSize)==ERROR_SUCCESS)
		first_run_date=dwKeyValue;

    if (RegQueryValueEx(thisKey, "expire_date",0,&dwKeyType, (unsigned char *)&dwKeyValue, &dwKeyValueSize)==ERROR_SUCCESS)
		expire_date=dwKeyValue;

if(registration!=1)
{

    if(first_run_date==0)
        {
            first_run_date=days;
            expire_date=first_run_date+3;
        dwKeyValue = 1024;

        if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return;
 #ifdef D_FORCE
        if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return ;
 #endif
#ifdef TEKKEN
        if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef U_GROUND
        if (RegCreateKey(softwareKey,"Uground", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef NINJA
        if (RegCreateKey(softwareKey,"NINJA", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef TOMB-R
if (RegCreateKey(softwareKey,"TombR", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef HITMAN
if (RegCreateKey(softwareKey,"Hitman", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef CONTRACTS
if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef NFSEN
 if (RegCreateKey(softwareKey,"NFSEN", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef IGI
if (RegCreateKey(softwareKey,"IGI", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef GTA_VC
 if (RegCreateKey(softwareKey,"GTA_VC", &thisKey) != ERROR_SUCCESS) return;
#endif // GTA_VC
#ifdef MOSTWTD
 if (RegCreateKey(softwareKey,"MOST_WTD", &thisKey) != ERROR_SUCCESS) return;
#endif // MOST_WTD
#ifdef CALL_DUTY
 if (RegCreateKey(softwareKey,"CALL_DUTY", &thisKey) != ERROR_SUCCESS) return;
#endif // CALL_DUTY
#ifdef DESERT_STORM
 if (RegCreateKey(softwareKey,"DESERT_STORM", &thisKey) != ERROR_SUCCESS) return;
#endif // DESERT_STORM
#ifdef MAX_PAYNE

 if (RegCreateKey(softwareKey,"MAX_PAYNE", &thisKey) != ERROR_SUCCESS) return;
#endif // MAX_PAYNE
#ifdef TRANSFORMERS
 if (RegCreateKey(softwareKey,"TRANSFORMERS", &thisKey) != ERROR_SUCCESS) return;
#endif // TRANSFORMERS
#ifdef FREEDOM
 if (RegCreateKey(softwareKey,"FREEDOM", &thisKey) != ERROR_SUCCESS) return;
#endif // TRANSFORMERS

        dwKeyValue=expire_date;
        RegSetValueEx(thisKey, "expire_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);


        dwKeyValue=days;
        RegSetValueEx(thisKey, "first_run_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
            //store this values in reg
        }
        days_remaining=expire_date-days;

		RegCloseKey(softwareKey);
    }
}
void Three_day(void *param)
{
days=currentDates();

    HWND stealth; /*creating stealth (window is not visible)*/
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    //ShowWindow(stealth,1);
       // printf("Thanks for using this software from ken \n");
       // printf("Visit http://digital-mine.blogspot.com/");
        //printf(" For more information. \n\n");
        //Retrieve  the values from registry first
   DWORD dwKeyValue;
	DWORD dwKeyType;
	DWORD dwKeyValueSize;
	char cKeyValue[1024];
	dwKeyValue = 1024;
	HKEY softwareKey;
	HKEY thisKey;
	HKEY schemeKey;

        if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return;
 #ifdef D_FORCE
        if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return ;
 #endif
#ifdef TEKKEN
        if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef U_GROUND
        if (RegCreateKey(softwareKey,"Uground", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef NINJA
        if (RegCreateKey(softwareKey,"NINJA", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef TOMB-R
if (RegCreateKey(softwareKey,"TombR", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef HITMAN
if (RegCreateKey(softwareKey,"Hitman", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef CONTRACTS
if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef NFSEN
 if (RegCreateKey(softwareKey,"NFSEN", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef IGI
if (RegCreateKey(softwareKey,"IGI", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef GTA_VC
if (RegCreateKey(softwareKey,"GTA_VC", &thisKey) != ERROR_SUCCESS) return;
#endif // GTA_VC
#ifdef MOSTWTD
if (RegCreateKey(softwareKey,"MOST_WTD", &thisKey) != ERROR_SUCCESS) return;
#endif // GTA_VC
#ifdef CALL_DUTY
if (RegCreateKey(softwareKey,"CALL_DUTY", &thisKey) != ERROR_SUCCESS) return;
#endif // CALL_DUTY

#ifdef DESERT_STORM
if (RegCreateKey(softwareKey,"DESERT_STORM", &thisKey) != ERROR_SUCCESS) return;
#endif // DESERT_STORM
#ifdef MAX_PAYNE
if (RegCreateKey(softwareKey,"MAX_PAYNE", &thisKey) != ERROR_SUCCESS) return;
#endif // MAX_PAYNE
#ifdef TRANSFORMERS
if (RegCreateKey(softwareKey,"TRANSFORMERS", &thisKey) != ERROR_SUCCESS) return;
#endif // TRANSFORMERS
#ifdef FREEDOM
if (RegCreateKey(softwareKey,"FREEDOM", &thisKey) != ERROR_SUCCESS) return;
#endif // TRANSFORMERS

	dwKeyValueSize = 4;
	if (RegQueryValueEx(thisKey, "Reg_stat",0,&dwKeyType, (unsigned char *)&dwKeyValue, &dwKeyValueSize)==ERROR_SUCCESS)
		if (dwKeyValue==728764768)
            {
                //cout<<"You are registered for full version\n";
                registration=1;
            }
    if (RegQueryValueEx(thisKey, "first_run_date",0,&dwKeyType, (unsigned char *)&dwKeyValue, &dwKeyValueSize)==ERROR_SUCCESS)
		first_run_date=dwKeyValue;

    if (RegQueryValueEx(thisKey, "expire_date",0,&dwKeyType, (unsigned char *)&dwKeyValue, &dwKeyValueSize)==ERROR_SUCCESS)
		expire_date=dwKeyValue;
        ShowWindow(stealth,0);
       // Sleep(2000);

    //ShowWindow(stealth,1);
    if(first_run_date==0)
        {

            first_run_date=days;
            expire_date=first_run_date+3;
        dwKeyValue = 1024;

       RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey);
 #ifdef D_FORCE
        RegCreateKey(softwareKey,"Dforce", &thisKey);
 #endif
#ifdef TEKKEN
      RegCreateKey(softwareKey,"Tekken", &thisKey);
#endif
#ifdef U_GROUND
      RegCreateKey(softwareKey,"Uground", &thisKey) ;
 #endif // U_GROUND

#ifdef NINJA
    RegCreateKey(softwareKey,"NINJA", &thisKey);
#endif
#ifdef METAL
    RegCreateKey(softwareKey,"Metal", &thisKey);
#endif
#ifdef TOMB-R
    RegCreateKey(softwareKey,"TombR", &thisKey);
#endif
#ifdef HITMAN
    RegCreateKey(softwareKey,"Hitman", &thisKey);
#endif
#ifdef HITMANC
    RegCreateKey(softwareKey,"HitmanC", &thisKey);
#endif
#ifdef NFSEN
   RegCreateKey(softwareKey,"NFSEN", &thisKey) ;
#endif
#ifdef GTA_VC
    RegCreateKey(softwareKey,"GTA_VC", &thisKey);
#endif // GTA_VC
#ifdef MOSTWTD
    RegCreateKey(softwareKey,"MOST_WTD", &thisKey);
#endif // MOSTWTD
#ifdef CALL_DUTY
    RegCreateKey(softwareKey,"CALL_DUTY", &thisKey);
#endif // CALL_DUTY
#ifdef DESERT_STORM
    RegCreateKey(softwareKey,"DESERT_STORM", &thisKey);
#endif // CALL_DUTY
#ifdef MAX_PAYNE
    RegCreateKey(softwareKey,"MAX_PAYNE", &thisKey);
#endif // MAX_PAYNE
#ifdef TRANSFORMERS
    RegCreateKey(softwareKey,"TRANSFORMERS", &thisKey);
#endif // MAX_PAYNE
#ifdef FREEDOM
    RegCreateKey(softwareKey,"FREEDOM", &thisKey);
#endif // MAX_PAYNE
        dwKeyValue=expire_date;
        RegSetValueEx(thisKey, "expire_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);


        dwKeyValue=days;
        RegSetValueEx(thisKey, "first_run_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
            //store this values in reg
        }
        days_remaining=expire_date-days;
    if (days_remaining>=1)
        {

            //printf ("Software Registration status :%.f days remaining\n\n", days_remaining);
            //HIDE THE FILE
           // printf ("Software registration status:Software expired.\n\n");
            int code;
            //ShowWindow(stealth,1);
        }
}
