

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
    void graph();
    void reproducir();
    void reproducirR();



private:
    bool isEmpty() { return size == 0; }
    int size;
    Nodo* first;
    Nodo* last;
    Nodo* reproduccion;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ Metodo addFirst ------------------------------------------------------
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
    reproduccion = first;
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
        while (iterador != 0)
        {
            if (index == x) { return *iterador->getDato(); }
            iterador = iterador->getNext();
            x++;
        }
    }
    
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo reproducir -------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void CircularDoubleLinckedList::reproducir()
{
    graph();
    reproducirR();
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo reproducir -------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void CircularDoubleLinckedList::reproducirR()
{

    cout << "Elija una opcion. "<<endl;
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
    if (i == 2)
    {
        reproduccion = reproduccion->getNext();
        graph();
        reproducirR();
    }
    else if (i == 1)
    {
        reproduccion = reproduccion->getBefore();
        graph();
        reproducirR();
    }
    else if (i == 0) {
        return;
    }
}

//-----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Metodo graph -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void CircularDoubleLinckedList::graph()
{
    Nodo* aux = first;
    int contador = 0;
    ofstream stream;
    stream.open("C:\\EDDProyect\\circlular.dot", ios::out);

    if (stream.fail())
    {
        cout << "Existe un problema con el archivo." << endl;
    }

    stream << "digraph { " << endl;
    stream << "rankdir = LR; " << endl;
    stream << "node [shape = rectangle, width = 1, height = 1];" << endl;
    for (int i = 0; i < size; i++)
    {
        if(aux->getDato()->getName().compare(reproduccion->getDato()->getName())==0)
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

    stream << "node" << size - 1 << " -> node0 ;" << endl;
    aux = first;
    contador = 0;
    for(int i = 0; i<size-1; i++)
    {
        stream << "node" << contador << " -> " << "node" << contador + 1 << " ;" << endl;
        aux = aux->getNext();
        contador++;
    }
    for (int i = 0; i < size-1; i++)
    {
        stream << "node" << contador << " -> " << "node" << contador - 1 << " ;" << endl;
        aux = aux->getBefore();
        contador--;
    }

    stream << "node0 -> node" << size - 1 << ";"<<endl;
   

    stream << "}";

    stream.close();

    system("dot -Tpng  C:\\EDDProyect\\circlular.dot -o C:\\EDDProyect\\circlular.png");
    system("start C:\\EDDProyect\\circlular.png");

}
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------



