#pragma once
#include <iostream>
#include "../Obj/Album.h"


using namespace std;

class Nodo
{
private:
	int yCord;
	int xCord;
	Nodo* left;
	Nodo* right;
	Nodo* top;
	Nodo* buttom;
	Nodo* next;
	Nodo* before;
	Album* data;


public:
	Nodo(Album* data_, int x_, int y_) :data(data_), left(NULL), right(NULL), top(NULL), buttom(NULL), next(NULL), before(NULL), xCord(x_), yCord(y_) {}

	void setLeft(Nodo* n) { left = n; }
	void setRight(Nodo* n) { right = n; }
	void setTop(Nodo* n) { top = n; }
	void setButtom(Nodo* n) { buttom = n; }
	void setNext(Nodo* n) { next = n; }
	void setBefore(Nodo* n) { before = n; }

	Nodo* getLeft() { return left; }
	Nodo* getRight() { return right; }
	Nodo* getTop() { return top; }
	Nodo* getButtom() { return buttom; }
	Nodo* getNext() { return next; }
	Nodo* getBefore() { return before; }
	Album* getAlbum() { return data; }
	int getX() { return xCord; }
	int getY() { return yCord; }



};


class HeaderX
{
private:
	HeaderX* nextx;
	HeaderX* beforex;
	Nodo* column;
	int namex;

public:
	HeaderX(int name_) :namex(name_), nextx(NULL), column(NULL), beforex(NULL) {}

	void setNext(HeaderX* n) { nextx = n; }
	void setBefore(HeaderX* n) { beforex = n; }
	void setColumn(Nodo* n) { column = n; }
	int getName() { return namex; }
	HeaderX* getNext() { return nextx; }
	HeaderX* getBefore() { return beforex; }
	Nodo* getColumn() { return column; }

};


class HeaderY
{
private:
	HeaderY* nexty;
	HeaderY* beforey;
	Nodo* row;
	string namey;
	int index;

public:
	HeaderY(string name_) :namey(name_), nexty(NULL), row(NULL), index(setIndex(name_)), beforey(NULL) { }

	void setNext(HeaderY* n) { nexty = n; }
	void setBefore(HeaderY* n) { beforey = n; }
	void setRow(Nodo* n) { row = n; }
	string getName() { return namey; }
	int getIndex() { return index; }
	HeaderY* getNext() { return nexty; }
	HeaderY* getBefore() { return beforey; }
	Nodo* getRow() { return row; }
	int setIndex(string namey_)
	{
		if (namey_.compare("Enero") == 0)return 1;
		else if (namey_.compare("Febrero") == 0)return 2;
		else if (namey_.compare("Marzo") == 0)return 3;
		else if (namey_.compare("Abril") == 0)return 4;
		else if (namey_.compare("Mayo") == 0)return 5;
		else if (namey_.compare("Junio") == 0)return 6;
		else if (namey_.compare("Julio") == 0)return 7;
		else if (namey_.compare("Agosto") == 0)return 8;
		else if (namey_.compare("Septiembre") == 0)return 9;
		else if (namey_.compare("Octubre") == 0)return 10;
		else if (namey_.compare("Noviembre") == 0)return 11;
		else if (namey_.compare("Diciembre") == 0)return 12;
	}

};


class DisperseCube 
{
	

private:
	HeaderX* x;
	HeaderY* y;

public:

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Constructor ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

	DisperseCube():x(NULL),y(NULL){}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo parseYIndex -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------

	int parseYIndex(string namey_)
	{
		if (namey_.compare("Enero") == 0)return 1;
		else if (namey_.compare("Febrero") == 0)return 2;
		else if (namey_.compare("Marzo") == 0)return 3;
		else if (namey_.compare("Abril") == 0)return 4;
		else if (namey_.compare("Mayo") == 0)return 5;
		else if (namey_.compare("Junio") == 0)return 6;
		else if (namey_.compare("Julio") == 0)return 7;
		else if (namey_.compare("Agosto") == 0)return 8;
		else if (namey_.compare("Septiembre") == 0)return 9;
		else if (namey_.compare("Octubre") == 0)return 10;
		else if (namey_.compare("Noviembre") == 0)return 11;
		else if (namey_.compare("Diciembre") == 0)return 12;
	}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getAlbum -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	Album* getAlbum(string y_, int x_, string name_)
	{
		HeaderX* auxX = x;
		Nodo* aux = 0;
		int index = parseYIndex(y_);
		while(auxX != NULL)
		{
			if (auxX->getName() == x_)
			{
				break;
			}
			auxX = auxX->getNext();
		}
		if (auxX == NULL) {return 0;}
		else { aux = auxX->getColumn(); }

		while (aux!= NULL)
		{
			if (aux->getY() == index) {
				while (aux != 0)
				{
					if (aux->getAlbum()->getName().compare(name_) == 0) 
					{
						return aux->getAlbum();
					}
					aux = aux->getNext();
				}
			}
			aux = aux->getButtom();
		}
		return 0;
	}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ Metodo getAlbums -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	void getAlbums() 
	{
		string out = "";
		int contador = 0;
		HeaderX* head = x;
		while (head != NULL) 
		{
			Nodo* aux = head->getColumn();
			while (aux != NULL) 
			{
				Nodo* aux2 = aux;
				while (aux2 != NULL)
				{
					contador++;
					cout << contador << ")   " << aux2->getAlbum()->getName() <<endl;
					aux2 = aux2->getNext();
				}
				aux = aux->getButtom();
			}
			head = head->getNext();
		}

	}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ Metodo getAlbum -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	Album* getAlbum(int index)
	{
		int contador = 0;
		HeaderX* head = x;
		Nodo* aux = 0;
		Nodo* aux2 = 0;
		while (head != NULL)
		{
			aux = head->getColumn();
			while (aux != NULL)
			{
				aux2 = aux;
				do
				{
					contador++;
					if (contador > index-1) 
					{
						return aux2->getAlbum();
					}
					aux2 = aux2->getNext();
				} while (aux2 != NULL);
				aux = aux->getButtom();
			}
			head = head->getNext();
		}
		
	}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo existX -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	bool existX(int name)
	{
		HeaderX* aux = x;
		while (aux != NULL)
		{
			if (aux->getName() == name)
			{
				return 1;
			}
			aux = aux->getNext();
		}
		return 0;
	}


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo existY -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	bool existY(string name)
	{
		HeaderY* aux = y;
		while (aux != NULL)
		{
			if (aux->getName().compare(name)==0)
			{
				return 1;
			}
			aux = aux->getNext();
		}
		return 0;
	}


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addY ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	void addY(string name)
	{
		HeaderY* y_ = new HeaderY(name);
		int indexY = y_->getIndex();
		if (y == NULL)
		{
			y = y_;
		}
		else if (indexY < y->getIndex())
		{
			y->setBefore(y_);
			y_->setNext(y);
			y = y_;
		}
		else
		{
			HeaderY* aux = y;
			while (aux->getNext() != NULL) {
				if (indexY > aux->getIndex() && indexY < aux->getNext()->getIndex())
				{
					y_->setNext(aux->getNext());
					aux->getNext()->setBefore(y_);
					aux->setNext(y_);
					y_->setBefore(aux);
					break;
				}
				aux = aux->getNext();
			}
			if (aux->getNext() == NULL)
			{
				aux->setNext(y_);
				y_->setBefore(aux);
			}
		}
	}


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addX ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	void addX(int name)
	{
		HeaderX* x_ = new HeaderX(name);
		if (x == NULL)
		{
			x = x_;
		}
		else if (name < x->getName())
		{
			x->setBefore(x_);
			x_->setNext(x);
			x = x_;
		}
		else
		{
			HeaderX* aux = x;
			while (aux->getNext() != NULL)
			{
				if (name > aux->getName() && name < aux->getNext()->getName())
				{
					x_->setNext(aux->getNext());
					aux->getNext()->setBefore(x_);
					aux->setNext(x_);
					x_->setBefore(aux);
					break;
				}
				aux = aux->getNext();
			}
			if (aux->getNext() == NULL)
			{
				aux->setNext(x_);
				x_->setBefore(aux);
			}
		}
	}

	
	//-----------------------------------------------------------------------------------------------------------------------
	//--------------------------------------------------- Metodo graph ------------------------------------------------------
	//-----------------------------------------------------------------------------------------------------------------------  
	void graph()
	{
		HeaderX* auxX = x;
		HeaderY* auxY = y;
		Nodo* aux = 0;
		int grupo = 2;
		int contador = 0;
		ofstream stream;
		stream.open("C:\\EDDProyect\\cuboAlbums.dot", ios::out);

		if (stream.fail())
		{
			cout << "Existe un problema con el archivo." << endl;
		}

		stream << "digraph { " << endl;
		stream << "node [shape = rectangle, width = 1, height = 1];" << endl;
		stream << "root [label = \"Raiz\", style=filled, fillcolor = fireBrick1, group = 1];" << endl;


		while (auxY != 0)
		{
			stream << "headY" << contador << " [label = \"" << auxY->getName() << "\",style=filled, fillcolor = lightskyblue, group = 1];" << endl;
			contador++;
			auxY = auxY->getNext();
		}


		contador = 0;
		while (auxX != 0)
		{
			stream << "headX" << contador << " [label = \"" << auxX->getName() << "\",style=filled, fillcolor = lightskyblue, group = " << grupo << " ];" << endl;
			aux = auxX->getColumn();
			while (aux != 0)
			{
				Nodo* aux2 = aux->getNext();
				stream << aux->getX() << aux->getY() << " [label = \"" << aux->getAlbum()->getName();
				while (aux2 != 0)
				{
					stream << " | " << aux2->getAlbum()->getName();
					aux2 = aux2->getNext();
				}
				stream << "\", group = " << grupo << " ];" << endl;
				aux = aux->getButtom();
			}

			contador++;
			grupo++;
			auxX = auxX->getNext();
		}

		stream << "{ rank = same; root;";
		contador = 0;
		auxX = x;
		while (auxX != 0)
		{
			stream << "headX" << contador << ";";
			auxX = auxX->getNext();
			contador++;
		}
		stream << "}" << endl;

		if (x != 0 && y != 0)
		{
			stream << "root -> headX0;" << endl;
			stream << "root -> headY0;" << endl;
		}

		auxY = y;
		contador = 0;
		while (auxY->getNext() != 0)
		{
			stream << "headY" << contador << " -> " << "headY" << contador + 1 << " ;" << endl;
			auxY = auxY->getNext();
			contador++;
		}
		while (auxY->getBefore() != 0)
		{
			stream << "headY" << contador << " -> " << "headY" << contador - 1 << " ;" << endl;
			auxY = auxY->getBefore();
			contador--;
		}
		
		
		auxX = x;
		contador = 0;
		while (auxX->getNext() != 0)
		{
			stream << "headX" << contador << " -> " << "headX" << contador + 1 << " ;" << endl;
			auxX = auxX->getNext();
			contador++;
		}
		while (auxX->getBefore() != 0)
		{
			stream << "headX" << contador << " -> " << "headX" << contador - 1 << " ;" << endl;
			auxX = auxX->getBefore();
			contador--;
		}


		contador = 0;
		auxY = y;
		while (auxY != 0)
		{
			aux = auxY->getRow();
			stream <<"{ rank = same; "<< "headY" << contador<< "; ";
			while (aux != 0)
			{
				stream << aux->getX() <<aux->getY()<<";" ;
				aux = aux->getRight();
			}
			stream << "}"<<endl;
			contador++;
			auxY = auxY->getNext();
		}

		contador = 0;
		auxX = x;
		while (auxX != 0)
		{
			aux = auxX->getColumn();
			stream << "headX" << contador << " -> " << aux->getX() << aux->getY() << ";"<<endl;
			while (aux->getButtom() != 0)
			{
				stream << aux->getX() << aux->getY() << " -> " << aux->getButtom()->getX() << aux->getButtom()->getY() << "[dir = both];" << endl;
				aux = aux->getButtom();
			}
			contador++;
			auxX = auxX->getNext();
		}

		contador = 0;
		auxY = y;
		while (auxY != 0)
		{
			aux = auxY->getRow();
			stream << "headY" << contador << " -> " << aux->getX() << aux->getY() << ";"<<endl;
			while (aux->getRight() != 0)
			{
				stream << aux->getX() << aux->getY() << " -> " << aux->getRight()->getX() << aux->getRight()->getY() << "[dir = both];"<<endl;
				aux = aux->getRight();
			}
			contador++;
			auxY = auxY->getNext();
		}
		
		


		stream << "}";

		stream.close();

		system("dot -Tpng  C:\\EDDProyect\\cuboAlbums.dot -o C:\\EDDProyect\\cuboAlbums.png");
		system("start C:\\EDDProyect\\cuboAlbums.png");

	}


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo add ----------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	void add(string y_, int x_, Album* data_)
	{
		bool flag = 1;
		HeaderY* auxY = 0;
		HeaderX* auxX = 0;
		auxY = getNodeY(y_);
		auxX = getNodeX(x_);
		int indexY = auxY->getIndex();
		Nodo* dato = new Nodo(data_, auxX->getName(), indexY);

		if (auxY->getRow() == NULL)
		{
			auxY->setRow(dato);
		}
		else
		{
			Nodo* aux = auxY->getRow();
			if (x_ < aux->getX())
			{
				dato->setRight(aux);
				aux->setLeft(dato);
				auxY->setRow(dato);

			}
			else
			{
				do
				{
					if (aux->getX() == auxX->getName())
					{

						flag = 0;
						while (aux->getNext() != NULL)
						{
							aux = aux->getNext();
						}
						aux->setNext(dato);
						dato->setBefore(aux);
						break;
					}
					else if (x_ > aux->getX() && x_ < aux->getRight()->getX())
					{
						dato->setRight(aux->getRight());
						dato->setLeft(aux);
						aux->getRight()->setLeft(dato);
						aux->setRight(dato);

						break;
					}
					else
					{
						aux = aux->getRight();
					}
				} while (aux != NULL);
				if (aux->getRight() == NULL && flag)
				{
					aux->setRight(dato);
					dato->setLeft(aux);

				}
			}
		}

		if (flag)
		{
			if (auxX->getColumn() == NULL)
			{
				auxX->setColumn(dato);
			}
			else
			{
				Nodo* aux = auxX->getColumn();
				if (indexY < aux->getY())
				{
					dato->setButtom(aux);
					aux->setTop(dato);
					auxX->setColumn(dato);


				}
				else
				{
					while (aux->getButtom() != NULL)
					{
						if (x_ > aux->getY() && x_ < aux->getButtom()->getY())
						{
							dato->setButtom(aux->getButtom());
							aux->getButtom()->setTop(dato);
							aux->setButtom(dato);
							dato->setTop(aux);

							break;
						}
						aux = aux->getButtom();
					}
					if (aux->getButtom() == NULL)
					{
						aux->setButtom(dato);
						dato->setTop(aux);
					}
				}
			}
		}
	}


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getNodeX -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	HeaderX* getNodeX(int name) 
	{
		if (!existX(name)) 
		{ 
			addX(name);
		}
		HeaderX* auxX = x;
		while (auxX != NULL)
		{
			if (auxX->getName() == name)
			{
				return auxX;
			}
			auxX = auxX->getNext();
		}
	}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getNodeY -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	HeaderY* getNodeY(string name) 
	{
		if (!existY(name)) 
		{ 
			addY(name); 
			
		}
		HeaderY* auxY = y;
		while (auxY != NULL)
		{
			if (auxY->getName().compare(name)==0)
			{
				return auxY;
			}
			auxY = auxY->getNext();
		}

	}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ Metodo graphTop -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
	void getTop()
	{

		Album* top1 = 0;
		Album* top2 = 0;
		Album* top3 = 0;
		Album* top4 = 0;
		Album* top5 = 0;
		HeaderX* head = x;
		while (head != NULL)
		{
			Nodo* aux = head->getColumn();
			while (aux != NULL)
			{
				Nodo* aux2 = aux;
				while (aux2 != NULL)
				{

					if (top1 == 0)
					{
						top1 = aux2->getAlbum();
					}
					else if (top2 == 0)
					{
						top2 = aux2->getAlbum();
						if (aux2->getAlbum()->getRate() > top1->getRate())
						{
							top2 = top1;
							top1 = aux2->getAlbum();
						}
					}
					else if (top3 == 0)
					{
						top3 = aux2->getAlbum();
						if (aux2->getAlbum()->getRate() > top2->getRate())
						{
							top3 = top2;
							top2 = aux2->getAlbum();
							if (aux2->getAlbum()->getRate() > top1->getRate())
							{
								top2 = top1;
								top1 = aux2->getAlbum();
							}
						}
					}
					else if (top4 == 0)
					{
						top4 = aux2->getAlbum();
						if (aux2->getAlbum()->getRate() > top3->getRate())
						{
							top4 = top3;
							top3 = aux2->getAlbum();
							if (aux2->getAlbum()->getRate() > top2->getRate())
							{
								top3 = top2;
								top2 = aux2->getAlbum();
								if (aux2->getAlbum()->getRate() > top1->getRate())
								{
									top2 = top1;
									top1 = aux2->getAlbum();
								}
							}
						}
					}
					else if (top5 == 0)
					{
						top5 = aux2->getAlbum();
						if (aux2->getAlbum()->getRate() > top4->getRate())
						{
							top5 = top4;
							top4 = aux2->getAlbum();
							if (aux2->getAlbum()->getRate() > top3->getRate())
							{
								top4 = top3;
								top3 = aux2->getAlbum();
								if (aux2->getAlbum()->getRate() > top2->getRate())
								{
									top3 = top2;
									top2 = aux2->getAlbum();
									if (aux2->getAlbum()->getRate() > top1->getRate())
									{
										top2 = top1;
										top1 = aux2->getAlbum();
									}
								}
							}
						}
					}
					else if (aux2->getAlbum()->getRate() > top5->getRate())
					{
						top5 = aux2->getAlbum();
						if (aux2->getAlbum()->getRate() > top4->getRate())
						{
							top5 = top4;
							top4 = aux2->getAlbum();
							if (aux2->getAlbum()->getRate() > top3->getRate())
							{
								top4 = top3;
								top3 = aux2->getAlbum();
								if (aux2->getAlbum()->getRate() > top2->getRate())
								{
									top3 = top2;
									top2 = aux2->getAlbum();
									if (aux2->getAlbum()->getRate() > top1->getRate())
									{
										top2 = top1;
										top1 = aux2->getAlbum();
									}
								}
							}
						}
					}
					aux2 = aux2->getNext();
				}
				aux = aux->getButtom();
			}
			head = head->getNext();
		}


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
		if (top1 != 0)
		{
			stream << "node" << contador << " [label=\"" << "---- " << contador + 1 << " ----\nNombre:  " << top1->getName() << "\nRate:  " << top1->getRate() << "\"];" << endl;
			contador++;
		}
		if (top2 != 0)
		{
			stream << "node" << contador << " [label=\"" << "---- " << contador + 1 << " ----\nNombre:  " << top2->getName() << "\nRate:  " << top2->getRate() << "\"];" << endl;
			contador++;
		}
		if (top3 != 0)
		{
			stream << "node" << contador << " [label=\"" << "---- " << contador + 1 << " ----\nNombre:  " << top3->getName() << "\nRate:  " << top3->getRate() << "\"];" << endl;
			contador++;
		}
		if (top4 != 0)
		{
			stream << "node" << contador << " [label=\"" << "---- " << contador + 1 << " ----\nNombre:  " << top4->getName() << "\nRate:  " << top4->getRate() << "\"];" << endl;
			contador++;
		}
		if (top5 != 0)
		{
			stream << "node" << contador << " [label=\"" << "---- " << contador + 1 << " ----\nNombre:  " << top5->getName() << "\nRate:  " << top5->getRate() << "\"];" << endl;
			contador++;
		}


		
		for (int i = 0; i < contador-1; i++) 
		{
			stream << "node" << i << " -> " << "node" << i + 1 << " ;" << endl;
		}
		
		

		stream << "}";

		stream.close();

		system("dot -Tpng  C:\\EDDProyect\\listaArtistas.dot -o C:\\EDDProyect\\listaArtistas.png");
		system("start C:\\EDDProyect\\listaArtistas.png");


	}
};



/*
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addX ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DisperseCube::addX(int name)
{
	HeaderX* x_ = new HeaderX(name);
	if (x == 0) 
	{
		x = x_;
	}
	else if (name < x->getName())
	{
		x->setBefore(x_);
		x_->setNext(x);
		x = x_;
	}
	else
	{
		HeaderX* aux = x;
		while (aux->getNext() != 0) 
		{
			if (name > aux->getName() && name < aux->getNext()->getName()) 
			{
				x_->setNext(aux->getNext());
				aux->getNext()->setBefore(x_);
				aux->setNext(x_);
				x_->setBefore(aux);
				break;
			}
			aux = aux->getNext();
		}
		if (aux->getNext() == 0) 
		{
			aux->setNext(x_);
			x_->setBefore(aux);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo addY ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DisperseCube::addY(string name)
{
	HeaderY* y_ = new HeaderY(name);
	int indexY = y_->getIndex();
	if (y == 0)
	{
		y = y_;
	}
	else
	{
		HeaderY* aux = y;
		while (aux->getNext() != 0) {
			if (indexY > aux->getIndex() && indexY < aux->getNext()->getIndex())
			{
				y_->setNext(aux->getNext());
				aux->getNext()->setBefore(y_);
				aux->setNext(y_);
				y_->setBefore(aux);
				break;
			}
			aux = aux->getNext();
		}
		if (aux->getNext() == 0)
		{
			aux->setNext(y_);
			y_->setBefore(aux);
		}
	}
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo existX -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool DisperseCube::existX(int name)
{
	HeaderX* aux= x;
	while (aux != 0) 
	{
		if (aux->getName() == name)
		{
			return 1;
		}
		aux = aux->getNext();
	}
	return 0;
}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo existY -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
bool DisperseCube::existY(string name)
{
	HeaderY* aux = y;
	while (aux != 0)
	{
		if (aux->getName().compare(name))
		{
			return 1;
		}
		aux = aux->getNext();
	}
	return 0;
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getNodeX -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
HeaderX* DisperseCube::getNodeX(int name)
{
	if (existX(name) == 0) { addX(name); }
	HeaderX* auxX = x;
	while (auxX != 0)
	{
		if (auxX->getName() == name)
		{
			return auxX;
		}
		auxX = auxX->getNext();
	}
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getNodeY -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
HeaderY* DisperseCube::getNodeY(string name)
{
	if (existY(name) == 0) { addY(name); }
	HeaderY* auxY = y;
	while (auxY != 0)
	{
		if (auxY->getName().compare(name))
		{
			return auxY;
		}
		auxY = auxY->getNext();
	}

}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo add ----------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
void DisperseCube::add(string y_, int x_, Album* data_)
{

	HeaderY* auxY = getNodeY(y_);
	HeaderX* auxX = getNodeX(x_);
	Nodo* dato = new Nodo(data_,auxX, auxY);
	int indexY = auxY->getIndex();

	
	if (auxY->getRow() == 0) 
	{
		auxY->setRow(dato);
	}
	else 
	{
		Nodo* aux = auxY->getRow();
		if (x_ < aux->getX()->getName())
		{
			dato->setRight(aux);
			aux->setLeft(dato);
			auxY->setRow(dato);
		}
		else
		{
			while (aux->getRight() != 0)
			{
				
				if (aux->getX()->getName() == auxX->getName())
				{
					aux->setNext(dato);
					dato->setBefore(aux);
					break;
				}
				else if (x_ > aux->getX()->getName() && x_ < aux->getRight()->getX()->getName())
				{
					dato->setRight(aux->getRight());
					aux->getRight()->setLeft(dato);
					aux->setRight(dato);
					dato->setLeft(aux);
					break;
				}
				aux = aux->getNext();
			}
			if (aux->getNext() == 0) 
			{
				aux->setRight(dato);
				dato->setLeft(aux);
			}
		}
	}


	if (auxX->getColumn() == 0)
	{
		auxX->setColumn(dato);
	}
	else
	{
		Nodo* aux = auxX->getColumn();
		if (indexY < aux->getY()->getIndex())
		{
			dato->setButtom(aux);
			aux->setTop(dato);
			auxX->setColumn(dato);
		}
		else
		{
			while (aux->getButtom() != 0)
			{

				if (aux->getY()->getIndex() == auxY->getIndex())
				{
					break;
				}
				else if (x_ > aux->getY()->getIndex() && x_ < aux->getButtom()->getY()->getIndex())
				{
					dato->setButtom(aux->getButtom());
					aux->getButtom()->setTop(dato);
					aux->setButtom(dato);
					dato->setTop(aux);
					break;
				}
				aux = aux->getNext();
			}
			if (aux->getNext() == 0)
			{
				aux->setButtom(dato);
				dato->setTop(aux);
			}
		}
	}
}
//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Metodo getAlbum -----------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
Album* DisperseCube::getAlbum(string y_, int x_, string name_)
{

	bool flag1 = 0;
	bool flag2 = 0;
	HeaderX* auxX = x;
	while (auxX != 0)
	{
		if (auxX->getName() == x_)
		{
			break;
		}
		auxX = auxX->getNext();
	}

	HeaderY* auxY = y;
	while (auxY != 0)
	{
		if (auxY->getName().compare(y_))
		{
			break;
		}
		auxY = auxY->getNext();
	}

	Nodo* aux = auxX->getColumn();

	while (aux->getButtom() != 0)
	{
		if (aux->getAlbum()->getName().compare(name_))
		{
			flag1 = 1;
			break;
		}
		aux = aux->getButtom();
	}

	aux = auxY->getRow();

	while (aux->getRight() != 0)
	{
		if (aux->getAlbum()->getName().compare(name_))
		{
			flag1 = 1;
			break;
		}
		aux = aux->getRight();
	}

	if (flag1 && flag2) return aux->getAlbum();
	else return 0;

}
*/