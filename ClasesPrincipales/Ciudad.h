#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>
using namespace std;

class Ciudad {
private:
    string nombreCiudad;
    

public:
    Ciudad() {
        nombreCiudad = "";
    }

    Ciudad(string nombreCiudad) {
        this->nombreCiudad = nombreCiudad;
    }

    // Getters
    string getNombreCiudad() {
        return nombreCiudad;
    }
    
    /*string getPais() {
        return pais;
    }*/

    // Setters
    void setNombreCiudad(string nombreCiudad) {
        Ciudad::nombreCiudad = nombreCiudad;
    }
    
    /*void setPais(string pais) {
        Ciudad::pais = pais;
    }*/
};

#endif

