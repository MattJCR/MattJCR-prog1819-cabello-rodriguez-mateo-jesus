#include <iostream>
#include <string>
#include <stdlib.h>
#include <iomanip>
#include <unistd.h>
#include <fstream>
#include "cristofinity.h"
#include "usuario.h"
#include "normal.h"
#include "administrador.h"
#include "media.h"
#include "cancion.h"
#include "pelicula.h"
#include "serie.h"
#include "videojuego.h"
#include "pugixml/src/pugixml.cpp"
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

Cristofinity::Cristofinity(){
	this->TotalUsuarios = 0;
	this->VectorDinamicoUsuarios = new Usuario*[this->TotalUsuarios];
	this->TotalCatalogo = 0;
	this->Catalogo = new Media*[this->TotalCatalogo];
	this->UsuarioActual = 0;
	this->ImportarXML("cristofinity.xml");
	this->CalcularValoracionCatalogo();
}

Cristofinity::~Cristofinity(){
	for (int i = 0; i < this->TotalUsuarios; ++i)
	{
		delete this->VectorDinamicoUsuarios[i];
		this->VectorDinamicoUsuarios[i] = 0;
	}
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		delete this->Catalogo[i];
		this->Catalogo[i] = 0;
	}
	delete [] this->VectorDinamicoUsuarios;
	delete [] this->Catalogo;
	this->VectorDinamicoUsuarios = 0;
	this->Catalogo = 0;
	this->TotalUsuarios = 0;
	this->TotalCatalogo = 0;
	this->UsuarioActual = 0;
}

void Cristofinity::resizeVectorDinamicoUsuarios(int NuevaDimensionDelVector){
	Usuario **NuevoVectorDinamicoUsuarios = new Usuario*[NuevaDimensionDelVector];
	unsigned int Limite = 0;
	if (NuevaDimensionDelVector < this->TotalUsuarios)
	{
		Limite = NuevaDimensionDelVector;
	}else{
		Limite = this->TotalUsuarios;
	}
	for (int i = 0; i < Limite; ++i)
	{
		NuevoVectorDinamicoUsuarios[i] = this->VectorDinamicoUsuarios[i];
		this->VectorDinamicoUsuarios[i] = 0;
	}
	delete [] this->VectorDinamicoUsuarios;
	this->VectorDinamicoUsuarios = NuevoVectorDinamicoUsuarios;
	NuevoVectorDinamicoUsuarios = 0;
	this->TotalUsuarios = NuevaDimensionDelVector;
}

void Cristofinity::MostrarUsuarios(){
	cout << cyan << "Lista Usuarios del sistema" << RESET << endl;
	for (int i = 0; i < this->TotalUsuarios; ++i)
	{
		cout << "[";
		cout << this->VectorDinamicoUsuarios[i]->getIDUsuario()<< "] ";
		cout << this->VectorDinamicoUsuarios[i]->getNombre() << " ";
		cout << this->VectorDinamicoUsuarios[i]->getApellidos() << "  ";
		if(Administrador *admin = dynamic_cast<Administrador*>(this->VectorDinamicoUsuarios[i])){
			cout << GREEN << "ADMIN";
		}else if(Normal *normal = dynamic_cast<Normal*>(this->VectorDinamicoUsuarios[i])){
			cout << YELLOW<< "Usuario";
		}
		cout << RESET <<endl;
		if(Normal *normal = dynamic_cast<Normal*>(this->VectorDinamicoUsuarios[i])){
			normal->MostrarListaMedia();
		}
		cout << endl;
	}
}

void Cristofinity::MostrarCatalogo(){
	cout << cyan << "Catalogo del sistema" << RESET << endl;
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		if (Serie *serie = dynamic_cast<Serie*>(this->Catalogo[i])){
			cout << RED << "SERIE";
		}else if (Pelicula *pelicula = dynamic_cast<Pelicula*>(this->Catalogo[i])){
			cout << YELLOW << "PELICULA";
		}else if(Cancion *cancion = dynamic_cast<Cancion*>(this->Catalogo[i])){
			cout << GREEN << "CANCION";
		}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(this->Catalogo[i])){
			cout << MAGENTA << "VIDEOJUEGO";
		}else {
			cout << "MEDIA";
		}
		cout << RESET <<endl;
		cout << "ID: " << this->Catalogo[i]->getIDMedia()<< " Titulo: ";
		cout << this->Catalogo[i]->getTitulo() << " GENERO: ";
		cout << this->Catalogo[i]->getGenero() << " Valoracion Catalogo: ";
		cout << this->Catalogo[i]->getTotalValoracionEnCatalogo() << "\n" << endl;
		//this->Catalogo[i]->MostrarComentarios();
		//this->Catalogo[i]->MostrarValoraciones();
	}
}

void Cristofinity::resizeCatalogo(int NuevaDimensionDelVector){
	Media **NuevoVectorDinamicoMedia = new Media*[NuevaDimensionDelVector];
	if (!NuevoVectorDinamicoMedia){
		cerr << "Error en la creación del vector de clientes" << endl;
		exit(-1);
	}
	unsigned int Limite = 0;
	if (NuevaDimensionDelVector < this->TotalCatalogo)
	{
		Limite = NuevaDimensionDelVector;
	}else{
		Limite = this->TotalCatalogo;
	}
	for (int i = 0; i < Limite; ++i)
	{
		NuevoVectorDinamicoMedia[i] = this->Catalogo[i];
		this->Catalogo[i] = 0;
	}
	delete [] this->Catalogo;
	this->Catalogo = NuevoVectorDinamicoMedia;
	NuevoVectorDinamicoMedia = 0;
	this->TotalCatalogo = NuevaDimensionDelVector;
}

void Cristofinity::InsertarMedia(Media *MediaCatalogo){
		resizeCatalogo(this->TotalCatalogo + 1);
		this->Catalogo[this->TotalCatalogo - 1] = MediaCatalogo;
}

void Cristofinity::InsertarUsuario(){
	string IDUsuario;
	char tipo;
	int pos = 0;
	Usuario *u = 0;
	do
	{
		cout << "Introduce un IDUsuario: ";
		cin >>IDUsuario;
		pos = this->BuscarUsuarioPorIDUsuario(IDUsuario);
		if (pos >= 0)
		{
			cout << RED << "Ese IDUsuario ya esta en uso..." << RESET << endl;
		}
	} while (pos >= 0);
	do
	{
		cout << "Tipo de Usuario 1)ADMIN 2)NORMAL: ";
		cin >> tipo;
	} while (tipo != '1' && tipo != '2');
	if (tipo = '1')
	{
		Administrador *a = new Administrador;
		u = a;
		a = 0;
	}else if(tipo = '2'){
		Normal *n = new Normal;
		u = n;
		n = 0;
	}else{
		u = new Usuario;
	}
	u->setIDUsuario(IDUsuario);
	cin >> *u;
	resizeVectorDinamicoUsuarios(this->TotalUsuarios + 1);
	this->VectorDinamicoUsuarios[this->TotalUsuarios - 1] = u;
	u = 0;
}

void Cristofinity::BorrarUsuario(){
	string IDUsuario;
	int pos = 0;
	Usuario *u = 0;
	cout << "Introduce el IDUsuario a borrar: ";
	cin >>IDUsuario;
	pos = this->BuscarUsuarioPorIDUsuario(IDUsuario);
	if (IDUsuario == this->UsuarioActual->getIDUsuario())
	{
		cout << RED << "No puedes borrar el usuario logueado actualmente..." << RESET << endl;
	}else if (pos >= 0)
	{
		 delete this->VectorDinamicoUsuarios[pos];
		 this->VectorDinamicoUsuarios[pos] = this->VectorDinamicoUsuarios[this->TotalUsuarios - 1];
		 this->VectorDinamicoUsuarios[this->TotalUsuarios - 1] = 0;
		 resizeVectorDinamicoUsuarios(this->TotalUsuarios - 1);
		 cout << GREEN << "Usuario " << IDUsuario << " borrado con exito." << RESET << endl;
	}else{
		cout << RED << "No existe el usuario..." << RESET << endl;
	}
}

void Cristofinity::EditarUsuarios(){
	if (Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
		cout << CYAN << "Editando datos del Usuario " << normal->getIDUsuario() << RESET << endl;
		cin >> *this->UsuarioActual;
	}else if (Administrador *admin = dynamic_cast<Administrador*>(this->UsuarioActual))
	{
		string IDUsuario;
		int pos = 0;
		cout << "Introduce el IDUsuario a editar: ";
		cin >> IDUsuario;
		pos = this->BuscarUsuarioPorIDUsuario(IDUsuario);
		if (pos >= 0)
		{
			cout << CYAN << "Editando datos del Usuario " << this->VectorDinamicoUsuarios[pos]->getIDUsuario() << RESET << endl;
			cin >> *this->VectorDinamicoUsuarios[pos];
		}else{
			cout << RED << "No existe el usuario..." << RESET << endl;
		}
	}
}

void Cristofinity::BuscarUsuario(){
	string IDUsuario;
	int pos = 0;
	cout << "Introduce el IDUsuario a buscar: ";
	cin >>IDUsuario;
	pos = this->BuscarUsuarioPorIDUsuario(IDUsuario);
	if (pos >= 0)
	{
		cout << *this->VectorDinamicoUsuarios[pos];
		if (Normal *normal = dynamic_cast<Normal*>(this->VectorDinamicoUsuarios[pos])){
			cout << "Tipo: " << YELLOW << "Usuario" << RESET << endl;
			cout << CYAN << "Listado de Medias asociados: " << RESET << endl;
			normal->MostrarListaMedia();
		}else{
			cout << "Tipo: " << GREEN << "ADMIN" << RESET << endl;
		}
	}else{
		cout << RED << "No existe el usuario..." << RESET << endl;
	}
}

void Cristofinity::InsertarMediaEnCatalogo(){
	bool Salir = false;
	char OpcionSeleccionada = ' ';
	unsigned int IDMedia = 0;
	int ComprobacionExiste = -1;
	Media *MediaAInsertar = 0;
	do
	{
		Salir = false;
		do
		{
			cout << "Introduce el IDMedia: ";
			cin >> IDMedia;
			ComprobacionExiste = BuscarEnCatalogoPorIDMedia(IDMedia);
			if (ComprobacionExiste < 0)
			{
				cout << RED << "El IDMedia introducido ya existe..." << RESET << endl;
			}
		} while (ComprobacionExiste < 0);
		cout << "1) Cancion." << endl;
		cout << "2) Pelicula." << endl;
		cout << "3) Serie." << endl;
		cout << "4) Videojuego." << endl;
		cout << "0) Salir." << endl;
		cout << "Selecciona el tipo de Media que vas a insertar: ";
		cin >> OpcionSeleccionada;
		if (OpcionSeleccionada == '1')
		{
			Cancion *c = new Cancion;
			cin >> *c;
			c->setIDMedia(IDMedia);
			MediaAInsertar = c;
			c = 0;
			Salir = true;
		}else if (OpcionSeleccionada == '2')
		{
			Pelicula *p = new Pelicula;
			cin >> *p;
			p->setIDMedia(IDMedia);
			MediaAInsertar = p;
			p = 0;
			Salir = true;
		}else if (OpcionSeleccionada == '3')
		{
			Serie *s = new Serie;
			cin >> *s;
			s->setIDMedia(IDMedia);
			MediaAInsertar = s;
			s = 0;
			Salir = true;
		}else if (OpcionSeleccionada == '4')
		{
			Videojuego *v = new Videojuego;
			cin >> *v;
			v->setIDMedia(IDMedia);
			MediaAInsertar = v;
			v = 0;
			Salir = true;
		}else if (OpcionSeleccionada == '0')
		{
			Salir = true;
		}else{
			cout << RED << "Opcion no valida..." << RESET << endl;
		}
	} while (Salir == false);
	if (MediaAInsertar != 0)
	{
		this->InsertarMedia(MediaAInsertar);
		cout << GREEN << "Media " << MediaAInsertar->getIDMedia() << " Insertado corectamente." << RESET << endl;
	}else{
		cout << RED << "Operacion Cancelada." << RESET << endl;
	}
	MediaAInsertar = 0;
}

void Cristofinity::BuscarMediaEnCatalogo(){

	int IDMedia = 0, pos = -1;
	cout << "Introduce el IDMedia a buscar: ";
	cin >> IDMedia;
	pos = BuscarEnCatalogoPorIDMedia(IDMedia);
	if (pos >= 0)
	{
		cout << BOLDMAGENTA << "INFO : " << RESET << endl;
		cout << *this->Catalogo[pos];
		cout << MAGENTA << "Valoraciones: " << RESET << endl;
		this->Catalogo[pos]->MostrarValoraciones();
		this->Catalogo[pos]->MostrarComentarios();
	}else{
		cout << RED << "No existe el IDMedia" << IDMedia << RESET << endl;
	}
}

void Cristofinity::BorrarMedia(){
	int IDMedia = 0, pos = 0;
	cout << "Introduce el ID del media que quieres borrar: ";
	cin >> IDMedia;
	pos = this->BuscarEnCatalogoPorIDMedia(IDMedia);
	if (pos >= 0)
	{
		delete this->Catalogo[pos];
		this->Catalogo[pos] = this->Catalogo[this->TotalCatalogo - 1];
		resizeCatalogo(this->TotalCatalogo - 1);
		cout << GREEN << "IDMedia " << IDMedia << " Borrado con exito." << RESET << endl;
	}else{
		cout << RED << "No existe el ID " << IDMedia << RESET << endl;
	}
}

void Cristofinity::MostrarPerfilUsuario(){
	cout << *this->UsuarioActual;
	if (Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
		cout << "MeGustas: " << normal->getTotalListaMedia() << endl;
		normal->MostrarListaMedia();
	}
}

int Cristofinity::BuscarUsuarioPorIDUsuario(string IDUsuario){
	int PosicionEncontrada = -1;
	bool UsuarioEncontrado = false;
	for (int i = 0; i < this->TotalUsuarios && UsuarioEncontrado == false; ++i)
	{
		if (this->VectorDinamicoUsuarios[i]->getIDUsuario() == IDUsuario)
		{
			PosicionEncontrada = i;
			UsuarioEncontrado = true;
		}
	}
	return PosicionEncontrada;
}

int Cristofinity::BuscarEnCatalogoPorIDMedia(int IDMedia){
	int PosicionEncontrada = -1;
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		if (this->Catalogo[i]->getIDMedia() == IDMedia)
		{
			PosicionEncontrada = i;
			i = this->TotalCatalogo;
		}
	}
	return PosicionEncontrada;
}

bool Cristofinity::Login(){
	string IDUsuario;
	int PosicionEncontrada = 0;
	bool UsuarioEncontrado = false;
	cout << "Introduzca su IDUsuario: ";
	cin >> IDUsuario;
	PosicionEncontrada = this->BuscarUsuarioPorIDUsuario(IDUsuario);
	cout << "PosicionEncontrada: " << PosicionEncontrada << endl;
	if (PosicionEncontrada >= 0 && PosicionEncontrada < this->TotalUsuarios)
	{
		this->UsuarioActual = this->VectorDinamicoUsuarios[PosicionEncontrada];
		UsuarioEncontrado = true;
		cout << this->UsuarioActual->getIDUsuario() << endl;
	}
	return UsuarioEncontrado;
}

void Cristofinity::Menu(){
	char OpcionSeleccionada;
	bool SalirMenuPrincipal = false;
	string XML;
	XML.clear();
	do
	{
		system("clear");

		cout << BOLDMAGENTA << "\n*****************************" <<endl;
		cout << "* Bienvenido a Cristofinity *" << endl;
		cout << "*****************************" << RESET << endl;
		cout << "1) Login" << endl;
		cout << "2) Importar XML." << endl;
		cout << "3) Exportar XML." << endl;
		cout << "0) Salir." << endl;
		cout << "Seleccione una opcion: ";
		cin >> OpcionSeleccionada;
		switch (OpcionSeleccionada){
			case '1':
				if (this->Login())
				{
					if(Administrador *admin = dynamic_cast<Administrador*>(this->UsuarioActual)){
						this->MenuAdministrador();
					}else if(Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
						this->MenuUsuario();
					}else{
						cout << "Usuario no encontrado..." << endl;
					}
				}else{ cout << "Error en el login..." << endl; }
				break;
			case '2':
				cout << "Introduce la ruta del XML: ";
				cin >> XML;
				this->ImportarXML(XML);
				break;
			case '3':
				cout << "Introduce la ruta del XML: ";
				cin >> XML;
				this->ExportarXML(XML);
				break;
			case '0':
				SalirMenuPrincipal = true;
				cout << "Adios..." << endl;
				this->ExportarXML("cristofinity.xml");
				break;
			default:
				cout << RED << "Opcion no valida..." << RESET << endl;
		}
	} while (SalirMenuPrincipal == false);
}

void Cristofinity::DesasociarMedia(){
	if (Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
		normal->MostrarListaMedia();
		normal->BorrarListaMedia();
	}
}

void Cristofinity::AniadirComentarioYValoracion(){
	int pos = 0;
	if (Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
		normal->MostrarListaMedia();
		cout << "Introduce el IDMedia a comentar: ";
		cin >> pos;
		if (normal->MediaExiste(pos))
		{
			for (int i = 0; i < normal->getTotalListaMedia(); ++i)
			{
				if (this->Catalogo[i]->getIDMedia() == pos)
				{
					pos = i;
					i = normal->getTotalListaMedia();
				}
			}
			normal->ValorarComentarMediaInsertado(this->Catalogo[pos]);
		}
	}
}

void Cristofinity::AsociarMedia(){
	unsigned int IDMedia = 0, pos = 0;
	bool IDMediaEncontrado = false;
	this->MostrarCatalogo();
	cout << "Introduce el IDMedia que desea asociar: ";
	cin >> IDMedia;
	cout << IDMedia << endl;
	for (int i = 0; i < this->TotalCatalogo && IDMediaEncontrado == false; ++i)
	{
		cout << this->Catalogo[i]->getIDMedia() << endl;
		if (this->Catalogo[i]->getIDMedia() == IDMedia)
		{
			IDMediaEncontrado = true;
			pos = i;
		}
	}
	cout << "IDMediaEncontrado: " << IDMediaEncontrado << endl;
	if (IDMediaEncontrado == true)
	{
		if (Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
			if (normal->InsertarMediaEnListaMedia(this->Catalogo[pos]))
			{
				normal->ValorarComentarMediaInsertado(this->Catalogo[pos]);
			}else{
				cout << RED << "IDMedia" << IDMedia << " ya existe..." << RESET << endl;
			}
		}
	}else{
		cout << RED << "No existe IDMedia" << IDMedia << RESET << endl;
	}

}

void Cristofinity::RankGeneralMedia(){
	Media **Rank = new Media *[3];
	unsigned int TotalEncontrados = 0;
	cout << CYAN << "TOP 3 VALORACION MEDIA EN CATALOGO" << RESET << endl;
	for (int i = 0, j = 0; i < this->TotalCatalogo && j < 4; ++i)
	{
		if (j < 1)
		{
			Rank[0] = this->Catalogo[i];
			j++;
		}
		if (j == 1 && Rank[0]->getTotalValoracionEnCatalogo() <=  this->Catalogo[i]->getTotalValoracionEnCatalogo())
		{
			if (j == 1 && Rank[0]->getIDMedia() != this->Catalogo[i]->getIDMedia())
			{
				Rank[0] = this->Catalogo[i];
			}
		}
		if (j == 2 && Rank[1]->getIDMedia() != this->Catalogo[i]->getIDMedia())
		{
			if (j == 2 && Rank[0]->getIDMedia() != this->Catalogo[i]->getIDMedia())
			{
				if (Rank[1]->getTotalValoracionEnCatalogo() < this->Catalogo[i]->getTotalValoracionEnCatalogo())
				{
					Rank[1] = this->Catalogo[i];
				}
			}
		}
		if (j == 3 && Rank[2]->getIDMedia() != this->Catalogo[i]->getIDMedia())
		{
			if (j == 3 && Rank[1]->getIDMedia() != this->Catalogo[i]->getIDMedia())
			{
				if (j == 3 && Rank[0]->getIDMedia() != this->Catalogo[i]->getIDMedia())
				{
					if (Rank[2]->getTotalValoracionEnCatalogo() < this->Catalogo[i]->getTotalValoracionEnCatalogo())
					{
						Rank[2] = this->Catalogo[i];
					}
				}
			}
		}
		if (i == this->TotalCatalogo - 1)
		{
			TotalEncontrados = j;
			j++;
			for (int t = 0; t < this->TotalCatalogo; ++t)
			{
				if (j == 2 && Rank[0]->getIDMedia() != this->Catalogo[t]->getIDMedia())
				{
					Rank[j - 1] = this->Catalogo[t];
					t = this->TotalCatalogo;
				}
				if (j == 3 && Rank[1]->getIDMedia() != this->Catalogo[t]->getIDMedia() && Rank[0]->getIDMedia() != this->Catalogo[t]->getIDMedia())
				{
					Rank[j - 1] = this->Catalogo[t];
					t = this->TotalCatalogo;
				}
			}
			i = 0;
		}
	}
	for (int i = 0; i < TotalEncontrados; ++i)
	{
		cout << i+1 << "º)" << Rank[i]->getTitulo();
		cout << " -> Valoracion en Catalogo: " << Rank[i]->getTotalValoracionEnCatalogo() << " ";
		if (Serie *serie = dynamic_cast<Serie*>(Rank[i])){
			cout << RED << " SERIE";
		}else if (Pelicula *pelicula = dynamic_cast<Pelicula*>(Rank[i])){
			cout << YELLOW << " PELICULA";
		}else if(Cancion *cancion = dynamic_cast<Cancion*>(Rank[i])){
			cout << GREEN << " CANCION";
		}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(Rank[i])){
			cout << MAGENTA << " VIDEOJUEGO";
		}else {
			cout << " MEDIA";
		}
		cout << RESET << endl;
	}
	for (int i = 0; i < 3; ++i)
	{
		Rank[i] = 0;
	}
	delete [] Rank;
	Rank = 0;
}

void Cristofinity::RankTipoMedia(){
	Media **Top = new Media *[this->TotalCatalogo];
	int Tipo = 0;
	unsigned int limite = 0;
	cout << CYAN << "Por que tipo quieres Sacar el Ranking?" << RESET << endl;
	cout << RED << "1)SERIE" << RESET << endl;
	cout << YELLOW << "2)PELICULA" << RESET << endl;
	cout << GREEN << "3)CANCION" << RESET << endl;
	cout << MAGENTA << "4)VIDEOJUEGO" << RESET << endl;
	cin >> Tipo;
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		if (Serie *serie = dynamic_cast<Serie*>(this->Catalogo[i])){
			if (Tipo == 1)
			{
				Top[limite] = serie;
				limite++;
			}
		}else if (Pelicula *pelicula = dynamic_cast<Pelicula*>(this->Catalogo[i])){
			if (Tipo == 2)
			{
				Top[limite] = pelicula;
				limite++;
			}
		}else if(Cancion *cancion = dynamic_cast<Cancion*>(this->Catalogo[i])){
			if (Tipo == 3)
			{
				Top[limite] = cancion;
				limite++;
			}
		}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(this->Catalogo[i])){
			if (Tipo == 4)
			{
				Top[limite] = videojuego;
				limite++;
			}
		}
	}
	Media *aux;
	bool check = false;
	for (int i = 0; i < limite && !check; ++i)
	{
		check = true;
		for (int j = limite-1; j > i; --j)
		{
			if (Top[j]->getTotalValoracionEnCatalogo() > Top[j-1]->getTotalValoracionEnCatalogo())
			{
				check =false;
				aux = Top[j];
				Top[j] = Top[j-1];
				Top[j-1] = aux;
			}
		}
	}
	cout << BLUE << "EL Top 3 del Catalogo es: " << RESET << endl;
	for (int i = 0; i < limite && i < 3; ++i)
	{
		if (Tipo == 1)
		{
			cout << RED;
		}else if (Tipo == 2)
		{
			cout << YELLOW;
		}
		else if (Tipo == 3)
		{
			cout << GREEN;
		}
		else if (Tipo == 4)
		{
			cout << MAGENTA;
		}
		cout << Top[i]->getTitulo() << BOLDRED << " -> Puntuacion: " << Top[i]->getTotalValoracionEnCatalogo() << RESET << endl;
	}
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		Top[i] = 0;
	}
	delete [] Top;
	Top = 0;
}

void Cristofinity::CalcularValoracionCatalogo(){
	float TotalComentarios = 0.0, TotalAsociaciones = 0.0;
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		TotalAsociaciones += this->Catalogo[i]->getMeGusta();
		TotalComentarios += this->Catalogo[i]->getTotalVectorValoraciones();
	}
	if (TotalAsociaciones > 0 && TotalComentarios > 0)
	{
		float CalculoValoraciones = 0.0, CalculoAsociaciones = 0.0, CalculoComentarios = 0.0, CalculoTotal = 0.0;
		for (int i = 0; i < this->TotalCatalogo; ++i)
		{
			CalculoValoraciones = (this->Catalogo[i]->getValoracionMedia() * 0.5);
			CalculoAsociaciones = ((this->Catalogo[i]->getMeGusta() / TotalAsociaciones) * 0.3);
			CalculoComentarios = ((this->Catalogo[i]->getTotalVectorDinamicoComentarios() / TotalComentarios) * 0.2);
			CalculoTotal = (CalculoValoraciones + CalculoAsociaciones + CalculoComentarios);
			this->Catalogo[i]->setTotalValoracionEnCatalogo(CalculoTotal);
		}
	}
}

void Cristofinity::MenuUsuario(){
	int OpcionSeleccionada;
	bool SalirMenuUsuario = false;
	system("clear");
	do
	{
		cout << BOLDBLUE << "\nBienvenido Usuario " << this->UsuarioActual->getIDUsuario() << "." << RESET << endl;
		cout << "1) Mostrar Catalogo." << endl;
		cout << "2) Consultar Lista Asociada." << endl;
		cout << "3) Asociar Media." << endl;
		cout << "4) Desasociar Media." << endl;
		cout << "5) Ver Perfil Usuario." << endl;
		cout << "6) Editar Usuario." << endl;
		cout << "7) Mostrar Ranking por valoracion." << endl;
		cout << YELLOW << "8) Valorar y comentar Media." << RESET << endl;
		cout << "9) Mostrar Ranking por valoracion." << RESET << endl;
		cout << "10) Mostrar Ranking por Tipo Media." << RESET << endl;
		cout << "0) Salir." << endl;
		cout << "Seleccione una opcion: ";
		cin >> OpcionSeleccionada;
		switch (OpcionSeleccionada)
		{
			case 1:
				this->MostrarCatalogo();
				break;
			case 2:
				if (Normal *normal = dynamic_cast<Normal*>(this->UsuarioActual)){
					normal->MostrarListaMedia();
					normal->MostrarDetalleListaMedia();
				}
				break;
			case 3:
				this->AsociarMedia();
				this->CalcularValoracionCatalogo();
				break;
			case 4:
				this->DesasociarMedia();
				this->CalcularValoracionCatalogo();
				break;
			case 5:
				this->MostrarPerfilUsuario();
				break;
			case 6:
				this->EditarUsuarios();
				break;
			case 7:
				this->RankGeneralMedia();
				break;
			case 8:
				this->AniadirComentarioYValoracion();
				break;
			case 9:
				this->RankGeneralMedia();
				break;
			case 10:
				this->RankTipoMedia();
				break;
			case 0:
				SalirMenuUsuario = true;
				break;
			default:
				cout << RED << "Opcion no valida..." << RESET << endl;
		}
	} while (SalirMenuUsuario == false);
}

void Cristofinity::EditarMediaEnCatalogo(){
	int IDMedia = 0, pos = -1;
	Media *m = 0;
	cout << "Introduce el IDMedia a editar: ";
	cin >>IDMedia;
	pos = BuscarEnCatalogoPorIDMedia(IDMedia);
	if (pos >= 0)
	{
		m = this->Catalogo[pos];
		if (Administrador *admin = dynamic_cast<Administrador*>(this->UsuarioActual)){
			admin->EditarMedia(m);
		}else{
			cout << RED << "El usuario seleccionado no dispone de permisos de edicion..." << RESET << endl;
		}
	}else{
		cout << RED << "El IDMedia " << IDMedia << " no existe..." << RESET << endl;
	}
}

void Cristofinity::MenuAdministrador(){
	int OpcionSeleccionada;
	bool SalirMenuAdministrador = false;
	system("clear");
	do
	{
		cout << GREEN << "\nBienvenido Administrador " << this->UsuarioActual->getIDUsuario() << "." << RESET << endl;
		cout << "1) Mostrar Usuarios." << endl;
		cout << "2) Mostrar Catalogo." << endl;
		cout << "3) Añadir Usuario." << endl;
		cout << "4) Añadir Media al Catalogo." << endl;
		cout << "5) Editar Usuario." << endl;
		cout << "6) Editar Media." << endl;
		cout << "7) Borrar Media." << endl;
		cout << "8) Borrar Usuario." << endl;
		cout << "9) Buscar Media." << endl;
		cout << "10) Buscar Usuario." << endl;
		cout << "11) Mostrar Ranking por valoracion." << RESET << endl;
		cout << "12) Mostrar Ranking por Tipo Media." << RESET << endl;
		cout << "0) Salir." << endl;
		cout << "Seleccione una opcion: ";
		cin >> OpcionSeleccionada;
		switch (OpcionSeleccionada)
		{
			case 1:
				this->MostrarUsuarios();
				break;
			case 2:
				this->MostrarCatalogo();
				break;
			case 3:
				this->InsertarUsuario();
				break;
			case 4:
				this->InsertarMediaEnCatalogo();
				this->CalcularValoracionCatalogo();
				break;
			case 5:
				this->EditarUsuarios();
				break;
			case 6:
				this->EditarMediaEnCatalogo();
				break;
			case 7:
				this->MostrarCatalogo();
				this->BorrarMedia();
				this->CalcularValoracionCatalogo();
				break;
			case 8:
				this->MostrarUsuarios();
				this->BorrarUsuario();
				break;
			case 9:
				this->BuscarMediaEnCatalogo();
				break;
			case 10:
				this->BuscarUsuario();
				break;
			case 11:
				this->RankGeneralMedia();
				break;
			case 12:
				this->RankTipoMedia();
				break;
				
			case 0:
				SalirMenuAdministrador = true;
				break;
			default:
				cout << RED << "Opcion no valida..." << RESET << endl;
		}
		if (cin.good() != 1)
		{
			cin.clear();
			cin.ignore(256,'\n');
		}
	} while (SalirMenuAdministrador == false);
}

void Cristofinity::ImportarXML(string RutaXML){
	this->~Cristofinity();
	pugi::xml_document doc;
	pugi::xml_parse_result result = doc.load_file(RutaXML.c_str());
	cout << "STATUS: " << result << endl; 
	string CadenaXML;
	CadenaXML = doc.child("cristofinity").child("totalusuarios").child_value();
	this->TotalUsuarios = atoi(CadenaXML.c_str());
	CadenaXML = doc.child("cristofinity").child("totalcatalogo").child_value();
	this->TotalCatalogo = atoi(CadenaXML.c_str());
	this->VectorDinamicoUsuarios = new Usuario*[this->TotalUsuarios];
	this->Catalogo = new Media*[this->TotalCatalogo];
	//Insertado de Media
	Media *m;
	unsigned int i = 0;
	for (pugi::xml_node node = doc.child("cristofinity").child("catalogo").child("media"); node && i < this->TotalCatalogo; node = node.next_sibling("media"))
	{
		CadenaXML = node.child("tipo").child_value();
		if (CadenaXML == "Cancion")
		{
			Cancion *c;
			c = new Cancion;
			c->setArtista(node.child("artista").child_value());
			c->setAlbum(node.child("album").child_value());
			m = c;
		}else if (CadenaXML == "Pelicula")
		{
			Pelicula *p;
			p = new Pelicula;
			p->setReparto(node.child("reparto").child_value());
			p->setDireccion(node.child("direccion").child_value());
			p->setGuion(node.child("guion").child_value());
			p->setProductor(node.child("productor").child_value());
			m = p;
		}else if (CadenaXML == "Serie")
		{
			Serie *s;
			s = new Serie;
			s->setReparto(node.child("reparto").child_value());
			s->setDireccion(node.child("direccion").child_value());
			s->setGuion(node.child("guion").child_value());
			s->setProductor(node.child("productor").child_value());
			CadenaXML = node.child("temporadas").child_value();
			s->setTemporadas(atoi(CadenaXML.c_str()));
			CadenaXML = node.child("capitulos").child_value();
			s->setCapitulos(atoi(CadenaXML.c_str()));
			if (node.child("estado").child_value() == "En emision")
			{
				s->setEstado(true);
			}else{
				s->setEstado(false);
			}
			m = s;
		}else if (CadenaXML == "Videojuego")
		{
			Videojuego *v;
			v = new Videojuego;
			v->setDesarrollador(node.child("desarrollador").child_value());
			v->setEditor(node.child("editor").child_value());
			CadenaXML = node.child("jugadores").child_value();
			v->setJugadores(atoi(CadenaXML.c_str()));
			v->setPlataformas(node.child("plataformas").child_value());
			m = v;
		}else{
			m = new Media;
		}
		CadenaXML = node.child("idmedia").child_value();
		m->setIDMedia(atoi(CadenaXML.c_str()));
		m->setTitulo(node.child("titulo").child_value());
		m->setGenero(node.child("genero").child_value());
		CadenaXML = node.child("duracionensegundos").child_value();
		m->setDuracionEnSegundos(atoi(CadenaXML.c_str()));
		m->setFechaPublicacion(node.child("fechapublicacion").child_value());
		CadenaXML = node.child("pegi").child_value();
		m->setPegi(atoi(CadenaXML.c_str()));
		m->setDescripcion(node.child("descripcion").child_value());
		CadenaXML = node.child("totalmegusta").child_value();
		m->setMeGusta(atoi(CadenaXML.c_str()));
		CadenaXML = node.child("valoracionmediaencatalogo").child_value();
		m->setTotalValoracionEnCatalogo(atof(CadenaXML.c_str()));
		CadenaXML = node.child("totalvaloraciones").child_value();
		unsigned int j = 0, limite_valoraciones = atoi(CadenaXML.c_str());
		for (pugi::xml_node node_v = node.child("valoraciones").child("valoracion"); node && j < limite_valoraciones; node_v = node_v.next_sibling("valoracion"))
		{
			CadenaXML = node_v.child("puntuacion").child_value();
			m->InsertarValoracion(atof(CadenaXML.c_str()), node_v.child("idusuario").child_value());
			j++;
		}
		CadenaXML = node.child("totalcomentarios").child_value();
		unsigned int limite_comentarios = atoi(CadenaXML.c_str());
		j = 0;
		for (pugi::xml_node node_v = node.child("listacomentarios").child("comentario"); node && j < limite_comentarios; node_v = node_v.next_sibling("comentario"))
		{
			CadenaXML = node_v.child("texto").child_value();
			m->InsertarComentario(CadenaXML, node_v.child("login").child_value());
			j++;
		}
		this->Catalogo[i] = m;
		i++;
		m = 0;
	}
	Usuario *u;
	i = 0;
	for (pugi::xml_node node = doc.child("cristofinity").child("usuarios").child("usuario"); node && i < this->TotalUsuarios; node = node.next_sibling("usuario"))
	{
		CadenaXML = node.child("tipousuario").child_value();
		if (CadenaXML == "normal")
		{
			Normal *n = new Normal;
			CadenaXML = node.child("totallistamedia").child_value();
			unsigned int limite_listamedia = atoi(CadenaXML.c_str());
			CadenaXML = node.child("listamedia").child_value();
			unsigned int MediasAsociados[limite_listamedia];
			string CadenaAuxiliar;

			for (int k = 0, j = 0; k < CadenaXML.size() && j < limite_listamedia; ++k)
			{
				if (CadenaXML[k] != ' ')
				{
					CadenaAuxiliar += CadenaXML[k];
				}else if(CadenaXML[k] == ' ' && k != 0){
					cout << atoi(CadenaAuxiliar.c_str()) << endl;
					MediasAsociados[j] = atoi(CadenaAuxiliar.c_str());
					CadenaAuxiliar.clear();
					j++;
				}
				if (k == CadenaXML.size() - 1)
				{
					cout << atoi(CadenaAuxiliar.c_str()) << endl;
					MediasAsociados[j] = atoi(CadenaAuxiliar.c_str());
					CadenaAuxiliar.clear();
				}
			}
			bool checkMedia = false;
			for (int j = 0; j < limite_listamedia; ++j)
			{
				checkMedia = false;
				for (int k = 0; k < this->TotalCatalogo && checkMedia == false; ++k)
				{
					if (this->Catalogo[k]->getIDMedia() == MediasAsociados[j])
					{
						n->InsertarMediaEnListaMedia(this->Catalogo[k]);
						checkMedia = true;
					}
				}
			}
			u = n;
		}else if (CadenaXML == "admin")
		{
			Administrador *a = new Administrador;
			u = a;
		}

		u->setIDUsuario(node.child("login").child_value());
		u->setNombre(node.child("nombre").child_value());
		u->setApellidos(node.child("apellidos").child_value());
		u->setURLFotoPerfil(node.child("urlfotoperfil").child_value());
		this->VectorDinamicoUsuarios[i] = u;
		i++;
	}
}

void Cristofinity::ExportarXML(string RutaXML){
	ofstream fs;
	fs.open(RutaXML.c_str());
	fs << "<cristofinity>" << endl;

	fs << "\t<totalcatalogo>" << this->TotalCatalogo << "</totalcatalogo>" << endl;
	fs << "\t<totalusuarios>" << this->TotalUsuarios << "</totalusuarios>" << endl;

	fs << "\t<catalogo>" << endl;
	for (int i = 0; i < this->TotalCatalogo; ++i)
	{
		fs << "\t\t<media>" << endl;
		fs << "\t\t\t<idmedia>" << this->Catalogo[i]->getIDMedia() << "</idmedia>" << endl;
		fs << "\t\t\t<titulo>" << this->Catalogo[i]->getTitulo() << "</titulo>" << endl;
		fs << "\t\t\t<genero>" << this->Catalogo[i]->getGenero() << "</genero>" << endl;
		fs << "\t\t\t<duracionensegundos>" << this->Catalogo[i]->getDuracionEnSegundos() << "</duracionensegundos>" << endl;
		fs << "\t\t\t<fechapublicacion>" << this->Catalogo[i]->getFechaPublicacion() << "</fechapublicacion>" << endl;
		fs << "\t\t\t<pegi>" << this->Catalogo[i]->getPegi() << "</pegi>" << endl;
		fs << "\t\t\t<descripcion>" << this->Catalogo[i]->getDescripcion() << "</descripcion>" << endl;
		if(Serie *serie = dynamic_cast<Serie*>(this->Catalogo[i])){
			fs << "\t\t\t<tipo>Serie</tipo>" << endl;
			fs << "\t\t\t<reparto>" << serie->getReparto() << "</reparto>" << endl;
			fs << "\t\t\t<direccion>" << serie->getDireccion() << "</direccion>" << endl;
			fs << "\t\t\t<guion>" << serie->getGuion() << "</guion>" << endl;
			fs << "\t\t\t<productor>" << serie->getProductor() << "</productor>" << endl;
			fs << "\t\t\t<temporadas>" << serie->getTemporadas() << "</temporadas>" << endl;
			fs << "\t\t\t<capitulos>" << serie->getCapitulos() << "</capitulos>" << endl;	
			fs << "\t\t\t<estado>" << serie->getEstado() << "</estado>" << endl;		
		}else if(Pelicula *pelicula = dynamic_cast<Pelicula*>(this->Catalogo[i])){
			fs << "\t\t\t<tipo>Pelicula</tipo>" << endl;
			fs << "\t\t\t<reparto>" << pelicula->getReparto() << "</reparto>" << endl;
			fs << "\t\t\t<direccion>" << pelicula->getDireccion() << "</direccion>" << endl;
			fs << "\t\t\t<guion>" << pelicula->getGuion() << "</guion>" << endl;
			fs << "\t\t\t<productor>" << pelicula->getProductor() << "</productor>" << endl;	
		}else if(Cancion *cancion = dynamic_cast<Cancion*>(this->Catalogo[i])){
			fs << "\t\t\t<tipo>Cancion</tipo>" << endl;
			fs << "\t\t\t<artista>" << cancion->getArtista() << "</artista>" << endl;
			fs << "\t\t\t<album>" << cancion->getAlbum() << "</album>" << endl;
		}else if(Videojuego *videojuego = dynamic_cast<Videojuego*>(this->Catalogo[i])){
			fs << "\t\t\t<tipo>Videojuego</tipo>" << endl;
			fs << "\t\t\t<desarrollador>" << videojuego->getDesarrollador() << "</desarrollador>" << endl;
			fs << "\t\t\t<plataformas>" << videojuego->getPlataformas() << "</plataformas>" << endl;
			fs << "\t\t\t<editor>" << videojuego->getEditor() << "</editor>" << endl;
			fs << "\t\t\t<jugadores>" << videojuego->getJugadores() << "</jugadores>" << endl;
		}else if(Media *media = dynamic_cast<Media*>(this->Catalogo[i])){
			fs << "\t\t\t<tipo>Media</tipo>" << endl;
		}
		fs << "\t\t\t<puntuacion>" << this->Catalogo[i]->getValoracionMedia() << "</puntuacion>" << endl;
		fs << "\t\t\t<totalmegusta>" << this->Catalogo[i]->getMeGusta() << "</totalmegusta>" << endl;
		fs << "\t\t\t<valoracionmediaencatalogo>" << this->Catalogo[i]->getTotalValoracionEnCatalogo() << "</valoracionmediaencatalogo>" << endl;
		fs << "\t\t\t<totalcomentarios>" << this->Catalogo[i]->getTotalVectorDinamicoComentarios() << "</totalcomentarios>" << endl;
		fs << "\t\t\t<totalvaloraciones>" << this->Catalogo[i]->getTotalVectorValoraciones() << "</totalvaloraciones>" << endl;
		fs << this->Catalogo[i]->InfoXML();
		fs << "\t\t</media>" << endl;
	}
	fs << "\t</catalogo>" << endl;
	fs << "\t<usuarios>" << endl;
	for (int i = 0; i < this->TotalUsuarios; ++i)
	{
		fs << "\t\t<usuario>" << endl;
		fs << "\t\t\t<login>" << this->VectorDinamicoUsuarios[i]->getIDUsuario() << "</login>" << endl;
		fs << "\t\t\t<nombre>" << this->VectorDinamicoUsuarios[i]->getNombre() << "</nombre>" << endl;
		fs << "\t\t\t<apellidos>" << this->VectorDinamicoUsuarios[i]->getApellidos() << "</apellidos>" << endl;
		fs << "\t\t\t<urlfotoperfil>" << this->VectorDinamicoUsuarios[i]->getURLFotoPerfil() << "</urlfotoperfil>" << endl;
		if(Normal *normal = dynamic_cast<Normal*>(this->VectorDinamicoUsuarios[i])){
			fs << "\t\t\t<tipousuario>normal</tipousuario>" << endl;
			fs << "\t\t\t<totallistamedia>" << normal->getTotalListaMedia() << "</totallistamedia>" << endl;
			fs << normal->InfoXML();
		}else if(Administrador *admin = dynamic_cast<Administrador*>(this->VectorDinamicoUsuarios[i])){
			fs << "\t\t\t<tipousuario>admin</tipousuario>" << endl;
		}
		fs << "\t\t</usuario>" << endl;
	}
	fs << "\t</usuarios>" << endl;
	fs << "</cristofinity>" << endl;
	fs.close();
}
//void Cristofinity::InsertarUsuariosPorDefecto();