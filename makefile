todo: main

Alumno.o: Alumno.h Alumno.cpp
	g++ -c Alumno.cpp -Wall

Abb.o: Abb.h Abb.cpp
	g++ -c Abb.cpp -Wall

main: test_arbol.o Alumno.o Abb.o
	g++ test_arbol.o Alumno.o Abb.o -o main

limpiar:
	rm test_arbol.o
	rm main
