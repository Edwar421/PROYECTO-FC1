#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "Ciudad.h"

#include <string>
using namespace std;

class Sucursal {
    private:
        string nombre;
        Ciudad ciudadSucursal;
        string barrioSucursal;
        string direccionSucursal;
        string gerenteSucursal;

    public:
    	
    	Sucursal() {} // Constructor vacï¿½o
    	
        Sucursal(string nombre, Ciudad ciudadSucursal, string barrioSucursal, string direccionSucursal, string gerenteSucursal) {
            this->nombre = nombre;
            this->ciudadSucursal = ciudadSucursal;
            this->barrioSucursal = barrioSucursal;
            this->direccionSucursal = direccionSucursal;
            this->gerenteSucursal = gerenteSucursal;
        }

        // Métodos getter para acceder a los atributos
        string getNombre() { 
			return nombre; 
		}
		
		Ciudad getCiudadSucursal() {
	        return ciudadSucursal;
	    }
	    
	    string getBarrioSucursal() {
	        return barrioSucursal;
	    }
	    
	    string getDireccionSucursal() {
	        return direccionSucursal;
	    }
		
        string getGerenteSucursal() { 
			return gerenteSucursal; 
		}
        
        // Mï¿½todo toString para la clase Partido
	    string toString() {
	        string datos;
	        datos = getNombre()+ "," + getGerenteSucursal();
	        return datos;
	    }

    
    void setNombre(string nombre) {
        Sucursal::nombre = nombre;
    }
    
    void setCiudadSucursal(Ciudad ciudadSucursal) {
        Sucursal::ciudadSucursal = ciudadSucursal;
    }
    
    void setBarrioSucursal(string barrioSucursal) {
        Sucursal::barrioSucursal = barrioSucursal;
    }
    
    void setDireccionSucursal(string direccionSucursal) {
        Sucursal::direccionSucursal = direccionSucursal;
    }

    void setgerenteSucursal(string gerenteSucursal) {
        Sucursal::gerenteSucursal = gerenteSucursal;
    }
};

#endif
