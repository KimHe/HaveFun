#include <stdio.h>
#include <math.h>
#include <time.h>
#include <gtk/gtk.h>

// define a struct of date which contains year month and day
struct date {
    int year;
    int month;
    int day;
};

// subroutine for generating performance index JD
double GRE2JULE(struct date input)
{
    double JD;
    double temp[3];

    temp[0] = 1461 * (input.year + 4800 + (input.month - 14) / 12) /4;
    temp[1] = 367 * (input.month - 2 - ((input.month - 14) / 12) * 12) / 12;
    temp[2] = 3 * (input.year + 4900 + (input.month - 14) / 12) / 100 / 4;
    JD = input.day - 32075 + temp[0] + temp[1] - temp[2] - 0.500;

    return JD;
}

// sobroutine for predicting next climax date
struct date JULE2GRE(int input)
{
    int J, N, L1, Y1, L2, M1, L3;
    struct date temp;

    J = (int)(input + 0.500);
    N = 4 * (J + 68569) / 146097;
    L1 = J + 68569 - (N * 146097 + 3) / 4;
    Y1 = 4000 * (L1 + 1) / 1461001;
    L2 = L1 - 1461 * Y1 / 4 + 31;
    M1 = 80 * L2 / 2447;
    temp.day = L2 - 2447 * M1 / 80;
    L3 = M1 / 11;
    temp.month = M1 + 2 - 12 * L3;
    temp.year = 100 * (N - 49) + Y1 + L3;

    return temp;
}


// the main function
int main(int argc, char *argv[])
{
    struct date today, birth;
    struct date psy_date, emo_date, int_date;

    int i, j, k, sum=0, numDay, spanInt, todayInt, next_index[3];
    int months[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int periodic[3] = {23, 28, 33};

    double span, star_index[3];
    double const TWOPI = 6.2831853071795864;

    // get the date struct, tm
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);

    today.day    = tm.tm_mday;
    today.month  = tm.tm_mon + 1;
    today.year   = tm.tm_year + 1900;
    // put your birthday information here
    birth.day    = 11; 
    birth.month  = 8;
    birth.year   = 1988;

    // calculate the day number in one year
    if (today.year % 4 == 0){
        months[1] = 29;
    }

    for (i = 0; i < today.month-1; i++){
        sum += months[i];
    }

    numDay = sum + today.day;

    // compute the today's index with respect to psycology, emotion, and intellegence
    span = GRE2JULE(today) - GRE2JULE(birth);
    
    for (j = 0; j < 3; j++){
        star_index[j] = 5.00 * sin(TWOPI * span / periodic[j]) + 5.00;
    }

    spanInt = (int)span; todayInt = (int)GRE2JULE(today);

    for (k = 0; k < 3; k++){
        next_index[k] = periodic[k] - (spanInt + periodic[k] * 3 / 4) % periodic[k] + todayInt + 1;
    }

    // compute the date of next climax with respect to psy, emo, and int
    psy_date = JULE2GRE(next_index[0]);
    emo_date = JULE2GRE(next_index[1]);
    int_date = JULE2GRE(next_index[2]);

    // print the results    
  	char str_date[1000], str_dayNum[1000], str_psy[1000], str_emo[1000];
  	char str_int[1000], str_Npsy[1000], str_Nint[1000], str_Nemo[1000];

    sprintf(str_date, "%d-%d-%d \n", today.year, today.month, today.day);
    sprintf(str_dayNum, "Today is the %dth day of year %d \n", numDay, today.year);
    sprintf(str_psy, "%.2f", star_index[0]);
    sprintf(str_emo, "%.2f", star_index[1]);
    sprintf(str_int, "%.2f", star_index[2]);
    sprintf(str_Npsy, "%d-%d-%d", psy_date.year, psy_date.month, psy_date.day);
    sprintf(str_Nemo, "%d-%d-%d", emo_date.year, emo_date.month, emo_date.day);
    sprintf(str_Nint, "%d-%d-%d", int_date.year, int_date.month, int_date.day);


    // GUI part by gtk-3.0
    GtkWidget *window;
    GtkWidget *button;
    GtkWidget *grid;
    GtkWidget *child00;
    GtkWidget *child01;
    GtkWidget *child1;
    GtkWidget *child2;
    GtkWidget *child3;
    GtkWidget *child4;
    GtkWidget *child5;
    GtkWidget *child6;


    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_window_set_title(GTK_WINDOW(window), "Output of HaveFun");
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);


/* ------------------------------------------------------*/
    grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(window), grid);

    child00 = gtk_label_new(str_date);
    gtk_grid_attach(GTK_GRID(grid), child00, 2, 0, 2, 2);


    child01 = gtk_label_new(str_dayNum);
    gtk_grid_attach(GTK_GRID(grid), child01, 2, 2, 2, 1);


    child1 = gtk_label_new("  Psycological climax index: \n");
    gtk_grid_attach(GTK_GRID(grid), child1, 0, 4, 4, 2);

    button = gtk_button_new_with_label(str_psy);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 4, 1, 1);
    gtk_widget_show(button);


    child2 = gtk_label_new("Emotional climax index:   \n");
    gtk_grid_attach(GTK_GRID(grid), child2, 0, 6, 4, 2);

    button = gtk_button_new_with_label(str_emo);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 6, 1, 1);
    gtk_widget_show(button);


    child3 = gtk_label_new("Intellectual climax index:  \n");
    gtk_grid_attach(GTK_GRID(grid), child3, 0, 8, 4, 2);

    button = gtk_button_new_with_label(str_int);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 8, 1, 1);
    gtk_widget_show(button);


    child4 = gtk_label_new("Next psycological climax:  \n");
    gtk_grid_attach(GTK_GRID(grid), child4, 0, 12, 4, 2);

    button = gtk_button_new_with_label(str_Npsy);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 12, 1, 1);
    gtk_widget_show(button);


    child5 = gtk_label_new("Next emotional climax:   \n");
    gtk_grid_attach(GTK_GRID(grid), child5, 0, 14, 4, 2);

    button = gtk_button_new_with_label(str_Nemo);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 14, 1, 1);
    gtk_widget_show(button);


    child6 = gtk_label_new("Next intellectual climax:  \n");
    gtk_grid_attach(GTK_GRID(grid), child6, 0, 16, 4, 2);

    button = gtk_button_new_with_label(str_Nint);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 16, 1, 1);
    gtk_widget_show(button);


    gtk_widget_show(button);
    gtk_widget_show_all(window);

    gtk_main();

    return 0;

}

