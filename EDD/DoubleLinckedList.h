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
    void graph();
    Artist* getArtist(string name_);
    void getTop5();
    void graphTop();


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
//------------------------------------------------------ Metodo add -----------------------------------------------------
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
//--------------------------------------------------- Metodo graph ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------  
void DoubleLinckedList::graph()
{
    Nodo* aux = first;
    int contador = 0;
    ofstream stream;
    stream.open("C:\\EDDProyect\\listaArtistas.dot", ios::out);

    if (stream.fail())
    {
        cout << "Existe un problema con el archivo." << endl;
    }

    stream << "digraph { " << endl;
    stream << "rankdir = LR; " << endl;
    stream << "node [shape = rectangle, width = 1, height = 1];" << endl;
    while (aux != 0)
    {
        stream << "node" << contador << " [label=\"" << aux->getDato()->getName() << "\"];" << endl;
        aux = aux->getNext();
        contador++;
    }
    aux = first;
    contador = 0;
    while (aux->getNext() != 0)
    {
        stream << "node" << contador << " -> " << "node" << contador + 1 << " ;" << endl;
        aux = aux->getNext();
        contador++;
    }
    while (aux->getBefore() != 0)
    {
        stream << "node" << contador << " -> " << "node" << contador - 1 << " ;" << endl;
        aux = aux->getBefore();
        contador--;
    }
    stream << "}";

    stream.close();

    system("dot -Tpng  C:\\EDDProyect\\listaArtistas.dot -o C:\\EDDProyect\\listaArtistas.png");
    system("start C:\\EDDProyect\\listaArtistas.png");

}

//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Metodo getArtist --------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
Artist *DoubleLinckedList::getArtist(string name_)
{
    Nodo* aux = first;
    int contador = 0;

    while (aux != 0)
    {
        if(aux->getDato()->getName().compare(name_)==0)return aux->getDato();
        aux = aux->getNext();
    }
    return 0;
}

//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Metodo getArtist --------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleLinckedList::getTop5()
{
    Nodo* aux = first;
    Artist* top1 = 0;
    Artist* top2 = 0;
    Artist* top3 = 0;
    Artist* top4 = 0;
    Artist* top5 = 0;


    while (aux != 0)
    {
        if (top1 == 0) 
        {
            top1 = aux->getDato();
        }
        else if (top2 == 0)
        {
            top2 = aux->getDato();
            if (aux->getDato()->getRate() > top1->getRate())
            {
                top2 = top1;
                top1 = aux->getDato();
            }
        }
        else if (top3 == 0)
        {
            top3 = aux->getDato();
            if (aux->getDato()->getRate() > top2->getRate())
            {
                top3 = top2;
                top2 = aux->getDato();
                if (aux->getDato()->getRate() > top1->getRate())
                {
                    top2 = top1;
                    top1 = aux->getDato();
                }
            }
        }
        else if (top4 == 0)
        {
            top4 = aux->getDato();
            if (aux->getDato()->getRate() > top3->getRate())
            {
                top4 = top3;
                top3 = aux->getDato();
                if (aux->getDato()->getRate() > top2->getRate())
                {
                    top3 = top2;
                    top2 = aux->getDato();
                    if (aux->getDato()->getRate() > top1->getRate())
                    {
                        top2 = top1;
                        top1 = aux->getDato();
                    }
                }
            }
        }
        else if (top5 == 0)
        {
            top5 = aux->getDato();
            if (aux->getDato()->getRate() > top4->getRate())
            {
                top5 = top4;
                top4 = aux->getDato();
                if (aux->getDato()->getRate() > top3->getRate())
                {
                    top4 = top3;
                    top3 = aux->getDato();
                    if (aux->getDato()->getRate() > top2->getRate())
                    {
                        top3 = top2;
                        top2 = aux->getDato();
                        if (aux->getDato()->getRate() > top1->getRate())
                        {
                            top2 = top1;
                            top1 = aux->getDato();
                        }
                    }
                }
            }
        }
        else if (aux->getDato()->getRate() > top5->getRate())
        {
            top5 = aux->getDato();
            if (aux->getDato()->getRate() > top4->getRate())
            {
                top5 = top4;
                top4 = aux->getDato();
                if (aux->getDato()->getRate() > top3->getRate())
                {
                    top4 = top3;
                    top3 = aux->getDato();
                    if (aux->getDato()->getRate() > top2->getRate())
                    {
                        top3 = top2;
                        top2 = aux->getDato();
                        if (aux->getDato()->getRate() > top1->getRate())
                        {
                            top2 = top1;
                            top1 = aux->getDato();
                        }
                    }
                }
            }
        }
        aux = aux->getNext();
    }

    DoubleLinckedList* top = new DoubleLinckedList();
    if (top1 != 0) 
    {
        top->addLast(top1);

    }
    if (top2 != 0)
    {
        top->addLast(top2);

    }
    if (top3 != 0)
    {
        top->addLast(top3);

    }
    if (top4 != 0)
    {
        top->addLast(top4);

    }
    if (top5 != 0)
    {
        top->addLast(top5);

    }

    top->graphTop();

}

//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Metodo graphTop ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------  
void DoubleLinckedList::graphTop()
{
    Nodo* aux = first;
    int contador = 0;
    ofstream stream;
    stream.open("C:\\EDDProyect\\listaArtistas.dot", ios::out);

    if (stream.fail())
    {
        cout << "Existe un problema con el archivo." << endl;
    }

    stream << "digraph { " << endl;
    stream << "rankdir = TB; " << endl;
    stream << "node [shape = rectangle, width = 1, height = 1];" << endl;
    while (aux != 0)
    {
        stream << "node" << contador << " [label=\"" <<"---- "<<contador+1 << " ----\nNombre:  "<<aux->getDato()->getName()<< "\nRate:  " << aux->getDato()->getRate() <<"\"];" << endl;
        aux = aux->getNext();
        contador++;
    }
    aux = first;
    contador = 0;
    while (aux->getNext() != 0)
    {
        stream << "node" << contador << " -> " << "node" << contador + 1 << " ;" << endl;
        aux = aux->getNext();
        contador++;
    }
    
    stream << "}";

    stream.close();

    system("dot -Tpng  C:\\EDDProyect\\listaArtistas.dot -o C:\\EDDProyect\\listaArtistas.png");
    system("start C:\\EDDProyect\\listaArtistas.png");

}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------



