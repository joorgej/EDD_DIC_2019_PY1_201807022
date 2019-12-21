#pragma once
#include "../Obj/Song.h"

class Stack
{
    class Nodo {
    public:
        Nodo(Song* x)
        {
            next = 0;
            dato = x;
        }

        ~Nodo()
        {
        }

        Nodo* getNext() { return next; }
        void setNext(Nodo* n) { next = n; }
        Song* getDato() { return dato; }
    private:
        Nodo* next;
        Song* dato;
    };
private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* first;
    Nodo* last;

public:
    Stack()
    {
        first = 0;
        last = 0;
        size = 0;
    }

    int getSize() { return size; }

    void push(Song* song_) { addFirst(song_); }
    Song* peek() { return getElementAt(0); }
    Song* pop() 
    {
        Song* out = getElementAt(0);
        Nodo* aux = first;
        first = first->getNext();
        delete(aux);
        size--;
        return out;
    }


    //-----------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------- Metodo addFirst -----------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------  
    void addFirst(Song* data)
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
            this->first = n;
            this->size++;
        }
    }

    //-----------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------- Metodo addLast ------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------   
    void addLast(Song* data)
    {
        if (this->isEmpty())
        {
            this->addFirst(data);
        }
        else
        {
            Nodo* n = new Nodo(data);
            this->last->setNext(n);
            this->last = n;
            this->size++;
        }
    }

    //-----------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------- Metodo addAt --------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------   
    void addAt(Song* data, int index)
    {
        if (index >= 0 && index <= this->size)
        {
            if (index == 0) { this->addFirst(data); }
            if (index == this->size) { this->addLast(data); }
            else
            {
                Nodo* aux = this->first;
                Nodo* aux2 = aux->getNext();
                int x = 1;
                while (aux2 != 0)
                {
                    if (x == index) { break; }
                    aux2 = aux2->getNext();
                    aux = aux->getNext();
                    x++;
                }
                Nodo* n = new Nodo(data);
                aux->setNext(n);
                n->setNext(aux2);
                this->size++;
            }

        }
    }

    //-----------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------- Metodo getElementAt -------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------   
    Song* getElementAt(int index)
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
    //----------------------------------------------- Metodo getElementWith -------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------  
    Song* getElementWith(string name_)
    {

        Nodo* aux = this->first;
        int x = 0;
        while (aux != 0)
        {
            if (name_.compare(aux->getDato()->getName()) == 0) { return aux->getDato(); }
            aux = aux->getNext();
            x++;
        }
        return 0;
    }

    //-----------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------- Metodo reproducir ---------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------  
    void reproducir()
    {
        if (size <= 0) { return; }


        graph(pop());
        _sleep(7000);
        
        reproducir();

        
    }

    //-----------------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------- Metodo graph -----------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------  
    void graph(Song* song_)
    {
        Nodo* aux = first;
        int contador = 0;
        ofstream stream;
        stream.open("C:\\EDDProyect\\listasimple.dot", ios::out);

        if (stream.fail())
        {
            cout << "Existe un problema con el archivo." << endl;
        }

        stream << "digraph { " << endl;
        stream << "rankdir = TB; " << endl;
        stream << "node [shape = rectangle, width = 1, height = 1];" << endl;

        stream << "poped" << " [label=\"" << song_->getName() << "\",style=filled, fillcolor = fireBrick1 ];" << endl;
        while (aux != 0)
        {
            stream << "node" << contador << " [label=\"" << aux->getDato()->getName() << "\"];" << endl;
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
        }
        stream << "}";

        stream.close();

        system("dot -Tpng  C:\\EDDProyect\\listasimple.dot -o C:\\EDDProyect\\listasimple.png");
        system("start C:\\EDDProyect\\listasimple.png");

    }
    

};
