//clase DLCURSORLIST.H
#ifndef DLCURSORLIST_H
#define DLCURSORLIST_H

#include "tdalist.h"
#include "object.h"

class DLCursorList : public TDAList
{
	struct fila{
		int antes, next;
		Object *ptrdata;
	};
	protected:
		fila *filaptr;// apuntador a tipo fila
	//variables caracteristicas de la fila
	//int head = -1, capacity = size;//preguntar
		int head, capacity;
	//size se hereda de tda list no necesito declararlo
	
	public:
		DLCursorList();
		virtual ~DLCursorList();
		virtual bool insert(Object*, int);
		virtual int indexOf(Object*)const ;
		virtual Object* get(unsigned)const ;
		virtual Object* remove(int) ;
		virtual int prev(int) const ;
		virtual int next(int) const ;
		virtual void reset() ;
		virtual Object* first()const ;
		virtual Object* last()const ;
		virtual void print()const ;
		virtual bool isFull()const ;
};
# endif