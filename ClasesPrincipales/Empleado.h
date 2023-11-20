#ifndef EMPLEADO_H
#define EMPLEADO_H

#include <string>

#include "Ciudad.h"

#include "Sucursal.h"

using namespace std;

class Empleado {
private: 
	string nombre;
    string apellido;
    string tipoIdentificacion;
    string numIdentificacion;
    char sexo;
    string telefonoCelular;
    string telefonoFijo;
    string email;
    string fechaNacimiento;
    string paisNacimiento;
    Ciudad ciudadNacimiento;
    Ciudad ciudadResidencia;
    string direccionResidencia;
    string barrioResidencia;
    string actividadLaboral;
    Sucursal sucursal;
    

public: Empleado() {
        nombre = "";
        apellido = "";
        tipoIdentificacion = "";
        numIdentificacion = "";
        sexo = 'N';
        telefonoCelular = "";
        telefonoFijo = "";
        email = "";
        fechaNacimiento = "";
        paisNacimiento = "";
        direccionResidencia = "";
    	barrioResidencia = "";
        actividadLaboral = "";
        //hijos = 'H';
    }

    Empleado(string nombre, string apellido, string tipoIdentificacion, string numIdentificacion, char sexo, string telefonoCelular,
			string telefonoFijo, string email, string fechaNacimiento, string paisNacimiento, Ciudad ciudadNacimiento, Ciudad ciudadResidencia, string direccionResidencia, 
			string barrioResidencia, string actividadLaboral, Sucursal sucursal) {
        this -> nombre = nombre;
        this -> apellido = apellido;
        this -> tipoIdentificacion = tipoIdentificacion;
        this -> numIdentificacion = numIdentificacion;
        this -> sexo = sexo;
        this -> telefonoCelular = telefonoCelular;
        this -> telefonoFijo = telefonoFijo;
        this -> email = email;
        this -> fechaNacimiento = fechaNacimiento;
        this -> paisNacimiento = paisNacimiento;
        this -> ciudadNacimiento = ciudadNacimiento;
        this -> ciudadResidencia = ciudadResidencia;
        this -> direccionResidencia = direccionResidencia;
        this -> barrioResidencia = barrioResidencia;
        this -> actividadLaboral = actividadLaboral;
        this -> sucursal = sucursal;
        
    }

    // M�todos getter para acceder a los atributos
    string getNombre() {
        return nombre;
    }
    string getApellido() {
        return apellido;
    }
    string getNombreCompleto() {
        return nombre + " " + apellido;
    }
    string getTipoIdentificacion() {
        return tipoIdentificacion;
    }
    string getNumIdentificacion() {
        return numIdentificacion;
    }
    char getSexo() {
        return sexo;
    }
    string getTelefonoCelular() {
        return telefonoCelular;
    }
    string getTelefonoFijo() {
        return telefonoFijo;
    }
    string getEmail() {
        return email;
    }
    string getFechaNacimiento() {
        return fechaNacimiento;
    }
    string getPaisNacimiento() {
        return paisNacimiento;
    }
    Ciudad getCiudadNacimiento() {
        return ciudadNacimiento;
    }
    Ciudad getCiudadResidencia() {
        return ciudadResidencia;
    }
    string getDireccionResidencia() {
        return direccionResidencia;
    }
    string getBarrioResidencia() {
        return barrioResidencia;
    }
    string getActividadLaboral() {
        return actividadLaboral;
    }
    Sucursal getSucursal(){
    	return sucursal;
	}
    

    //setters
    void setNombre(string nombre) {
        Empleado::nombre = nombre;
    }

    void setApellido(string apellido) {
        Empleado::apellido = apellido;
    }

    void settipoIdentificacion(string tipoIdentificacion) {
        Empleado::tipoIdentificacion = tipoIdentificacion;
    }

    void setNumIdentificacion(string numIdentificacion) {
        Empleado::numIdentificacion = numIdentificacion;
    }

    void setSexo(char sexo) {
        Empleado::sexo = sexo;
    }

    void setTelefonoCelular(string telefonoCelular) {
        Empleado::telefonoCelular = telefonoCelular;
    }
    
    void setTelefonoFijo(string telefonoFijo) {
        Empleado::telefonoFijo = telefonoFijo;
    }
    
    void setEmail(string email) {
        Empleado::email = email;
    }

    void setFechaNacimiento(string fechaNacimiento) {
        Empleado::fechaNacimiento = fechaNacimiento;
    }
    
    void setPaisNacimiento(string paisNacimiento) {
        Empleado::paisNacimiento = paisNacimiento;
    }

    void setCiudadNacimiento(Ciudad ciudadNacimiento) {
        Empleado::ciudadNacimiento = ciudadNacimiento;
    }

    void setCiudadResidencia(Ciudad ciudadResidencia) {
        Empleado::ciudadResidencia = ciudadResidencia;
    }
    
    void setDireccionResidencia(string direccionResidencia) {
        Empleado::direccionResidencia = direccionResidencia;
    }

    void setBarrioResidencia(string barrioResidencia) {
        Empleado::barrioResidencia = barrioResidencia;
    }
    void setActividadLaboral(string actividadLaboral) {
        Empleado::actividadLaboral = actividadLaboral;
    }
    void setSucursal(Sucursal sucursal) {
        Empleado::sucursal = sucursal;
    }
};

#endif
