#ifndef BINARITREE_H_INCLUDED
#define BINARITREE_H_INCLUDED

#include <iostream>
#include "../Obj/Playlist.h"

using namespace std;

class BinariTree
{
    class Nodo {
    public:
        Nodo(T x):left(0), right(0), dato(x) {}

        ~Nodo() 
        {
        }

        Nodo* getLeft() { return left; }
        Nodo* getRight() { return right; }
        void setLeft(Nodo* n) { left = n; }
        void setRight(Nodo* n) { right = n; }
        T getDato() { return dato; }
    private:
        Nodo* left;
        Nodo* right
        Playlist* dato;
    };
public:
    ListaDoble()
    {
        root = 0;
    }

    void add(T data);
    void addR(T data, Nodo* aux)
    string graph();
    T getElement(string name);


private:
    bool isEmpty() { return root == 0; }
    Nodo* root;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class T>
void BinariTree<T>::add(T data)
{
    Nodo* n = new Nodo(data);
    if (this->isEmpty())
    {
        this->root = n;
    }
    else
    {
        
    }
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class T>
void BinariTree<T>::addR(T data, Nodo* aux)
{
    if(aux->getDato)
}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------




#endif // LINCKEDLIST_H_INCLUDED
