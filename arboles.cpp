/*
******************************************************************
PROGRAMA: Practica 5, Arboles.
ASIGNATURA: 2� CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 26 de Abril del 2012
******************************************************************
*/

#include "arboles.h"





bool ArbolBB::EsVacio(nodoBB *nodo)
{
  return nodo==NULL;
};

bool ArbolBB::EsHoja(nodoBB *nodo) 
{
  return !nodo->dcho && !nodo->izdo;
};

void ArbolBB::imprime()
{ 
  imprimeN(raiz,1); 
};

void ArbolBB::imprimeN( nodoBB* &nodo, int margen )
{
if (!EsVacio(nodo))
{
  imprimeN( nodo->izdo, margen + 1 ) ;
  for (int i = 0; i < margen; i++)
  {  
    cout << " ";
    cout << nodo->dato ;
  }  
  imprimeN( nodo->dcho, margen + 1 ) ;
};
};

const int ArbolBB::Tam()
{ 
  TamRama(raiz); 
  
};

const int ArbolBB::TamRama(nodoBB* &nodo)
{
if (nodo == NULL)
  return 0 ;
return 1 + TamRama(nodo->izdo) + TamRama(nodo->dcho);
};


const int ArbolBB::Alt() 
{ 
  AltN(raiz); 
  
};

const int ArbolBB::AltN(nodoBB* &nodo)
{
  if (nodo == NULL) return 0 ;

  int alt_i = AltN(nodo->izdo) ;
  int alt_d = AltN(nodo->izdo) ;
  if (alt_i > alt_d)
    return alt_d++ ;
  else 
    return alt_i++ ;
};



const bool ArbolBB::Equilibrado() 

{
  return EquilibrioRama(raiz); 
  
};

const bool ArbolBB::EquilibrioRama(nodoBB *nodo)
{
  if (nodo == NULL) return true ;
    int eq = TamRama(nodo->izdo) - TamRama(nodo->dcho);
  switch (eq) 
  {
  case -1:
  case 0:
  case 1:
  return EquilibrioRama(nodo->izdo) &&  EquilibrioRama(nodo->dcho) ;
  default: return false ;
  }
};

void ArbolBB::InsertaEquil(const int dato)
{
  InsertaEquilRama(dato, raiz) ;
};

void ArbolBB::InsertaEquilRama(const int dato,nodoBB* &nodo)
{
  if (nodo != NULL)
  {
    if (TamRama(nodo->izdo) < TamRama(nodo->dcho))
      InsertaEquilRama(dato,nodo->izdo);
    else 
      InsertaEquilRama(dato,nodo->dcho);
  };
  if (nodo == NULL)
  {
    nodoBB* nodo ;
  };
};



ArbolBB::nodoBB* ArbolBB::Buscar( int clave_dada )
{ 
  return BuscarRama(raiz,clave_dada); 
};

ArbolBB::nodoBB* ArbolBB::BuscarRama( nodoBB* &nodo,int clave_dada) 
{
  if (nodo == NULL)
    return NULL ;
  if (clave_dada == nodo->clave)
    return  nodo ;
  if (clave_dada < nodo->clave)
    return BuscarRama(nodo->izdo,clave_dada) ;
  
  return BuscarRama(nodo->dcho,clave_dada) ;
};

void ArbolBB::Insertar( int clave_dada) 
{
  InsertarRama( raiz, clave_dada) ; 
};


void ArbolBB::InsertarRama( nodoBB* &nodo, int clave_dada)
{
  if (nodo == NULL) 
  {
    //nodoBB* nodo ; 
    nodoBB* nodo = new nodoBB( clave_dada, 0 ) ;
    //nodo->clave = clave_dada ;
  }
  else 
  {
    if (clave_dada < nodo->clave)
      InsertarRama(nodo->izdo,clave_dada);
    else 
      InsertarRama(nodo->dcho,clave_dada);
  };
};

void ArbolBB::Eliminar( int clave_dada)
{
  EliminarRama( raiz, clave_dada) ; 
  
};

int ArbolBB::EliminarRama( nodoBB* &nodo, int clave_dada) 
{
  if (nodo==NULL) return NULL ;
	
  if (clave_dada < nodo->clave)
    EliminarRama(nodo->izdo,clave_dada) ;
  else
    if (clave_dada > nodo->clave)
      EliminarRama(nodo->dcho,clave_dada) ;
    else 
    {
      if(EsHoja(nodo)) //si la clave dada es igual a la clave del nodo y es una hoja pues borramos el nodo
      {
	delete(nodo) ;
	nodo = NULL;
      };
      
    };
};



void ArbolAVL::rotacion_DD (nodoAVL* &nodo) 

{
  nodoAVL* nodo1 = nodo->dcho ;
  nodo->dcho = nodo1->izdo ;
  nodo1->izdo = nodo ;
  if (nodo1->bal = -1) 
  {
    nodo->bal = 0 ;
    nodo1->bal = 0 ;
  }
  else  // nodo1->bal == 0
  {
    nodo->bal = -1 ;
    nodo1->bal = 1 ;
  }
  nodo = nodo1 ;
};

void ArbolAVL::rotacion_II (nodoAVL* &nodo)
{
  nodoAVL* nodo1 = nodo->izdo ;
  nodo->izdo = nodo1->dcho ;
  nodo1->dcho = nodo ;
  if (nodo1->bal = 1)
  {
    nodo->bal = 0 ;
    nodo1->bal = 0 ;
  }
  else 
  { // nodo1->bal == 0
    nodo->bal = 1 ;
    nodo1->bal = -1 ;
  }
  nodo = nodo1 ;
};

void ArbolAVL::rotacion_ID (nodoAVL* &nodo)
{
  nodoAVL* nodo1 = nodo->izdo ;
  nodoAVL* nodo2 = nodo1->dcho ;
  nodo->izdo = nodo2->dcho ;
  nodo2->dcho = nodo ;
  nodo1->dcho = nodo2->izdo ;
  nodo2->izdo = nodo1 ;
  if (nodo2->bal == -1)
    nodo1->bal = 1 ;
  else 
    nodo1->bal = 0 ;
  if (nodo2->bal == 1)
    nodo->bal = -1;
  else 
    nodo->bal = 0 ;
  
  nodo2->bal = 0 ;
  nodo = nodo2 ;
};

void ArbolAVL::rotacion_DI (nodoAVL* &nodo)
{
  nodoAVL* nodo1 = nodo->dcho ;
  nodoAVL* nodo2 = nodo1->izdo ;
  nodo->dcho = nodo2->izdo ;
  nodo2->izdo = nodo ;
  nodo1->izdo = nodo2->dcho ;
  nodo2->dcho = nodo1 ;
  if (nodo2->bal == 1)
    nodo1->bal = -1 ;
  else 
    nodo1->bal = 0 ;
  if (nodo2->bal == -1)
    nodo->bal = 1;
  else 
    nodo->bal = 0 ;
  nodo2->bal = 0 ;
  nodo = nodo2 ;
};


void ArbolAVL::Insertar( int ClaveDada) 
{
  nodoAVL *nuevo = new nodoAVL( ClaveDada, 0 ) ;
  bool crece = true ;
  inserta_bal( raiz, nuevo,ClaveDada, &crece) ;
};

void ArbolAVL::inserta_bal( nodoAVL* &nodo,nodoAVL* &nuevo, int ClaveDada, bool* crece)
{
  if (nodo == NULL) 
  {
    nodo = nuevo ;
    *crece = true ; 
  }
  else if (nuevo->clave < nodo->clave) 
  {
    inserta_bal(nodo->izdo,nuevo,ClaveDada,crece);
    if (crece) re_balancea_izda(nodo);
  }
  else 
  {
    inserta_bal(nodo->dcho,nuevo,ClaveDada,crece);
    if (crece) re_balancea_izda(nodo);
  };
};

void ArbolAVL::re_balancea_izda (nodoAVL* &nodo)
{
switch (nodo->bal) 
{
  case -1 : 
    nodo->bal = 0 ;
    crece = false ;
    break ;
  case 0 : 
    nodo->bal = 1 ;
    break ;
  case 1 : 
    nodo = nodo->izdo ;
    if (nodo->bal == 1)
      rotacion_II(nodo);
    else 
      rotacion_ID(nodo) ;
    crece = false;
};

};

void ArbolAVL::re_balancea_dcha (nodoAVL* &nodo) 
{
  switch (nodo->bal) 
  {
    case 1 : 
      nodo->bal = 0 ;
      crece = false ;
      break ;
    case 0 : 
      nodo->bal = -1 ;
      break ;
    case -1 : 
      nodo = nodo->dcho ;
      if (nodo->bal == -1)
	rotacion_DD(nodo);
      else rotacion_DI(nodo) ;
    crece = false;
  };
};

void ArbolAVL::eliminar( int ClaveDada)
{
  bool decrece = false ;
  elimina_rama( raiz, ClaveDada, &decrece) ; 
  
}
int ArbolAVL::elimina_rama( nodoAVL* &nodo, int ClaveDada, bool* decrece)
{
  if (nodo == NULL) return 0 ;
  if (ClaveDada < nodo->clave) 
  {
    elimina_rama(nodo->izdo,ClaveDada,decrece);
    if (decrece) re_balancea_izda(nodo,decrece);
  }
  else if (ClaveDada > nodo->clave) 
  {
    elimina_rama(nodo->dcho,ClaveDada,decrece);
    if (decrece) re_balancea_dcha(nodo,decrece);
  }
  else // ClaveDada == nodo->clave
  {
  nodoAVL* otro = nodo ;
  
  if (otro->izdo == NULL) 
  {
    nodo = otro->dcho ;
    *decrece = true ;
  }
  else if (otro->dcho == NULL)
  {
    nodo = otro->izdo ;
    *decrece = true ;
  }
  else
  {
    elimina_rama(nodo->izdo,ClaveDada,decrece);
    if (decrece) re_balancea_izda(nodo,decrece);
  };
  delete otro;
  };
  

  nodoAVL* &Eliminado = nodo;
  if (nodo->dcho == NULL)
  { 
    nodo = nodo->izdo; 
  }
  else 
  {
  if (nodo->izdo == NULL)
  {
    nodo = nodo->dcho;
  }
  else 
  {
    nodo = nodo->izdo ;
    while (nodo->dcho != NULL) 
    {
      nodo = nodo->dcho ;
    };
    Eliminado->clave = nodo->clave ;
    Eliminado->dato = nodo->dato ;
    nodo = nodo->izdo ;
    *decrece = true ;
    delete nodo ;
  };
  };
};

void ArbolAVL::re_balancea_izda (nodoAVL* &nodo,bool* decrece)
{
  switch (nodo->bal) 
  {
    case -1 : 
      nodoAVL* otro = nodo->dcho ;
      if (nodo->bal > 0)
      rotacion_DI(nodo) ;
      else 
      {
	if (nodo->bal == 0)
	*decrece = false ;
	rotacion_DD(nodo) ;
      };
    break ;
    
    
  };
};

void ArbolAVL::re_balancea_dcha (nodoAVL* &nodo,bool* decrece) 
{
  switch (nodo->bal) 
  {
  case 1 : 
    nodoAVL* otro = nodo->izdo ;
    if (nodo->bal > 0)
    rotacion_ID(nodo) ;
    else
    {
    if (nodo->bal == 0)
    decrece = false ;
    rotacion_II(nodo) ;
    };
  break ;
  
  };
};  



void ArbolAVL::imprime()
{ 
  imprimeN(raiz,1); 
};

void ArbolAVL::imprimeN( nodoAVL* &nodo, int margen )
{

  imprimeN( nodo->izdo, margen + 1 ) ;
  for (int m = 0; m < margen; m++)
  cout << " ";
  cout << nodo->dato ;
  imprimeN( nodo->dcho, margen + 1 ) ;

};

bool ArbolAVL::EsHoja(nodoAVL *nodo) 
{
  return !nodo->dcho && !nodo->izdo;
};



















