#ifndef BINARITREE_H_INCLUDED
#define BINARITREE_H_INCLUDED

#include <iostream>

using namespace std;

template<class T>
class BinariTree
{
    class Nodo {
    public:
        Nodo(T x):left(0), right(0), dato(x) {}

        ~Nodo() 
        {
        }

        Nodo* getLeft() { return left; }
        nodo* getRight() { return right; }
        void setLeft(Nodo* n) { left = n; }
        void setRight(Nodo* n) { right = n; }
        T getDato() { return dato; }
    private:
        Nodo* left;
        Nodo* right
        T dato;
    };
public:
    ListaDoble()
    {
        first = 0;
        last = 0;
        size = 0;
    }

    void add(T data);
    void removeAt(int index);
    void add(T data);
    T getElementAt(string name);


private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* raiz;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class T>
void BinariTree<T>::addFirst(T data)
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
template<class T>
void BinariTree<T>::addLast(T data)
{
    if (this->isEmpty())
    {
        this->add_first(data);
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
template<class T>
void BinariTree<T>::addAt(T dato, int index)
{
    if (index >= 0 && index <= this->size)
    {
        if (index == 0) { this->add_first(dato); return; }
        if (index == this->size) { this->add_last(dato); return; }
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
template<class T>
T BinariTree<T>::getElementAt(int index)
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
//------------------------------------------------- Metodo removeAt -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class T>
void BinariTree<T>::removeAt(int index)
{
    if (index >= 0 && index < size)
    {
        if (index == 0)
        {
            Nodo* aux = first;
            first = first->getNext();
            first->setBefore(0);
            aux->setNext(0);
            aux->~Nodo();
        }
        else if (index == size - 1)
        {
            Nodo* aux = last;
            last = last->getBefore();
            last->setNext(0);
            aux->setBefore(0);
            aux->~Nodo();
        }
        else
        {
            Nodo* aux = this->first;
            for (int i = 0; i < index; i++) { aux = aux->getNext(); }
            aux->getBefore()->setNext(aux->getNext());
            aux->getNext()->setBefore(aux->getBefore());
            aux->setBefore(0);
            aux->setNext(0);
            aux->~Nodo();
        }
        size--;
    }
}
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------




#endif // LINCKEDLIST_H_INCLUDED
