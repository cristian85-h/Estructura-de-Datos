//clase DLCURSORLIST.CPP
#include <iostream>
#include "dlcursorlist.h"
#include "tdalist.h"
#include "object.h"

using namespace std;

DLCursorList::DLCursorList()//constructor de la clase lista de cursores 
{
	head = -1, capacity = size;
	filaptr = new fila[capacity];
	filaptr -> antes = head;
	filaptr -> ptrdata = NULL;
	filaptr -> next = 0;
}

//Destructor de la clase cursores list
DLCursorList::~DLCursorList()
{
	delete filaptr;
}

bool DLCursorList::insert(Object* dato, int pos)// metodo colocador en la lista de cursores
{
	cout<< "entro****" << endl;
	if(pos < 0 || pos > size){
		cout << "pude" << endl;
		return false;// pos esta fuera de frontera de la lista
	}
	
	//ingreso al principio con algo en lista
	fila *temp = filaptr; //copio lo que tenga dentro de temp
	if((head != -1) && (pos == 0)){//ta llena y quiero insertar en pos 0
		cout<< "entro" << endl;
		capacity ++;
		fila *filaptr = new fila[capacity];
		for(int i = capacity-1; i > 0; i--){
			filaptr[i]. next = i;
			filaptr[i]. antes = temp[i-1]. next;
			filaptr[i]. ptrdata = temp[i-1]. ptrdata;
		}
		filaptr[pos]. ptrdata = temp[pos]. ptrdata;
		filaptr[pos]. antes = head-1;
		filaptr[pos]. next = pos+1;
	}else if(head == -1){
		//lista no esta llena ingreso en 0
		cout<< "entro--" << endl;
		capacity ++;
		fila *filaptr = new fila[capacity];
		filaptr[pos]. ptrdata = dato;
		head = 0;
		filaptr[pos]. antes = head-1;
		filaptr[pos]. next = pos+1;
	}else if((pos == capacity) && (head != -1)){
		// lleno e inserto al final
		cout<< "entro---" << endl;
		capacity ++;
		filaptr = new fila[capacity];
		filaptr[pos]. ptrdata = dato;
		filaptr[pos]. antes = pos;
		filaptr[pos]. next = pos+1;
		for(int i = size-1; i > 0; i--){
			filaptr[i]. next = temp[i]. next;
			filaptr[i]. antes = temp[i-1]. next;
			filaptr[i]. ptrdata = temp[i]. ptrdata;
		}
	}else if((filaptr[pos]. ptrdata) != NULL){
		//lleno en el medio
		cout<< "entro----" << endl;
		capacity ++;
		filaptr = new fila[capacity];
		for(int i = head; i < capacity; i++){
			if(i == pos){
				filaptr[i]. antes = temp[i-1]. next;
				filaptr[i]. ptrdata = dato;
				filaptr[i]. next = i+1;temp[i]. next;
				i++;
			}
			if(i == (capacity - 1)){
				filaptr[i]. antes = i;
				filaptr[i]. ptrdata = temp[i-1]. ptrdata;
				filaptr[i]. next = i+1;
			}else{
				filaptr[i]. antes = temp[i]. antes;
				filaptr[i]. ptrdata = temp[i]. ptrdata;
				filaptr[i]. next = temp[i]. next;
			}
		}
	}
	size++;
	cout<<"pude: " << size << ":: " <<capacity << endl;
	return true;
}

int DLCursorList::indexOf(Object *dato)const{
	for (int i=0; i < size; i++){
        if ((filaptr[i]. ptrdata) == dato)
                return i;
    }
    return -1;
}

Object* DLCursorList::get(unsigned int indice)const{
	if (indice < 0 || indice > size)
        return NULL;
    
    return filaptr[indice]. ptrdata;
}

 Object* DLCursorList::remove(int indice){
	if (indice < 0 || indice > size) {
        return NULL;
    }
    if (isEmpty()) {
        return NULL;
    }
    Object *temp;
	temp = filaptr[indice]. ptrdata;
    for (int i = indice; i < size; ++i) {
        filaptr[indice]. ptrdata = filaptr[indice+1]. ptrdata;
    }
    size--;
    return temp;
}

int DLCursorList::prev(int pos) const {
	return pos-1;
}

int DLCursorList::next(int pos) const{
	return pos+1;
}

void DLCursorList::reset(){
	if (filaptr)
        delete filaptr;
    filaptr = NULL;
    size = 0;
}

Object* DLCursorList::first()const{
	if(!(isEmpty()))
		return filaptr[head]. ptrdata;
	return NULL;
}

Object* DLCursorList::last()const{
	if(!(isEmpty()))
		return filaptr[size-1]. ptrdata;
	return NULL;
}

void DLCursorList::print()const{
	for (int i = 0; i < size; i++) {
        if (i == 0) {
            cout<<"["<<filaptr[i]. ptrdata -> toString()<<",";
        } else if (i == size-1) {
            cout<<filaptr[i]. ptrdata -> toString()<<"]";
        }else{
           cout<<filaptr[i]. ptrdata -> toString()<<",";
        }
    }
}

bool DLCursorList::isFull()const{
	if (size == capacity) {
        return false;
    }
}