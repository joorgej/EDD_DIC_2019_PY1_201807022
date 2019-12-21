
#include <iostream>
#include <fstream>
#include <string.h>
#include "../Obj/Playlist.h"

using namespace std;

class BinariTree
{
    class Nodo {
    public:
        Nodo(Playlist* x):left(0), right(0), dato(x) {}

        ~Nodo() 
        {
        }

        Nodo* getLeft() { return left; }
        Nodo* getRight() { return right; }
        void setLeft(Nodo* n) { left = n; }
        void setRight(Nodo* n) { right = n; }
        Playlist* getDato() { return dato; }
    private:
        Nodo* left;
        Nodo* right;
        Playlist* dato;
    };
public:
    BinariTree()
    {
        root = 0;
    }

    void add(Playlist* data);
    void addR(Playlist* data, Nodo* aux);
    void graph();
    string graphR(Nodo* aux);
    Playlist getElement(string name);
    void printTree();
    void printTreeR(Nodo* aux);
    void getPlaylist(int index);
    void getPlaylistR(int index, Nodo* aux);


private:
    bool isEmpty() { return root == 0; }
    Nodo* root;
    int count = 0;
};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo add --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void BinariTree::add(Playlist* data)
{
    Nodo* n = new Nodo(data);
    if (this->isEmpty())
    {
        this->root = n;
    }
    else
    {
        addR(data,root);
    }
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addR --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void BinariTree::addR(Playlist* data, Nodo* aux)
{
    if (_strcmpi(data->getName().c_str(), aux->getDato()->getName().c_str()) < 0)
    {
        if (aux->getLeft() == 0)aux->setLeft(new Nodo(data));
        else addR(data, aux->getLeft());
    }
    else
    {
        if (aux->getRight() == 0)aux->setRight(new Nodo(data));
        else addR(data, aux->getRight());
        
    }    
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo graph --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

void BinariTree::graph()
{

    string arbol = graphR(root);

    int contador = 0;
    ofstream stream;
    stream.open("C:\\EDDProyect\\arbolbinario.dot", ios::out);

    if (stream.fail())
    {
        cout << "Existe un problema con el archivo." << endl;
    }

    stream << "digraph { " << endl;
    stream << "rankdir = TB; " << endl;
    stream << "node [shape = circle, width = 1, height = 1];" << endl;
    
    stream << arbol;

    stream << "}";

    stream.close();

    system("dot -Tpng  C:\\EDDProyect\\arbolbinario.dot -o C:\\EDDProyect\\arbolbinario.png");
    system("start C:\\EDDProyect\\arbolbinario.png");
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo graphR -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
string BinariTree::graphR(Nodo* aux)
{
    string out = "";
    if (aux == 0) {
        return out;
    }
    if (aux->getLeft() != 0) 
    {
        out += aux->getDato()->getName() + " -> " + aux->getLeft()->getDato()->getName()+ ";";
        out +=graphR(aux->getLeft());
    }
    if (aux->getRight() != 0)
    {
        out += aux->getDato()->getName() + " -> " + aux->getRight()->getDato()->getName() + ";";
        out +=graphR(aux->getRight());
    }
    return out;

   
}

//-----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------- Metodo printTree ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void BinariTree::printTree()
{
    count = 1;
    printTreeR(root);
}

//-----------------------------------------------------------------------------------------------------------------------
//----------------------------------------------- Metodo printTree ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void BinariTree::printTreeR(Nodo* aux)
{
    if (aux == 0) { return; }
    printTreeR(aux->getLeft());
    cout << count << ")  " << aux->getDato()->getName() << endl;
    count++;
    printTreeR(aux->getRight());

}

//-----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------- Metodo getPlaylist -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void BinariTree::getPlaylist(int index)
{
    count = 0;
    getPlaylistR(index, root);
}

//-----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------- Metodo getPlaylist -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void BinariTree::getPlaylistR(int index, Nodo* aux)
{
    if (aux == 0) { return; }
    
        getPlaylistR(index, aux->getLeft());

        count++;
        if (count == index) 
        {
            aux->getDato()->reproducir();
            return;
        }
        

        getPlaylistR(index, aux->getRight());
    

}

//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------



