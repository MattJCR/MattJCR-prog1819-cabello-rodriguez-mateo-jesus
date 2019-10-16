/* 
 * File:   cancion.h
 * Author: MadMatt
 */

#ifndef CANCION_H
#define	CANCION_H
#include <string>
#include "comentario.h"
#include "media.h"

using namespace std;
class Cancion: public Media{
	private:
		string Artista;
		string Album;
	public:
		/*
		 * @brief Constructor por defecto de Cancion.
		 * @post Inicializacion de la Clase Cancion con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Cancion();
		/*
		 * @brief Constructor de Cancion por parametro.
		 * @param const Cancion &cancion(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Cancion(const Cancion &cancion);
		/*
		 * @brief Destructor de Cancion.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Cancion();
		/*
		 * @brief Imprime por pantalla Cancion.
		 * @param ostream &out.
		 * @param const Cancion &cancion
		 * @return Devuelve un ostream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend ostream& operator<<(ostream &out, const Cancion &cancion);
		/*
		 * @brief Pide por pantalla Los valores de Cancion.
		 * @param istream &in.
		 * @param const Cancion &cancion
		 * @return Devuelve un istream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend istream& operator>>(istream &in, Cancion &cancion);
		/*
		 * @brief Asigna un valor a Artista.
		 * @param string Artista(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setArtista(string Artista){this->Artista = Artista;};
		/*
		 * @brief Asigna un valor a Album.
		 * @param string Album(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setAlbum(string Album){this->Album = Album;};
		/*
		 * @brief Devuelve el valor de Artista.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getArtista(){return this->Artista;};
		/*
		 * @brief Devuelve el valor de Album.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getAlbum(){return this->Album;};
};
#endif	/* CANCION_H */