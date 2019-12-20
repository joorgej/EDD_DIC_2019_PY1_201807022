#pragma once
#include <iostream>
#include "../EDD/LinckedList.h"
#include "Song.h"

using namespace std;

class Album
{
private:
	string name;
	double rate;
	LinckedList *songs;

public:
	Album(string name_) : name(name_), rate(0),songs(new LinckedList) {}
	void setName(string name_) { name = name_; }
	void setRate(double rate_) { rate = rate_; }
	void addSong(Song* data) { songs->addLast(data); }
	string getName() { return name; }
	double getRate() { return rate; }
	LinckedList* getSongList() { return songs; }
	void graphSongs() { songs->graph(); }
	void printSongs() { songs->getSongs(); }
	Song* getSong(int i) { return songs->getElementAt(i-1); }
	Song* getSong(string name_) { return songs->getSong(name_); }


};