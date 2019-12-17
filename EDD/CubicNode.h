#pragma once
#include "CubicHeaders.h"
#include "../Obj/Objects.h"

class Nodo
{
public:
	Nodo(Album* data_,HeaderX* x_, HeaderY* y_):data(data_),left(0),right(0),top(0),buttom(0),next(0),before(0),x(x_),y(y_){}
	
	void setLeft(Nodo* n) { this->left = n; }
	void setRight(Nodo* n) { this->right = n; }
	void setTop(Nodo* n) { this->top = n; }
	void setButtom(Nodo* n) { this->buttom = n; }
	void setNext(Nodo* n) { this->next = n; }
	void setBefore(Nodo* n) { this->before = n; }
	
	Nodo* getLeft() { return this->left; }
	Nodo* getRight() { return this->right; }
	Nodo* getTop() { return this->top; }
	Nodo* getButtom() { return this->buttom; }
	Nodo* getNext() { return this->next; }
	Nodo* getBefore() { return this->before; }
	Album* getAlbum() { return this->data; }
	HeaderX* getX() { return this->x; }
	HeaderY* getY() { return this->y; }



private:
	Nodo* left;
	Nodo* right;
	Nodo* top;
	Nodo* buttom;
	Nodo* next;
	Nodo* before;
	Album* data;
	HeaderX* x;
	HeaderY* y;
};

