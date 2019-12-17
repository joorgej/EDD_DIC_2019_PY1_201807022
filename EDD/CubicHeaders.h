#pragma once
#include "CubicNode.h"

using namespace std;

class HeaderY
{
public:
	HeaderY(string name_):name(name_),next(0),row(0){}

	void setNext(HeaderY* n) { this->next = n; }
	void setBefore(HeaderY* n) { this->before = n; }
	void setRow(Nodo* n) { this->row = n; }
	string getName() { return this->name; }
	HeaderY* getNext() { return this->next; }
	HeaderY* getBefore() { return this->before; }
	Nodo* getRow() { return this->row; }
private:
	HeaderY* next;
	HeaderY* before;
	Nodo* row;
	string name;
};

class HeaderX
{
public:
	HeaderX(int name_):name(name_), next(0), column(0){}

	void setNext(HeaderX* n) { this->next = n; }
	void setBefore(HeaderX* n) { this->before = n; }
	void setColumn(Nodo* n) { this->column = n; }
	int getName() { return this->name; }
	HeaderX* getNext() { return this->next; }
	HeaderX* getBefore() { return this->before; }
	Nodo* getColumn() { return this->column; }
private:
	HeaderX* next;
	HeaderX* before;
	Nodo* column;
	int name;
};