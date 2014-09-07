/*
******************************************************************
PROGRAMA: Practica 5, Arboles.
ASIGNATURA: 2� CURSO, Algoritmos y Estructuras de Datos Avanzados.
AUTOR: Jose Antonio Rodriguez Leandro. 
FECHA: 26 de Abril del 2012
******************************************************************
*/

#include "arboles.h"
#include <iostream>

using namespace std;

main()
{

    ArbolBB  arbolBinario;
    ArbolAVL arbolBalanceado;
    float dato=0;
    int menu=0,altura=0,tam=0;
    bool equilibrado;
    char pausa;
    
    do
    {  
      cout << "\n\n\n\n\n\n\n\n" << "\t\t" << "PRACTICA 5. ARBOLES BINARIOS\n" << "\t***************************************\n\n\n";
      cout << "MENU:\n" << "\t1.INSERTAR DATO.\n" << "\t2.BUSCAR DATO.\n" << "\t3.BORRAR DATO.\n" << "\t4.MOSTRAR ARBOL\n" << "\t5.SALIR.\n\n\n";
      cin >> menu;
      
      switch(menu)
      {
	case 1:
	  cout << "\n\nINSERTAR DATO." << "\n\nDATO: ";
	  cin >> dato;
	  
	  arbolBinario.Insertar(dato);
	  arbolBalanceado.Insertar(dato);
	  
	  arbolBinario.imprime();   //mostramos el arbol
	  //arbolBalanceado.imprime();
	  
	  equilibrado = arbolBinario.Equilibrado();
	  if(equilibrado)
	    cout << "\nEl arbol esta balanceado";
	  else
	    cout << "\nEl arbol no esta balanceado";
	  
	  altura=arbolBinario.Alt();
	  tam=arbolBinario.Tam();
	  cout << "\nALTURA DEL ARBOL: " << altura << "\nTAMA�O: " << tam << endl;
	  
	  cout << "PULSE UNA TECLA Y ENTER PARA CONTINUAR."; cin >> pausa;
	break;
	
	case 2:
	  cout << "\n\nBUSCAR DATO." << "\n\nDATO: ";
	  cin >> dato;
	  
	  if(arbolBinario.Buscar(dato)== NULL)  //devuelve NULL si no se encuentra, devuelve direccion nodo donde se encuentra el dato
	    cout << "\nNO SE HA ENCONTRADO!!!\n\n";
	  else
	    cout << "\nDATO ENCONTRADO EN EL ARBOL\n\n";
	    cout << "PULSE UNA TECLA Y ENTER PARA CONTINUAR."; cin >> pausa;
	  break;
	case 3:
	  cout << "\n\nBORRAR DATO." << "\n\nDATO: ";
	  cin >> dato;
	  
	  arbolBinario.Eliminar(dato);   //borramos el dato
	  arbolBalanceado.eliminar(dato); //borramos el dato en el arbol balanceado
	  
	  arbolBinario.imprime();   //mostramos el arbol
	  arbolBalanceado.imprime();
	  
	  cout << "PULSE UNA TECLA Y ENTER PARA CONTINUAR."; cin >> pausa;
	break;
	
	case 4:
	  arbolBinario.imprime();   //mostramos el arbol
	  //arbolBalanceado.imprime();
	  
	  cout << "PULSE UNA TECLA Y ENTER PARA CONTINUAR."; cin >> pausa;
	break;
      };
      
      
      
    } while(menu != 5);
    
  
  
  
  
};  