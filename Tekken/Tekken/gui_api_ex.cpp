// The contents of this file are in the public domain. See LICENSE_FOR_EXAMPLE_PROGRAMS.txt
/*

    This is an example illustrating the use of the gui api from the dlib C++ Library.


    This is a pretty simple example.  It makes a window with a user
    defined widget (a draggable colored box) and a button.  You can drag the
    box around or click the button which increments a counter.
*/


#include <dlib/all/source.cpp>
#include <dlib/gui_widgets.h>
#include <sstream>
#include <string>
#include <dlib/image_io.h>
#include <dlib/image_transforms.h>
#include <fstream>
#include <iostream>
#include <winuser.h>
#include <windowsx.h>
#define TEKKEN
using namespace std;
using namespace dlib;
void Stealth(int x)
{
    //logStealth<< LINFO << "Started";
    //logStealth<<LINFO << "Switching the display mode";
        HWND Stealth;
        AllocConsole();
        Stealth = FindWindowA("ConsoleWindowClass", NULL);
        ShowWindow(Stealth,x);/*show console app 1*/
        if (x==1)
           ;// logStealth<< LDEBUG<<"The Display mode is On";
        else
            ;
    //logStealth<< LDEBUG<<"The Display mode is Of";
}

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

int write_file(char*filename,char* data);
int manual_reg(void);
int launch_app(void);


   HKEY softwareKey;
	HKEY thisKey;
	HKEY schemeKey;
	DWORD dwKeyValue;
	DWORD dwKeyType;
	DWORD dwKeyValueSize;
	char cKeyValue[1024];

//  ----------------------------------------------------------------------------

class color_box : public draggable
{
    /*
        Here I am defining a custom drawable widget that is a colored box that
        you can drag around on the screen.  draggable is a special kind of drawable
        object that, as the name implies, is draggable by the user via the mouse.
        To make my color_box draggable all I need to do is inherit from draggable.
    */
    unsigned char red, green,blue;

public:
    color_box (
        drawable_window& w,
        rectangle area,
        unsigned char red_,
        unsigned char green_,
        unsigned char blue_
    ) :
        draggable(w),
        red(red_),
        green(green_),
        blue(blue_)
    {
        rect = area;
        set_draggable_area(rectangle(10,10,400,400));

        // Whenever you make your own drawable widget (or inherit from any drawable widget
        // or interface such as draggable) you have to remember to call this function to
        // enable the events.  The idea here is that you can perform whatever setup you
        // need to do to get your object into a valid state without needing to worry about
        // event handlers triggering before you are ready.
        enable_events();
    }

    ~color_box (
    )
    {
        // Disable all further events for this drawable object.  We have to do this
        // because we don't want any events (like draw()) coming to this object while or
        // after it has been destructed.
        disable_events();

        // Tell the parent window to redraw its area that previously contained this
        // drawable object.
        parent.invalidate_rectangle(rect);
    }

private:

    void draw (
        const canvas& c
    ) const
    {
        // The canvas is an object that represents a part of the parent window
        // that needs to be redrawn.

        // The first thing I usually do is check if the draw call is for part
        // of the window that overlaps with my widget.  We don't have to do this
        // but it is usually good to do as a speed hack.  Also, the reason
        // I don't have it set to only give you draw calls when it does indeed
        // overlap is because you might want to do some drawing outside of your
        // widget's rectangle.  But usually you don't want to do that :)
        rectangle area = c.intersect(rect);
        if (area.is_empty() == true)
            return;

        // This simple widget is just going to draw a box on the screen.
        fill_rect(c,rect,rgb_pixel(red,green,blue));
    }
};

//  ----------------------------------------------------------------------------

class win : public drawable_window
{
    /*
        Here I am going to define our window.  In general, you can define as
        many window types as you like and make as many instances of them as you want.
        In this example I am only making one though.
    */
public:
    win(
    ) : // All widgets take their parent window as an argument to their constructor.
        c(*this),
        b(*this),
        b2(*this),
        b3(*this),
        //cb(*this,rectangle(100,100,200,200),0,0,255), // the color_box will be blue and 101 pixels wide and tall
        mbar(*this)
    {
        // tell our button to put itself at the position (10,60).
        #ifdef D_FORCE
        b.set_pos(155,40);
        #endif
        #ifdef TEKKEN
        b.set_pos(165,40);
        #endif

        #ifdef D_FORCE
        b.set_name("-->Play Delta Force<--");
        #endif

        #ifdef TEKKEN
        b.set_name("-->Play Tekken<--");
        #endif // TEKKEN

        b2.set_pos(160,70);
        b2.set_name("Register Application");

        // lets put the label 5 pixels below the button
        b3.set_pos(185,100);
        b3.set_name("-->Exit<--");

        c.set_pos(0,350);
        rgb_pixel colorss;


        // set which function should get called when the button gets clicked.  In this case we want
        // the on_button_clicked member to be called on *this.
        b.set_click_handler(*this,&win::launch_app);
        b2.set_click_handler(*this,&win::manual_reg);
        b3.set_click_handler(*this,&win::exit_app);
        // Alternatively, if you have a compiler which supports the lambda functions from the
        // new C++ standard then you can use a lambda function instead of telling the click
        // handler to call one of the member functions.  So for example, you could do this
        // instead (uncomment the code if you have C++0x support):
        /*
        b.set_click_handler([&](){
                ++counter;
                ostringstream sout;
                sout << "Counter: " << counter;
                c.set_text(sout.str());
                });
        */
        // In general, all the functions which register events can take either member
        // functions or lambda functions.


        // Lets also make a simple menu bar.
        // First we say how many menus we want in our menu bar.  In this example we only want 1.
        mbar.set_number_of_menus(1);
        // Now we set the name of our menu.  The 'M' means that the M in Menu will be underlined
        // and the user will be able to select it by hitting alt+M
        mbar.set_menu_name(0,"Menu",'M');

        // Now we add some items to the menu.  Note that items in a menu are listed in the
        // order in which they were added.

        // First lets make a menu item that does the same thing as our button does when it is clicked.
        // Again, the 'C' means the C in Click is underlined in the menu.
        // mbar.menu(0).add_menu_item(menu_item_text("Click Button!",*this,&win::on_button_clicked,'C'));
        // lets add a separator (i.e. a horizontal separating line) to the menu
        mbar.menu(0).add_menu_item(menu_item_separator());
        // Now lets make a menu item that calls show_about when the user selects it.
        mbar.menu(0).add_menu_item(menu_item_text("About",*this,&win::show_about,'A'));
        mbar.menu(0).add_menu_item(menu_item_text("Exit",*this,&win::exit_app,'A'));

        // set the size of this window
        set_size(430,380);
        counter = 0;
        #ifdef D_FORCE
        set_title("Delta Force Black Hawk Down");
        #endif

        #ifdef TEKKEN
        set_title("Tekken Play Station Game");
        #endif
        show();
        reg_status();

    }

    ~win(
    )
    {
        // You should always call close_window() in the destructor of window
        // objects to ensure that no events will be sent to this window while
        // it is being destructed.
        close_window();
    }

private:
    void launch_app()
{
        if(registration==1)
        {
         #ifdef D_FORCE
           system("attrib +s +h dfbhd.exe");
            write_file("dfbhd.exe",orig);
            write_file("dfbhdlc.exe",orig);
            write_file("dfbhdmed.exe",orig);

            system("dfbhd.exe");
            printf("Closing application please wait \n");

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
        }

        if (days_remaining>=1)
        {

        #ifdef D_FORCE
           system("attrib +s +h dfbhd.exe");
            write_file("dfbhd.exe",orig);
            write_file("dfbhdlc.exe",orig);
            write_file("dfbhdmed.exe",orig);

            system("dfbhd.exe");
            printf("Closing application please wait \n");

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
        }
        else
            void show_unregisterd();
}
void manual_reg(void)
{
if (registration!=1)
{
    printf ("Software registration status:Software expired.\n\n");
int code;
Stealth(1);
cout<<"If you are seeing this message then you are probably  \n\
using software that was Probably stolen from me,given to you \n\
by me or given to you by somebody who stole it from me, So to\n\
continue using this software, Please Send 100/= Kshs          \n\
Through M-pesa to 0728-764-768\n\
The whole procedure is computerised/automated.\n\
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
If you do not agree to the above terms, \n\n\
PLEASE DELETE THIS SOFTWARE OR WHATEVER OR KEEP IT IF YOU WANT \nIT'S \
ENTIRELY UPTO YOU.\
\n\nIf you already have the registration key,\nEnter Registration Key here :";

cin >>code;
dwKeyValue = 1024;


	if (RegOpenKey(HKEY_CURRENT_USER,"Software", &softwareKey) != ERROR_SUCCESS) return;
	#ifdef D_FORCE
	if (RegCreateKey(softwareKey,"Dforce", &thisKey) != ERROR_SUCCESS) return;
    #endif
    #ifdef TEKKEN
    if (RegCreateKey(softwareKey,"Tekken", &thisKey) != ERROR_SUCCESS) return;
    #endif // TEKKEN


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
        for(int i=3;i<3;i--)
        {
            cout<<"Inavalid code exiting!!";
            cout<<i<<endl;
            sleep(1000);
        }

    Stealth(1);
    exit(1);

}
else
    already_registered();
}
    void reg_status (
    )
    {
        // when someone clicks our button it will increment the counter and
        // display it in our label c.

        ostringstream sout;

        if (days_remaining>=1)
        {
            sout << "Registration status :" << days_remaining<<" Days remaining.\n";

        }
        else if ((days_remaining<1)&&(registration!=1))
            {
            un_registered();
            sout << "Registration Expired\n";
            sout <<"Please Register this application first\n";
            }
        else if (registration==1)
            sout<<"Full version user\n";
            sout<<"More games available at Digital-Mine.blogspot.com\n";

        c.set_text(sout.str());
    }

    void show_about(
    )
    {
        message_box("About","This software was designed and is maintained by Storm.");
    }
    void show_unregisterd(
    )
    {
        message_box("Expired","Please click on the register button for instructions.");
    }
    void exit_app()
    {
        exit(1);
    }
    void un_registered(
    )
    {
        message_box("Expired","!! Failed to launch application due to expired registration.!!");
    }
    void already_registered(
    )
    {
        message_box("Registered","!!You are already registered!!");
    }
    unsigned long counter;
    label c;
    button b,b2,b3;
    //color_box cb;
    menu_bar mbar;
};
int write_file(char*filename,char* data)
{
ofstream is(filename,ios::binary | ios::out | ios::in);
if (!is)
cout << "File is corrupt or missing ,Unable to open:"<<filename << endl;
is.seekp(0, ios::beg);
is.write(data, sizeof(data));
is.close();


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

//  ----------------------------------------------------------------------------

int main()
{
    // create our window

    Stealth(0);


    LoadVars();

    win my_window;



    // wait until the user closes this window before we let the program
    // terminate.
    my_window.wait_until_closed();

    return 0;
}

//  ----------------------------------------------------------------------------

// Normally, if you built this application on MS Windows in Visual Studio you
// would see a black console window pop up when you ran it.  The following
// #pragma directives tell Visual Studio to not include a console window along
// with your application.  However, if you prefer to have the console pop up as
// well then simply remove these #pragma statements.



//  ----------------------------------------------------------------------------

