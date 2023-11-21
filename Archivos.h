#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>

#include <sstream>


#include "Estructuras de Datos/Lista.h"

#include "ClasesPrincipales/Empleado.h"

#include "LeerEntradas.h"

using namespace std;

class Archivos {
private: string nombreArchivo;
    string rutaArchivo;

    //Lista leidas de la memoria secundaria

    //Lista < Empleado > * empleados;
	Lista < Ciudad > * ciudades;
   	Lista < Sucursal > * sucursales;

public: Archivos(string nombre) {
        nombreArchivo = nombre + ".txt";
        rutaArchivo = "Memoria Secundaria/" + nombreArchivo;
    }

     void escribir(const std::string& contenido) {
        std::ofstream archivo(rutaArchivo.c_str());  // Utiliza c_str() para obtener const char*
        if (archivo.is_open()) {
            archivo << contenido;
            archivo.close();
        } else {
            std::cerr << "Error al abrir el archivo para escribir." << std::endl;
        }
    }

    void anadir(std::string texto, std::string rutaArchivo) {
	    std::ofstream archivo(rutaArchivo.c_str(), std::ios::app);
	    archivo << texto;
	    archivo.close();
	}

    void modificar(std::string textoAntiguo, std::string textoNuevo, std::string rutaArchivo) {
    	std::ifstream archivoAntiguo(rutaArchivo.c_str());
        ofstream archivoNuevo("temp.txt");

        string linea;
        while (getline(archivoAntiguo, linea)) {
            if (linea == textoAntiguo) {
                archivoNuevo << textoNuevo << endl;
            } else {
                archivoNuevo << linea << endl;
            }
        }

        archivoAntiguo.close();
        archivoNuevo.close();

        remove(rutaArchivo.c_str());
        rename("temp.txt", rutaArchivo.c_str());
    }

   void eliminar(std::string rutaArchivo, std::string texto) {
	    std::ifstream archivoAntiguo(rutaArchivo.c_str());  // Utiliza c_str() para obtener const char*
	    std::ofstream archivoNuevo("temp.txt");
	
	    std::string linea;
	    while (getline(archivoAntiguo, linea)) {
	        if (linea != texto) {
	            archivoNuevo << linea << std::endl;
	        }
	    }
	
	    archivoAntiguo.close();
	    archivoNuevo.close();
	
	    remove(rutaArchivo.c_str());
	    rename("temp.txt", rutaArchivo.c_str());
	}

    //Del archivo Ciudades, lee las ciudades, crea los objetos de las ciudades, los a�ade a la lista y retorna la lista
    Lista<Ciudad>* leerCiudades() {
	    ciudades = new Lista<Ciudad>();
	
	    ifstream archivo(rutaArchivo.c_str());  // Utiliza c_str() para obtener const char*
	    if (!archivo) {
	        cout << "Error al abrir el archivo." << endl;
	        return ciudades;
	    }
	
	    string linea;
	    while (getline(archivo, linea)) {
	        stringstream ss(linea);
	        string nombreCiudad;
	
	        if (getline(ss, nombreCiudad)) {
	            if (!nombreCiudad.empty()) {
	                Ciudad ciudad(nombreCiudad);
	                ciudades->insertar(ciudad);
	            }
	        }
	    }
	
	    archivo.close();
	    return ciudades;
	}
	/*
    //Del archivo Partidos, lee los partidos, crea los objetos de los partidos, los a�ade a la lista y retorna la lista
    Lista < Sucursal > * leerSucursales() {
        sucursales = new Lista < Sucursal > ();

        ifstream archivo(rutaArchivo.c_str());
        if (!archivo) {
            cout << "Error al abrir el archivo." << endl;
            return sucursales;
        }

        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, ciudadSucursal, barrioSucursal, direccionSucursal, gerenteSucursal;

            if (getline(ss, nombre, ',') && getline(ss, ciudadSucursal, ',') && getline(ss, barrioSucursal, ',') && 
				getline(ss, direccionSucursal, ',') && getline(ss, gerenteSucursal)) {
                if (!nombre.empty() && !gerenteSucursal.empty()) {
                	
                	Ciudad ciudadSucursal(ciudadSucursal);

                    Sucursal sucursal(nombre, ciudadSucursal, barrioSucursal, direccionSucursal, gerenteSucursal);
                    sucursales -> insertar(sucursal);
                }
            }
        }

        archivo.close();
        return sucursales;
    }
/*
    //Del archivo empleados, lee los empleados, crea los objetos de los empleados, los a�ade a la lista y retorna la lista

    Lista < Empleado > * leerEmpleados() {
        empleados = new Lista < Empleado > ();

        ifstream archivo(rutaArchivo);
        if (!archivo) {
            cout << "Error al abrir el archivo." << endl;
            return empleados;
        }

        string linea;
        while (getline(archivo, linea)) {
            stringstream ss(linea);
            string nombre, apellido, tipoIdentificacion, numIdentificacion, sexo, telefonoCelular,
					telefonoFijo, email, fechaNacimiento, paisNacimiento, ciudadNacimiento, ciudadResidencia, direccionResidencia, 
					barrioResidencia, actividadLaboral, sucursal

            if (getline(ss, nombre, ',') && getline(ss, apellido, ',') &&
                getline(ss, tipoIdentificacion, ',') && getline(ss, numIdentificacion, ',') &&
                getline(ss, sexoStr, ',') && getline(ss, telefonoCelular, ',') && getline(ss, telefonoFijo, ',') && getline(ss, email, ',') &&
                getline(ss, fechaNacimiento, ',')  && getline(ss, paisNacimiento, ',') && getline(ss, ciudadNacimiento, ',') &&
                getline(ss, ciudadResidencia, ',') && getline(ss, direccionResidencia, ',') && getline(ss, barrioRedidencia, ',') && 
				getline(ss, actividadLaboral, ',') && getline(ss, nombreSucursal)
            {
                if (!nombre.empty() && !apellido.empty() && !tipoIdentificacion.empty() && !numIdentificacion.empty() &&
                    !sexoStr.empty() && !telefonoCelular.empty() && !telefonoFijo.empty() && !fechaNacimiento.empty() && !paisNacimiento.empty() &&
                    !ciudadNacimiento.empty() && !ciudadResidencia.empty() && !direccionResidencia.empty() &&
					!barrioResidencia.empty() && !actividadLaboral.empty() && !nombreSucursal.empty()) {

                    char sexo = sexoStr[0];
                    Ciudad ciudadNacimiento(ciudadNacimiento, " ", 0, 0);
                    Ciudad ciudadResidencia(ciudadResidencia, " ", 0, 0);
                    Sucursal sucursal(nombreSucursal, " ");


                    //inicializa el empleado y lo a�ade en la lista
                    Empleado empleado(nombre, apellido, tipoIdentificacion, numIdentificacion, sexo, telefonoCelular,
										telefonoFijo, email, fechaNacimiento, paisNacimiento, ciudadNacimiento, ciudadResidencia, direccionResidencia, 
										barrioResidencia, actividadLaboral, sucursal);

                    empleados -> insertar(empleado);
                }
            }
        }

        archivo.close();
        return empleados;
    }*/

};
#endif
