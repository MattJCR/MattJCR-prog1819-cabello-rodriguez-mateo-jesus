#include "usuario.h"
#include "normal.h"
#include "administrador.h"
#include "media.h"
#include "cancion.h"
#include "pelicula.h"
#include "serie.h"
#include "videojuego.h"
#include "comentario.h"
#include "valoracion.h"
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

Usuario::Usuario(){
	this->IDUsuario = " ";
	this->Nombre = " ";
	this->Apellidos = " ";
	this->URLFotoPerfil = " ";
}

Usuario::Usuario(const Usuario &usuario){
 	this->IDUsuario = usuario.IDUsuario;
 	this->Nombre = usuario.Nombre;
 	this->Apellidos = usuario.Apellidos;
 	this->URLFotoPerfil = usuario.URLFotoPerfil;
}

Usuario::~Usuario(){
 	this->IDUsuario = "NULL";
 	this->Nombre = "NULL";
 	this->Apellidos = "NULL";
 	this->URLFotoPerfil = "NULL";
}

ostream& operator<<(ostream &out, const Usuario &usuario){
	out << cyan << "Imprimiendo Datos del Usuario..." << white << endl;
	out << "IDUsuario: " << usuario.IDUsuario << endl;
	out << "Nombre: " << usuario.Nombre << endl;
	out << "Apellidos: " << usuario.Apellidos << endl;
	out << "URLFotoPerfil: " << usuario.URLFotoPerfil << endl;
	return out;
}

istream& operator>>(istream &in, Usuario &usuario){
	string datos;
	cout << "Introduce Datos del Usuario..." << endl;
	cout << "Nombre: ";
	cin >> datos;
	usuario.setNombre(datos);
	cout << "Apellidos: ";
	cin >> datos;
	usuario.setApellidos(datos);
	cout << "URLFotoPerfil: ";
	cin >> datos;
	usuario.setURLFotoPerfil(datos);
	return in;
}

void Usuario::InsertarComentario(Media *MediaSeleccionado){
	string Comentario;
	cout << "Introduce el comentario para " << MediaSeleccionado->getTitulo() << ": ";
	getline(cin, Comentario);
	MediaSeleccionado->InsertarComentario(Comentario, this->getIDUsuario());
}

void Usuario::BorrarComentario(Media *MediaSeleccionado){
	int IDComentario;
	string IDUsuario;
	MediaSeleccionado->MostrarComentarios();
	if(Normal *normal = dynamic_cast<Normal*>(this)){
		cout << "Introduce el IDComentario del comentario a borrar: ";
		cin >> IDComentario;
		IDUsuario = this->IDUsuario;
	}else if (Administrador *admin = dynamic_cast<Administrador*>(this)){
		cout << "Introduce el IDUsuario del comentario a borrar: ";
		cin >> IDUsuario;
		cin.clear();
		cin.ignore(256,'\n');
		cout << "Introduce el IDComentario del comentario a borrar: ";
		cin >> IDComentario;
	}
	MediaSeleccionado->BorrarComentarioPorIDUsuarioYIDComentario(IDUsuario, IDComentario);
}

void Usuario::MostrarComentarios(Media *MediaSeleccionado){
	MediaSeleccionado->MostrarComentarios();
}

void Usuario::MostrarMedia(Media *MediaSeleccionado){
	if(Serie *serie = dynamic_cast<Serie*>(MediaSeleccionado)){
		cout << *serie << endl;
	}else if(Pelicula *pelicula = dynamic_cast<Pelicula*>(MediaSeleccionado)){
		cout << *pelicula << endl;
	}else if(Cancion *cancion = dynamic_cast<Cancion*>(MediaSeleccionado)){
		cout << *cancion << endl;
	}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(MediaSeleccionado)){
		cout << *videojuego << endl;
	}else if(Media *media = dynamic_cast<Media*>(MediaSeleccionado)){
		cout << *media << endl;
	}
}










