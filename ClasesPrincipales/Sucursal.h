#ifndef SUCURSAL_H
#define SUCURSAL_H

#include "Ciudad.h"

#include <string>
using namespace std;

class Sucursal {
    private:
        string nombreSucursal;
        Ciudad ciudadSucursal;
        string barrioSucursal;
        string direccionSucursal;
        string gerenteSucursal;

    public:
    	
    	Sucursal() {} // Constructor vacï¿½o
    	
        Sucursal(string nombreSucursal, Ciudad ciudadSucursal, string barrioSucursal, string direccionSucursal, string gerenteSucursal) {
            this->nombreSucursal = nombreSucursal;
            this->ciudadSucursal = ciudadSucursal;
            this->barrioSucursal = barrioSucursal;
            this->direccionSucursal = direccionSucursal;
            this->gerenteSucursal = gerenteSucursal;
        }

        // Métodos getter para acceder a los atributos
        string getNombreSucursal() { 
			return nombreSucursal; 
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
	        datos = getNombreSucursal()+ "," + getGerenteSucursal();
	        return datos;
	    }

    
    void setNombreSucursal(string nombreSucursal) {
        Sucursal::nombreSucursal = nombreSucursal;
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
