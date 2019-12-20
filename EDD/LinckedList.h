#pragma once
#include <fstream>
#include "../Obj/Song.h"

class LinckedList
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
        Song *getDato() { return dato; }
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
    LinckedList()
    {
        first = 0;
        last = 0;
        size = 0;
    }

    int getSize() { return size; }
    
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
            if (index == 0) { this->addFirst(data);  }
            else if (index == this->size) { this->addLast(data);  }
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
    Song *getElementAt(int index)
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
            if (name_.compare(aux->getDato()->getName())==0) { return aux->getDato(); }
            aux = aux->getNext();
            x++;
        }
        return 0;
    }
//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Metodo graph ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------  
    void graph()
    {
        Nodo* aux = first;
        int contador = 0;
        ofstream stream;
        stream.open("C:\\EDDProyect\\listasimple.dot", ios::out);

        if (stream.fail())
        {
            cout << "Existe un problema con el archivo."<<endl;
        }

        stream << "digraph { " << endl;
        stream << "rankdir = LR; " << endl;
        stream << "node [shape = rectangle, width = 1, height = 1];" << endl;
        while (aux != 0) 
        {
            stream << "node" << contador << " [label=\"" << aux->getDato()->getName() << "\",style=filled];" << endl;
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

        system("dot -Tpng  C:\\EDDProyect\\listasimple.dot -o C:\\EDDProyect\\listasimple.png");
        system("start C:\\EDDProyect\\listasimple.png");
        
    }
    //-----------------------------------------------------------------------------------------------------------------------
    //------------------------------------------------- Metodo getSongs -----------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------
    void getSongs() 
    {
        Nodo* aux = first;
        int contador = 0;

        while (aux != 0) 
        {
            contador++;
            cout << contador << ")  " << aux->getDato()->getName()<<endl;
            aux = aux->getNext();
        }
    }

    //-----------------------------------------------------------------------------------------------------------------------
    //-------------------------------------------------- Metodo getSong -----------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------
    Song* getSong(string name_)
    {
        Nodo* aux = first;
        int contador = 0;

        while (aux != 0)
        {
            if (aux->getDato()->getName().compare(name_) == 0)return aux->getDato();
            aux = aux->getNext();
        }
        return 0;
    }
    //-----------------------------------------------------------------------------------------------------------------------
    //---------------------------------------------------- Metodo add -------------------------------------------------------
    //-----------------------------------------------------------------------------------------------------------------------
    void add(Song* data) {
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
};

/*
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void LinckedList::addFirst(Song* data)
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
void LinckedList::addLast(Song* data)
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
void LinckedList::addAt(Song* dato, int index)
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
Song LinckedList::getElementAt(int index)
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
void LinckedList::removeAt(int index)
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

*/
