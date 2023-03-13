# include <gtk/gtk.h>
# include <stdlib.h>
# include <string.h>
# include <gdk-pixbuf/gdk-pixbuf.h>

GtkWidget *label1;

static void btnclick(GtkWidget *a, gpointer data)
{
    FILE *w,*r;
    char buffer[65];
    w = fopen("city.csv","w");
    fputs(gtk_entry_get_text(GTK_ENTRY(data)),w);
    fclose(w);
    gtk_entry_set_text(GTK_ENTRY(data),"");
    system("python3 main.py");
    r = fopen("city.csv", "r+");
    fread(buffer,sizeof(char),65,r);
    fclose(r);
    gtk_label_set_text(GTK_LABEL(label1),buffer);


}

int main(int argc,char *argv[])
{
    gtk_init(&argc,&argv);
    GtkWidget *win, *label, *btn,*vbox, *entry;
    GdkPixbuf *pic;
    pic = gdk_pixbuf_new_from_file("w.ico", NULL);
    win = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(win,"delete_event",gtk_main_quit,NULL); 
    gtk_window_set_title(GTK_WINDOW(win), "W4cast");
    gtk_window_set_position(GTK_WINDOW(win), GTK_WIN_POS_CENTER);
    gtk_window_set_icon(GTK_WINDOW(win), pic);
    gtk_window_set_resizable(GTK_WINDOW(win), FALSE);
    label = gtk_label_new("Enter the city"); 
    label1 = gtk_label_new(""); 
    btn = gtk_button_new_with_label("Proceed");
    entry = gtk_entry_new(); 

    vbox = gtk_box_new(GTK_ORIENTATION_VERTICAL,10); 
    gtk_box_pack_start(GTK_BOX(vbox),label,0,0,0); 
    gtk_box_pack_start(GTK_BOX(vbox),entry,0,0,0); 

    gtk_container_add(GTK_CONTAINER(win),vbox); 
    gtk_box_pack_start(GTK_BOX(vbox),btn,0,0,0); 
    gtk_box_pack_start(GTK_BOX(vbox),label1,0,0,0); 
    g_signal_connect(btn,"clicked",G_CALLBACK(btnclick),entry);
    g_signal_connect(entry,"activate",G_CALLBACK(btnclick),entry);
    gtk_widget_show_all(win); 
    gtk_main(); 
    return 0;
}