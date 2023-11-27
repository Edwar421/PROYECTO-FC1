#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <map>

#include "Estructuras de Datos/ArbolConsultas.h"

#include "ClasesPrincipales/Empleado.h"

#include "Estructuras de Datos/ArbolRojiNegro.h"

using namespace std;

class OpcionesConsultas
{
private:
    ArbolRojiNegro<string, ArbolConsultas<Sucursal>> *arbolCiudades = new ArbolRojiNegro<string, ArbolConsultas<Sucursal>>; // Cada ciudad tiene un arbol
    ArbolRojiNegro<string, ArbolConsultas<Ciudad>> *arbolSucursales = new ArbolRojiNegro<string, ArbolConsultas<Ciudad>>;   // Cada surcusal tiene una estructura nodoCiudad

public:
    OpcionesConsultas(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados);

    // Funcion que calcula la edad
    int calcularEdad(Empleado *auxEmpleado);
    int calcularEdadHijo(string fechaNacimientoHijo);
    string obtenerRangoEdades(int edad);
    void actualizar(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados);
    void agregarDatosArbolCiudades(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados);
    void agregarDatosArbolSucursales(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados);

    void consulta1(string ciudad, string nombreSucursal);
    void consulta2(int seleccion);
    void consulta3(string ciudad);
    void consulta4(int numPersonas);
    void consulta5(Lista<Ciudad> ciudades);
    void consulta6(int edadMinima, int edadMaxima, string actividadLaboral);
};

// Constrctor
OpcionesConsultas::OpcionesConsultas(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados)
{
    actualizar(ciudades, sucursales, empleados);
}

void OpcionesConsultas::actualizar(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados)
{
    agregarDatosArbolCiudades(ciudades, sucursales, empleados);
    agregarDatosArbolSucursales(ciudades, sucursales, empleados);
}

/* organiza información sobre ciudades, sucursales y empleados utilizando un árbol rojo-negro 
para las ciudades y árboles de consulta para manejar sucursales y empleados asociados a cada ciudad.*/
void OpcionesConsultas::agregarDatosArbolCiudades(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados)
{
    // Se agregan las ciudades al árbol rojo-negro (arbolCiudades)
    for (int i = 0; i < ciudades->getTam(); i++)
    {
        arbolCiudades->insertarNodo(ciudades->buscar(i).getNombre());
    }

    // Se realiza un recorrido inorden y se almacenan los nodos en una cola y luego en una lista
    Cola<NodoArbol<string, ArbolConsultas<Sucursal>> *> CInOrden = arbolCiudades->obtenerInOrden(arbolCiudades->obtenerRaiz());
    Lista<NodoArbol<string, ArbolConsultas<Sucursal>> *> ciudadesArbolRN;
    NodoArbol<string, ArbolConsultas<Sucursal>> *nodoAux; // Nodo auxiliar para insertar arbol

    while (!CInOrden.isVacia())
    {
        nodoAux = CInOrden.dequeue();
        ciudadesArbolRN.insertar(nodoAux);
    }

    // Se crea un árbol de consultas para cada ciudad
    for (int i = 0; i < ciudadesArbolRN.getTam(); i++)
    {
        nodoAux = ciudadesArbolRN.buscar(i);
        nodoAux->data = new ArbolConsultas<Sucursal>;
        nodoAux->data->cambiarNombre(nodoAux->clave);

        // Se agregan nodos de consulta al árbol utilizando sucursales como datos
        for (int i = 0; i < sucursales->getTam(); i++)
        {
            nodoAux->data->agregarNodoConsulta(sucursales->buscar(i));
        }
    }

    // Se agregan los empleados a la ciudad y sucursal correspondiente
    for (int i = 0; i < empleados->getTam(); i++)
    {
        Empleado *auxEmpleado = empleados->buscarApuntador(i);
        nodoAux = arbolCiudades->buscar(auxEmpleado->getCiudadResidencia().getNombre());

        // Se verifica que la ciudad encontrada sea la correcta antes de agregar el empleado
        if (nodoAux->clave == auxEmpleado->getCiudadResidencia().getNombre())
            nodoAux->data->agregarEmpleado(auxEmpleado, auxEmpleado->getSucursal().getNombre());
    }
}


void OpcionesConsultas::agregarDatosArbolSucursales(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados)
{
	/*organiza información sobre sucursales, ciudades y empleados utilizando un árbol rojo-negro para las sucursales y 
	árboles de consultas para manejar ciudades y empleados asociados a cada sucursal.*/
    // Paso 1: Se agregan las sucursales al árbol rojo-negro (arbolSucursales)
    for (int i = 0; i < sucursales->getTam(); i++)
    {
        arbolSucursales->insertarNodo(sucursales->buscar(i).getNombre());
    }

    // Se realiza un recorrido inorden y se almacenan los nodos en una cola y luego en una lista
    Cola<NodoArbol<string, ArbolConsultas<Ciudad>> *> CInOrden = arbolSucursales->obtenerInOrden(arbolSucursales->obtenerRaiz());
    Lista<NodoArbol<string, ArbolConsultas<Ciudad>> *> sucursalesArbolRN;
    NodoArbol<string, ArbolConsultas<Ciudad>> *nodoAux; // Nodo auxiliar para insertar arbol

    while (!CInOrden.isVacia())
    {
        nodoAux = CInOrden.dequeue();
        sucursalesArbolRN.insertar(nodoAux);
    }

    // Se crea un árbol de consultas para cada sucursal
    for (int i = 0; i < sucursalesArbolRN.getTam(); i++)
    {
        nodoAux = sucursalesArbolRN.buscar(i);
        nodoAux->data = new ArbolConsultas<Ciudad>;
        nodoAux->data->cambiarNombre(nodoAux->clave);

        // Se agregan nodos de consulta al árbol utilizando ciudades como datos
        for (int i = 0; i < ciudades->getTam(); i++)
        {
            nodoAux->data->agregarNodoConsulta(ciudades->buscar(i));
        }
    }

    // Se agregan los empleados a la sucursal y ciudad correspondiente
    for (int i = 0; i < empleados->getTam(); i++)
    {
        Empleado *auxEmpleado = empleados->buscarApuntador(i);
        nodoAux = arbolSucursales->buscar(auxEmpleado->getSucursal().getNombre());

        // Se verifica que la sucursal encontrada sea la correcta antes de agregar el empleado
        if (nodoAux->clave == auxEmpleado->getSucursal().getNombre())
            nodoAux->data->agregarEmpleado(auxEmpleado, auxEmpleado->getCiudadResidencia().getNombre());
    }
}


string OpcionesConsultas::obtenerRangoEdades(int edad) {
    if (edad >= 0 && edad <= 5) {
        return "0-5";
    } else if (edad >= 6 && edad <= 12) {
        return "6-12";
    } else if (edad >= 13 && edad <= 18) {
        return "13-18";
    } else if (edad >= 19 && edad <= 30) {
        return "19-30";
    } else if (edad >= 31 && edad <= 50) {
        return "31-50";
    } else {
        return "M?s de 50";
    }
}

int OpcionesConsultas::calcularEdad(Empleado *auxEmpleado)
{
    if(auxEmpleado->getFechaNacimiento().length() != 10)
        return 0;

    // Se calcular la edad partiendo en sub string con las posiciones necesarias para obtener dia, mes, anio
    int diaNacimiento = stoi(auxEmpleado->getFechaNacimiento().substr(0, 2));
    int mesNacimiento = stoi(auxEmpleado->getFechaNacimiento().substr(3, 2));
    int anioNacimiento = stoi(auxEmpleado->getFechaNacimiento().substr(6, 4));
    // Obtener la fecha actual
    time_t tiempoActual = time(nullptr);
    tm *fechaActual = localtime(&tiempoActual);

    int diaActual = fechaActual->tm_mday;
    int mesActual = fechaActual->tm_mon + 1;      // tm_mon está basado en 0
    int anioActual = fechaActual->tm_year + 1900; // tm_year cuenta los años desde 1900

    // Calcular la edad
    int edad = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
    {
        // No se ha cumplido el cumpleaños este año
        edad--;
    }

    return edad;
}

int OpcionesConsultas::calcularEdadHijo(string fechaNacimientoHijo)
{
    if (fechaNacimientoHijo.length() != 10)
        return 0;
    // Se calcula la edad partiendo en subcadena con las posiciones necesarias para obtener d?a, mes, a?o
    stringstream ss(fechaNacimientoHijo);
    string diaStr, mesStr, anioStr;
    getline(ss, diaStr, '/');
    getline(ss, mesStr, '/');
    getline(ss, anioStr, '/');
    int diaNacimiento = stoi(diaStr);
    int mesNacimiento = stoi(mesStr);
    int anioNacimiento = stoi(anioStr);
    // Obtener la fecha actual
    time_t tiempoActual = time(nullptr);
    tm *fechaActual = localtime(&tiempoActual);
    int diaActual = fechaActual->tm_mday;
    int mesActual = fechaActual->tm_mon + 1;      // tm_mon est? basado en 0
    int anioActual = fechaActual->tm_year + 1900; // tm_year cuenta los a?os desde 1900
    // Calcular la edad
    int edad = anioActual - anioNacimiento;
    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
    {
        // No se ha cumplido el cumplea?os este a?o
        edad--;
    }
    return edad;
}
	
	//CONSULTAS
	void OpcionesConsultas::consulta1(string ciudad, string nombreSucursal)
{
    // Mostrar información inicial de la consulta
    cout << endl << "Consulta 1 - Personas por rangos de edades en la sucursal " << nombreSucursal << " en la ciudad " << ciudad << endl;

    // Buscar la ciudad en el árbol de ciudades
    NodoArbol<string, ArbolConsultas<Sucursal>> *nodoCiudad = arbolCiudades->buscar(ciudad);
    if (nodoCiudad != nullptr)
    {
        // Buscar la sucursal en el árbol de consultas de la ciudad
        NodoConsulta nodoSucursal = nodoCiudad->data->buscar(nombreSucursal);
        if (nodoSucursal.nombre == nombreSucursal)
        {
            // Obtener la lista de empleados de la sucursal
            Queue<Empleado> *empleados = nodoSucursal.empleados;

            // Verificar si hay empleados en la sucursal
            if (empleados->getTam() > 0)
            {
                // Inicializar un mapa para contabilizar personas por rangos de edades
                map<string, int> personasPorRango;

                // Recorrer la lista de empleados
                for (int i = 0; i < empleados->getTam(); i++)
                
                /*En resumen, esta línea de código extrae un empleado de la posición i de la cola de empleados y almacena un 
				puntero a ese empleado en la variable empleado. Este puntero permitirá acceder a los atributos y métodos del objeto 
				Empleado correspondiente en el cuerpo del bucle o en cualquier parte del código posterior.*/
                {
                    Empleado *empleado = empleados->retornarElemento(i, 'I');
                    // Clasificar por rangos de edades de los hijos
                    bool sinHijos = true; // bandera para verificar si el empleado no tiene hijos

                    // Recorrer los hijos del empleado
                    for (const Hijo &hijo : empleado->getHijos())
                    {
                        // Calcular la edad del hijo y obtener el rango de edades
                        int edadHijo = calcularEdadHijo(hijo.getFechaNacimiento());
                        string rangoEdades = obtenerRangoEdades(edadHijo);

                        // Incrementar el contador en el mapa
                        personasPorRango[rangoEdades]++;
                        sinHijos = false; // el empleado tiene al menos un hijo
                    }

                    // Si el empleado no tiene hijos, incrementar el contador correspondiente
                    if (sinHijos)
                    {
                        personasPorRango["Sin hijos"]++;
                    }
                }

                // Mostrar los resultados
                for (const auto &pair : personasPorRango)
                {
                    cout << "Personas con hijos " << pair.first << ": " << pair.second << endl;
                }
            }
            else
            {
                // Mostrar un mensaje si no hay empleados en la sucursal
                cout << "No se encontraron personas en la sucursal " << nombreSucursal << endl;
            }
        }
        else
        {
            // Mostrar un mensaje si no se encuentra la sucursal en la ciudad
            cout << "No se encontró la sucursal " << nombreSucursal << " en la ciudad " << ciudad << endl;
        }
    }
    else
    {
        // Mostrar un mensaje si no se encuentra la ciudad
        cout << "No se encontró la ciudad " << ciudad << endl;
    }

    // Pausar el sistema y retornar
    system("pause");
    return;
}

void OpcionesConsultas::consulta2(int seleccionRangoHijos) {
    Cola<NodoArbol<string, ArbolConsultas<Sucursal>> *> CInOrden = arbolCiudades->obtenerInOrden(arbolCiudades->obtenerRaiz());

    while (!CInOrden.isVacia()) {
        NodoArbol<string, ArbolConsultas<Sucursal>> *nodoCiudad = CInOrden.dequeue();
        string nombreCiudad = nodoCiudad->clave;

        Lista<NodoConsulta> sucursalesCiudad = nodoCiudad->data->getRaiz()->listaConsulta;

        // Iterar sobre las sucursales en la ciudad
        for (int j = 0; j < sucursalesCiudad.getTam(); j++) {
            string nombreSucursal = sucursalesCiudad.buscar(j).nombre;
            Queue<Empleado> *empleadosSucursal = sucursalesCiudad.buscar(j).empleados;

            // Iterar sobre los empleados en la sucursal
            for (int k = 0; k < empleadosSucursal->getTam(); k++) {
                Empleado *auxEmpleado = empleadosSucursal->retornarElemento(k, 'I');
                int numHijos = auxEmpleado->getNumHijos();

                // Verificar si el número de hijos está en el rango
                if ((seleccionRangoHijos == 1 && numHijos == 0) ||
                    (seleccionRangoHijos == 2 && numHijos >= 1 && numHijos <= 2) ||
                    (seleccionRangoHijos == 3 && numHijos >= 3 && numHijos <= 4) ||
                    (seleccionRangoHijos == 4 && numHijos > 4)) {
                    // Obtener información adicional del empleado
                    string barrio = auxEmpleado->getBarrioResidencia();
                    string pais = auxEmpleado->getCiudadResidencia().getNombre();

                    // Mostrar la información
                    cout << "País: " << pais << ", Ciudad: " << nombreCiudad << ", Sucursal: " << nombreSucursal << endl;
                    cout << "  Nombre: " << auxEmpleado->getNombre() << ", Apellido: " << auxEmpleado->getApellido() << ", Número de Hijos: " << numHijos << endl;
                }
            }
        }
    }
    // Pausar para que el usuario pueda ver los resultados
    system("pause");
}

// Consulta 3. Nombre y apellidos de las personas que viven en una ciudad dada,  clasificándolos por ciudad de nacimiento y actividad laboral. 
void OpcionesConsultas::consulta3(string ciudad)
{
    cout << endl << ciudad << endl;

    NodoArbol<string, ArbolConsultas<Sucursal>> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoConsulta> auxCiudades = nodoAux->data->getRaiz()->listaConsulta;

    if (auxCiudades.getTam() > 0)
    {
        for (int i = 0; i < auxCiudades.getTam(); i++) // Iterate through each city
        {
        	
            Queue<Empleado> *auxEmpleados = auxCiudades.buscar(i).empleados;

            if (auxEmpleados->getTam() > 0)
            {
                for (int j = 0; j < auxEmpleados->getTam(); j++) // Iterate through each person
                {
                    Empleado *p = auxEmpleados->retornarElemento(j, 'I');
                    cout << " Nombre:" << p->getNombreCompleto();
					cout << ", ciudad de nacimiento: " << p->getCiudadNacimiento().getNombre();
					cout << ", actividad laboral: " << p->getActividadLaboral() << endl;
                }
            }
            else
            {
            }
        }
    }
    else
    {
        cout << "    No se encontraron ciudades para la ciudad: " << ciudad << endl;
    }

    system("pause");
    return;
}


void OpcionesConsultas::consulta4(int numeroPersonas)
{
    // Iterar sobre las ciudades
    Cola<NodoArbol<string, ArbolConsultas<Sucursal>> *> CInOrden = arbolCiudades->obtenerInOrden(arbolCiudades->obtenerRaiz());

    while (!CInOrden.isVacia())
    {
        NodoArbol<string, ArbolConsultas<Sucursal>> *nodoCiudad = CInOrden.dequeue();
        string nombreCiudad = nodoCiudad->clave;

        Lista<NodoConsulta> sucursalesCiudad = nodoCiudad->data->getRaiz()->listaConsulta;
        

        // Iterar sobre las sucursales en la ciudad
        for (int j = 0; j < sucursalesCiudad.getTam(); j++)
        {
            string nombreSucursal = sucursalesCiudad.buscar(j).nombre;
            Queue<Empleado> *empleadosSucursal = sucursalesCiudad.buscar(j).empleados;

            // Verificar si el número de personas en la sucursal es mayor al número dado
            if (empleadosSucursal->getTam() > numeroPersonas)
            {
                // Obtener información adicional de la sucursal
                //string nombreGerente = sucursalesCiudad.buscar(j). gerenteSucursal.getNombre();
                //string barrio = sucursalesCiudad.buscar(j).barrioSucursal;

                // Mostrar la información
                cout << "  Sucursal: " << nombreSucursal << endl;
                //cout << "    Gerente: " << nombreGerente << endl;
                //cout << "    Barrio: " << barrio << endl;
                cout << "    Número de personas: " << empleadosSucursal->getTam() << endl;

            }
        }
    }

    // Pausar para que el usuario pueda ver los resultados
    system("pause");
}


void OpcionesConsultas::consulta5(Lista<Ciudad> ciudades) {
    for (int i = 0; i < ciudades.getTam(); i++) {
        Ciudad ciudad = ciudades.buscar(i);

        // Obtener la lista de nodos de la ciudad actual
        NodoArbol<std::string, ArbolConsultas<Sucursal>> *nodoCiudad = arbolCiudades->buscar(ciudad.getNombre());
        Lista<NodoConsulta> nodosSucursales = nodoCiudad->data->getRaiz()->listaConsulta;
        
        std::cout << "País: " << ciudad.getPais() << ", Ciudad: " << ciudad.getNombre() << std::endl;

        for (int j = 0; j < nodosSucursales.getTam(); j++) {
            NodoConsulta nodoSucursal = nodosSucursales.buscar(j);

            // Obtener la lista de empleados de la sucursal actual
            Lista<Empleado> *empleados = nodoSucursal.empleados;

            // Contadores para hombres y mujeres
            int hombres = 0;
            int mujeres = 0;

            // Iterar sobre los empleados de la sucursal
            for (int k = 0; k < empleados->getTam(); k++) {
                Empleado *empleado = empleados->retornarElemento(k, 'I');

                // Contar hombres y mujeres
                if ('M' == empleado->getSexo()) {
                    hombres++;
                } else if (empleado->getSexo() == 'F') {
                    mujeres++;
                }
            }
            
            // Mostrar información por sucursal
            std::cout << "  Sucursal: " << nodoSucursal.nombre << std::endl;
            //std::cout << "    Gerente: " << nodoSucursal.gerenteSucursal.getNombre() << std::endl;
            std::cout << "    Número de hombres: " << hombres << std::endl;
            std::cout << "    Número de mujeres: " << mujeres << std::endl;
        }
    }

    system("pause");
    return;
}

void OpcionesConsultas::consulta6(int edadMinima, int edadMaxima, string actividadLaboral)
{
    // Iterar sobre las ciudades
    Cola<NodoArbol<string, ArbolConsultas<Sucursal>> *> CInOrden = arbolCiudades->obtenerInOrden(arbolCiudades->obtenerRaiz());
    
    while (!CInOrden.isVacia())
    {
        NodoArbol<string, ArbolConsultas<Sucursal>> *nodoCiudad = CInOrden.dequeue();
        string nombreCiudad = nodoCiudad->clave;

        Lista<NodoConsulta> sucursalesCiudad = nodoCiudad->data->getRaiz()->listaConsulta;

        // Iterar sobre las sucursales en la ciudad
        for (int j = 0; j < sucursalesCiudad.getTam(); j++)
        {
            string nombreSucursal = sucursalesCiudad.buscar(j).nombre;
            Queue<Empleado> *empleadosSucursal = sucursalesCiudad.buscar(j).empleados;

            // Iterar sobre los empleados en la sucursal
            for (int k = 0; k < empleadosSucursal->getTam(); k++)
            {
                Empleado *auxEmpleado = empleadosSucursal->retornarElemento(k, 'I');
                int edad = calcularEdad(auxEmpleado);

                // Verificar si la edad está en el rango y la actividad laboral es la buscada
                if (edad >= edadMinima && edad <= edadMaxima && actividadLaboral == auxEmpleado->getActividadLaboral())
                {
                	// Obtener información adicional del empleado
                    string barrio = auxEmpleado->getBarrioResidencia();

                	// Mostrar la información
                	cout << "  Barrio: " << barrio << ", Sucursal: " << nombreSucursal << endl;
                	cout << "    Nombre: " << auxEmpleado->getNombre() << ", Edad: " << edad << ", Actividad Laboral: " << auxEmpleado->getActividadLaboral() << endl;
                }
            }
        }
    }
    // Pausar para que el usuario pueda ver los resultados
    system("pause");
}
