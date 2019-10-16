/* 
 * File:   pelicula.h
 * Author: MadMatt
 */

#ifndef PELICULA_H
#define	PELICULA_H
#include <string>
#include "comentario.h"
#include "media.h"

using namespace std;
class Pelicula: public Media{
	protected:
		string Reparto;
		string Direccion;
		string Guion;
		string Productor;
	public:
		/*
		 * @brief Constructor por defecto de Pelicula.
		 * @post Inicializacion de la Clase Pelicula con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Pelicula();
		/*
		 * @brief Constructor de Pelicula por parametro.
		 * @param const Pelicula &pelicula(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Pelicula(const Pelicula &pelicula);
		/*
		 * @brief Destructor de Pelicula.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		virtual ~Pelicula();
		/*
		 * @brief Imprime por pantalla Pelicula.
		 * @param ostream &out.
		 * @param const Pelicula &pelicula
		 * @return Devuelve un ostream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend ostream& operator<<(ostream &out, const Pelicula &pelicula);
		/*
		 * @brief Pide por pantalla Los valores de Cancion.
		 * @param istream &in.
		 * @param const Cancion &cancion
		 * @return Devuelve un istream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend istream& operator>>(istream &in, Pelicula &pelicula);
		/*
		 * @brief Asigna un valor a Reparto.
		 * @param string Reparto(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */

		inline void setReparto(string Reparto){this->Reparto = Reparto;};
		/*
		 * @brief Asigna un valor a Direccion.
		 * @param string Direccion(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setDireccion(string Direccion){this->Direccion = Direccion;};
		/*
		 * @brief Asigna un valor a Guion.
		 * @param string Guion(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setGuion(string Guion){this->Guion = Guion;};
		/*
		 * @brief Asigna un valor a Productor.
		 * @param string Productor(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setProductor(string Productor){this->Productor = Productor;};
		/*
		 * @brief Devuelve el valor de Reparto.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getReparto(){return this->Reparto;};
		/*
		 * @brief Devuelve el valor de Direccion.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getDireccion(){return this->Direccion;};
		/*
		 * @brief Devuelve el valor de Guion.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getGuion(){return this->Guion;};
		/*
		 * @brief Devuelve el valor de Productor.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getProductor(){return this->Productor;};
};
#endif	/* PELICULA_H */