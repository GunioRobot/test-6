#include <gtk/gtk.h>

int main( int argc, char *argv[] )
	{
			GtkWidget *window;
		
			// Esta funcion se manda llamar en todas las aplicaciones GTK	
			gtk_init(&argc, &argv);
			
			// Se crea y se muestra una ventana
			window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
			gtk_widget_show(window);
			
			gtk_main();
			
			return 0;
	}
	
	