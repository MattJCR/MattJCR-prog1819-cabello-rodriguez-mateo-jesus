/* 
 * File:   serie.h
 * Author: MadMatt
 */

#ifndef SERIE_H
#define	SERIE_H
#include <string>
#include "comentario.h"
#include "media.h"
#include "serie.h"
#include "pelicula.h"

using namespace std;
class Serie: public Pelicula{
	protected:
		int Temporadas;
		int Capitulos;
		bool Estado;
	public:
		/*
		 * @brief Constructor por defecto de Serie.
		 * @post Inicializacion de la Clase Serie con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Serie();
		/*
		 * @brief Constructor de Serie por parametro.
		 * @param const Serie &serie(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Serie(const Serie &serie);
		/*
		 * @brief Destructor de Serie.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Serie();
		/*
		 * @brief Imprime por pantalla Serie.
		 * @param ostream &out.
		 * @param const Serie &pelicula
		 * @return Devuelve un ostream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend ostream& operator<<(ostream &out, const Serie &serie);
		/*
		 * @brief Pide por pantalla Los valores de Cancion.
		 * @param istream &in.
		 * @param const Cancion &cancion
		 * @return Devuelve un istream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend istream& operator>>(istream &in, Serie &serie);
		/*
		 * @brief Asigna un valor a Temporadas.
		 * @param int Temporadas(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setTemporadas(int Temporadas){this->Temporadas = Temporadas;};
		/*
		 * @brief Asigna un valor a Capitulos.
		 * @param int Capitulos(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setCapitulos(int Capitulos){this->Capitulos = Capitulos;};
		/*
		 * @brief Asigna un valor a Estado.
		 * @param bool Estado(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setEstado(bool Estado){this->Estado = Estado;};
		/*
		 * @brief Devuelve el valor de Temporadas.
		 * @return Devuelve un int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline int getTemporadas(){return this->Temporadas;};
		/*
		 * @brief Devuelve el valor de Capitulos.
		 * @return Devuelve un int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline int getCapitulos(){return this->Capitulos;};
		/*
		 * @brief Devuelve el valor de Estado.
		 * @return Devuelve un bool con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline bool getEstado(){return this->Estado;};
};
#endif	/* SERIE_H */