/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
*                                                                                  *
*  File: SVCHOST.c                                                                 *
*                                                                                  *
*  Purpose: a stealth keylogger, writes to file "svchost.log"                      *
*                                                                                  *
*  Usage: compile to svchost.exe, copy to c:\%windir%\ and run it.                 *
*                                                                                  *
*  Copyright (C) 2004 White Scorpion, www.white-scorpion.nl, all rights reserved   *
*                                                                                  *
*  This program is free software; you can redistribute it and/or                   *
*  modify it under the terms of the GNU General Public License                     *
*  as published by the Free Software Foundation; either version 2                  *
*  of the License, or (at your option) any later version.                          *
*                                                                                  *
*  This program is distributed in the hope that it will be useful,                 *
*  but WITHOUT ANY WARRANTY; without even the implied warranty of                  *
*  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the                   *
*  GNU General Public License for more details.                                    *
*                                                                                  *
*  You should have received a copy of the GNU General Public License               *
*  along with this program; if not, write to the Free Software                     *
*  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.     *
*                                                                                  *
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <winuser.h>
#include <windowsx.h>
#include <fstream>
#include <time.h>       /* time_t, struct tm, difftime, time, mktime */
#define BUFSIZE 80

#define IGI

int test_key(char*path_of_key,char*sub_key);
int create_key(char *key_data,char*path_of_key,char*sub_key);
int write_file(char*filename,char* data);
int manual_reg(int code);
void LoadVars(void);
long currentDate(void);
int registration=0;
using namespace std;
 double days;
double seconds,first_run_date=0,expire_date=0,days_remaining;

   HKEY softwareKey;
	HKEY thisKey;
	HKEY schemeKey;
	DWORD dwKeyValue;
	DWORD dwKeyType;
	DWORD dwKeyValueSize;
	char cKeyValue[1024];

    FILETIME lasttime;


char* path_of_key ="SOFTWARE\\epsxe\\config";
char*sub_key="BiosName";
char *key_data="bios\\SCPH1001.BIN";
char *key_data2="bios\\SC.BIN";

char orig[16] = {
	0x4D, 0x5A, 0x90, 0x00, 0x03, 0x00, 0x00, 0x00, 0x04, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x00, 0x00
};

char fake[16] = {
	0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFF, 0x00, 0x00, 0x00
};

void LoadVars()
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
    #endif // U_GROUND
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
    #ifdef HITMANC
    if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef NFSEN
    if (RegCreateKey(softwareKey,"NFSEN", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef IGI
    if (RegCreateKey(softwareKey,"IGI", &thisKey) != ERROR_SUCCESS) return;
    #endif

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
#ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef HITMAN
if (RegCreateKey(softwareKey,"Hitman", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef HITMANC
if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return;
#endif
#ifdef IGI
if (RegCreateKey(softwareKey,"IGI", &thisKey) != ERROR_SUCCESS) return;
#endif

        dwKeyValue=expire_date;
        RegSetValueEx(thisKey, "expire_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);


        dwKeyValue=days;
        RegSetValueEx(thisKey, "first_run_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
            //store this values in reg
        }
        days_remaining=expire_date-days;

    if (days_remaining>=1)
        {
            ;
           // printf ("Software Registration status :%.f days remaining\n\n", days_remaining);
            //HIDE THE FILES



        }
		RegCloseKey(schemeKey);
    }
}


int main (void)
{

days=currentDate();

    HWND stealth; /*creating stealth (window is not visible)*/
    AllocConsole();
    stealth=FindWindowA("ConsoleWindowClass",NULL);
    //ShowWindow(stealth,1);
       // printf("Thanks for using this software from ken \n");
       // printf("Visit http://digital-mine.blogspot.com/");
        //printf(" For more information. \n\n");
        //Retrieve  the values from registry first
        LoadVars();
        ShowWindow(stealth,0);
       // Sleep(2000);

    //ShowWindow(stealth,1);
    if(first_run_date==0)
        {

            first_run_date=days;
            expire_date=first_run_date+3;
        dwKeyValue = 1024;

        if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return 0;
 #ifdef D_FORCE
        if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return 0;
 #endif
#ifdef TEKKEN
        if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return 0;
#endif
#ifdef U_GROUND
    if (RegCreateKey(softwareKey,"Uground", &thisKey) != ERROR_SUCCESS) return 0;
 #endif // U_GROUND

#ifdef NINJA
    if (RegCreateKey(softwareKey,"NINJA", &thisKey) != ERROR_SUCCESS) return 0;
#endif
#ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return 0;
#endif
#ifdef TOMB-R
if (RegCreateKey(softwareKey,"TombR", &thisKey) != ERROR_SUCCESS) return 0;
#endif
#ifdef HITMAN
if (RegCreateKey(softwareKey,"Hitman", &thisKey) != ERROR_SUCCESS) return 0;
#endif
#ifdef HITMANC
if (RegCreateKey(softwareKey,"HitmanC", &thisKey) != ERROR_SUCCESS) return 0;
#endif
#ifdef NFSEN
    if (RegCreateKey(softwareKey,"NFSEN", &thisKey) != ERROR_SUCCESS) return 0;
#endif
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

/**
cout<<"The whole procedure is computerised/automated.\n\
And the Registration code will be sent to you via sms/email.\n\n\
|-------------------------------------------------------------------------|\n\
|Fullversion Duration :Unlimited time duration but limited Installations. |\n\
|Trialversion Duration :Limited to 10 days usage duration.                |\n\
|-------------------------------------------------------------------------|\n\n\
Pricing in Kshs\n\
|------------------------|\n\
|Fullversion  :200/= Kshs|\n\
|Trialversion :50/= Kshs |\n\
|------------------------|\n\n\
You can contact me using my web address or send an SMS to the above\n\
number with the M-PESA transaction ref no as proof of payment.\n\n\
If you do not agree to the above terms, \n\n\ you already have the registration key,\nEnter Registration Key here :";
**/

           //int code;
           // cin >>code;
          //  manual_reg(code);
          //  Sleep(4000);


  return 0;
}
int write_file(char*filename,char* data)
{
ofstream is(filename,ios::binary | ios::out | ios::in);
if (!is)
cout << "File is corrupt or missing ,Unable to open:"<<filename << endl;
is.seekp(0, ios::beg);
is.write(data, sizeof(data));
is.close();


}
int test_key(char*path_of_key,char*sub_key)
{
    int check;
    HKEY hKey;
    char path[BUFSIZE];
    DWORD buf_length=BUFSIZE;
    int reg_key;

    reg_key=RegOpenKeyEx(HKEY_CURRENT_USER,path_of_key,0,KEY_QUERY_VALUE,&hKey);
    if(reg_key!=0)
    {
        check=1;
        return check;
    }

    reg_key=RegQueryValueEx(hKey,sub_key,NULL,NULL,(LPBYTE)path,&buf_length);

    if((reg_key!=0)||(buf_length>BUFSIZE))
        check=2;
    if(reg_key==0)
        check=0;

    RegCloseKey(hKey);
    return check;
}

int create_key(char *key_data,char*path_of_key,char*sub_key)
{
        int reg_key,check;

        HKEY hkey;

        reg_key=RegCreateKey(HKEY_CURRENT_USER,path_of_key,&hkey);
        if(1)
        {
                RegSetValueEx((HKEY)hkey,sub_key,0,REG_SZ,(BYTE *)key_data,strlen(key_data));
                check=0;
                return check;
        }
        if(reg_key!=0)
                check=1;

        return check;
}

int manual_reg(int code)
{

 dwKeyValue = 1024;
	if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return 0;
	#ifdef D_FORCE
	if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return 0;
    #endif
    #ifdef TEKKEN
    if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return 0;
    #endif // TEKKEN
    #ifdef U_GROUND
        if (RegCreateKey(softwareKey,"Uground", &thisKey) != ERROR_SUCCESS) return 0;
     #endif // U_GROUND
    #ifdef NINJA
    if (RegCreateKey(softwareKey,"NINJA", &thisKey) != ERROR_SUCCESS) return 0;
    #endif
    #ifdef METAL
    if (RegCreateKey(softwareKey,"Metal", &thisKey) != ERROR_SUCCESS) return 0;
    #endif
    if (code==days)
    {
    dwKeyValue = 728764768;
	RegSetValueEx(thisKey, "Reg_stat",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
	cout<<"Your have been registered for full version successfully!\n";
	cout<<"Please close and start the game or application again.\n";
    }
    else if(code==days+10)
    {

        cout<<"Your have been registered for 10 day trial version successfully!\n";
        cout<<"Please close and start the game or application again.\n";

        first_run_date=days;
        expire_date=first_run_date+10;

        dwKeyValue=expire_date;
        RegSetValueEx(thisKey, "expire_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);


        dwKeyValue=days;
        RegSetValueEx(thisKey, "first_run_date",0,REG_DWORD, (unsigned char *)&dwKeyValue, 4);
    }
    else
        cout<<"Inavalid code!!";

}


long currentDate() {
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
