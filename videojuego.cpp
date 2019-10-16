#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "comentario.h"
#include "videojuego.h"
#include "videojuego.h"
#include "valoracion.h"
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;

//SOBRECARGA << DE VIDEOJUEGO
ostream& operator<<(ostream &out, const Videojuego &videojuego){
	out << "IDMedia: " << videojuego.IDMedia << endl;
	out << "Titulo: " << videojuego.Titulo << endl;
	out << "Genero: " << videojuego.Genero << endl;
	out << "Duracion: " << videojuego.DuracionEnSegundos << " segundos" << endl;
	out << "Fecha de Publicacion: " << videojuego.FechaPublicacion << endl;
	out << "Pegi: +" << videojuego.Pegi << endl;
	out << "Desarrollador: " << videojuego.Desarrollador << endl;
	out << "Editor: " << videojuego.Editor << endl;
	out << "Jugadores: " << videojuego.Jugadores << endl;
	out << "Plataformas: " << videojuego.Plataformas << endl;
	out << "Descripcion: " << videojuego.Descripcion << endl;
	out << "ValoracionMedia: " << videojuego.ValoracionMedia << endl;
	out << "ValoracionMediaEnCatalogo: " << videojuego.TotalValoracionEnCatalogo << endl;
	out << "Me Gusta: " << videojuego.MeGusta << endl;
}
istream& operator>>(istream &in, Videojuego &videojuego){
	string aux_string;
	unsigned int aux_uint = 0;
	int aux_int = 0;
	float aux_float = 0.0;
	in.clear();
	in.ignore(256,'\n');
	cout << "Titulo: ";
	getline(in,aux_string);
	videojuego.setTitulo(aux_string);
	cout << "Genero: ";
	getline(in,aux_string);
	videojuego.setGenero(aux_string);
	cout << "Duracion: ";
	in >> aux_int;
	videojuego.setDuracionEnSegundos(aux_int);
	cout << "Fecha de Publicacion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(cin,aux_string);
	videojuego.setFechaPublicacion(aux_string);
	cout << "Pegi: +";
	in >> aux_int;
	videojuego.setPegi(aux_int);
	cout << "Descripcion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(in,aux_string);
	videojuego.setDescripcion(aux_string);
	cout << "Desarrollador: ";
	getline(in,aux_string);
	videojuego.setDesarrollador(aux_string);
	cout << "Editor: ";
	getline(in,aux_string);
	videojuego.setEditor(aux_string);
	cout << "Jugadores: ";
	in >> aux_int;
	videojuego.setJugadores(aux_int);
	cout << "Plataformas: ";
	getline(in,aux_string);
	videojuego.setPlataformas(aux_string);
	return in;
}

Videojuego::Videojuego(){
	this->Desarrollador = " ";
	this->Editor = " "; 
	this->Jugadores = 0; 
	this->Plataformas = " ";
}

Videojuego::Videojuego(const Videojuego &videojuego): Media(videojuego){
	this->Desarrollador = "NULL";
	this->Editor = "NULL"; 
	this->Jugadores = -1; 
	this->Plataformas = "NULL";
}

Videojuego::~Videojuego(){
	this->Desarrollador = "NULL";
	this->Editor = "NULL"; 
	this->Jugadores = -1; 
	this->Plataformas = "NULL";
}	