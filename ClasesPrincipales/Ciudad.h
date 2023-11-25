#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>
using namespace std;

class Ciudad {
private:
    string nombreCiudad;
    string pais;

public:
    Ciudad() {
        nombreCiudad = "";
        pais = "";
    }

    Ciudad(string nombreCiudad, string pais) {
        this->nombreCiudad = nombreCiudad;
        this->pais = pais;
    }

    // Getters
    string getNombreCiudad() {
        return nombreCiudad;
    }
    
    string getPais() {
        return pais;
    }
    
    // Setters
    void setNombreCiudad(string nombreCiudad) {
        Ciudad::nombreCiudad = nombreCiudad;
    }
    
    void setPais(string pais) {
        Ciudad::pais = pais;
    }
};

#endif

