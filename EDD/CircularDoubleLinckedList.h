

#include "../obj/Song.h"

using namespace std;

class CircularDoubleLinckedList
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
        Song *getDato() { return dato; }
    private:
        Nodo* next;
        Nodo* before;
        Song* dato;
    };




public:
    CircularDoubleLinckedList()
    {
        first = 0;
        last = 0;
        reproduccion = 0;
        size = 0;
    }

    int getSize() { return size; }
    void addFirst(Song *data);
    void addLast(Song *data);
    void addAt(Song *data, int index);
    Song getElementAt(int index);
    string graph();



private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* first;
    Nodo* last;
    Nodo* reproduccion;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void CircularDoubleLinckedList::addFirst(Song *data)
{
    Nodo *n = new Nodo(data);
    
    if (this->isEmpty())
    {
        this->first = n;
        this->last = n;
        n->setNext(n);
        n->setBefore(n);
        this->size++;
    }
    else
    {
        n->setNext(this->first);
        n->setBefore(this->last);
        this->first->setBefore(n);
        this->last->setNext(n);
        this->first = n;
        this->size++;
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addLast ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void CircularDoubleLinckedList::addLast(Song *data)
{
    if (this->isEmpty())
    {
        this->addFirst(data);
    }
    else
    {
        Nodo *n = new Nodo(data);
        this->last->setNext(n);
        n->setBefore(this->last);
        n->setNext(this->first);
        first->setBefore(n);
        this->last = n;
        this->size++;
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void CircularDoubleLinckedList::addAt(Song *dato, int index)
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
Song CircularDoubleLinckedList::getElementAt(int index)
{
    if (index >= 0 && index < this->size)
    {
        Nodo* iterador = this->first;
        int x = 0;
        while (iterador != NULL)
        {
            if (index == x) { return *iterador->getDato(); }
            iterador = iterador->getNext();
            x++;
        }
    }
    
}
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------



