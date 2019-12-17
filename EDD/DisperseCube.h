#pragma once
#include <iostream>
#include "../Obj/Objects.h"
#include "CubicHeaders.h"
#include "CubicNode.h"

using namespace std;


class DisperseCube 
{

public:
	DisperseCube():x(0),y(0){}

	Album getAlbum(string y_, int x_, string name_);
	Nodo* getNodo(string y_, int x_);
	string getAlbums();
	bool existX(int name);
	bool existY(string name);
	HeaderX* getNodeX(int name);
	HeaderY* getNodeY(string name);
	void addY(string name);
	void addX(int name);
	string graph();
	void add(string y_, int x_, Album* data_);


private:
	HeaderX* x;
	HeaderY* y;
};

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addX ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DisperseCube::addX(int name)
{
	HeaderX* x_ = new HeaderX(name);
	if (x == 0) 
	{
		x = x_;
	}
	else if (name < x->getName())
	{
		x->setBefore(x_);
		x_->setNext(x);
		x = x_;
	}
	else
	{
		HeaderX* aux = x;
		while (aux->getNext() != 0) 
		{
			if (name > aux->getName() && name < aux->getNext()->getName()) 
			{
				x_->setNext(aux->getNext());
				aux->getNext()->setBefore(x_);
				aux->setNext(x_);
				x_->setBefore(aux);
				break;
			}
			aux = aux->getNext();
		}
		if (aux->getNext() == 0) 
		{
			aux->setNext(x_);
			x_->setBefore(aux);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addY ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DisperseCube::addY(string name)
{
	HeaderY* y_ = new HeaderY(name);
	if (y == 0)
	{
		y = y_;
	}
	else
	{
		HeaderY* aux = y;
		while (aux->getNext() != 0) {
			aux = aux->getNext();
		}
		aux->setNext(y_);
		y_->setBefore(aux);
	}
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo existX -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool DisperseCube::existX(int name)
{
	HeaderX* aux= x;
	while (aux != 0) 
	{
		if (aux->getName() == name)
		{
			return 1;
		}
		aux = aux->getNext();
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo existY -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool DisperseCube::existY(string name)
{
	HeaderY* aux = y;
	while (aux != 0)
	{
		if (aux->getName().compare(name))
		{
			return 1;
		}
		aux = aux->getNext();
	}
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getNodeX -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
HeaderX* DisperseCube::getNodeX(int name)
{
	if (existX == 0) { addX(name); }
	HeaderX* auxX = x;
	while (auxX != 0)
	{
		if (auxX->getName() == name)
		{
			return auxX;
		}
		auxX = auxX->getNext();
	}
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getNodeY -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
HeaderY* DisperseCube::getNodeY(string name)
{
	if (existY == 0) { addY(name); }
	HeaderY* auxY = y;
	while (auxY != 0)
	{
		if (auxY->getName().compare(name))
		{
			return auxY;
		}
		auxY = auxY->getNext();
	}

}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo add ----------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DisperseCube::add(string y_, int x_, Album* data_)
{

	HeaderY* auxY = getNodeY(y_);
	HeaderX* auxX = getNodeX(x_);
	Nodo* dato = new Nodo(data_,auxX, auxY);

	
	if (auxY->getRow() == 0) 
	{
		auxY->setRow(dato);
	}
	else 
	{
		Nodo* aux = auxY->getRow();
		if (x_ < aux->getX()->getName())
		{
			dato->setRight(aux);
			aux->setLeft(dato);
			auxY->setRow(dato);
		}
		else
		{
			while (aux->getRight() != 0)
			{
				
				if (aux->getX()->getName() == auxX->getName())
				{
					aux->setNext(dato);
					dato->setBefore(aux);
					break;
				}
				else if (x_ > aux->getX()->getName() && x_ < aux->getRight()->getX()->getName())
				{
					dato->setRight(aux->getRight());
					aux->getRight()->setLeft(dato);
					aux->setRight(dato);
					dato->setLeft(aux);
					break;
				}
				aux = aux->getNext();
			}
			if (aux->getNext() == 0) 
			{
				aux->setRight(dato);
				dato->setLeft(aux);
			}
		}
	}


	if (auxX->getColumn() == 0)
	{
		auxX->setColumn(dato);
	}
	else
	{
		Nodo* aux = auxX->getColumn();
		if (x_ < aux->get()->getName())
		{
			dato->setRight(aux);
			aux->setLeft(dato);
			auxY->setRow(dato);
		}
		else
		{
			while (aux->getRight() != 0)
			{

				if (aux->getX()->getName() == auxX->getName())
				{
					aux->setNext(dato);
					dato->setBefore(aux);
					break;
				}
				else if (x_ > aux->getX()->getName() && x_ < aux->getRight()->getX()->getName())
				{
					dato->setRight(aux->getRight());
					aux->getRight()->setLeft(dato);
					aux->setRight(dato);
					dato->setLeft(aux);
					break;
				}
				aux = aux->getNext();
			}
			if (aux->getNext() == 0)
			{
				aux->setRight(dato);
				dato->setLeft(aux);
			}
		}
	}
}