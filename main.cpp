#include <iostream>
#include <cstdlib>
#include "tdalist.h"
//#include "varraylist.h" 	//Arreglos de tama�o variable
//#include "farraylist.h" 	//Arreglos de tama�o fijo
//#include "slinkedlist.h" 	//Lista Enlazada Sencilla
#include "linkedlist.h"         //Lista Doblemente Enlazada
#include "dlcursorlist.h"       //Cursor de Tama�o Fijo simulando lista doblemente enlazada
#include "integer.h"

using namespace std;

/*
	Programa Principal Proyecto I Estructura de Datos
	*************************************************
	*********** N O    M O D I F I C A R ************
	*************************************************

	Usar nombres de encabezados que aparecen en los 
	#include arriba:
		varraylist.h y varraylist.cpp
		farraylist.h y farraylist.cpp
		slinkedlist.h y slinkedlist.cpp
		dlcursorlist.h y dlcursorlist.cpp

*/



void testTDA(TDAList*);

int main(int argc, char *argv[])
{
	TDAList *list;
//	list = new VArrayList(10, 5);
//	testTDA(list);
//	delete list;
//
//
//	list = new FArrayList(25);
//	testTDA(list);
//	delete list;
//
//	list = new SLinkedList();
//	testTDA(list);
//	delete list;
   
//  list = new LinkedList();
//	testTDA(list);
//	delete list;
   
	list = new DLCursorList();
	testTDA(list);
	delete list;
    
    return 0;
}


void testTDA(TDAList* list){
	// Insert 20 numbers
	for (int i=0; i<2; i++){
		cout<< "antes del insert"<< endl;
		list->insert(new Integer(i*2), i);
		cout<< "despues del insert\n"<< endl;
		//cout << "-*->"<< list->insert(new Integer(i*2), i)<< endl;
	}
	cout<< "*-*>"<< list->getSize()<<endl;
	/*
	Integer salida;
	cout<< "--> "<< salida.getValue()<<endl;
	// Print list
	*/
	for (int i=0; i<list->getSize(); i++)
		cout << list->get(i)->toString() << endl;

	cout<< "mediatamente fuera"<< endl;
	// Remove three Elements
    Object* t = NULL;
    t = list->remove(0);
    delete t;
    t = list->remove(10);
    delete t;
    t = list->remove(5);
    delete t;

	cout<< "*-*> despues de remove"<< list->getSize()<<endl;
	// Print list
	for (int i=0; i<list->getSize(); i++)
		cout << list->get(i)->toString() << endl;
	
    cout << "First = " << list->first()->toString() << endl;
    cout << "Last  = " << list->last()->toString() << endl;

	// indexOf
	for (int i=0; i<20; i++){
		cout << "list->indexOf(" << i << ") = " << list->indexOf(list->get(i) ) << endl;
	}

	list->reset();
	cout << "Size = " << list->getSize() << endl;
}
