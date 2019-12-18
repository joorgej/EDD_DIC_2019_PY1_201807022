#pragma once
#include <iostream>
#include "../EDD/LinckedList.h"

using namespace std;

class Song
{
private:
	string name;
	string file;
	int rate;
	bool suena;

public:
	Song() {}
	Song(string name_, string file_, int rate_) :name(name_), file(file_), rate(rate_), suena(0) {}
	void setName(string name_) { name = name_; }
	void setFile(string file_) { file = file_; }
	void setRate(int rate_) { rate = rate_; }
	void setIsOn(bool isOn_) { suena = isOn_; }
	string getName() { return name; }
	string getFIle() { return file; }
	int getRate() { return rate; }
	bool isOn() { return suena; }
};

