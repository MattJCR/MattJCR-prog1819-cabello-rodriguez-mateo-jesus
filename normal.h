/* 
 * File:   normal.h
 * Author: MattMad
 */

#ifndef NORMAL_H
#define	NORMAL_H
#include "media.h"
/*********************************
 * DEFINICION DE LA CLASE NORMAL *
 *********************************/
class Normal: public Usuario{
	private:
		Media **ListaMedia;
		unsigned int TotalListaMedia;
		/*
		 * @brief Aumenta o disminuye el tamaño del vector dinamico de Media.
		 * @param NuevaDimensionDelVector(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void resizeListaMedia(int NuevaDimensionDelVector);
	public:
		/*
		 * @brief Constructor por defecto de Normal.
		 * @post Inicializacion de la Clase Normal con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Normal();
		/*
		 * @brief Constructor de Normal por parametro.
		 * @param const Normal &normal(E).
		 * @post La clase pasa a tener los valores de la Clase por referencia.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Normal(const Normal &normal);
		/*
		 * @brief Destructor de Normal.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Normal();
		/*
		 * @brief Devuelve el valor de TotalListaMedia.
		 * @return Devuelve un unsigned int con el valor.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		inline unsigned int getTotalListaMedia(){return this->TotalListaMedia;};
		/*
		 * @brief Muestra por pantalla los Media del vector dinamico de Media.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarListaMedia();
		/*
		 * @brief Inserta un usuario en el vector dinamico de Media.
		 * @param Media *MediaCatalogo.
		 * @post TotalVectorDinamicoMediaVisto aumenta en 1.
		 * @return Devuelve TRUE si el IDMedia ya existe.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		bool InsertarMediaEnListaMedia(Media *MediaCatalogo);
		/*
		 * @brief Borra un usuario en el vector dinamico de Media.
		 * @pre Pedira el IDMedia antes del borrado.
		 * @post TotalVectorDinamicoMediaVisto disminuye en 1.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BorrarListaMedia();
		/*
		 * @brief Comprueba si existe en el vector dinamico de Media.
		 * @return Devuelve true si existe
		 */
		bool MediaExiste(int IDMedia);
		/*
		 * @brief Ordena los Media.
		 * @post Ordena el TotalVectorDinamicoMediaVisto pos su IDMedia ascendente.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void OrdenarListaMediaPorIDMedia();
		/*
		 * @brief Valora y comenta un media.
		 * @param Media *MediaCatalogo
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void ValorarComentarMediaInsertado(Media *MediaCatalogo);
		/*
		 * @brief Muestra los detalles de un media.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarDetalleListaMedia();
		/*
		 * @brief Devuelve comentarios y valoraciones en formato xml.
		 * @return Devuelve una cadena con los datos del xml
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		string InfoXML();
};
#endif	/* NORMAL_H */