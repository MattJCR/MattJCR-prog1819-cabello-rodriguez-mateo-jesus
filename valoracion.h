/* 
 * File:   valoracion.h
 * Author: MadMatt
 */
#ifndef VALORACION_H
#define	VALORACION_H
#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;

/*************************************
 * DEFINICION DE LA CLASE VALORACION *
 *************************************/

class Valoracion{
	private:
		float Puntuacion;
		string IDUsuario;

	public:
		/*
		 * @brief Constructor por defecto de Valoracion.
		 * @post Inicializacion de la Clase Comentario con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Valoracion(){
			this->Puntuacion = 0.0;
			this->IDUsuario = " ";
		};
		/*
		 * @brief Destructor de Valoracion.
		 * @post Pone a NULL todos los atributos de la Clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Valoracion(){
			this->Puntuacion = 0.0;
			this->IDUsuario = "NULL";
		};
		/*
		 * @brief Asigna un valor a IDUsuario.
		 * @param int IDUsuario(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setIDUsuario(string IDUsuario){this->IDUsuario = IDUsuario;};
		/*
		 * @brief Asigna un valor a Puntuacion.
		 * @param float Puntuacion(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void setPuntuacion(float Puntuacion){
			if (Puntuacion >= 0.0 && Puntuacion <= 10.0)
			{
				this->Puntuacion = Puntuacion;
			}else{
				cout << red << "Error: La valoracion debe estar entre 0 y 10..." << white << endl;
			}
		};
		/*
		 * @brief Devuelve el valor de Puntuacion.
		 * @return Devuelve un float con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline float getPuntuacion(){return this->Puntuacion;};
		/*
		 * @brief Devuelve el valor de IDUsuario.
		 * @return Devuelve un string con el valor.
		 * @version 1
		 */
		inline string getIDUsuario(){return this->IDUsuario;};
};

#endif	/* VALORACION_H */