#pragma once
#include <iostream>
#include <string.h>
#include "../Obj/Artist.h"

class DoubleLinckedList
{


    class Nodo {
    public:
        Nodo(Artist* x)
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
        Artist* getDato() { return dato; }
    private:
        Nodo* next;
        Nodo* before;
        Artist* dato;
    };




public:
    DoubleLinckedList()
    {
        first = 0;
        last = 0;
        size = 0;
    }

    int getSize() { return size; }
    void addFirst(Artist* data);
    void addLast(Artist* data);
    void addAt(Artist* data, int index);
    void add(Artist* data);
    Artist* getElementAt(int index);
    void getArtists();


private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* first;
    Nodo* last;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleLinckedList::addFirst(Artist* data)
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
void DoubleLinckedList::addLast(Artist* data)
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
void DoubleLinckedList::addAt(Artist* dato, int index)
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
Artist* DoubleLinckedList::getElementAt(int index)
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
void DoubleLinckedList::add(Artist* data)
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
                addAt(data,contador);
                break;
            }
            contador++;
            aux = aux->getNext();
        }
        if (contador==getSize()) 
        {
            addLast(data);
        }
        
    }
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getArtists ---------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleLinckedList::getArtists()
{
    Nodo* aux = first;
    int contador = 0;
    while (aux != 0) {
        contador++;
        cout << contador << ")  " << aux->getDato()->getName()<<endl;
        aux = aux->getNext();
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------



