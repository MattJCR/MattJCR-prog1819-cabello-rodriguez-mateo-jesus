#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include "comentario.h"
#include "media.h"
#include "pelicula.h"
#include "serie.h"
#include "valoracion.h"
#define white "\033[1;0m"
#define red "\033[1;31m"
#define green "\033[1;32m"
#define blue "\033[1;34m"
#define cyan "\033[1;36m"
#define yellow "\033[1;33m"

using namespace std;


//SOBRECARGA << DE SERIE
ostream& operator<<(ostream &out, const Serie &serie){
	out << "IDMedia: " << serie.IDMedia << endl;
	out << "Titulo: " << serie.Titulo << endl;
	out << "Genero: " << serie.Genero << endl;
	out << "Duracion: " << serie.DuracionEnSegundos << " segundos" << endl;
	out << "Fecha de Publicacion: " << serie.FechaPublicacion << endl;
	out << "Pegi: +" << serie.Pegi << endl;
	out << "Reparto: " << serie.Reparto << endl;
	out << "Direccion: " << serie.Direccion << endl;
	out << "Guion: " << serie.Guion << endl;
	out << "Productor: " << serie.Productor << endl;
	out << "Temporadas: " << serie.Temporadas << endl;
	out << "Capitulos: " << serie.Capitulos << endl;
	out << "Estado: ";
	if (serie.Estado == true)
	{
		out << "En emision" << endl;
	}else{
		out << "Finalizada" << endl;
	}
	out << "Descripcion: " << serie.Descripcion << endl;
	out << "ValoracionMedia: " << serie.ValoracionMedia << endl;
	out << "ValoracionMediaEnCatalogo: " << serie.TotalValoracionEnCatalogo << endl;
	out << "Me Gusta: " << serie.MeGusta << endl;
}
istream& operator>>(istream &in, Serie &serie){
	string aux_string;
	unsigned int aux_uint = 0;
	int aux_int = 0;
	float aux_float = 0.0;
	in.clear();
	in.ignore(256,'\n');
	cout << "Titulo: ";
	getline(in,aux_string);
	serie.setTitulo(aux_string);
	cout << "Genero: ";
	getline(in,aux_string);
	serie.setGenero(aux_string);
	cout << "Duracion: ";
	in >> aux_int;
	serie.setDuracionEnSegundos(aux_int);
	cout << "Fecha de Publicacion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(cin,aux_string);
	serie.setFechaPublicacion(aux_string);
	cout << "Pegi: +";
	in >> aux_int;
	serie.setPegi(aux_int);
	cout << "Descripcion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(in,aux_string);
	serie.setDescripcion(aux_string);
	cout << "Reparto: ";
	getline(in,aux_string);
	serie.setReparto(aux_string);
	cout << "Guion: ";
	getline(in,aux_string);
	serie.setGuion(aux_string);
	cout << "Direccion: ";
	getline(in,aux_string);
	serie.setDireccion(aux_string);
	cout << "Productor: ";
	getline(in,aux_string);
	serie.setProductor(aux_string);
	cout << "Temporadas: ";
	in >> aux_int;
	serie.setTemporadas(aux_int);
	cout << "Capitulos: ";
	in >> aux_int;
	serie.setCapitulos(aux_int);
	cout << "Estado 0[Finalizada], 1[Emision]: ";
	in.clear();
	in.ignore(256,'\n');
	getline(in,aux_string);
	if (aux_string == "1")
	{
		serie.setEstado(true);
	}else{
		serie.setEstado(false);
	}
	return in;
}

Serie::Serie(){
	this->Temporadas = 0;
	this->Capitulos = 0; 
	this->Estado = false; 
}

Serie::Serie(const Serie &serie): Pelicula(serie){
	this->Reparto = serie.Temporadas;
	this->Direccion = serie.Capitulos; 
	this->Guion = serie.Estado; 
}

Serie::~Serie(){
	this->Temporadas = 0;
	this->Capitulos = 0; 
	this->Estado = false; 
}	
