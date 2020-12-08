#include "videogame.h"
#include <fstream>
#include <algorithm>

Videogame::Videogame()
{

}

void Videogame::setUsuario(const string &v)
{
    usuario = v;
}

string Videogame::getUsuario()
{
    return usuario;
}

void Videogame::agregarCivilizacion(const Civilizacion &p)
{
    civilizaciones.push_back(p);
}

void Videogame::insertar(const Civilizacion &c, size_t pos)
{
    civilizaciones.insert(civilizaciones.begin()+pos, c);
}

size_t Videogame::size()
{
    return civilizaciones.size();
}

void Videogame::crear(const Civilizacion &c, size_t n)
{
    civilizaciones = vector<Civilizacion>(n, c);
}

void Videogame::primera()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(20) << "Ubicavión en X";
    cout << setw(20) << "Ubicación en Y";
    cout << setw(15) << "Puntuación";
    cout << endl;
    cout << civilizaciones.front();
}

void Videogame::ultimo()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(20) << "Ubicavión en X";
    cout << setw(20) << "Ubicación en Y";
    cout << setw(15) << "Puntuación";
    cout << endl;
    cout << civilizaciones.back();
}

void Videogame::ordenarNombre()
{
    sort(civilizaciones.begin(), civilizaciones.end());
}

void Videogame::ordenarX()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getUbix() > c2.getUbix();});
}

void Videogame::ordenarY()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getUbiy() > c2.getUbiy();});
}

void Videogame::ordenarPun()
{
    sort(civilizaciones.begin(), civilizaciones.end(), 
    [](Civilizacion c1, Civilizacion c2){return c1.getPuntuacion() > c2.getPuntuacion();});
}

Civilizacion* Videogame::eliminar(const string &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);
    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        return &(*civilizaciones.erase(it));
    }
}

Civilizacion* Videogame::buscar(const string &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        cout << left;
        cout << setw(10) << "Nombre";
        cout << setw(20) << "Ubicavión en X";
        cout << setw(20) << "Ubicación en Y";
        cout << setw(15) << "Puntuación";
        cout << endl;
        return &(*it);
    }
}

void Videogame::total()
{
    cout << left;
    cout << setw(10) << "Nombre";
    cout << setw(20) << "Ubicavión en X";
    cout << setw(20) << "Ubicación en Y";
    cout << setw(15) << "Puntuación";
    cout << endl;

    for (size_t i=0; i<civilizaciones.size(); i++)
    {
        Civilizacion &p = civilizaciones[i];
        cout << p;
    }
}

Civilizacion* Videogame::buscarCivil(const Civilizacion &c)
{
    auto it = find(civilizaciones.begin(), civilizaciones.end(), c);

    if(it == civilizaciones.end()){
        return nullptr;
    }
    else{
        cout << endl;
        cout << left;
        cout << setw(10) << "Nombre";
        cout << setw(20) << "Ubicavión en X";
        cout << setw(20) << "Ubicación en Y";
        cout << setw(15) << "Puntuación";
        cout << endl;
        return &(*it);
    }
}