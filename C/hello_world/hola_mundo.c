#include <gtk/gtk.h>

   /* Esta es una función callback.
    * Los argumentos son ignorados en este ejemplo.
    */    
    void hello(GtkWidget *widget, gpointer data)
    {
        g_print ("Hola mundo!\n");
    }
     
    gint delete_event( GtkWidget * widget, GdkEvent *event, gpointer data)
    {
        /* Si tu regresas FALSO en el manejador de señales delete_event , 
        *   GTK emitirá una señal "destroy". Regresando TRUE significa
        *   que tu no quieres que la ventana sea destruida.
        *   Esto es util para mostrar los tipos de dialogo "Estás seguro que deseas salir?"
        */
        
        g_print("Ocurrio un  delete_event ");
        
        /* Cambia TRUE a FALSE y la ventana principal será destruída con un "delete event */
        
        return TRUE;
     }
     
     /* Otra Callback */
     void destroy( GtkWidget *widget, gpointer data)
     {
            gtk_main_quit();
     }
     
     int main( int argc, char *argv[])
     {
        /*GTKWidget es el tipo de almacenaje para widgets*/
        GtkWidget *window;
        GtkWidget *button;
        
        /*Esta es llamada en todas las aplicaciones GTK. Los argumentos son pasados
        *  desde la linea de comandos y son regresados a la aplicacion. */
        gtk_init(&argc, &argv);
        
        /* Crea una ventana nueva*/
        window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
        
        /* Cuandoo a la ventana se le da la señal "delete_event" (Esta es
         * dada por el windows manager, usualmente por la opcion "cerrar" o
		 * por el boton en la barra de titulo), vemos si llamar a la funcion
		 * delete_event() como la definimos arriba. Los datos pasados a la
		 * funcion callback es NULL y es ignorado en la funcion callback.*/

		g_signal_connect(G_OBJECT(window), "delete_event", G_CALLBACK(delete_event), NULL);

		/* Aqui conectamos el evento "destroy"  al manejador de señales.
		 * Este evento ocurre cuando llamamos  gtk_widget_destroy() en la ventana, 
		 * o si nosotros retornamos FALSE en el "delete_event".*/

		gtk_container_set_border_width (GTK_CONTAINER(window), 20);

		/* Crea un nuevo boton con el label "Hola Mundo!".*/
		button = gtk_button_new_with_label ("Hola Mundo!");

		/* Cuando el boton recive la señal de "click", este llamara la
		 * funcion hello() pasando NULL como su argumento. La funcion hello()
		 * está definida arriba. */
		g_signal_connect(G_OBJECT(button), "clicked",
		                 G_CALLBACK(hello), NULL);

		/* Esto causará que la ventana sea destruida cuando se llame 
		 * gtk_widget_destroy(window) cuando "clicked". De nuevo, la señal
		 * destroy debería venir de aquí, o del manejador de ventanas. */
		g_signal_connect_swapped(G_OBJECT(button), "clicked",
		                         G_CALLBACK(gtk_widget_destroy), 
		                         G_OBJECT(window));

		/* Esto empaqueta el boton dentro de la ventana (un contenedor gtk) */
		gtk_container_add (GTK_CONTAINER(window), button);

		/* El paso final es mostrar este recién creado widget */
		gtk_widget_show(button);

		/* y la ventana*/
		gtk_widget_show(window);

		/* Todas las aplicaciones GTK deben contener gtk_main(). El control 
		 * termina aquí y espera a que un evento ocurra (como el presionar una tecla o
		 * un evento del mouse). */
		gtk_main();

		return 0;

	 }
		