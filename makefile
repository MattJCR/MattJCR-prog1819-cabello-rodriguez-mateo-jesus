#Archivo makefile
program: main cristofinity usuario normal administrador media cancion pelicula serie videojuego
	g++ -o program main.o cristofinity.o usuario.o normal.o administrador.o media.o cancion.o pelicula.o serie.o videojuego.o
main: main.cpp
	g++ -c -o main.o main.cpp
cristofinity: cristofinity.cpp
	g++ -c -o cristofinity.o cristofinity.cpp
usuario: usuario.cpp
	g++ -c -o usuario.o usuario.cpp
normal: normal.cpp
	g++ -c -o normal.o normal.cpp
administrador: administrador.cpp
	g++ -c -o administrador.o administrador.cpp
media: media.cpp
	g++ -c -o media.o media.cpp
cancion: cancion.cpp
	g++ -c -o cancion.o cancion.cpp
pelicula: pelicula.cpp
	g++ -c -o pelicula.o pelicula.cpp
serie: serie.cpp
	g++ -c -o serie.o serie.cpp
videojuego: videojuego.cpp
	g++ -c -o videojuego.o videojuego.cpp
git: program
	rm -r *.o

