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
  	char str[1000];

    sprintf(str, "                  %d-%d-%d \n\n    Today is the %dth day of year %d \n \n    Psycological climax index: %.2f \n    Emotional    climax index:  %.2f \n    Intellectual climax index:   %.2f \n \n    Next psycological climax: %d-%d-%d \n    Next emotionaly climax:   %d-%d-%d \n    Next intellectual climax:   %d-%d-%d \n", today.year, today.month, today.day, numDay, today.year, star_index[0], star_index[1], star_index[2], psy_date.year, psy_date.month, psy_date.day, emo_date.year, emo_date.month, emo_date.day, int_date.year, int_date.month, int_date.day);
    

    // GUI part by gtk-3.0
    GtkWidget *window;
    GtkWidget *vbox;

    GtkWidget *output;

    gtk_init(&argc, &argv);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 300);
    gtk_window_set_title(GTK_WINDOW(window), "Output of HaveFun");
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);

    vbox = gtk_box_new(TRUE, 1);
    gtk_container_add(GTK_CONTAINER(window), vbox);

    output = gtk_button_new_with_label(str);

  	gtk_box_pack_start(GTK_BOX(vbox), output, TRUE, TRUE, 0);

  	g_signal_connect(G_OBJECT(window), "destroy", G_CALLBACK(gtk_main_quit), G_OBJECT(window));

  	gtk_widget_show_all(window);

  	gtk_main();

    return 0;

}

