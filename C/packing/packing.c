#include <stdio.h>
#include <stdlib.h>
#include "gtk/gtk.h"

gint delete_event( GtkWidget *widget,
                   GdkEvent  *event,
                   gpointer  data )
{
	gtk_main_quit();
	return FALSE;
}

/* Crea un nuevo hbox llenado con button-labels. 
 * No mostraremos la caja, pero mostraremos todo lo que contiene
 */
GtkWidget *make_box( gboolean homogeneous,
                     gint     spacing,
                     gboolean expand,
                     gboolean fill,
                     gboolean padding )
{
	GtkWidget *box;
	GtkWidget *button;
	char padstr[80];

	/* Crear una nueva hbox con los apropiadas configuraciones homogeneous
	 * y spacing */
	box = gtk_hbox_new(homogeneous, spacing);

	/* Crear una serie de botones con los apropiadas configuraciones */
	button = gtk_button_new_with_label ("gtk_box_pack");
	gtk_box_pack_start (GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	button = gtk_button_new_with_label ("(box,");
	gtk_box_pack_start (GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	button = gtk_button_new_with_label ("button,");
	gtk_box_pack_start(GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	/* Creamos un boton con el label dependiendo del valor en expand */
	if(expand == TRUE)
		button = gtk_button_new_with_label ("TRUE,");
	else
		button = gtk_button_new_with_label ("FALSE,");

	gtk_box_pack_start (GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show(button);

	/* Esto es lo mismo que la creacion  para expand de arriba, 
	 * pero usa la forma rapida */
	button = gtk_button_new_with_label (fill ? "TRUE,":"FALSE,");
	gtk_box_pack_start (GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show (button);

	sprintf(padstr, "%d;",padding);

	button = gtk_button_new_with_label (padstr);
	gtk_box_pack_start (GTK_BOX(box), button, expand, fill, padding);
	gtk_widget_show (button);

	return box;
}

int main( int   argc,
           char *argv[])
{
	GtkWidget *window;
	GtkWidget *button;
	GtkWidget *box1;
	GtkWidget *box2;
	GtkWidget *separator;
	GtkWidget *label;
	GtkWidget *quitbox;
	int which;

	/* Nuestro init, nunca se olvide! */
	gtk_init(&argc,&argv);

	if(argc != 2){
		fprintf(stderr, "usage: packing num, where num is 1, 2 or 3. \n");
		/* Esto solo limpia en GTK y sale con un estatus 1 */
		exit(1);
	}

	which = atoi (argv[1]);

	/* Creamos nuestra ventana */
	window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

	/* Deberias siempre recordar conectar la señal delete_event con la
	 * ventana principal. Esto es muy importante para el funcionamiento
	 * intuitivo esperado.*/
	g_signal_connect(G_OBJECT(window), "delete_event", 
	                 G_CALLBACK(delete_event), NULL);
	gtk_container_set_border_width (GTK_CONTAINER(window), 10);

	/* Creamos una caja horizontal (vbox) para empaquetar las cajas
	 * horizontales dentro. Esto nos permite acomodar las cajas horizontales
	 * llenadas con botones uno arriba del otro en esta caja.*/
	box1 = gtk_vbox_new(FALSE, 0);

	/* wich example to show. These correspond to the pictures above.*/
	switch(which){
		case 1:
			/* Crea un nuevo label */
			label = gtk_label_new("gtk_hbox_new(FALSE,0);");

			/* Alineamos el label al lado izquierdo.*/
			gtk_misc_set_alignment (GTK_MISC(label), 0,0);

			/* Empaquetamos el label dentro de la caja vertical (vbox box1).
			 * Recuerda que los widgets agregados a vbox seran acomodados 
			 * uno arriba del otro en orden.*/
			gtk_box_pack_start(GTK_BOX(box1), label, FALSE, FALSE, 0);

			/* Mostramos el label */
			gtk_widget_show(label);

			/* Llamamos a nuestra funcion make_box - homogeneous = FALSE, 
			 * spacing = 0, expand = FALSE, fill = FALSE, padding = 0 */
			box2 = make_box(FALSE, 0, FALSE, FALSE, 0);
			gtk_box_pack_start(GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			/* Llamamos a nuestra funcion make_box - homogeneous = FALSE,
			 * spacing = 0, expand = TRUE, fill = FALSE, padding = 0 */
			box2 = make_box(FALSE, 0, TRUE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show(box2);

			/* Los argumentos son: homogeneous, spacing, expand, fill, padding*/
			box2 = make_box(FALSE, 0, TRUE, TRUE, 0);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			/* Creamos un separador */
			separator = gtk_hseparator_new ();

			/* Empaquetamos el separador dentro del vbox. Recuerda que cada 
			 * widget está siendo empaquetado en una vbox. asi que se van a 
			 * acomodar verticalmente */
			gtk_box_pack_start(GTK_BOX(box1), separator, FALSE, TRUE, 5);
			gtk_widget_show (separator);

			/* Creamos un nuevo label, y lo mostramos */
			label = gtk_label_new ("gtk_hbox_new(TRUE, 0);");
			gtk_misc_set_alignment (GTK_MISC(label), 0,0);
			gtk_box_pack_start(GTK_BOX(box1), label, FALSE, FALSE, 0);
			gtk_widget_show (label);

			/* Args: homogeneous, spacing, expand, fill, padding */
			box2 = make_box(TRUE, 0, TRUE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX(box1),box2, FALSE, FALSE, 0);
			gtk_widget_show(box2);

			/* Args: homogeneous, spacing, expand, fill, padding */
			box2 = make_box(TRUE, 0, TRUE, TRUE, 0);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			/* Otro separador */
			separator = gtk_hseparator_new ();
			/* Los ultimos 3 argumentos para gtk_box_pack_start son:
			 * expand, fill, padding.*/
			gtk_box_pack_start (GTK_BOX(box1), separator, FALSE, TRUE, 5);
			gtk_widget_show (separator);

			break;

		case 2:
			/* Creamos un nuevo label, recuerda box1 es un vbox que creamos
			 * cerca del inicio del main() */
			label = gtk_label_new ("gtk_box_new(FALSE, 10);");
			gtk_misc_set_alignment (GTK_MISC(label), 0, 0);
			gtk_box_pack_start (GTK_BOX(box1),label, FALSE, FALSE, 0);
			gtk_widget_show (label);

			/* Args: homogeneous, spacing, expand, fill, padding */
			box2 = make_box(FALSE, 10, TRUE, FALSE, 0);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			/* Args: homogenous, spacing,  expand, fill, padding */
			box2 = make_box(FALSE, 10, TRUE, TRUE, 0);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			separator = gtk_hseparator_new ();
			/* Los tres ultimos argumentos para gtk_box_pack_Start son:
			 * expand, fill, padding. */
			gtk_box_pack_start (GTK_BOX(box1), separator, FALSE, TRUE, 5);
			gtk_widget_show (separator);

			label = gtk_label_new ("gtk_hbox_new(FALSE, 0);");
			gtk_misc_set_alignment (GTK_MISC(label), 0, 0);
			gtk_box_pack_start (GTK_BOX(box1), label, FALSE, FALSE, 0);
			gtk_widget_show (label);

			/* Args: homogeneous, spacing, expand, fill, padding */
			box2 = make_box(FALSE, 0, TRUE, FALSE, 10);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			/* Args: homogeneous, spacing, expand, fill, padding */
			box2 = make_box(FALSE, 0, TRUE, TRUE, 10);
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			separator = gtk_hseparator_new ();
			gtk_box_pack_start (GTK_BOX(box1), separator, FALSE, TRUE, 5);
			gtk_widget_show (separator);

			break;

		case 3:
			/* Esto demuestra el uso de gtk_box_pack_end() para justificar a
		     * la derecha los widgets. Primero creamos una nueva caja como
			 * antes */
			box2 = make_box(FALSE, 0, FALSE, FALSE, 0);
			
			/* Creamos un label que será puesto al final.*/
			label = gtk_label_new("end");
			/* Empaquetamos usando gtk_box_pack_end(), asi que lo pone del lado
		     * derecho de la hbox creada en la llamada a make_box().*/
			gtk_box_pack_end (GTK_BOX(box2), label, FALSE, FALSE, 0); 
			/* Mostramos el label*/
			gtk_widget_show (label);

			/* Empaquetamos box2 en box1. */
			gtk_box_pack_start (GTK_BOX(box1), box2, FALSE, FALSE, 0);
			gtk_widget_show (box2);

			/* Un separador al final */
			separator = gtk_hseparator_new ();
			/* Esto explicitamente pone el separador a 400 pixeles de ancho por
			 * 5 pixeles de alto. Esto hace que el hbox creado sea tambien de 
			 * 400 pixeles de ancho, y el label "end" será separado de los
			 * otros labels en el hbox. De otra manera, todos los widgets en el 
			 * hbox estarian empaquetados tan cerca como fuera posible. */
			gtk_widget_set_size_request (separator, 400, 5);
			/* Empaquetamos el separador en el vbox(box1)*/
			gtk_box_pack_start (GTK_BOX(box1), separator, FALSE, TRUE, 5);
			gtk_widget_show(separator);
	}

	/* Creamos una nueva hbox. Se pueden usar tantas como necesitemos. */
	quitbox = gtk_hbox_new(FALSE, 0);

	/* Nuestro boton salir */
	button = gtk_button_new_with_label ("Salir");

	/* Configuramos la señal para terminar el programa cuando el boton se haya presionado */
	g_signal_connect_swapped (G_OBJECT(button), "clicked", 
							  G_CALLBACK(gtk_main_quit),
							  G_OBJECT(window));
							  
	/* Empaquetamos el boton en la caja quitbox 
	 * los ultimos 3 argumentos para gtk_box_pack_start son:
	 * expand, fill, padding. */
	gtk_box_pack_start( GTK_BOX (quitbox), button, TRUE, FALSE, 0);
	/* Empaquetamos el quitbox dentro de la caja vbox (box1)*/
	gtk_box_pack_start( GTK_BOX(box1), quitbox, FALSE, FALSE, 0);
	
	/* Empaquetar la vbox(box1) la cual contiene todos nuestros widgets, dentro de la
	 * ventana principal. */
	gtk_container_add(GTK_CONTAINER(window), box1);
	
	/* Y mostramos todo lo que falte */
	gtk_widget_show(button);
	gtk_widget_show(quitbox);
	
	gtk_widget_show(box1);
	/* Mostrando la ventana hasta el último para que todo aparezca al mismo tiempo.*/
	gtk_widget_show(window);
	
	/* Y por supuesto, nuestra funcion main */
	gtk_main();
	
	/* Regresamos el control aquí cuando gtk_main_quit() sea llamada, pero no cuando 
	 * exit() sea usada.*/
	return 0;
}
