#pragma once
#include <iostream>
#include "../EDD/DisperseCube.h"

using namespace std;

class Artist
{
private:
	string name;
	double rate;
	DisperseCube* albums;

public:
	Artist(string name_) :name(name_), rate(0), albums(new DisperseCube()) {}
	Artist(string name_, double rate_): name(name_), rate(rate_), albums(new DisperseCube()){}
	void setName(string name_) { name = name_; }
	void setRate(double rate_) { rate = rate_; }
	void addAlbum(Album* album, int anio, string mes) { albums->add(mes, anio, album); }
	string getName() { return name; }
	double getRate() { return rate; }
	void printAlbums() { albums->getAlbums(); }
	void graphAlbums() { albums->graph(); }
	void graphTop() { albums->getTop(); }
	Album* getAlbum(int i)
	{
		return albums->getAlbum(i);
	}
	Album* getAlbum(string mes, int anio, string nombre)
	{
		return albums->getAlbum(mes, anio, nombre);
	}


};