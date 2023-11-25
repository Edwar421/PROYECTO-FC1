#ifndef LISTA_H
#define LISTA_H

#include <iostream>

using namespace std;

// Definici�n de la clase Nodo
template < typename T >
class Nodo {
public: T valor;
    Nodo < T > * siguiente;

    // Constructor de la clase Nodo
    Nodo(T valor) {
        this -> valor = valor;
        this -> siguiente = NULL;
    }
};

// Definici�n de la clase Lista
template < typename T >
class Lista {
private: Nodo < T > * inicio;
    Nodo < T > * fin;
    int tam;

public:
    // Constructor de la clase Lista
    Lista() {
        inicio = NULL;
        fin = NULL;
        tam = 0;
    }

    // Destructor de la clase Lista
    ~Lista() {
        Nodo < T > * actual = inicio;
        Nodo < T > * tmp;
        // Se recorre la lista liberando la memoria de cada nodo
        while (actual != NULL) {
            tmp = actual -> siguiente;
            delete actual;
            actual = tmp;
        }
    }

    void insertar(T valor) {
        Nodo < T > * nuevo = new Nodo < T > (valor);

        // Si la lista est� vac�a, el nuevo nodo ser� tanto el primero como el �ltimo
        if (inicio == NULL) {
            inicio = nuevo;
            fin = nuevo;
        }
            // Si no, se agrega el nuevo nodo despu�s del �ltimo
        else {
            fin -> siguiente = nuevo;
            fin = nuevo;
        }

        // Se aumenta el tama�o de la lista
        tam++;
    }

    void modificar(T valor, int pos) {
        if (pos >= tam || pos < 0) { // Verificar si la posici�n es v�lida
            cout << "Posicion invalida" << endl;
            return;
        }

        Nodo < T > * actual = inicio;
        for (int i = 0; i < pos; i++) { // Recorrer la lista hasta llegar a la posici�n indicada
            actual = actual -> siguiente;
        }
        actual -> valor = valor; // Modificar el valor del nodo en la posici�n indicada
    }

    void borrar(int pos) {
        if (pos >= tam || pos < 0) {
            cout << "Posicion invalida" << endl;
            return;
        }

        Nodo < T > * actual = inicio;
        Nodo < T > * tmp;
        if (pos == 0) {
            inicio = actual -> siguiente;
            if (inicio == NULL) {
                fin = NULL;
            }
            delete actual;
        } else {
            for (int i = 0; i < pos - 1; i++) {
                actual = actual -> siguiente;
            }
            tmp = actual -> siguiente;
            actual -> siguiente = tmp -> siguiente;
            if (actual -> siguiente == NULL) {
                fin = actual;
            }
            delete tmp;
        }

        tam--;
    }

    int getTam() {
        return tam;
    }

    bool lista_vacia() {
        return (tam == 0);
    }

    T buscar(int pos) {
        if (pos < 0 || pos >= tam) {
            cout << "Posición inválida al buscar" << endl;
            // Aqu� puedes retornar un valor predeterminado o lanzar una excepci�n, seg�n tus necesidades
        }

        Nodo < T > * actual = this -> inicio;
        if (pos == 0)
            return actual -> valor;

        for (int i = 0; i < pos; i++) {
            actual = actual -> siguiente;
        }

        return actual -> valor;
    }

    T * buscarApuntador(int pos) {
        if (pos < 0 || pos >= tam) {
            cout << "Posición inválida al buscar" << endl;
            // Aqu� puedes retornar un valor predeterminado o lanzar una excepci�n, seg�n tus necesidades
        }

        Nodo < T > * actual = this -> inicio;
        if (pos == 0)
            return &actual -> valor;

        for (int i = 0; i < pos; i++) {
            actual = actual -> siguiente;
        }

        return &actual -> valor;
    }

    bool existe(T valor) {
        Nodo < T > * actual = inicio;
        while (actual != NULL) {
            if (actual -> valor == valor) {
                return true;
            }
            actual = actual -> siguiente;
        }
        return false;
    }
};

#endif
