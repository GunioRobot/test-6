#include <gtk/gtk.h>

/* Callback mejorada. Los datos pasados a esta funcion son impresos en el stdout
*/
void callback(GtkWidget *widget,
			   gpointer  data)
{
	g_print("Hola de nuevo - %s fué presionado\n", (gchar *) data);
}

/* Otra callback */
gint delete_event(GtkWidget *widget, 
				  GdkEvent  *event,
				  gpointer  data )
{
	gtk_main_quit();
	return FALSE;
}

int main(int argc, 
		  char *argv[])		
{
	/* GtkWidget es el tipo de almacenamiento para los widgets */
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box1;
	
	/* Esto es llamado en todas las aplicaciones GTK. Argumentos son pasados
	 * desde la linea de comandos y son regresados a la aplicacion */
	gtk_init(&argc, &argv);
	
	/* Crea una nueva ventana */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
	
	/* Esta es una nueva llamada, que solo pone como titulo a nuestra ventana
	 * "Hola Botones!"*/
	gtk_window_set_title(GTK_WINDOW(window), "Hola botones");
	
	/* Aqui solo ponemos un manejador para el delete_event que inmediatamente
	 * cierra GTK. */
	g_signal_connect(G_OBJECT(window), "delete_event", 
					 G_CALLBACK(delete_event), NULL);
					 
	/* Pone el ancho del borde de la ventana */
	gtk_container_set_border_width(GTK_CONTAINER(window), 10);
	
	/* Creamos una caja para empaquetar los widgets dentro. Esto es descrito 
	 * con detalle en la seccion "empaquetado". La caja realmente no es visible, 
	 * esta es solo usada como una herramienta para acomodar los widgets */
	box1 = gtk_hbox_new(FALSE, 0);
	
	/* Ponemos la caja en la ventana principal */
	gtk_container_add(GTK_CONTAINER(window), box1);
	
	/* Creamos un nuevo botón con label "Boton 1"*/
	button = gtk_button_new_with_label("Boton 1");
	
	/* Ahora cuando el boton sea precionado, nosotros llamaremos a la funcion
	 * callback con el puntero al boton 1 como argumento.*/
	g_signal_connect(G_OBJECT(button), "clicked", 
	    G_CALLBACK(callback), (gpointer) "button 1");
	    
	/* En lugar de gtk_container_add, necesitamos empaquetar el boton en la caja
	 * visible, la cuál ha sido empaquetada en la ventana.*/
	gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);
	
	/* Siempre recuerda este paso, esto le dice a GTK nuestra preparacion para
	 * este boton está completa, y que ahora puede ser mostrado */
	gtk_widget_show(button);
	
	/* Haz los mismos pasos de nuevo para crear un segundo boton */
	button = gtk_button_new_with_label("Boton 2");
	
	/* Llama la misma función callback con un argumento diferente, 
	 * pasando un puntero con "button 2" ahora.*/ 
	g_signal_connect(G_OBJECT(button), "clicked", 
	    G_CALLBACK(callback), (gpointer) "button 2");
	    
	gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

	/* El orden en que mostramos los botones realmente no importa, pero  se 
	 * recomienda mostrar la ventana al final. Para que todo aparezca al mismo
	 * tiempo.*/
	gtk_widget_show(button);
	
	/***************************************************************************
	** Inicia modificacion para agregar un tercer boton "Salir"
	*-------------------------------------------------------------------------*/
	button = gtk_button_new_with_label("Salir");
	
	g_signal_connect(G_OBJECT(button), "clicked", 
		G_CALLBACK(delete_event), NULL);
	/*
	g_signal_connect_swapped(G_OBJECT(button), "clicked", 
	                         G_CALLBACK(gtk_widget_destroy), 
	                         G_OBJECT(window));
	*/
	gtk_box_pack_start(GTK_BOX(box1), button, TRUE, TRUE, 0);

	gtk_widget_show(button);
	/**************************************************************************/
	
	
	
	
	gtk_widget_show(box1);
	
	gtk_widget_show(window);
	
	/* Espera en gtk_main */
	gtk_main();
	
	return 0;
}	