#ifndef ARBOLCONSULTAS_H
#define ARBOLCONSULTAS_H

#include <iostream>

#include "Lista.h"

#include "Queue.h"

#include "../ClasesPrincipales/Empleado.h"

using namespace std;

struct NodoConsulta
{
    string nombre;
    Queue<Empleado> *empleados; // Cola doble
};

struct NodoRaiz
{
    string nombre;
    Lista<NodoConsulta> listaConsulta;
};

template <class T>
class ArbolConsultas
{
    NodoRaiz *raiz;

public:
    ArbolConsultas()
    {
        raiz = new NodoRaiz;
        raiz->nombre = "nombre";
    }
    void cambiarNombre(string nombre)
    {
        raiz->nombre = nombre;
    };
    NodoRaiz *getRaiz()
    {
        return raiz;
    };
    NodoConsulta *crearNodoConsulta(string nombre);
    void agregarNodoConsulta(T objeto);
    void agregarEmpleado(Empleado *empleado, string nodoObjetivo);
    NodoConsulta getSucursal(string sucursal);
};

template <class T>
NodoConsulta *ArbolConsultas<T>::crearNodoConsulta(string nombre)
{
    NodoConsulta *nuevo = new NodoConsulta;
    nuevo->empleados = new Queue<Empleado>;
    nuevo->nombre = nombre;
    return nuevo;
}

template <class T>
void ArbolConsultas<T>::agregarNodoConsulta(T objeto)
{
    // Verifica que el objeto no exista
    for (int i = 0; i < raiz->listaConsulta.getTam(); i++)
    {
        if (raiz->listaConsulta.buscar(i).nombre == objeto.getNombre())
        {
            return;
        }
    }

    raiz->listaConsulta.insertar(*crearNodoConsulta(objeto.getNombre()));
}


template <class T>
void ArbolConsultas<T>::agregarEmpleado(Empleado *empleado, string nodoObjetivo)
{
    for (int i = 0; i < raiz->listaConsulta.getTam(); i++)
    {
        NodoConsulta aux = raiz->listaConsulta.buscar(i);
        if (aux.nombre == nodoObjetivo)
        {
            if (empleado->getTipoIdentificacion() == "Concejo")
                raiz->listaConsulta.buscar(i).empleados->Enqueue(empleado, 'I');
            else
                raiz->listaConsulta.buscar(i).empleados->Enqueue(empleado, 'F');

            return;
        }
    }
}

template <class T>
NodoConsulta ArbolConsultas<T>::getSucursal(string sucursal)
{
    for (int i = 0; i < raiz->listaConsulta.getTam(); i++)
    {
        if (raiz->listaConsulta.buscar(i).nombre == partido)
        {
            return raiz->listaConsulta.buscar(i);
        }
    }
    return raiz->listaConsulta.buscar(0);
}

#endif
