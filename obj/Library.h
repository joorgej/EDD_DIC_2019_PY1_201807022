#pragma once
#include <iostream>
#include "../EDD/LinckedList.h"
#include "../EDD/DoubleLinckedList.h"

using namespace std;


class Library
{
private:
	DoubleLinckedList* artists;

public:
	Library() :artists(new DoubleLinckedList()) {}
	DoubleLinckedList* getArtistList() { return artists; }
	void addArtist(Artist* data) { artists->add(data); }
	void printArtists() { artists->getArtists(); }
	Artist* getArtist(int index) { return artists->getElementAt(index - 1); }

};

