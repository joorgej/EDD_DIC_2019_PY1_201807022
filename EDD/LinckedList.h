#ifndef LINCKEDLIST_H_INCLUDED
#define LINCKEDLIST_H_INCLUDED


template<class T>
class LinckedList
{
    class Nodo {
    public:
        Nodo(T x)
        {
            next = 0;
            dato = x;
        }

        ~Nodo()
        {
        }

        Nodo* getNext() { return next; }
        void setNext(Nodo* n) { next = n; }
        T getDato() { return dato; }
    private:
        Nodo* next;
        T dato;
    };
public:
    ListaDoble()
    {
        first = 0;
        last = 0;
        size = 0;
    }

    int getSize() { return size; }
    void addFirst(T data);
    void addLast(T data);
    void addAt(T data, int index);
    void removeAt(int index);
    void add(T data);
    T getElementAt(int index);


private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* first;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addAt --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
template<class T>
void LinckedList<T>::addFirst(T data)
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
void LinckedList<T>::addLast(T data)
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
void LinckedList<T>::addAt(T dato, int index)
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
T LinckedList<T>::getElementAt(int index)
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
void LinckedList<T>::removeAt(int index)
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
