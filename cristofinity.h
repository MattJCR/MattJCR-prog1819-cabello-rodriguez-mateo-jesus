/* 
 * File:   media.h
 * Author: MattMad
 */

#ifndef CRISTOFINITY_H
#define	CRISTOFINITY_H
#include "usuario.h"
#include "media.h"

/***************************************
 * DEFINICION DE LA CLASE CRISTOFINITY *
 ***************************************/
class Cristofinity{
	private:
		Usuario** VectorDinamicoUsuarios;
		Usuario* UsuarioActual;
		Media** Catalogo;
		unsigned int TotalUsuarios;
		unsigned int TotalCatalogo;
		/*
		 * @brief Aumenta o disminuye el tamaño del vector dinamico de usuarios.
		 * @param NuevaDimensionDelVector(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void resizeVectorDinamicoUsuarios(int NuevaDimensionDelVector);
		/*
		 * @brief Aumenta o disminuye el tamaño del vector dinamico del Catalogo.
		 * @param NuevaDimensionDelVector(E).
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void resizeCatalogo(int NuevaDimensionDelVector);
	public:
		/*
		 * @brief Constructor por defecto de Cristofinity.
		 * @post Inicializacion de la Clase vista Cristofinity con atributos NULL.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		Cristofinity();
		/*
		 * @brief Destructor de Cristofinity.
		 * @post Se pondran a NULL todos los valores de la clase.
		 * @post Se borrara toda la memoria dinamica de la clase.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		~Cristofinity();
		/*
		 * @brief Obtiene el total de Usuarios en la clase.
		 * @return Devuelve el numero de Usuarios del vector.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		unsigned int getTotalUsuarios(){return this->TotalUsuarios;};
		/*
		 * @brief Obtiene el total de Usuarios en la clase.
		 * @return Devuelve el numero de Usuarios del vector.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		unsigned int getTotalCatalogo(){return this->TotalCatalogo;};
		/*
		 * @brief Muestra por pantalla los usuarios del vector dinamico de usuarios.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarUsuarios();
		/*
		 * @brief Pide y desasocia un Media de un Usuario Normal.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void DesasociarMedia();
		/*
		 * @brief Pide y asasocia un Media de un Usuario Normal.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void AsociarMedia();
		/*
		 * @brief Muestra en top 3 por valoracion.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void RankGeneralMedia();
		/*
		 * @brief Muestra en top 3 por Tipo de Media.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void RankTipoMedia();
		/*
		 * @brief Añade un comentario y valoracion a un media.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void AniadirComentarioYValoracion();
		/*
		 * @brief Muestra por pantalla el catalogo del sistema.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarCatalogo();
		/*
		 * @brief Muestra por pantalla el perfil del usuario actual.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MostrarPerfilUsuario();
		/*
		 * @brief Inserta un usuario en el vector dinamico de usuarios.
		 * @pre Pedira los datos de usuario previamente antes de insertarlo.
		 * @post TotalUsuarios aumenta en 1.
		 * @return Devuelve FALSE si el IDUsuario ya existe en otro Usuario.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void InsertarUsuario();
		/*
		 * @brief Inserta media en el vector dinamico de catalogo.
		 * @pre Pedira los datos previamente antes de insertarlo.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void InsertarMediaEnCatalogo();
		/*
		 * @brief Inserta media en el vector dinamico de medias.
		 * @param Media *MediaCatalogo. Media a insertar
		 * @post TotalCatalogo aumenta en 1 si el idmedia no existe previamente.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void InsertarMedia(Media *MediaCatalogo);
		/*
		 * @brief Borra un Media en el vector dinamico.
		 * @pre Pedira el IDMedia antes del borrado.
		 * @post TotalCatalogo disminuye en 1.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BorrarMedia();
		/*
		 * @brief Edita un media.
		 * @pre Pedira los datos previamente antes de insertarlo.
		 * @pre Dependiendo del usuario actual editara el catalogo o su lista de medias.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void EditarMediaEnCatalogo();
		/*
		 * @brief Edita un Usuario.
		 * @pre Pedira los datos previamente antes de insertarlo.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void EditarUsuarios();
		/*
		 * @brief Borra un usuario en el vector dinamico de usuarios.
		 * @pre Pedira el IDUsuario antes del borrado.
		 * @post TotalUsuarios disminuye en 1.
		 * @return Devuelve FALSE si el IDUsuario ya existe en otro Usuario.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BorrarUsuario();
		/*
		 * @brief Buscar Un usuario y lo imprime por pantalla.
		 * @return Si encuentra el usuario lo imprime por pantalla.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BuscarUsuario();
		/*
		 * @brief Ordena los usuarios.
		 * @post Ordena el VectorDinamicoUsuarios pos su IDUsuario ascendente.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void OrdenarusuariosPorIDUsuario();
		/*
		 * @brief Loguea un usuario del sistema.
		 * @return Devuelve true si ha sido logueado con exito.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		bool Login();
		/*
		/*
		 * @brief Muestra un menu por pantalla al usuario final del programa.
		 * @return True si el log es correcto.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void Menu();
		/*
		 * @brief Muestra un menu por pantalla al Administrador del programa.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MenuAdministrador();
		/*
		 * @brief Muestra un menu por pantalla al Usuario del programa.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void MenuUsuario();
		/*
		 * @brief Buscar usuario.
		 * @param string IDUsuario.
		 * @return Devuelve la posicion de memoria del usuario.
		 * @return Si el valor es -1 no se ha encontrado el usuario.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		int BuscarUsuarioPorIDUsuario(string IDUsuario);
		/*
		 * @brief Buscar Media.
		 * @param unsigned int IDMedia.
		 * @return Devuelve la posicion de memoria del Media.
		 * @return Si el valor es -1 no se ha encontrado el Media.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		int BuscarEnCatalogoPorIDMedia(int IDMedia);
		/*
		 * @brief Busca y muestra por pantalla un Media del catalogo.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void BuscarMediaEnCatalogo();
		/*
		 * @brief Calcula la valoracion media del catalogo en cada Media.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void CalcularValoracionCatalogo();
		/*
		 * @brief Importa un xml.
		 * @param Ruta del XML.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void ImportarXML(string RutaXML);
		/*
		 * @brief Exporta un xml.
		 * @param Ruta del XML.
		 * @version 1.0
		 * @Autor MateoJCR
		 */
		void ExportarXML(string RutaXML);
};

#endif	/* CRISTOFINITY_H */