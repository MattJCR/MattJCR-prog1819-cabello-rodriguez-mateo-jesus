/* 
 * File:   usuario.h
 * Author: MattMad
 */

#ifndef ADMINISTRADOR_H
#define	ADMINISTRADOR_H
#include "media.h"
#include "usuario.h"
/****************************************
 * DEFINICION DE LA CLASE ADMINISTRADOR *
 ****************************************/
class Administrador: public Usuario{
	public:
		/*
		 * @brief Muestra un usuario en detalle.
		 * @param Usuario *UsuarioSeleccionado.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarUsuario(Usuario *UsuarioSeleccionado);
		/*
		 * @brief Edita un Media.
		 * @param Media *MediaSeleccionado.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void EditarMedia(Media *MediaSeleccionado);
		/*
		 * @brief Edita un usuario.
		 * @param Media *MediaSeleccionado.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void EditarUsuario(Usuario *UsuarioSeleccionado);
};

#endif	/* ADMINISTRADOR_H */