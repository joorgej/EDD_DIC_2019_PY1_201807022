// proyecto_1.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//
#pragma warning(disable : 4996).
#include <iostream>
#include <chrono>
#include <fstream>
#include "json/json.h" 
#include "EDD/DisperseCube.h"
#include "Obj/Album.h"
#include "Obj/Library.h"
#include "Obj/Artist.h"
#include "Obj/Playlist.h"

using namespace std;

class Menus
{

private:
    Library* l;


public:

    Menus() :l(new Library()) {}

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ Cargar Libreria ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void cargaLibreria()
    {
        cout << "Ingresa la ruta de la libreria de musica:  "<<endl;
        string ruta = "";
        cin >> ruta;

        ifstream ifs(ruta);
        Json::Reader reader;
        Json::Value root;
        reader.parse(ifs, root);

        //Library* l = new Library();

        for (int i = 0; i < root["Library"].size(); i++)
        {
            double rateArt = 0;
            Artist* artist = new Artist(root["Library"][i]["Artist"]["Name"].asString());

            for (int j = 0; j < root["Library"][i]["Artist"]["Albums"].size(); j++)
            {
                double rateAlb = 0;
                Album* album = new Album(root["Library"][i]["Artist"]["Albums"][j]["Name"].asString());
                for (int k = 0; k < root["Library"][i]["Artist"]["Albums"][j]["Songs"].size(); k++)
                {
                    string name = root["Library"][i]["Artist"]["Albums"][j]["Songs"][k]["Name"].asString();
                    string file = root["Library"][i]["Artist"]["Albums"][j]["Songs"][k]["File"].asString();
                    double rate = stod(root["Library"][i]["Artist"]["Albums"][j]["Songs"][k]["Rating"].asString());
                    Song* song = new Song(name, file, rate);
                    rateAlb += rate;
                    album->addSong(song);
                    l->addSong(song);
                }
                rateArt += rateAlb / root["Library"][i]["Artist"]["Albums"].size();
                album->setRate(rateAlb / root["Library"][i]["Artist"]["Albums"].size());
                string mes = root["Library"][i]["Artist"]["Albums"][j]["Month"].asString();
                int anio = stoi(root["Library"][i]["Artist"]["Albums"][j]["Year"].asString());
                artist->addAlbum(album, anio, mes);
            }
            artist->setRate(rateArt / root["Library"].size());
            l->addArtist(artist);
        }
        cout << "La libreria se cargo exitosamente" << endl << endl << endl << endl;
        menuInicio();
    }


//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Menu Inicio -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void menuInicio() 
    {
        cout << "---------------------------------------MENU---------------------------------------"<<endl<<endl;
        cout << "1)  Canciones" << endl;
        cout << "2)  Playlist" << endl;
        cout << "3)  Reportes" << endl;
        cout << endl;
        cout << "0)  X Salir" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 1:
            Navegacion();
            break;

        case 2:
            Playlists();
            break;

        case 3:
            Reportes();
            break;

        case 0:
            exit(0);
            break;

        default:
            cout<<"Escoje una opcion valida" << endl << endl << endl << endl;
            menuInicio();
            break;
        }

    }

//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Navegacion --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void Navegacion()
    {
        cout << "------------------------------ELEGIR NAVEGACION------------------------------" << endl << endl;
        cout << "Elije como deseas navegar." << endl;
        cout << "1)  Por artistas" << endl;
        cout << "2)  Por canciones" << endl;
        cout << endl;
        cout << "0)  <- Regresar" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 1:
            byArtist();
            break;

        case 2:
            bySong();
            break;

        case 0:
            menuInicio();
            break;

        default:
            cout << "Escoje una opcion valida" << endl << endl << endl << endl;
            Navegacion();
            break;
        }
    }
//-----------------------------------------------------------------------------------------------------------------------
//--------------------------------------------------- Por Artistas ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void byArtist()
    {
        Artist* art = seleccionarArtista();
        Album* album = seleccionarAlbum(art);
        Song* a = seleccionarCancion(album);
        cout << "Se esta reproduciendo \"" << a->getName() << "\".";
        _sleep(7000);
        cout << endl << endl << endl << endl;
        byArtist();
    }
    //-------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------- Por Canciones ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void bySong()
    {
        Song* a = seleccionarCancion();
        cout << "Se esta reproduciendo \"" << a->getName() << "\".";
        _sleep(7000);
        cout << endl << endl << endl<<endl;
        bySong();
    }
//-----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Reportes ---------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void Reportes()
    {
        Artist* art = 0;
        cout << "----------------------------------REPORTES----------------------------------" << endl << endl;
        cout << "Elije el reporte que deseas consultar." << endl;
        cout << "1)  Artists Report" << endl;
        cout << "2)  Discography Report" << endl;
        cout << "3)  Album Report" << endl;
        cout << "4)  Playlist Report" << endl;
        cout << "5)  Top 5 Albums By Artist Report" << endl;
        cout << "6)  Top 5 Artists Report" << endl;
        cout << endl;
        cout << "0)  <- Regresar" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 1:
            l->graphArtists();
            Reportes();
            break;

        case 2:
            art = seleccionarArtista();
            art->graphAlbums();
            Reportes();
            break;

        case 3:
            art = seleccionarArtista();
            seleccionarAlbum(art)->graphSongs();
            Reportes();
            break;

        case 5:
            art = seleccionarArtista();
            art->graphTop();
            Reportes();
            break;

        case 4:
            l->graphPlaylist();
            Reportes();
            break;

        case 6:
            l->graphTop5();
            Reportes();
            break;

        case 0:
            menuInicio();
            break;

        default:
            cout << "Escoja una opcion valida" << endl << endl << endl << endl;
            Navegacion();
            break;
        }
    }

//-----------------------------------------------------------------------------------------------------------------------
//---------------------------------------------------- Playlists --------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void Playlists()
    {
        cout << "----------------------------------PLAYLISTS----------------------------------" << endl << endl;
        cout << "Elije la opcion que desees realizar." << endl;
        cout << "1)  Reproducir playlist" << endl;
        cout << "2)  Cargar playlist" << endl;
        cout << endl;
        cout << "0)  <- Regresar" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 1:
            PlaylistNav();
            Reportes();
            break;

        case 2:
            ingresarPlaylist();
            Playlists();
            break;


        case 0:
            menuInicio();
            break;

        default:
            cout << "Escoja una opcion valida" << endl << endl << endl << endl;
            Navegacion();
            break;
        }
    }

//-----------------------------------------------------------------------------------------------------------------------
//-------------------------------------------------- PlaylistsNav -------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void PlaylistNav()
    {
        cout << "----------------------------------PLAYLISTS----------------------------------" << endl << endl;
        cout << "Elije la playlist que desees reproducir." << endl;
        l->printPlaylist();
        cout << endl;
        cout << "0)  <- Regresar" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 0:
            menuInicio();
            break;

        default:
            l->getPlaylist(c);
            Playlists();
            break;
        }
    }

//-----------------------------------------------------------------------------------------------------------------------
//------------------------------------------------ Cargar Playlist ------------------------------------------------------
//-----------------------------------------------------------------------------------------------------------------------
    void ingresarPlaylist()
    {
        cout << "Ingresa el nombre de la nueva Playlist :   ";
        string name = "";
        cin >> name;
        cout << endl << endl;
        cout << "Ingresa la ruta de la Playlist que se agregara:  " << endl;
        string ruta = "";
        cin >> ruta;

        ifstream ifs(ruta);
        Json::Reader reader;
        Json::Value root;
        reader.parse(ifs, root);

        string type = root["Type"].asString();

        Playlist* p = new Playlist(name, type);

        for (int i = 0; i < root["Songs"].size(); i++)
        {
            int year = stoi(root["Songs"][i]["Year"].asString());
            string month = root["Songs"][i]["Month"].asString();
            string album = root["Songs"][i]["Album"].asString();
            string song = root["Songs"][i]["Song"].asString();
            string artist = root["Songs"][i]["Artist"].asString();
            bool exist= l->validarCancion(artist, album, year, month, song);
            if (exist) 
            {
                p->add(l->getSong(artist, album, year, month, song));
            }
            
        }
        l->addPlaylist(p);
        cout << "La playlist se cargo exitosamente" << endl << endl << endl << endl;
    }

    Artist* seleccionarArtista()
    {
        cout << "----------------------------------ARTISTAS----------------------------------" << endl << endl;
        cout << "Elije un artista." << endl;
        l->printArtists();
        cout << endl;
        cout << "0)  <- Regresar Menu" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 0:
            menuInicio();
            return 0;
            break;

        default:
            return l->getArtist(c);
            break;
        }
    }
    Album* seleccionarAlbum(Artist* a)
    {
        cout << "-----------------------------------ALBUMES-----------------------------------" << endl << endl;
        cout << "Elije un album." << endl;
        a->printAlbums();
        cout << endl;
        cout << "0)  <- Regresar Menu" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 0:
            menuInicio();
            return 0;
            break;

        default:
            return a->getAlbum(c);
            break;
        }
    }
    Song* seleccionarCancion(Album* a)
    {
        cout << "----------------------------------CANCIONES----------------------------------" << endl << endl;
        cout << "Elije una cancion." << endl;
        a->printSongs();
        cout << endl;
        cout << "0)  <- Regresar Menu" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 0:
            menuInicio();
            return 0;
            break;

        default:
            return a->getSong(c);
            break;
        }
    }

    Song* seleccionarCancion()
    {
        cout << "----------------------------------CANCIONES----------------------------------" << endl << endl;
        cout << "Elije una cancion." << endl;
        l->printSongs();
        cout << endl;
        cout << "0)  <- Regresar Menu" << endl;
        cout << endl;
        cout << endl;
        cout << "Selecciona una opcion:  ";
        int c = 0;
        cin >> c;
        cout << endl << endl << endl << endl;
        switch (c)
        {
        case 0:
            menuInicio();
            return 0;
            break;

        default:
            return l->getSong(c);
            break;
        }
    }
};


int main()
{

    Menus* m = new Menus();
    m->cargaLibreria();



}

    /*

    Library* l = new  Library();
    Artist* artista1 = new Artist("Juana");
    Artist* artista2 = new Artist("Marcos");
    Artist* artista3 = new Artist("Ana");
    Artist* artista4 = new Artist("Mariel");


    l->addArtist(artista1);
    l->addArtist(artista2);
    l->addArtist(artista3);
    l->addArtist(artista4);


    l->printArtists();

    cout<<l->getArtist()->getName()<<endl<<endl;
    


    Album* a = new Album("album1");
    Album* b = new Album("album2");
    Album* g = new Album("album3");
    Album* d = new Album("album4");
    Album* f = new Album("album5");
    Album* y = new Album("album6");
    DisperseCube* c = new DisperseCube();

    c->add("Marzo", 2019, f);
    c->add("Febrero", 2020, b);
    c->add("Febrero", 1999, g);
    c->add("Febrero", 2019, d);
    c->add("Enero", 2019, a);
    c->add("Febrero", 2019, y);
    c->add("Febrero", 1999, g);
    c->getAlbums();
    Album* p = c->getAlbum("Febrero", 2019, "album4");

    std::cout << p->getName();
}

        */


// Ejecutar programa: Ctrl + F5 o menú Depurar > Iniciar sin depurar
// Depurar programa: F5 o menú Depurar > Iniciar depuración

// Sugerencias para primeros pasos: 1. Use la ventana del Explorador de soluciones para agregar y administrar archivos
//   2. Use la ventana de Team Explorer para conectar con el control de código fuente
//   3. Use la ventana de salida para ver la salida de compilación y otros mensajes
//   4. Use la ventana Lista de errores para ver los errores
//   5. Vaya a Proyecto > Agregar nuevo elemento para crear nuevos archivos de código, o a Proyecto > Agregar elemento existente para agregar archivos de código existentes al proyecto
//   6. En el futuro, para volver a abrir este proyecto, vaya a Archivo > Abrir > Proyecto y seleccione el archivo .sln
