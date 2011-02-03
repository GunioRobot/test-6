#include <gtk/gtk.h>

/* Esta es una función de llamada hacia atras (callback).
    Los argumentos son ignorados en este ejemplo.
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
        
        /* */
     }