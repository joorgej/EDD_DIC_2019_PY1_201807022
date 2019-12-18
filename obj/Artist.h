#pragma once
#include <iostream>
#include "../EDD/DisperseCube.h"

using namespace std;

class Artist
{
private:
	string name;
	int rate;
	DisperseCube* albums;

public:
	Artist(string name_) :name(name_), rate(0) {}
	void setName(string name_) { name = name_; }
	void setRate(int rate_) { rate = rate_; }
	void addAlbum() {}
	string getName() { return name; }
	int getRate() { return rate; }


};