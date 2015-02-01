#include <stdlib.h>
#include <redes2/chat.h>

/**
 * @page connect_client \b connect_client
 *
 * @brief Llamada por el botón de "Conexión".
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b connect_client \b (\b void\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se pulsa el botón de "Conexión" en el
 * interfaz gráfico.
 * Esta función debe ser implementada por el alumno.
 * 
 * No tiene parámetros de entrada.
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b disconnect_client(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void connect_client(void)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 * @page disconnect_client \b disconnect_client
 *
 * @brief Llamada por el botón de "Desconexión".
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b disconnect_client \b (\b void\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se pulsa el botón de "Desconexión" en el
 * interfaz gráfico.
 * Esta función debe ser implementada por el alumno.
 * 
 * No tiene parámetros de entrada.
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b connect_client(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void disconnect_client(void)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 * @page topic_protect \b topic_protect
 *
 * @brief Llamada por el checkbox de "Protección de tópico".
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b topic_protect \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se selecciona o deselecciona el checkbox
 * de "Protección de tópico".
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro de entrada el valor TRUE o FALSE según se active o
 * desactive el botón de "Protección de tópico".
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b extern_msg(3), \b secret(3), \b guests(3), \b privated(3), \b moderated(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void topic_protect(gboolean state)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 * @page extern_msg \b extern_msg
 *
 * @brief Llamada por el checkbox de "Mensaje externos".
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b extern_msg \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se selecciona o deselecciona el checkbox
 * de "Mensaje externos".
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro de entrada el valor TRUE o FALSE según se active o
 * desactive el botón de "Mensaje externos".
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b topic_protect(3), \b secret(3), \b guests(3), \b privated(3), \b moderated(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void extern_msg(gboolean state)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 *
 * @brief Llamada por el checkbox de "Secreto".
 * @page secret \b secret
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b secret \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se selecciona o deselecciona el checkbox
 * de "Secreto".
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro de entrada el valor TRUE o FALSE según se active o
 * desactive el botón de "Secreto".
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b extern_msg(3), \b topic_protect(3), \b guests(3), \b privated(3), \b moderated(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void secret(gboolean state)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 *
 * @brief Llamada por el checkbox de "Invitados".
 * @page guests \b guests
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b guests \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se selecciona o deselecciona el checkbox
 * de "Invitados".
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro de entrada el valor TRUE o FALSE según se active o
 * desactive el botón de "Invitados".
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b extern_msg(3), \b topic_protect(3), \b secret(3), \b privated(3), \b moderated(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void guests(gboolean state)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 *
 * @brief Llamada por el checkbox de "Privado".
 * @page privated \b privated
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b privated \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se selecciona o deselecciona el checkbox
 * de "Privado".
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro de entrada el valor TRUE o FALSE según se active o
 * desactive el botón de "Privado".
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b extern_msg(3), \b topic_protect(3), \b secret(3), \b guests(3), \b moderated(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void privated(gboolean state)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 *
 * @brief Llamada por el checkbox de "Moderado".
 * @page moderated \b moderated
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b moderated \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se selecciona o deselecciona el checkbox
 * de "Moderado".
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro de entrada el valor TRUE o FALSE según se active o
 * desactive el botón de "Moderado".
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section seealso VER TAMBIÉN
 * \b extern_msg(3), \b topic_protect(3), \b secret(3), \b guests(3), \b privated(3).
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void moderated(gboolean state)
{
	error_text(current_page(),"Función no implementada"); /* Ejemplo de uso */
}

/**
 * @page new_text \b new_text
 *
 * @brief Llamada por la introducción de texto.
 *
 * @section SYNOPSIS
 * 	\b #include \b <redes2/chat.h>
 *
 *	\b void \b new_text \b (\b gboolean\b )
 * 
 * @section descripcion DESCRIPCIÓN
 *
 * Es la función llamada cada vez que se introduce un texto en el campo de
 * introducción de texto.
 * Esta función debe ser implementada por el alumno.
 * 
 * Recibe como parámetro el texto introducido en el campo.
 *
 * @section retorno RETORNO
 * No devuelve ningún valor ni código de error.
 *
 * @section authors AUTOR
 * Eloy Anguiano (eloy.anguiano@uam.es)
*/

void new_text (char *msg)
{
	int currpage;
	
	currpage = current_page(); /* Ejemplo de uso */
	public_text(currpage,"User",msg); /* Ejemplo de uso */
	add_new_page("System2"); /* Ejemplo de uso */
}



