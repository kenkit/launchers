#ifndef FUNCS_H
#define FUNCS_H
#include "fstream"

void Three_day(void *param);
void launch_app(void);
void write_file(char*filename,char* data);

class Funcs
{


public:
    long currentDate();
    int Date_To_Int(void);
    void LoadVars();


    void launch_app();
    int registration;
    int k;
    void manual_reg(int code);
    double seconds,first_run_date,expire_date,days_remaining,days;

};

#endif // FUNCS_H
