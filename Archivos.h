#ifndef ARCHIVOS_H
#define ARCHIVOS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>


#include "Estructuras de Datos/Lista.h"

#include "ClasesPrincipales/Sucursal.h"

#include "ClasesPrincipales/Ciudad.h"

#include "ClasesPrincipales/Empleado.h"

#include "LeerEntradas.h"

using namespace std;

class Archivos {
private: string nombreArchivo;
    string rutaArchivo;

    //Lista leidas de la memoria secundaria

    Lista < Empleado > * empleados;
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

    //Del archivo Ciudades, lee las ciudades, crea los objetos de las ciudades, los aï¿½ade a la lista y retorna la lista
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
	
    //Del archivo Partidos, lee los partidos, crea los objetos de los partidos, los aï¿½ade a la lista y retorna la lista
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
            string nombre, ciudadSucur, barrioSucursal, direccionSucursal, gerenteSucursal;

            if (getline(ss, nombre, ',') && getline(ss, ciudadSucur, ',') && getline(ss, barrioSucursal, ',') && 
				getline(ss, direccionSucursal, ',') && getline(ss, gerenteSucursal)) {
                if (!nombre.empty() && !gerenteSucursal.empty()) {
                	
                	Ciudad ciudadSucursal(ciudadSucur);

                    Sucursal sucursal(nombre, ciudadSucursal, barrioSucursal, direccionSucursal, gerenteSucursal);
                    sucursales -> insertar(sucursal);
                }
            }
        }

        archivo.close();
        return sucursales;
    }

    //Del archivo empleados, lee los empleados, crea los objetos de los empleados, los aï¿½ade a la lista y retorna la lista

    Lista<Empleado>* leerEmpleados() {
	    Lista<Empleado>* empleados = new Lista<Empleado>();
	
	    ifstream archivo(rutaArchivo.c_str());
	    if (!archivo) {
	        cout << "Error al abrir el archivo." << endl;
	        return empleados;
	    }
	
	    string linea;
	    while (getline(archivo, linea)) {
	        stringstream ss(linea);
	        string nombre, apellido, tipoIdentificacion, numIdentificacion, sexoStr, telefonoCelular,
	            telefonoFijo, email, fechaNacimiento, paisNacimiento, ciudadNaci, ciudadResi, direccionResidencia,
	            barrioResidencia, actividadLaboral, tieneHijosStr, numHijosStr, hijosInfo, sucursalStr;
	
	        if (getline(ss, nombre, ',') && getline(ss, apellido, ',') &&
	            getline(ss, tipoIdentificacion, ',') && getline(ss, numIdentificacion, ',') &&
	            getline(ss, sexoStr, ',') && getline(ss, telefonoCelular, ',') && getline(ss, telefonoFijo, ',') && getline(ss, email, ',') &&
	            getline(ss, fechaNacimiento, ',') && getline(ss, paisNacimiento, ',') && getline(ss, ciudadNaci, ',') &&
	            getline(ss, ciudadResi, ',') && getline(ss, direccionResidencia, ',') && getline(ss, barrioResidencia, ',') &&
	            getline(ss, actividadLaboral, ',') && getline(ss, tieneHijosStr, ',') && getline(ss, numHijosStr, ',') &&
	            getline(ss, hijosInfo, ',') && getline(ss, sucursalStr)) {
	
	            if (!nombre.empty() && !apellido.empty() && !tipoIdentificacion.empty() && !numIdentificacion.empty() &&
	                !sexoStr.empty() && !telefonoCelular.empty() && !telefonoFijo.empty() && !fechaNacimiento.empty() && !paisNacimiento.empty() &&
	                !ciudadNaci.empty() && !ciudadResi.empty() && !direccionResidencia.empty() &&
	                !barrioResidencia.empty() && !actividadLaboral.empty() && !tieneHijosStr.empty() && !numHijosStr.empty() && !sucursalStr.empty()) {
	
	                char sexo = sexoStr[0];
	                char tieneHijos = tieneHijosStr[0];
	                int numHijos = stoi(numHijosStr);
	                

					
	                Ciudad ciudadNacimiento(ciudadNaci);
	                Ciudad ciudadResidencia(ciudadResi);
	                
	                Sucursal sucursal(sucursalStr, ciudadResidencia, " ", " ", " "); 
	                
	
	               Empleado nuevoEmpleado(nombre, apellido, tipoIdentificacion, numIdentificacion, sexo, telefonoCelular,
										    telefonoFijo, email, fechaNacimiento, paisNacimiento, ciudadNacimiento, ciudadResidencia, direccionResidencia,
										    barrioResidencia, actividadLaboral, tieneHijos, numHijos, sucursal);
	
	                // Procesar la información de los hijos
	                if (tieneHijos == 'S') {
	                    stringstream hijosStream(hijosInfo);
	                    string hijoNombre, fechaNacimientoHijo;
	                    while (getline(hijosStream, hijoNombre, ';') && getline(hijosStream, fechaNacimientoHijo, ';')) {
	                        Hijo hijo(hijoNombre, fechaNacimientoHijo);
	                        nuevoEmpleado.agregarHijo(hijo);
	                    }
	                }
	
	                empleados->insertar(nuevoEmpleado);
	            }
	        }
	    }
	
	    archivo.close();
	    return empleados;
}
};


#endif
