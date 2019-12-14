#pragma once
#include <iostream>
#include "EDD/LinckedList.h"
#include "EDD/DoubleLinckedList.h"

using namespace std;


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Object Library ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
class Library
{
private:
	DoubleLinckedList<Artist> *artists;

public:
	Library():artists(new DoubleLinckedList<Artist>()){}
	DoubleLinckedList<Artist> *getArtistList() { return artists; }
	void addArtist(Artist data) { artists->add(data); }

};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Object Artist -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
class Artist
{
private:
	string name;
	int rate;

public:
	Artist(string name_):name(name_), rate(0) {}
	void setName(string name_) { name = name_; }
	void setRate(int rate_) { rate = rate_; }
	void addAlbum() {}
	string getName() { return name; }
	int getRate() { return rate; }


};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Object Album --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
class Album
{
private:
	string name;
	int rate;
	LinckedList<Song> *songs;

public:
	Album(string name_): name(name_),rate(0),songs(new LinckedList<Song>){}
	void setName(string name_) { name = name_; }
	void setRate(int rate_) { rate = rate_;}
	void addSong(Song data) { songs->add(data); }
	string getName() { return name; }
	int getRate() { return rate; }
	LinckedList<Song>* getSongList() { return songs; }


};


//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------- Object Song ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
class Song
{
private:
	string name;
	string file;
	int rate;
	bool isOn;

public:
	Song(string name_, string file_, int rate_):name(name_), file(file_), rate(rate_), isOn(0){}
	void setName(string name_) { name = name_; }
	void setFile(string file_) { file = file_; }
	void setRate(int rate_) { rate = rate_; }
	void setIsOn(bool isOn_) { isOn = isOn_; }
	string getName() { return name; }
	string getFIle() { return file; }
	int getRate() { return rate; }
	bool isOn() { return isOn; }
};
