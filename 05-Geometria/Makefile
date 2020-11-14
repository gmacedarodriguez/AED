# Makes Poligono.exe
# Ezequiel Maceda
# 2020

#
CC = g++
CFLAGS  = -g -Wall -I./includes -Wconversion -std=c++17

default: Main

Main: PoligonoCont.o Punto.o Color.o Main.o	#Cambiar PoligonoCont o PoligonoLink aca tambien
	$(CC) $(CFLAGS) -o Main PoligonoCont.o Punto.o Color.o Main.o

PoligonoCont.o: PoligonoCont.cpp 	
	$(CC) $(CFLAGS) -c PoligonoCont.cpp

#PoligonoLink.o: PoligonoLink.cpp 	
#	$(CC) $(CFLAGS) -c PoligonoLink.cpp

Punto.o:  Punto.cpp 
	$(CC) $(CFLAGS) -c Punto.cpp


Color.o:  Color.cpp 
	$(CC) $(CFLAGS) -c Color.cpp


Main.o:  Main.cpp 
	$(CC) $(CFLAGS) -c Main.cpp

clean: 
	$(RM) Main *.o *~