#ifndef CIUDAD_H
#define CIUDAD_H

#include <string>
using namespace std;

class Ciudad {
private:
    string nombre;
    string pais;

public:
    Ciudad() {
        nombre = "";
        pais = "";
    }

    Ciudad(string nombre, string pais) {
        this->nombre = nombre;
        this->pais = pais;
    }

    // Getters
    string getNombre() {
        return nombre;
    }
    
    string getPais() {
        return pais;
    }
    
    // Setters
    void setNombre(string nombre) {
        Ciudad::nombre = nombre;
    }
    
    void setPais(string pais) {
        Ciudad::pais = pais;
    }
};

#endif

