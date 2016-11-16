/**
*    Clase abb
*/

#include "Abb.h"
/**
*    Constructor implícito
*/
ABB::ABB()
{
    miRaiz = NULL;
}

/**
*    Destructor de la clase
*/
ABB::~ABB()
{
	destruir(miRaiz);
	inorden(cout);
}
/**
*    Función auxiliar del destructor.
*
*@param &raiz Nodo raiz que se quiere destruir.
*
*/
void ABB::destruir(PtrNodoBin &raiz)
{
	if (raiz != NULL)
    {
        destruir(raiz->izq);
        destruir(raiz->der);
        //delete raiz;
        raiz = NULL;
    }
}

/**
*    Función insertar elemento en el arbol.
*/
bool ABB::insertarAux(PtrNodoBin &raiz, const TipoClave &clave, const TipoDato & dato)
{
	bool ok;
	
	if (raiz == NULL){
		raiz = new ABB::NodoBin(clave, dato);
		ok = true;
	}
	else if(clave < raiz->clave)
		return(insertarAux(raiz->izq, clave, dato));
	else if(raiz->clave < clave)
		return(insertarAux(raiz->der, clave, dato));
	else // ya existe !
		ok = false;
		
	return ok;		
}

/**
*    Función auxiliar para buscar un elemento en el arbol.
*/
bool ABB::buscarAux(PtrNodoBin raiz, const TipoClave &clave, TipoDato &dato) const
{
	if(raiz == NULL)
		return false;
	if(clave < raiz->clave)
		return(buscarAux(raiz->izq, clave, dato));
	else if(raiz->clave < clave)
		return(buscarAux(raiz->der, clave, dato));
	else // encontrado
	{
		dato = raiz->dato;
		return true;
	}
}

/**
*    Función para buscar un elemento en el arbol.
*/
bool ABB::buscar(const TipoClave &clave, TipoDato &dato) const
{
	bool c = buscarAux(miRaiz, clave, dato);
	return c;
}

/**
*    Función para insertar un elemento en el arbol.
*/
bool ABB::insertar(const TipoClave &clave, const TipoDato &dato)
{
	bool b = insertarAux(miRaiz, clave, dato);
	return b;
}
/**
*    Función para comprobar si el arbol está vacio.
*/
bool ABB::vacio() const
{
	if (miRaiz == NULL)
		return true;
	else
		return false;	
}
/**
*    Función para mostrar el arbol por pantalla en inorden.
*/
void ABB::inorden(ostream & sal) const
{
	inordenAux(sal, miRaiz);
}

/**
*    Función auxiliar para mostrar el arbol por pantalla.
*/
void ABB::inordenAux(ostream & sal, PtrNodoBin raiz) const
{
	if(raiz != NULL)
     {
          inordenAux(sal, raiz->izq);
          sal << raiz->dato << endl;
          inordenAux(sal, raiz->der);
     }
}

/**
*    Función para obtener el tamaño del arbol.
*/
unsigned int ABB::tam() const
{
	return tamAux(miRaiz);
}

/**
*    Función auxiliar para obtener el tamaño del arbol.
*/
unsigned int ABB::tamAux(PtrNodoBin nodo) const
{
	if (nodo == NULL)
		return 0;
	else
		return 1 + tamAux(nodo->izq) + tamAux(nodo->der);
	
}
/**
*    Función para obtener la altura del arbol.
*
*/
unsigned int ABB::altura() const
{
   unsigned int altura = auxAltura(miRaiz); // Función auxiliar
   return altura;
}

/**
*    Función auxiliar para obtener la altura del arbol.
*/
unsigned int ABB::auxAltura(PtrNodoBin nodo) const
{
   int altura_derecha = 0;
   int altura_izquierda = 0;
   int altura_resultado = 0;
   
   if (nodo->izq == NULL && nodo->der == NULL)
   		return 1;
   else
   {
   		if(nodo->izq) 
       		altura_izquierda = auxAltura(nodo->izq);
   
   		if(nodo->der)   
       		altura_derecha = auxAltura(nodo->der);
       		
       	altura_resultado = max(altura_izquierda, altura_derecha) + 1;
   
   }
   
   return altura_resultado;
}
