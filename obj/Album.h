#pragma once
#include <iostream>
#include "../EDD/LinckedList.h"

using namespace std;

class Album
{
private:
	string name;
	int rate;
	LinckedList *songs;

public:
	Album(string name_) : name(name_), rate(0),songs(new LinckedList) {}
	void setName(string name_) { name = name_; }
	void setRate(int rate_) { rate = rate_; }
	void addSong(Song* data) { songs->addLast(data); }
	string getName() { return name; }
	int getRate() { return rate; }
	LinckedList* getSongList() { return songs; }


};