/* 
 * File:   usuario.h
 * Author: MattMad
 */

#ifndef USUARIO_H
#define	USUARIO_H
#include "media.h"
/**********************************
 * DEFINICION DE LA CLASE USUARIO *
 **********************************/
class Usuario{
	protected:
		string IDUsuario;
		string Nombre;
		string Apellidos;
		string URLFotoPerfil;
	public:
		/*
		 * @brief Constructor por defecto de Usuario.
		 * @post Inicializacion de la Clase Usuario con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Usuario();
		/*
		 * @brief Constructor de Usuario por parametro.
		 * @param const Usuario &usuario(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Usuario(const Usuario &usuario);
		/*
		 * @brief Destructor de Usuario.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		virtual ~Usuario();
		/*
		 * @brief Asigna un valor a IDUsuario.
		 * @param string IDUsuario(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setIDUsuario(string IDUsuario){this->IDUsuario = IDUsuario;};
		/*
		 * @brief Asigna un valor a Nombre.
		 * @param string Nombre(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setNombre(string Nombre){this->Nombre = Nombre;};
		/*
		 * @brief Asigna un valor a Apellidos.
		 * @param string Apellidos(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setApellidos(string Apellidos){this->Apellidos = Apellidos;};
		/*
		 * @brief Asigna un valor a URLFotoPerfil.
		 * @param string URLFotoPerfil(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setURLFotoPerfil(string URLFotoPerfil){this->URLFotoPerfil = URLFotoPerfil;};
		/*
		 * @brief Devuelve el valor de IDUsuario.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getIDUsuario(){return this->IDUsuario;};
		/*
		 * @brief Devuelve el valor de Nombre.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getNombre(){return this->Nombre;};
		/*
		 * @brief Devuelve el valor de Apellidos.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getApellidos(){return this->Apellidos;};
		/*
		 * @brief Devuelve el valor de URLFotoPerfil.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getURLFotoPerfil(){return this->URLFotoPerfil;};
		/*
		 * @brief Imprime por pantalla el Usuario.
		 * @param ostream &out.
		 * @param const Usuario &usuario
		 * @return Devuelve un ostream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend ostream& operator<<(ostream &out, const Usuario &usuario);
		/*
		 * @brief Pide por pantalla los datos del Usuario.
		 * @param istream &in.
		 * @param const Usuario &usuario
		 * @return Devuelve un istream& (buffer de entrada) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend istream& operator>>(istream &in, Usuario &usuario);
		/*
		 * @brief Inserta un comentario en el vector dinamico de Comentarios.
		 * @param Media *MediaSeleccionado.
		 * @post TotalVectorDinamicoMediaVisto aumenta en 1.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void InsertarComentario(Media *MediaSeleccionado);
		/*
		 * @brief Borra un comentario en el vector dinamico de Comentarios.
		 * @param Media *MediaSeleccionado.
		 * @post TotalVectorDinamicoMediaVisto disminuye en 1.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BorrarComentario(Media *MediaSeleccionado);
		/*
		 * @brief Muestra por pantalla los comentarios del del Media Seleccionado.
		 * @param Media *MediaSeleccionado.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarComentarios(Media *MediaSeleccionado);
		/*
		 * @brief Muestra por pantalla el Media Seleccionado con sus detalles.
		 * @param Media *MediaSeleccionado.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarMedia(Media *MediaSeleccionado);
};

#endif	/* USUARIO_H */