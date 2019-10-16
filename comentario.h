/* 
 * File:   media.h
 * Author: MadMatt
 */
#ifndef COMENTARIO_H
#define	COMENTARIO_H
#include <string>

using namespace std;

/*************************************
 * DEFINICION DE LA CLASE COMENTARIO *
 *************************************/

class Comentario{
	private:
		unsigned int IDComentario;
		string IDUsuario;
		string Texto;
	public:
		/*
		 * @brief Constructor por defecto de Comentario.
		 * @post Inicializacion de la Clase Comentario con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Comentario(){
			this->IDComentario = 0;
			this->IDUsuario = " ";
			this->Texto = " ";
		};
		/*
		 * @brief Constructor por parametros de Comentario.
		 * @param string IDComentario. Debe de ser unico.
		 * @param string IDUsuario. Sera el IDUsuario del usuario que escriba el comentario.
		 * @param string Texto. Texto del comentario.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Comentario(unsigned int IDComentario, string IDUsuario, string Texto){
			this->IDComentario = IDComentario;
			this->IDUsuario = IDUsuario;
			this->Texto = Texto;
		};
		/*
		 * @brief Destructor de Comentario.
		 * @post Pone a NULL todos los atributos de la Clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Comentario(){
			this->IDComentario = 0;
			this->IDUsuario = "NULL";
			this->Texto = "NULL";
		};
		/*
		 * @brief Asigna un valor a IDComentario.
		 * @param int IDComentario(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setIDComentario(unsigned int IDComentario){this->IDComentario = IDComentario;};
		/*
		 * @brief Asigna un valor a IDUsuario.
		 * @param int IDUsuario(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setIDUsuario(string IDUsuario){this->IDUsuario = IDUsuario;};
		/*
		 * @brief Asigna un valor a Texto.
		 * @param int Texto(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setTexto(string Texto){this->Texto = Texto;};
		/*
		 * @brief Devuelve el valor de IDComentario.
		 * @return Devuelve un unsigned int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline unsigned int getIDComentario(){return this->IDComentario;};
		/*
		 * @brief Devuelve el valor de IDUsuario.
		 * @return Devuelve un string con el valor.
		 * @version 1
		 */
		inline string getIDUsuario(){return this->IDUsuario;};
		/*
		 * @brief Devuelve el valor de Texto.
		 * @return Devuelve un string con el valor.
		 * @version 1
		 */
		inline string getTexto(){return this->Texto;};
};

#endif	/* COMENTARIO_H */