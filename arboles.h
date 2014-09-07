/*
******************************************************************
PROGRAMA: Practica 5, Arboles.
ASIGNATURA: 2� CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 26 de Abril del 2012
******************************************************************
*/

#if !defined(_ARBOLES_H_)
#define _ARBOLES_H_


#include <cstddef>  //para el NULL
#include <iostream>

using namespace std;

class ArbolBB   //clase arbol binario de busqueda
{      
  private:
    class nodoBB 
    { // Clase local: nodo de ArbolBB
      public:
      // Constructor:
      nodoBB(int dat, int cl,nodoBB *iz=NULL, nodoBB *de=NULL) :  dato(dat), clave(cl), izdo(iz), dcho(de) {}
      // Miembros:
      int dato;
      int clave;
      nodoBB *izdo;
      nodoBB *dcho;
    };
  

  public:
    nodoBB *raiz;   //puntero a la clase nodo
    
    bool EsVacio(nodoBB *nodo);  //esta vacio el arbol�?
    bool EsHoja(nodoBB *nodo);   //es un nodo hoja�? 
    void imprime();              //sacamos por pantalla el arbol
    void imprimeN( nodoBB* &nodo, int margen);
    const int Tam();                 //tama�o del arbol
    const int TamRama(nodoBB* &nodo);
    const int Alt();           //altura del arbol
    const int AltN(nodoBB* &nodo);
    const bool Equilibrado();      //el arbol binario esta equilibrado�?
    const bool EquilibrioRama(nodoBB *nodo);
    void InsertaEquil(const int dato);  //insertar dato de forma equilibrada
    void InsertaEquilRama(const int dato,nodoBB* &nodo);
    nodoBB* Buscar( int clave_dada);   //buscar dato en el arbol binario
    nodoBB* BuscarRama( nodoBB* &nodo,int clave_dada);
    void Insertar( int clave_dada);   //insertamos dato en el arbol binario 
    void InsertarRama( nodoBB* &nodo, int clave_dada);
    void Eliminar( int clave_dada);   //borramos  un dato
    int EliminarRama( nodoBB* &nodo, int clave_dada);
    
    
    ArbolBB() : raiz(NULL) {}  //constructor
    ~ArbolBB() {  } //destructor 
 
    
    
};    


class ArbolAVL 
{
  private:
    class nodoAVL 
      { // Clase local: nodo de ArbolAVL
      public:
	// Constructor:
	nodoAVL(int dat, int cl,nodoAVL *iz=NULL, nodoAVL *de=NULL) : dato(dat), clave(cl), bal(0),izdo(iz), dcho(de) {}
	// Miembros:
	int dato; int clave; int bal; 
	nodoAVL *izdo; nodoAVL *dcho;
      };
      
    nodoAVL *raiz;
    
  public:
    void Insertar( int ClaveDada);
    void inserta_bal( nodoAVL* &nodo,nodoAVL* &nuevo, int ClaveDada, bool* crece);
    void re_balancea_izda (nodoAVL* &nodo);
    void re_balancea_dcha (nodoAVL* &nodo);
    void eliminar( int ClaveDada);
    int elimina_rama( nodoAVL* &nodo,int ClaveDada, bool* decrece);
    void re_balancea_izda (nodoAVL* &nodo,bool* decrece);
    void re_balancea_dcha (nodoAVL* &nodo,bool* decrece);
    void rotacion_DD (nodoAVL* &nodo);
    void rotacion_II (nodoAVL* &nodo);
    void rotacion_ID (nodoAVL* &nodo);
    void rotacion_DI (nodoAVL* &nodo);
    void imprime();              //sacamos por pantalla el arbol
    void imprimeN( nodoAVL* &nodo, int margen);
    bool EsVacio(nodoAVL *nodo);  //esta vacio el arbol�?
    bool EsHoja(nodoAVL *nodo); 
    bool crece;
    
    ArbolAVL() : raiz(NULL) {}  //constructor
    ~ArbolAVL() {  } //destructor 
    
};








#endif