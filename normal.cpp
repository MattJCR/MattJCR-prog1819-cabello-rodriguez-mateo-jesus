#include "usuario.h"
#include "normal.h"
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
using namespace std;

Normal::Normal(){
	this->TotalListaMedia = 0;
	this->ListaMedia = new Media*[this->TotalListaMedia];
}

Normal::Normal(const Normal &normal): Usuario(normal){
	for (int i = 0; i < normal.TotalListaMedia; ++i)
	{
		this->InsertarMediaEnListaMedia(normal.ListaMedia[i]);
	}
}

Normal::~Normal(){
	for (int i = 0; i < this->TotalListaMedia; ++i)
	{
		this->ListaMedia[i]->setMeGusta(this->ListaMedia[i]->getMeGusta() - 1);
		this->ListaMedia[i] = 0;
	}
	delete [] this->ListaMedia;
	this->ListaMedia = 0;
}

void Normal::resizeListaMedia(int NuevaDimensionDelVector){
	Media **NuevoVectorDinamicoMedia = new Media*[NuevaDimensionDelVector];
	if (!NuevoVectorDinamicoMedia){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	unsigned int Limite = 0;
	if (NuevaDimensionDelVector < this->TotalListaMedia)
	{
		Limite = NuevaDimensionDelVector;
	}else{
		Limite = this->TotalListaMedia;
	}
	for (int i = 0; i < Limite; ++i)
	{
		NuevoVectorDinamicoMedia[i] = this->ListaMedia[i];
		this->ListaMedia[i] = 0;
	}
	delete [] this->ListaMedia;
	this->ListaMedia = NuevoVectorDinamicoMedia;
	NuevoVectorDinamicoMedia = 0;
	this->TotalListaMedia = NuevaDimensionDelVector;
}

void Normal::ValorarComentarMediaInsertado(Media *MediaCatalogo){
	int Puntuacion = 0;
	do{
		cout << "Introduce una Puntuacion[0-10]: ";
		cin >> Puntuacion;
	} while (!(Puntuacion >= 0.0 && Puntuacion <= 10.0));
	MediaCatalogo->InsertarValoracion(Puntuacion, this->IDUsuario);
	cin.clear();
	cin.ignore(256,'\n');
	this->InsertarComentario(MediaCatalogo);
}

bool Normal::MediaExiste(int IDMedia){
	bool Existe = false;
	for (int i = 0; i < this->TotalListaMedia && Existe == false; ++i)
	{
		if (this->ListaMedia[i]->getIDMedia() == IDMedia)
		{
			Existe = true;
		}
	}
	return Existe;
}

bool Normal::InsertarMediaEnListaMedia(Media *MediaCatalogo){
	bool ComprobacionDuplicado = false;
	for (int i = 0; i < this->TotalListaMedia && ComprobacionDuplicado == false; ++i)
	{
		if (this->ListaMedia[i]->getIDMedia() == MediaCatalogo->getIDMedia())
		{
			ComprobacionDuplicado = true;
		}
	}
	if (ComprobacionDuplicado == false)
	{
		float Puntuacion = -1.0;
		resizeListaMedia(this->TotalListaMedia + 1);
		this->ListaMedia[this->TotalListaMedia - 1] = MediaCatalogo;
	}
	return ComprobacionDuplicado;
}

void Normal::BorrarListaMedia(){
	unsigned int BorrarIDMedia = 0;
	bool IDMediaEncontrado = false;
	cout << "Introduce el IDMedia a borrar...";
	cin >> BorrarIDMedia;
	for (int i = 0; i < this->TotalListaMedia && IDMediaEncontrado == false; ++i)
	{
		if (BorrarIDMedia == this->ListaMedia[i]->getIDMedia())
		{
			this->ListaMedia[i]->setMeGusta(this->ListaMedia[i]->getMeGusta() - 1);
			this->ListaMedia[i]->BorrarValoracionPorIDUsuario(this->IDUsuario);
			this->ListaMedia[i]->BorrarTodosLosComentarioPorIDUsuario(this->IDUsuario);
			this->ListaMedia[i] = this->ListaMedia[this->TotalListaMedia - 1];
			resizeListaMedia(this->TotalListaMedia - 1);
		}
	}
}
void Normal::MostrarListaMedia(){
	cout << CYAN << "Medias asociados: " << RESET << endl;
	for (int i = 0; i < this->TotalListaMedia; ++i)
	{
		if(Serie *serie = dynamic_cast<Serie*>(this->ListaMedia[i])){
			cout << serie->getIDMedia() << ") " << serie->getTitulo()  << RED  << "  Serie" << RESET << endl;
		}else if(Pelicula *pelicula = dynamic_cast<Pelicula*>(this->ListaMedia[i])){
			cout << pelicula->getIDMedia() << ") " << pelicula->getTitulo()  << YELLOW << "  Pelicula" << RESET << endl;
		}else if(Cancion *cancion = dynamic_cast<Cancion*>(this->ListaMedia[i])){
			cout << cancion->getIDMedia() << ") " << cancion->getTitulo()  << GREEN << "  Cancion" << RESET <<endl;
		}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(this->ListaMedia[i])){
			cout << videojuego->getIDMedia() << ") " << videojuego->getTitulo() << MAGENTA << "  Videojuego" << RESET << endl;
		}else if(Media *media = dynamic_cast<Media*>(this->ListaMedia[i])){
			cout << media->getIDMedia() << ") " << media->getTitulo()  << ". Media Generico" << RESET << endl;
		}
	}
}



void Normal::MostrarDetalleListaMedia(){
	int IDMedia = 0;
	cout << cyan << "Introduce el numero ID para ver detalles: " << white;
	cin >> IDMedia;
	for (int i = 0; i < this->TotalListaMedia; ++i)
	{
		if (this->ListaMedia[i]->getIDMedia() == IDMedia)
		{
			if(Serie *serie = dynamic_cast<Serie*>(this->ListaMedia[i])){
				cout << *serie;
			}else if(Pelicula *pelicula = dynamic_cast<Pelicula*>(this->ListaMedia[i])){
				cout << *pelicula;
			}else if(Cancion *cancion = dynamic_cast<Cancion*>(this->ListaMedia[i])){
				cout << *cancion;
			}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(this->ListaMedia[i])){
				cout << *videojuego;
			}else if(Media *media = dynamic_cast<Media*>(this->ListaMedia[i])){
				cout << *media;
			}
			this->ListaMedia[i]->MostrarComentarios();
			i = this->TotalListaMedia;
		}
	}
}
void Normal::OrdenarListaMediaPorIDMedia(){
	for (int i = 0; i < this->TotalListaMedia; ++i)
	{
		double shrink = 1.3;
		int gap = this->TotalListaMedia;
		bool check = false;
		Media *aux = 0;
		while(!check){
			gap = (gap/shrink);
			if (gap <= 1)
			{
				gap = 1;
				check = true;
			}
			for (int i = 0; i+gap < this->TotalListaMedia; ++i)
			{
				if (this->ListaMedia[i]->getIDMedia() > this->ListaMedia[i + gap]->getIDMedia())
				{
					check = false;
					aux = this->ListaMedia[i];
					this->ListaMedia[i] = this->ListaMedia[i + gap];
					this->ListaMedia[i + gap] = aux;
				}
			}
		}
	}
}

string Normal::InfoXML(){
	string cadena;
	ostringstream BufferAuxiliar;
	cadena += "\t\t\t<listamedia>";
	for (int i = 0; i < this->TotalListaMedia; ++i)
	{
		if (i != 0)
		{
			cadena += " ";
		}
		BufferAuxiliar << this->ListaMedia[i]->getIDMedia();
		cadena += BufferAuxiliar.str();
		BufferAuxiliar.str("");
		BufferAuxiliar.clear();
	}
	cadena += "</listamedia>\n";
	return cadena;
}