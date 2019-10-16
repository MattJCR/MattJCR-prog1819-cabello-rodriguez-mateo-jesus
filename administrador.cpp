#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "usuario.h"
#include "administrador.h"
#include "normal.h"
#include "media.h"
#include "cancion.h"
#include "pelicula.h"
#include "serie.h"
#include "videojuego.h"
#include "comentario.h"
#include "valoracion.h"
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"
using namespace std;


void Administrador::EditarMedia(Media *MediaSeleccionado){
	cout << "Se va a editar el IDMedia: " << MediaSeleccionado->getIDMedia() << endl;
	if (Serie *serie = dynamic_cast<Serie*>(MediaSeleccionado)){
		cin >> *serie;
	}else if (Pelicula *pelicula = dynamic_cast<Pelicula*>(MediaSeleccionado)){
		cin >> *pelicula;
	}else if(Cancion *cancion = dynamic_cast<Cancion*>(MediaSeleccionado)){
		cin >> *cancion;
	}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(MediaSeleccionado)){
		cin >> *videojuego;
	}else {
		cin >> *MediaSeleccionado;
	}
	cout << green << "Media editado correctamente." << white << endl;
};

//void Administrador::EditarMedia(Media *MediaSeleccionado){}
//void Administrador::MostrarUsuario(Usuario *UsuarioSeleccionado){}