#include <gtk/gtk.h>
#include "defs.h"

void gui(struct string s)
{

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


    gtk_init(0, NULL);

    window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_position(GTK_WINDOW(window), GTK_WIN_POS_CENTER);
    gtk_window_set_default_size(GTK_WINDOW(window), 500, 300);
    gtk_window_set_title(GTK_WINDOW(window), "Output of HaveFun");
    gtk_container_set_border_width(GTK_CONTAINER(window), 5);


    grid = gtk_grid_new();

    gtk_container_add(GTK_CONTAINER(window), grid);

    child00 = gtk_label_new(s.str_date);
    gtk_grid_attach(GTK_GRID(grid), child00, 2, 0, 2, 2);


    child01 = gtk_label_new(s.str_dayNum);
    gtk_grid_attach(GTK_GRID(grid), child01, 2, 2, 2, 1);


    child1 = gtk_label_new(" Physiologic index today:  \n");
    gtk_grid_attach(GTK_GRID(grid), child1, 0, 4, 4, 2);

    button = gtk_button_new_with_label(s.str_psy);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 4, 1, 1);
    gtk_widget_show(button);


    child2 = gtk_label_new("Psychologic index today:  \n");
    gtk_grid_attach(GTK_GRID(grid), child2, 0, 6, 4, 2);

    button = gtk_button_new_with_label(s.str_emo);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 6, 1, 1);
    gtk_widget_show(button);


    child3 = gtk_label_new("Intelligent index today:  \n");
    gtk_grid_attach(GTK_GRID(grid), child3, 0, 8, 4, 2);

    button = gtk_button_new_with_label(s.str_int);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 8, 1, 1);
    gtk_widget_show(button);


    child4 = gtk_label_new("Next physiologic climax:  \n");
    gtk_grid_attach(GTK_GRID(grid), child4, 0, 12, 4, 2);

    button = gtk_button_new_with_label(s.str_Npsy);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 12, 1, 1);
    gtk_widget_show(button);


    child5 = gtk_label_new("Next psychologic climax:  \n");
    gtk_grid_attach(GTK_GRID(grid), child5, 0, 14, 4, 2);

    button = gtk_button_new_with_label(s.str_Nemo);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 14, 1, 1);
    gtk_widget_show(button);


    child6 = gtk_label_new("Next intelligent climax:  \n");
    gtk_grid_attach(GTK_GRID(grid), child6, 0, 16, 4, 2);

    button = gtk_button_new_with_label(s.str_Nint);
    gtk_grid_attach(GTK_GRID(grid), button, 4, 16, 1, 1);
    gtk_widget_show(button);


    gtk_widget_show(button);
    gtk_widget_show_all(window);

    gtk_main();

}
