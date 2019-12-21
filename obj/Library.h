#pragma once
#include <iostream>
#include "../EDD/BinariTree.h"
#include "../EDD/DoubleLinckedList.h"

using namespace std;


class Library
{
private:
	DoubleLinckedList* artists;
	LinckedList* songs;
	BinariTree* playlists;

public:
	Library() :artists(new DoubleLinckedList()), playlists(new BinariTree()), songs(new LinckedList()) {}
	DoubleLinckedList* getArtistList() { return artists; }
	void addArtist(Artist* data) { artists->add(data); }
	void printArtists() { artists->getArtists(); }
	void graphArtists() { artists->graph(); }
	void addSong(Song* data) { songs->add(data); }
	void printSongs() { songs->getSongs(); }
	Song* getSong(int i) { return songs->getElementAt(i-1); }
	void graphPlaylist() { playlists->graph(); }
	void getPlaylist(int index) { playlists->getPlaylist(index); }
	Artist* getArtist(int i) 
	{ 
		return artists->getElementAt(i - 1); 
	}

	void addPlaylist(Playlist* data) { playlists->add(data); }

	void graphTop5() { artists->getTop5(); }

	void printPlaylist() { playlists->printTree(); }


	Song* getSong(string artist, string album, int anio, string mes, string name)
	{
		Artist* art = artists->getArtist(artist);
		if (art == 0) { return 0; }
		else
		{
			Album* alb = art->getAlbum(mes, anio, album);
			if (alb == 0) { return 0; }
			else
			{
				Song* son = alb->getSong(name);
				if (son == 0) { return 0; }
				else
				{
					return son;
				}
			}
		}
	}

	bool validarCancion(string artist, string album, int anio, string mes, string name)
	{
		Artist* art = artists->getArtist(artist);
		if (art == 0) { return 0; }
		else 
		{
			Album* alb = art->getAlbum(mes, anio, album);
			if (alb == 0) { return 0; }
			else
			{
				Song* son = alb->getSong(name);
				if (son == 0) { return 0; }
				else
				{
					return 1;
				}
			}
		}
	}

};
