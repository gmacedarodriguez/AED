# Makes Poligono.exe
# Ezequiel Maceda
# 2020

#
CC = g++
CFLAGS  = -g -Wall -I./includes -Wconversion -std=c++17

default: Poligono

Poligono: Poligono.o PoligonoTest.o
	$(CC) $(CFLAGS) -o Poligono Poligono.o PoligonoTest.o


Poligono.o:  Poligono.cpp 
	$(CC) $(CFLAGS) -c Poligono.cpp


PoligonoTest.o:  PoligonoTest.cpp 
	$(CC) $(CFLAGS) -c PoligonoTest.cpp

clean: 
	$(RM) Poligono *.o *~