#include <iostream>
#include <sstream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#define RESET   "\033[0m"
#define BLACK   "\033[30m"      /* Black */
#define RED     "\033[31m"      /* RED */
#define GREEN   "\033[32m"      /* Green */
#define YELLOW  "\033[33m"      /* Yellow */
#define BLUE    "\033[34m"      /* Blue */
#define MAGENTA "\033[35m"      /* Magenta */
#define CYAN    "\033[36m"      /* Cyan */
#define BOLDBLACK   "\033[1m\033[30m"      /* Bold Black */
#define BOLDRED     "\033[1m\033[31m"      /* Bold RED */
#define BOLDGREEN   "\033[1m\033[32m"      /* Bold Green */
#define BOLDYELLOW  "\033[1m\033[33m"      /* Bold Yellow */
#define BOLDBLUE    "\033[1m\033[34m"      /* Bold Blue */
#define BOLDMAGENTA "\033[1m\033[35m"      /* Bold Magenta */
#define BOLDCYAN    "\033[1m\033[36m"      /* Bold Cyan */
#define BOLDRESET   "\033[1m\033[37m"      /* Bold RESET */
#include "media.h"
#include "cancion.h"
#include "pelicula.h"
#include "serie.h"
#include "videojuego.h"
#include "comentario.h"
#include "valoracion.h"

using namespace std;

Media::Media(){
	this->IDMedia = 0;
	this->Titulo = " ";
	this->Genero = " ";
	this->DuracionEnSegundos = 0;
	this->FechaPublicacion = " ";
	this->Pegi = 0;
	this->Descripcion = " ";
	this->ValoracionMedia = 0;
	this->MeGusta = 0;
	this->TotalVectorDinamicoComentarios = 0;
	this->TotalValoracionEnCatalogo = 0.0;
	this->VectorDinamicoComentarios = new Comentario*[this->TotalVectorDinamicoComentarios];
	if (!this->VectorDinamicoComentarios){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	this->TotalVectorValoraciones = 0;
	this->VectorValoraciones = new Valoracion*[this->TotalVectorValoraciones];
	if (!this->VectorValoraciones){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
}

Media::Media(const Media &media){
	this->IDMedia = media.IDMedia;
	this->Titulo = media.Titulo;
	this->Genero = media.Genero;
	this->DuracionEnSegundos = media.DuracionEnSegundos;
	this->FechaPublicacion = media.FechaPublicacion;
	this->Pegi = media.Pegi;
	this->Descripcion = media.Descripcion;
	this->ValoracionMedia = media.ValoracionMedia;
	this->MeGusta = media.MeGusta;
	this->TotalVectorDinamicoComentarios = media.TotalVectorDinamicoComentarios;
	this->TotalValoracionEnCatalogo = media.TotalValoracionEnCatalogo;
	this->VectorDinamicoComentarios = new Comentario*[this->TotalVectorDinamicoComentarios];
	if (!this->VectorDinamicoComentarios){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		*this->VectorDinamicoComentarios[i] = *media.VectorDinamicoComentarios[i];
	}
	this->TotalVectorValoraciones = media.TotalVectorValoraciones;
	this->VectorValoraciones = new Valoracion*[this->TotalVectorValoraciones];
	if (!this->VectorValoraciones){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	for (int i = 0; i < this->TotalVectorValoraciones; ++i)
	{
		*this->VectorValoraciones[i] = *media.VectorValoraciones[i];
	}
}

Media::~Media(){
	this->IDMedia = 0;
	this->Titulo = "NULL";
	this->Genero = "NULL";
	this->DuracionEnSegundos = 0;
	this->FechaPublicacion = "NULL";
	this->Pegi = 0;
	this->Descripcion = "NULL";
	this->ValoracionMedia = 0;
	this->MeGusta = 0;
	this->TotalValoracionEnCatalogo = 0.0;
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		delete this->VectorDinamicoComentarios[i];
		this->VectorDinamicoComentarios[i] = 0;
	}
	delete [] this->VectorDinamicoComentarios;
	this->VectorDinamicoComentarios = 0;
	this->TotalVectorDinamicoComentarios = 0;

	for (int i = 0; i < this->TotalVectorValoraciones; ++i)
	{
		delete this->VectorValoraciones[i];
		this->VectorValoraciones[i] = 0;
	}
	delete [] this->VectorValoraciones;
	this->VectorValoraciones = 0;
	this->TotalVectorValoraciones = 0;
}


ostream& operator<<(ostream &out, const Media &media){
	out << "IDMedia: " << media.IDMedia << endl;
	out << "Titulo: " << media.Titulo << endl;
	out << "Genero: " << media.Genero << endl;
	out << "Duracion: " << media.DuracionEnSegundos << " segundos" << endl;
	out << "Fecha de Publicacion: " << media.FechaPublicacion << endl;
	out << "Pegi: +" << media.Pegi << endl;
	out << "Descripcion: " << media.Descripcion << endl;
	out << "ValoracionMedia: " << media.ValoracionMedia << endl;
	out << "ValoracionMediaEnCatalogo: " << media.TotalValoracionEnCatalogo << endl;
	out << "Me Gusta: " << media.MeGusta << endl;
}
istream& operator>>(istream &in, Media &media){
	string aux_string;
	unsigned int aux_uint = 0;
	int aux_int = 0;
	float aux_float = 0.0;
	cout << "IDMedia: ";
	in >> aux_uint;
	in.clear();
	in.ignore(256,'\n');
	media.setIDMedia(aux_uint);
	cout << "Titulo: ";
	getline(in,aux_string);
	media.setTitulo(aux_string);
	cout << "Genero: ";
	getline(in,aux_string);
	media.setGenero(aux_string);
	cout << "Duracion: ";
	in >> aux_int;
	media.setDuracionEnSegundos(aux_int);
	cout << "Fecha de Publicacion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(cin,aux_string);
	media.setFechaPublicacion(aux_string);
	cout << "Pegi: +";
	in >> aux_int;
	media.setPegi(aux_int);
	cout << "Descripcion: ";
	in.clear();
	in.ignore(256,'\n');
	getline(in,aux_string);
	media.setDescripcion(aux_string);
	return in;
}

void Media::resizeVectorDinamicoComentarios(int NuevaDimensionDelVector){
	Comentario **NuevoVectorDinamicoComentarios = new Comentario*[NuevaDimensionDelVector];
	if (!NuevoVectorDinamicoComentarios){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	unsigned int Limite = 0;
	if (NuevaDimensionDelVector < this->TotalVectorDinamicoComentarios)
	{
		Limite = NuevaDimensionDelVector;
	}else{
		Limite = this->TotalVectorDinamicoComentarios;
	}
	for (int i = 0; i < Limite; ++i)
	{
		NuevoVectorDinamicoComentarios[i] = this->VectorDinamicoComentarios[i];
		this->VectorDinamicoComentarios[i] = 0;
	}
	delete [] this->VectorDinamicoComentarios;
	this->VectorDinamicoComentarios = NuevoVectorDinamicoComentarios;
	NuevoVectorDinamicoComentarios = 0;
	this->TotalVectorDinamicoComentarios = NuevaDimensionDelVector;
}

void Media::resizeVectorValoraciones(int NuevaDimensionDelVector){
	Valoracion **NuevoVectorValoraciones = new Valoracion*[NuevaDimensionDelVector];
	if (!NuevoVectorValoraciones){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	unsigned int Limite = 0;
	if (NuevaDimensionDelVector < this->TotalVectorValoraciones)
	{
		Limite = NuevaDimensionDelVector;
	}else{
		Limite = this->TotalVectorValoraciones;
	}
	for (int i = 0; i < Limite; ++i)
	{
		NuevoVectorValoraciones[i] = this->VectorValoraciones[i];
		this->VectorValoraciones[i] = 0;
	}
	delete [] this->VectorValoraciones;
	this->VectorValoraciones = NuevoVectorValoraciones;
	NuevoVectorValoraciones = 0;
	this->TotalVectorValoraciones = NuevaDimensionDelVector;
}

void Media::InsertarComentario(string Texto, string IDUsuario){
	int Posicion = this->TotalVectorDinamicoComentarios;
	if (Posicion >= 0)
	{
		this->resizeVectorDinamicoComentarios(this->TotalVectorDinamicoComentarios + 1);
		this->VectorDinamicoComentarios[Posicion] = new Comentario;
		if (!this->VectorDinamicoComentarios[Posicion]){
			cerr << "Error en la creación del vector de clientes" << endl;
			exit(-1);
		}
		if (Posicion > 0)
		{
			this->VectorDinamicoComentarios[Posicion]->setIDComentario(this->VectorDinamicoComentarios[Posicion - 1]->getIDComentario() + 1);
		}else{
			this->VectorDinamicoComentarios[Posicion]->setIDComentario(1);
		}
		this->VectorDinamicoComentarios[Posicion]->setIDUsuario(IDUsuario);
		this->VectorDinamicoComentarios[Posicion]->setTexto(Texto);
		this->OrdenarComentariosPorIDComentario();
	}
}

void Media::OrdenarComentariosPorIDComentario(){
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		double shrink = 1.3;
		int gap = this->TotalVectorDinamicoComentarios;
		bool check = false;
		Comentario *aux = 0;
		while(!check){
			gap = (gap/shrink);
			if (gap <= 1)
			{
				gap = 1;
				check = true;
			}
			for (int i = 0; i+gap < this->TotalVectorDinamicoComentarios; ++i)
			{
				if (this->VectorDinamicoComentarios[i]->getIDComentario() > this->VectorDinamicoComentarios[i + gap]->getIDComentario())
				{
					check = false;
					aux = this->VectorDinamicoComentarios[i];
					this->VectorDinamicoComentarios[i] = this->VectorDinamicoComentarios[i + gap];
					this->VectorDinamicoComentarios[i + gap] = aux;
				}
			}
		}
	}
}

int Media::BuscarComentarioPorIDUsuario(string IDUsuario){
	int PosicionEncontrada = -1;
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		if (this->VectorDinamicoComentarios[i]->getIDUsuario() == IDUsuario)
		{
			PosicionEncontrada = i;
			i = this->TotalVectorDinamicoComentarios;
		}
	}
	return PosicionEncontrada;
}

void Media::BorrarTodosLosComentarioPorIDUsuario(string IDUsuario){
	int Posicion = -1;
	if (this->TotalVectorDinamicoComentarios > 0)
	{
		for (int i = 0; i >= 0 && i < this->TotalVectorDinamicoComentarios; ++i)
		{

			if (this->VectorDinamicoComentarios[i]->getIDUsuario() == IDUsuario)
			{

				delete this->VectorDinamicoComentarios[i];
				this->VectorDinamicoComentarios[i] = this->VectorDinamicoComentarios[this->TotalVectorDinamicoComentarios - 1];
				
				resizeVectorDinamicoComentarios(this->TotalVectorDinamicoComentarios - 1);
				--i;
			}
		}
		cout << YELLOW << "Se han borrado todos los comentarios del Usuario " << IDUsuario << RESET << endl;
	}else{
		cout << RED <<"No hay Comentarios para borrar..." << RESET << endl;
	}
	this->OrdenarComentariosPorIDComentario();
}

void Media::BorrarComentarioPorIDUsuarioYIDComentario(string IDUsuario, int IDComentario){
	bool ComprobacionBorrado = false; 
	if (this->TotalVectorDinamicoComentarios > 0)
	{
		for (int i = 0; i >= 0 && i < this->TotalVectorDinamicoComentarios; ++i)
		{
			if (this->VectorDinamicoComentarios[i]->getIDUsuario() == IDUsuario)
			{
				if (this->VectorDinamicoComentarios[i]->getIDComentario() == IDComentario)
				{
					delete this->VectorDinamicoComentarios[i];
					this->VectorDinamicoComentarios[i] = this->VectorDinamicoComentarios[this->TotalVectorDinamicoComentarios - 1];
					resizeVectorDinamicoComentarios(this->TotalVectorDinamicoComentarios - 1);
					cout << YELLOW << "Se ha borrado el comentario" << IDComentario << " del Usuario " << IDUsuario << RESET << endl;
					ComprobacionBorrado = true;
					i = this->TotalVectorDinamicoComentarios;
				}
			}
		}
		if (ComprobacionBorrado == false)
		{
			cout << RED << "El IDComentario y/o IDUsuario no coinciden..." << RESET << endl;
		}
	}else{
		cout << RED <<"No hay Comentarios para borrar..." << RESET << endl;
	}
	this->OrdenarComentariosPorIDComentario();
}


void Media::MostrarComentarios(){
	cout << MAGENTA << "Comentarios: ";
	if (this->TotalVectorDinamicoComentarios <= 0)
	{
		cout << RED << "No hay comentarios.";
	}
	cout << RESET << endl;
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		cout << this->VectorDinamicoComentarios[i]->getIDComentario() << ") ";
		cout << this->VectorDinamicoComentarios[i]->getTexto() << ". Autor: ";
		cout << this->VectorDinamicoComentarios[i]->getIDUsuario() << endl;
	}
}

void Media::MostrarComentariosDelUsuario(string IDUsuario){
	bool ComprobacionMostrar = false;
	cout << MAGENTA << "Comentarios: ";
	if (this->TotalVectorDinamicoComentarios <= 0)
	{
		cout << RED << "No hay comentarios.";
	}
	cout << RESET << endl;
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		if (this->VectorDinamicoComentarios[i]->getIDUsuario() == IDUsuario)
		{
			cout << this->VectorDinamicoComentarios[i]->getIDComentario() << ") ";
			cout << this->VectorDinamicoComentarios[i]->getTexto() << ". Autor: ";
			cout << this->VectorDinamicoComentarios[i]->getIDUsuario() << endl;
			ComprobacionMostrar = true;
		}
	}
	if (ComprobacionMostrar == false)
	{
		cout << RED <<"No hay Comentarios para mostrar..." << RESET << endl;
	}
}

int Media::BuscarValoracionPorIDUsuario(string IDUsuario){
	int PosicionEncontrada = -1; 
	for (int i = 0; i < this->TotalVectorValoraciones; ++i)
	{
		if (this->VectorValoraciones[i]->getIDUsuario() == IDUsuario)
		{
			PosicionEncontrada = i;
			i = this->TotalVectorValoraciones;
		}
	}
	return PosicionEncontrada;
}

void Media::CalcularValoracionMedia(){
	float SumaPuntuaciones = 0.0;
	float Divisor = this->TotalVectorValoraciones;
	for (int i = 0; i < this->TotalVectorValoraciones; ++i)
	{
		SumaPuntuaciones += this->VectorValoraciones[i]->getPuntuacion();
	}
	if (Divisor > 0.0)
	{
		this->ValoracionMedia = (SumaPuntuaciones / Divisor);
	}
}

void Media::InsertarValoracion(float Puntuacion, string IDUsuario){
	int PosicionEncontrada = -1;
	PosicionEncontrada = BuscarValoracionPorIDUsuario(IDUsuario);
	if (PosicionEncontrada < 0)
	{
		resizeVectorValoraciones(this->TotalVectorValoraciones + 1);
		this->VectorValoraciones[this->TotalVectorValoraciones - 1] = new Valoracion;
		this->VectorValoraciones[this->TotalVectorValoraciones - 1]->setIDUsuario(IDUsuario);
		this->VectorValoraciones[this->TotalVectorValoraciones - 1]->setPuntuacion(Puntuacion);
	}else{
		this->VectorValoraciones[PosicionEncontrada]->setPuntuacion(Puntuacion);
	}
	this->CalcularValoracionMedia();
}

void Media::BorrarValoracionPorIDUsuario(string IDUsuario){
	int PosicionEncontrada = -1;
	PosicionEncontrada = BuscarValoracionPorIDUsuario(IDUsuario);
	if (PosicionEncontrada >= 0)
	{
		delete this->VectorValoraciones[PosicionEncontrada];
		this->VectorValoraciones[PosicionEncontrada] = this->VectorValoraciones[this->TotalVectorValoraciones - 1];
		resizeVectorValoraciones(this->TotalVectorValoraciones  - 1);
		this->CalcularValoracionMedia();
	}else{
		cout << RED << "Este Multimedia no ha sido valorado por " << IDUsuario << "." << RESET << endl;
	}
}

void Media::MostrarValoraciones(){
	for (int i = 0; i < this->TotalVectorValoraciones; ++i)
	{
		cout << i << ")" << this->VectorValoraciones[i]->getIDUsuario() << ": " << this->VectorValoraciones[i]->getPuntuacion() << endl;
	}
}

string Media::InfoXML(){
	ostringstream BufferAuxiliar;
	string cadena;
	cadena += "\t\t\t<listacomentarios>\n";
	for (int i = 0; i < this->TotalVectorDinamicoComentarios; ++i)
	{
		BufferAuxiliar.str("");
		cadena += "\t\t\t\t<comentario>\n";
		cadena += "\t\t\t\t\t<idcomentario>";
		BufferAuxiliar << this->VectorDinamicoComentarios[i]->getIDComentario();
		cadena += BufferAuxiliar.str();
		BufferAuxiliar.str("");
		BufferAuxiliar.clear();
		cadena += "</idcomentario>\n";

		cadena += "\t\t\t\t\t<login>";
		cadena += this->VectorDinamicoComentarios[i]->getIDUsuario();
		cadena += "</login>\n";

		cadena += "\t\t\t\t\t<texto>"; 
		cadena += this->VectorDinamicoComentarios[i]->getTexto();
		cadena += "</texto>\n";
		cadena += "\t\t\t\t</comentario>\n";
	}
	cadena += "\t\t\t</listacomentarios>\n";
	cadena += "\t\t\t<valoraciones>\n";
	for (int i = 0; i < this->TotalVectorValoraciones; ++i)
	{
		BufferAuxiliar.str("");
		cadena += "\t\t\t\t<valoracion>\n";
		cadena += "\t\t\t\t\t<idusuario>"; 
		BufferAuxiliar << this->VectorValoraciones[i]->getIDUsuario();
		cadena += BufferAuxiliar.str();
		BufferAuxiliar.str("");
		BufferAuxiliar.clear();
		cadena += "</idusuario>\n";
		cadena += "\t\t\t\t\t<puntuacion>"; 
		BufferAuxiliar << this->VectorValoraciones[i]->getPuntuacion();
		cadena += BufferAuxiliar.str();
		BufferAuxiliar.str("");
		BufferAuxiliar.clear();
		cadena += "</puntuacion>\n";
		cadena += "\t\t\t\t</valoracion>\n";
	}
	cadena += "\t\t\t</valoraciones>\n";
	return cadena;
}