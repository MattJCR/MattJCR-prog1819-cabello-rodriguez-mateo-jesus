#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "comentario.h"
#include "cancion.h"
#include "cancion.h"
#include "valoracion.h"
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;
//SOBRECARGA << DE CANCION
ostream& operator<<(ostream &out, const Cancion &cancion){
	out << "IDMedia: " << cancion.IDMedia << endl;
	out << "Titulo: " << cancion.Titulo << endl;
	out << "Genero: " << cancion.Genero << endl;
	out << "Duracion: " << cancion.DuracionEnSegundos << " segundos" << endl;
	out << "Fecha de Publicacion: " << cancion.FechaPublicacion << endl;
	out << "Pegi: +" << cancion.Pegi << endl;
	out << "Artista: " << cancion.Artista << endl;
	out << "Album: " << cancion.Album << endl;
	out << "Descripcion: " << cancion.Descripcion << endl;
	out << "ValoracionMedia: " << cancion.ValoracionMedia << endl;
	out << "ValoracionMediaEnCatalogo: " << cancion.TotalValoracionEnCatalogo << endl;
	out << "Me Gusta: " << cancion.MeGusta << endl;
}
istream& operator>>(istream &in, Cancion &cancion){
	string aux_string;
	unsigned int aux_uint = 0;
	int aux_int = 0;
	float aux_float = 0.0;
	in.clear();
	in.ignore(256,'\n');
	cout << "Titulo: ";
	getline(in,aux_string);
	cancion.setTitulo(aux_string);
	cout << "Genero: ";
	getline(in,aux_string);
	cancion.setGenero(aux_string);
	cout << "Duracion: ";
	in >> aux_int;
	cancion.setDuracionEnSegundos(aux_int);
	cout << "Fecha de Publicacion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(cin,aux_string);
	cancion.setFechaPublicacion(aux_string);
	cout << "Pegi: +";
	in >> aux_int;
	cancion.setPegi(aux_int);
	cout << "Descripcion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(in,aux_string);
	cancion.setDescripcion(aux_string);
	cout << "Artista: ";
	getline(in,aux_string);
	cancion.setArtista(aux_string);
	cout << "Album: ";
	getline(in,aux_string);
	cancion.setAlbum(aux_string);
	return in;
}

Cancion::Cancion(){
	this->Artista = " ";
	this->Album = " "; 
}

Cancion::Cancion(const Cancion &cancion): Media(cancion){
	this->Artista = cancion.Artista;
	this->Album = cancion.Album; 
}

Cancion::~Cancion(){
	this->Artista = "NULL";
	this->Album = "NULL"; 
}
