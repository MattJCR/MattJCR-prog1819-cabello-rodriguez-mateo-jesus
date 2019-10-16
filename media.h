/* 
 * File:   media.h
 * Author: MadMatt
 */

#ifndef MEDIA_H
#define	MEDIA_H
#include <string>
#include <iostream>
#include <sstream>
#include "comentario.h"
#include "valoracion.h"

using namespace std;
class Media{
	protected:
		unsigned int IDMedia;
		string Titulo;
		string Genero;
		int DuracionEnSegundos;
		string FechaPublicacion;
		int Pegi;
		string Descripcion;
		float ValoracionMedia;
		int MeGusta;
		Comentario** VectorDinamicoComentarios;
		unsigned int TotalVectorDinamicoComentarios;
		Valoracion** VectorValoraciones;
		unsigned int TotalVectorValoraciones;
		float TotalValoracionEnCatalogo;
		/*
		 * @brief Aumenta o disminuye el tamaño del vector dinamico de comentarios.
		 * @param int NuevaDimensionDelVector(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void resizeVectorDinamicoComentarios(int NuevaDimensionDelVector);
		/*
		 * @brief Aumenta o disminuye el tamaño del vector dinamico de valoraciones.
		 * @param int NuevaDimensionDelVector(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void resizeVectorValoraciones(int NuevaDimensionDelVector);
	public:
		/*
		 * @brief Constructor por defecto de Media.
		 * @post Inicializacion de la Clase Media con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Media();
		/*
		 * @brief Constructor de Media por parametro.
		 * @param const Media &media(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Media(const Media &media);
		/*
		 * @brief Destructor de Media.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		virtual ~Media();
		/*
		 * @brief Asigna un valor a IDMedia.
		 * @param unsigned int IDMedia(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setIDMedia(unsigned int IDMedia){this->IDMedia = IDMedia;};
		/*
		 * @brief Asigna un valor a Titulo.
		 * @param string Titulo(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setTitulo(string Titulo){this->Titulo = Titulo;};
		/*
		 * @brief Asigna un valor a Genero.
		 * @param string Genero(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setGenero(string Genero){this->Genero = Genero;};
		/*
		 * @brief Asigna un valor a DuracionEnSegundos.
		 * @param int Segundos(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setDuracionEnSegundos(int Segundos){this->DuracionEnSegundos = Segundos;};
		/*
		 * @brief Asigna un valor a FechaPublicacion.
		 * @param string Fecha(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setFechaPublicacion(string Fecha){this->FechaPublicacion = Fecha;};
		/*
		 * @brief Asigna un valor a Pegi.
		 * @param int Pegi(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setPegi(int Pegi){this->Pegi = Pegi;};
		/*
		 * @brief Asigna un valor a Descripcion.
		 * @param string Descripcion(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setDescripcion(string Descripcion){this->Descripcion = Descripcion;};
		/*
		 * @brief Asigna un valor a ValoracionMedia.
		 * @param float ValoracionMedia(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setValoracionMedia(float ValoracionMedia){this->ValoracionMedia = ValoracionMedia;};
		/*
		 * @brief Asigna un valor a MeGusta.
		 * @param int MeGusta(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setMeGusta(int MeGusta){this->MeGusta = MeGusta;};
		/*
		 * @brief Devuelve el valor de TotalValoracionEnCatalogo.
		 * @return Devuelve un float con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline float getTotalValoracionEnCatalogo(){return this->TotalValoracionEnCatalogo;};
		/*
		 * @brief Asigna el valor de TotalValoracionEnCatalogo.
		 * @param float TotalValoracionEnCatalogo.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline void setTotalValoracionEnCatalogo(float TotalValoracionEnCatalogo){this->TotalValoracionEnCatalogo = TotalValoracionEnCatalogo;};
		/*
		 * @brief Devuelve el valor de IDMedia.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline unsigned int getIDMedia(){return this->IDMedia;};
		/*
		 * @brief Devuelve el valor de Titulo.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getTitulo(){return this->Titulo;};
		/*
		 * @brief Devuelve el valor de Genero.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getGenero(){return this->Genero;};
		/*
		 * @brief Devuelve el valor de DuracionEnSegundos.
		 * @return Devuelve un int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline int getDuracionEnSegundos(){return this->DuracionEnSegundos;};
		/*
		 * @brief Devuelve el valor de FechaPublicacion.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getFechaPublicacion(){return this->FechaPublicacion;};
		/*
		 * @brief Devuelve el valor de Pegi.
		 * @return Devuelve un int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline int getPegi(){return this->Pegi;};
		/*
		 * @brief Devuelve el valor de Descripcion.
		 * @return Devuelve un string con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline string getDescripcion(){return this->Descripcion;};
		/*
		 * @brief Devuelve el valor de ValoracionMedia.
		 * @return Devuelve un float con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline float getValoracionMedia(){return this->ValoracionMedia;};
		/*
		 * @brief Devuelve el valor de MeGusta.
		 * @return Devuelve un int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline int getMeGusta(){return this->MeGusta;};
		/*
		 * @brief Devuelve el valor de TotalVectorDinamicoComentarios.
		 * @return Devuelve un unsigned int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline unsigned int getTotalVectorDinamicoComentarios(){return this->TotalVectorDinamicoComentarios;};
		/*
		 * @brief Devuelve el valor de TotalVectorValoraciones.
		 * @return Devuelve un unsigned int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline unsigned int getTotalVectorValoraciones(){return this->TotalVectorValoraciones;};
		/*
		 * @brief Imprime por pantalla Media.
		 * @param ostream &out.
		 * @param const Media &media
		 * @return Devuelve un ostream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend ostream& operator<<(ostream &out, const Media &media);
		/*
		 * @brief Pide por pantalla Los valores de Media.
		 * @param istream &in.
		 * @param const Media &media
		 * @return Devuelve un istream& (buffer de salida) por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		friend istream& operator>>(istream &in, Media &media);
		/*
		 * @brief Inserta un Comentario en el vector.
		 * @param string Texto(E)
		 * @param string IDUsuario(E)
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void InsertarComentario(string Texto, string IDUsuario);
		/*
		 * @brief Inserta un Puntuacion en el vector.
		 * @param float Puntuacion(E)
		 * @param string IDUsuario(E)
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void InsertarValoracion(float Puntuacion, string IDUsuario);
		/*
		 * @brief Ordena los comentarios del vector por IDComentario.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void OrdenarComentariosPorIDComentario();
		/*
		 * @brief Borra los Comentarios en el vector por IDUsuario.
		 * @param  string IDUsuario
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BorrarTodosLosComentarioPorIDUsuario(string IDUsuario);
		/*
		 * @brief Borra una Valoracion en el vector.
		 * @param string IDUsuario
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BorrarValoracionPorIDUsuario(string IDUsuario);
		/*
		 * @brief Muestra todos los comentarios del vector.
		 * @return Devuelve por pantalla los comentarios del vector.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarComentarios();
		/*
		 * @brief Muestra todos las valoraciones del vector.
		 * @return Devuelve por pantalla las valoraciones del vector.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarValoraciones();
		/*
		 * @brief Calcula la media de las valoraciones.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void CalcularValoracionMedia();

		int BuscarComentarioPorIDUsuario(string IDUsuario);

		void MostrarComentariosDelUsuario(string IDUsuario);

		void BorrarComentarioPorIDUsuarioYIDComentario(string IDUsuario, int IDComentario);

		int BuscarValoracionPorIDUsuario(string IDUsuario);
		string InfoXML();
};


#endif	/* MEDIA_H */