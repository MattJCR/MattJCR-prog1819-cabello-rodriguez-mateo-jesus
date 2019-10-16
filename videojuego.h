/* 
 * File:   videojuego.h
 * Author: MadMatt
 */

#ifndef VIDEOJUEGO_H
#define	VIDEOJUEGO_H
#include <string>
#include "comentario.h"
#include "media.h"

using namespace std;
class Videojuego: public Media{
	protected:
		string Desarrollador;
		string Editor;
		int Jugadores;
		string Plataformas;
	public:
		/*
		 * @brief Constructor por defecto de Videojuego.
		 * @post Inicializacion de la Clase Videojuego con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Videojuego();
		/*
		 * @brief Constructor de Videojuego por parametro.
		 * @param const Videojuego &videojuego(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Videojuego(const Videojuego &videojuego);
		/*
		 * @brief Destructor de Videojuego.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Videojuego();
		/*
		 * @brief Imprime por pantalla Videojuego.
		 * @param ostream &out.
		 * @param const Videojuego &videojuego
		 * @return Devuelve un ostream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend ostream& operator<<(ostream &out, const Videojuego &videojuego);
		/*
		 * @brief Pide por pantalla Los valores de Videojuego.
		 * @param istream &in.
		 * @param const Videojuego &videojuego
		 * @return Devuelve un istream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend istream& operator>>(istream &in, Videojuego &videojuego);
		/*
		 * @brief Asigna un valor a Desarrollador.
		 * @param string Desarrollador(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setDesarrollador(string Desarrollador){this->Desarrollador = Desarrollador;};
		/*
		 * @brief Asigna un valor a Editor.
		 * @param string Editor(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setEditor(string Editor){this->Editor = Editor;};
		/*
		 * @brief Asigna un valor a Jugadores.
		 * @param int Jugadores(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setJugadores(int Jugadores){this->Jugadores = Jugadores;};
		/*
		 * @brief Asigna un valor a Plataformas.
		 * @param string Plataformas(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setPlataformas(string Plataformas){this->Plataformas = Plataformas;};
		/*
		 * @brief Devuelve el valor de Desarrollador.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getDesarrollador(){return this->Desarrollador;};
		/*
		 * @brief Devuelve el valor de Editor.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getEditor(){return this->Editor;};
		/*
		 * @brief Devuelve el valor de Jugadores.
		 * @return Devuelve un int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline int getJugadores(){return this->Jugadores;};
		/*
		 * @brief Devuelve el valor de Plataformas.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getPlataformas(){return this->Plataformas;};
};
#endif	/* VIDEOJUEGO_H */