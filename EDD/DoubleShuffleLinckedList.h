#pragma once
#include <iostream>
#include <string.h>
#include "../Obj/Artist.h"

class DoubleShuffleLinckedList
{


    class Nodo {
    public:
        Nodo(Song* x)
        {
            next = 0;
            before = 0;
            dato = x;
        }

        ~Nodo()
        {
        }

        Nodo* getNext() { return next; }
        Nodo* getBefore() { return before; }
        void setNext(Nodo* n) { next = n; }
        void setBefore(Nodo* n) { before = n; }
        Song* getDato() { return dato; }
    private:
        Nodo* next;
        Nodo* before;
        Song* dato;
    };




public:
    DoubleShuffleLinckedList()
    {
        first = 0;
        last = 0;
        posicion = 0;
        size = 0;
    }

    int getSize() { return size; }
    void addFirst(Song* data);
    void addLast(Song* data);
    void addAt(Song* data, int index);
    void add(Song* data);
    Song* getElementAt(int index);
    void getSong();
    void shuffle();
    Song* getNext();
    Song* getBefore();


private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* first;
    Nodo* last;
    Nodo* posicion;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::addFirst(Song* data)
{
    Nodo* n = new Nodo(data);
    if (this->isEmpty())
    {
        this->first = n;
        this->last = n;
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        this->first->setBefore(n);
        this->first = n;
        this->size++;
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addLast ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::addLast(Song* data)
{
    if (this->isEmpty())
    {
        this->addFirst(data);
    }
    else
    {
        Nodo* n = new Nodo(data);
        this->last->setNext(n);
        n->setBefore(this->last);
        this->last = n;
        this->size++;
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::addAt(Song* dato, int index)
{
    if (index >= 0 && index <= this->size)
    {
        if (index == 0) { this->addFirst(dato); return; }
        if (index == this->size) { this->addLast(dato); return; }
        Nodo* aux = this->first;
        int x = 0;
        while (aux != 0)
        {
            if (x == index) { break; }
            aux = aux->getNext();
            x++;
        }
        Nodo* n = new Nodo(dato);
        aux->getBefore()->setNext(n);
        n->setBefore(aux->getBefore());
        n->setNext(aux);
        aux->setBefore(n);
        this->size++;
    }
}


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getElementAt -------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
Song* DoubleShuffleLinckedList::getElementAt(int index)
{
    if (index >= 0 && index < this->size)
    {
        Nodo* iterador = this->first;
        int x = 0;
        while (iterador != 0)
        {
            if (index == x) { return iterador->getDato(); }
            iterador = iterador->getNext();
            x++;
        }
    }
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getElementAt -------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::add(Song* data)
{
    if (isEmpty())
    {
        addFirst(data);
    }
    else
    {
        int contador = 0;
        Nodo* aux = first;
        while (aux != 0)
        {
            if (_strcmpi(data->getName().c_str(), aux->getDato()->getName().c_str()) < 0)
            {
                addAt(data, contador);
                break;
            }
            contador++;
            aux = aux->getNext();
        }
        if (contador == getSize())
        {
            addLast(data);
        }

    }
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getArtists ---------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::getSong()
{
    Nodo* aux = first;
    int contador = 0;
    while (aux != 0) {
        contador++;
        cout << contador << ")  " << aux->getDato()->getName() << endl;
        aux = aux->getNext();
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------




