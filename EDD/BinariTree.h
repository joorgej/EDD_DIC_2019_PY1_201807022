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
        root = 0;
    }

    void add(T data);
    void removeAt(int index);
    string graph();
    string getData();
    T getElement(string name);


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
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------




#endif // LINCKEDLIST_H_INCLUDED
