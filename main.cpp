/*********************************************************************
 * PRACTICA DE PROGRAMACION DEL TRIMESTRE 3 DE 1ºDAM CURSO 2018/2020 *
 * 				AUTOR: MATEO JESUS CABELLO RODRIGUEZ				 *
 *********************************************************************/

#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "cristofinity.h"
#include "usuario.h"
#include "normal.h"
#include "administrador.h"
#include "media.h"
#include "cancion.h"
#include "pelicula.h"
#include "serie.h"
#include "videojuego.h"
//#include "pugixml/src/pugixml.cpp"
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;

int main(){
	//Cristofinity sistema;
	//sistema.Menu();

	/* TESTING DE COMENTARIOS */
	Media *prueba = new Media;
	Normal n;
	n.setIDUsuario("ID1");
	Administrador a;
	a.setIDUsuario("ID2");
	prueba->InsertarComentario("a","ID1");
	prueba->InsertarComentario("b","ID1");
	prueba->InsertarComentario("c","ID2");
	prueba->InsertarComentario("d","ID1");
	prueba->InsertarComentario("e","ID2");
	prueba->InsertarComentario("f","ID1");
	prueba->InsertarComentario("g","ID2");
	prueba->InsertarComentario("h","ID1");
	prueba->MostrarComentarios();
	prueba->BorrarComentarioPorIDUsuarioYIDComentario("ID1", 1);
	//prueba.BorrarTodosLosComentarioPorIDUsuario("ID2");
	prueba->MostrarComentarios();
	prueba->BorrarComentarioPorIDUsuarioYIDComentario("ID2", 3);
	prueba->BorrarComentarioPorIDUsuarioYIDComentario("ID1", 1);
	prueba->BorrarComentarioPorIDUsuarioYIDComentario("ID2", 1);
	//prueba.BorrarTodosLosComentarioPorIDUsuario("ID1");
	prueba->MostrarComentarios();
	//prueba.BorrarTodosLosComentarioPorIDUsuario("ID2");
	//prueba.BorrarTodosLosComentarioPorIDUsuario("ID1");
	prueba->MostrarComentarios();
	n.BorrarComentario(prueba);
	a.BorrarComentario(prueba);
	delete prueba;
	prueba = 0;
}