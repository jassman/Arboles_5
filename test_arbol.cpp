#include<vector>
#include<iostream>
#include <fstream>
#include"Alumno.h"
#include"Abb.h"

using namespace std;

int main ()
{
	
	cout << "hola" <<endl;

	ABB arbol;
	ofstream h;
	unsigned t = 3;
	for(int i=0; i<1000; i++)
	{
		Alumno al(t);
		arbol.insertar(al.getDNI(), al);
	}
	h.open("fichero.dat");
	arbol.inorden(h);

	return 0;
}

