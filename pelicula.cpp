#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "comentario.h"
#include "media.h"
#include "pelicula.h"
#include "valoracion.h"
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;

//SOBRECARGA << DE PELICULA
ostream& operator<<(ostream &out, const Pelicula &pelicula){
	out << "IDMedia: " << pelicula.IDMedia << endl;
	out << "Titulo: " << pelicula.Titulo << endl;
	out << "Genero: " << pelicula.Genero << endl;
	out << "Duracion: " << pelicula.DuracionEnSegundos << " segundos" << endl;
	out << "Fecha de Publicacion: " << pelicula.FechaPublicacion << endl;
	out << "Pegi: +" << pelicula.Pegi << endl;
	out << "Reparto: " << pelicula.Reparto << endl;
	out << "Direccion: " << pelicula.Direccion << endl;
	out << "Guion: " << pelicula.Guion << endl;
	out << "Productor: " << pelicula.Productor << endl;
	out << "Descripcion: " << pelicula.Descripcion << endl;
	out << "ValoracionMedia: " << pelicula.ValoracionMedia << endl;
	out << "ValoracionMediaEnCatalogo: " << pelicula.TotalValoracionEnCatalogo << endl;
	out << "Me Gusta: " << pelicula.MeGusta << endl;
}
istream& operator>>(istream &in, Pelicula &pelicula){
	string aux_string;
	unsigned int aux_uint = 0;
	int aux_int = 0;
	float aux_float = 0.0;
	in.clear();
	in.ignore(256,'\n');
	cout << "Titulo: ";
	getline(in,aux_string);
	pelicula.setTitulo(aux_string);
	cout << "Genero: ";
	getline(in,aux_string);
	pelicula.setGenero(aux_string);
	cout << "Duracion: ";
	in >> aux_int;
	pelicula.setDuracionEnSegundos(aux_int);
	cout << "Fecha de Publicacion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(cin,aux_string);
	pelicula.setFechaPublicacion(aux_string);
	cout << "Pegi: +";
	in >> aux_int;
	pelicula.setPegi(aux_int);
	cout << "Descripcion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(in,aux_string);
	pelicula.setDescripcion(aux_string);
	cout << "Reparto: ";
	getline(in,aux_string);
	pelicula.setReparto(aux_string);
	cout << "Guion: ";
	getline(in,aux_string);
	pelicula.setGuion(aux_string);
	cout << "Direccion: ";
	getline(in,aux_string);
	pelicula.setDireccion(aux_string);
	cout << "Productor: ";
	getline(in,aux_string);
	pelicula.setProductor(aux_string);
	return in;
}

Pelicula::Pelicula(){
	this->Reparto = " ";
	this->Direccion = " "; 
	this->Guion = " "; 
	this->Productor = " "; 
}

Pelicula::Pelicula(const Pelicula &pelicula): Media(pelicula){
	this->Reparto = pelicula.Reparto;
	this->Direccion = pelicula.Direccion; 
	this->Guion = pelicula.Guion; 
	this->Productor = pelicula.Productor;  
}

Pelicula::~Pelicula(){
	this->Reparto = "NULL";
	this->Direccion = "NULL"; 
	this->Guion = "NULL"; 
	this->Productor = "NULL"; 
}
