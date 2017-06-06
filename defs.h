#define LEN 1000
#define TWOPI 6.2831853071795864

// define a struct of date which contains year month and day
struct date {
    int year;
    int month;
    int day;
};

struct string {
    char str_date[LEN];
    char str_dayNum[LEN];
    char str_psy[LEN];
    char str_emo[LEN];
    char str_int[LEN];
    char str_Npsy[LEN];
    char str_Nint[LEN];
    char str_Nemo[LEN];
};

int dayNum();
struct date JULE2GRE();
double GRE2JULE();
struct date getTime();
struct string printStr();
void gui();
