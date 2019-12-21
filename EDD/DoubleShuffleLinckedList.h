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
        reproduccion = 0;
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
    void reproducir();
    void reproducirR();
    void graph();
    void change(int i, int j);
    void removeAt(int index);


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
    reproduccion = first;
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
//-------------------------------------------------- Metodo change -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

void DoubleShuffleLinckedList::change(int i, int j)
{
    Song* aux = getElementAt(i);
    removeAt(i);
    addAt(aux, j);
}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------- Metodo shuffle -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

void DoubleShuffleLinckedList::shuffle()
{
    int i = 0;
    int j = 0;
    for (int k = 0; k < size; k++)
    {
        i = rand() % (size - 1);
        j = rand() % (size - 1);
        change(i,j);
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo reproducir ---------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::reproducir()
{
    shuffle();
    graph();
    reproducirR();
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo reproducir -------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::reproducirR()
{

    cout << "Elija una opcion. " << endl;
    cout << endl;
    cout << "1)  Cancion Anterior." << endl;
    cout << "2)  Cancion Siguiente." << endl;
    cout << endl;
    cout << "0) <- Regresar" << endl;
    cout << endl << endl;
    cout << "Ingrese la opcion elegida:   ";


    int i = 0;
    cin >> i;
    cout << endl << endl << endl;
    if (i == 2 && reproduccion->getNext()!=0)
    {
        reproduccion = reproduccion->getNext();
        graph();
        reproducirR();
    }
    else if (i == 1 && reproduccion->getBefore() != 0)
    {
        reproduccion = reproduccion->getBefore();
        graph();
        reproducirR();
    }
    else {
        return;
    }
}
//-----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Metodo graph -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::graph()
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
        if (aux->getDato()->getName().compare(reproduccion->getDato()->getName())==0)
        {
            stream << "node" << contador << " [label=\"" << aux->getDato()->getName() << "\", style=filled, fillcolor = fireBrick1];" << endl;
        }
        else
        {
            stream << "node" << contador << " [label=\"" << aux->getDato()->getName() << "\"];" << endl;
        }
        aux = aux->getNext();
        contador++;
    }
    aux = first;
    contador = 0;
    if (aux != 0) {
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
    }

    stream << "}";

    stream.close();

    system("dot -Tpng  C:\\EDDProyect\\listaArtistas.dot -o C:\\EDDProyect\\listaArtistas.png");
    system("start C:\\EDDProyect\\listaArtistas.png");

}
//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------Metodo remove_at -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DoubleShuffleLinckedList::removeAt(int index)
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




