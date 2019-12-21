#pragma once
#include "Song.h"
#include "../EDD/CircularDoubleLinckedList.h"
#include "../EDD/Queue.h"
#include "../EDD/Stack.h"
#include "../EDD/DoubleShuffleLinckedList.h"


class Playlist
{

private:

	string typeS;
	int type;
	Stack* pila;
	Queue* cola;
	DoubleShuffleLinckedList* shuffle;
	CircularDoubleLinckedList* circular;
	string name;


public:
	Playlist(string name_, string type_) :name(name_), typeS(type_), type(getType(type_)) 
	{
		if (type == 0) pila = new Stack();
		else if (type == 1) cola = new Queue();
		else if (type == 2) shuffle = new DoubleShuffleLinckedList();
		else if (type == 3) circular = new CircularDoubleLinckedList();
	}

	int getType(string type_)
	{
		if (type_.compare("Stack") == 0) return 0;
		else if (type_.compare("Queue") == 0) return 1;
		else if (type_.compare("Shuffle") == 0) return 2;
		else if (type_.compare("Circular") == 0) return 3;
	}
	string getName() { return name; }
	string getType() { return typeS; }


	void add(Song* song_) 
	{
		if (type == 0)pila->push(song_);
		else if (type == 1)cola->enqueue(song_);
		else if (type == 2)shuffle->addLast(song_);
		else if (type == 3)circular->addLast(song_);
	}

	void reproducir() 
	{
		if (type == 0)pila->reproducir();
		else if (type == 1)cola->reproducir();
		else if (type == 2)shuffle->reproducir();
		else if (type == 3)circular->reproducir();
	}

};