#include <iostream>
#include <string>
#include <ctime>
#include <sstream>
#include <map>

#include "Estructuras de Datos (Consultas)/ArbolConsultas.h"

#include "ClasesPrincipales/Empleado.h"

#include "Estructuras de Datos (Consultas)/ArbolRojiNegro.h"

using namespace std;

class OpcionesConsultas
{
private:
    // Lista<NodoCiudad> *listaArboles = new Lista<NodoCiudad>;            // Cada ciudad tiene un arbol
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
    void consulta2(string partido);
    void consulta3(string ciudad);
    void consulta4(string ciudad);
    void consulta5(Lista<Ciudad> ciudades);
    //void consulta6(string ciudad);
    void consulta6(int edadMinima, int edadMaxima, string actividadLaboral);
    void consulta7(Lista<Ciudad> ciudades);
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

void OpcionesConsultas::agregarDatosArbolCiudades(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados)
{
    // Se agregan las ciudades al arbolRN
    for (int i = 0; i < ciudades->getTam(); i++)
    {
        arbolCiudades->insertarNodo(ciudades->buscar(i).getNombre());
    }

    // Se agregan lo nodos del arbol a una lista para manejarlos facilmente
    Cola<NodoArbol<string, ArbolConsultas<Sucursal>> *> CInOrden = arbolCiudades->obtenerInOrden(arbolCiudades->obtenerRaiz());
    Lista<NodoArbol<string, ArbolConsultas<Sucursal>> *> ciudadesArbolRN;
    NodoArbol<string, ArbolConsultas<Sucursal>> *nodoAux; // Nodo auxiliar para insertar arbol
    while (!CInOrden.isVacia())
    {
        nodoAux = CInOrden.dequeue();
        ciudadesArbolRN.insertar(nodoAux);
    }

    // Se crea un arbol Consulta para cada ciudad
    for (int i = 0; i < ciudadesArbolRN.getTam(); i++) // Se crean arboles
    {
        nodoAux = ciudadesArbolRN.buscar(i);
        nodoAux->data = new ArbolConsultas<Sucursal>;
        nodoAux->data->cambiarNombre(nodoAux->clave);
        for (int i = 0; i < sucursales->getTam(); i++) // agrega partido
        {
            nodoAux->data->agregarNodoConsulta(sucursales->buscar(i));
        }
    }

    // Se agregan los empleados a la ciudad y sucursal correspondiente
    for (int i = 0; i < empleados->getTam(); i++)
    {
        Empleado *auxEmpleado = empleados->buscarApuntador(i);
        nodoAux = arbolCiudades->buscar(auxEmpleado->getCiudadResidencia().getNombre()); // busca la ciudad la cual debe agregar el cadidato
        if(nodoAux->clave == auxEmpleado->getCiudadResidencia().getNombre()) // valida que la ciudad corresponda
            nodoAux->data->agregarEmpleado(auxEmpleado, auxEmpleado->getSucursal().getNombre());
    }
}

void OpcionesConsultas::agregarDatosArbolSucursales(Lista<Ciudad> *ciudades, Lista<Sucursal> *sucursales, Lista<Empleado> *empleados)
{
    // Se agregan los partidos al arbolRN
    for (int i = 0; i < sucursales->getTam(); i++)
    {
        arbolSucursales->insertarNodo(sucursales->buscar(i).getNombre());
    }

    // Se agregan lo nodos del arbol a una lista para manejarlos facilmente
    Cola<NodoArbol<string, ArbolConsultas<Ciudad>> *> CInOrden = arbolSucursales->obtenerInOrden(arbolSucursales->obtenerRaiz());
    Lista<NodoArbol<string, ArbolConsultas<Ciudad>> *> sucursalesArbolRN;
    NodoArbol<string, ArbolConsultas<Ciudad>> *nodoAux; // Nodo auxiliar para insertar arbol
    while (!CInOrden.isVacia())
    {
        nodoAux = CInOrden.dequeue();
        sucursalesArbolRN.insertar(nodoAux);
    }

    // Se crea un arbol Consulta para cada sucursal
    for (int i = 0; i < sucursalesArbolRN.getTam(); i++) // Se crean arboles
    {
        nodoAux = sucursalesArbolRN.buscar(i);
        nodoAux->data = new ArbolConsultas<Ciudad>;
        nodoAux->data->cambiarNombre(nodoAux->clave);
        for (int i = 0; i < ciudades->getTam(); i++) // agrega ciudad
        {
            nodoAux->data->agregarNodoConsulta(ciudades->buscar(i));
        }
    }

    // Se agregan los empelados a la sucursal y ciudad correspondiente
    for (int i = 0; i < empleados->getTam(); i++)
    {
        Empleado *auxEmpleado = empleados->buscarApuntador(i);
        nodoAux = arbolSucursales->buscar(auxEmpleado->getSucursal().getNombre()); // busca la ciudad la cual debe agregar el cadidato
        if(nodoAux->clave == auxEmpleado->getSucursal().getNombre()) // valida que el partido corresponda
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
	
	// Cosulta 1. Dado un partido y una ciudad, mostrar la lista de sus candidatos al Concejo y el candidato a la alcaldía (nombre, edad, sexo).
	void OpcionesConsultas::consulta1(string ciudad, string nombreSucursal)
	{
	    cout << endl << "Consulta 1 - Personas por rangos de edades en la sucursal " << nombreSucursal << " en la ciudad " << ciudad << endl;
	    NodoArbol<string, ArbolConsultas<Sucursal>> *nodoCiudad = arbolCiudades->buscar(ciudad);
	    if (nodoCiudad != nullptr)
	    {
	        NodoConsulta nodoSucursal = nodoCiudad->data->buscar(nombreSucursal);
	        if (nodoSucursal.nombre == nombreSucursal)
	        {
	            Queue<Empleado> *empleados = nodoSucursal.empleados;
	            if (empleados->getTam() > 0)
	            {
	                // Mapa para contabilizar personas por rangos de edades
	                map<string, int> personasPorRango;
	                for (int i = 0; i < empleados->getTam(); i++)
	                {
	                    Empleado *empleado = empleados->retornarElemento(i, 'I');
	                    // Clasificar por rangos de edades de los hijos
	                    bool sinHijos = true; // Nuevo: bandera para verificar si el empleado no tiene hijos
	                    for (const Hijo &hijo : empleado->getHijos())
	                    {
	                    	int prueba = calcularEdadHijo("15/01/2003");
	                    	cout << prueba <<endl;
	                    	string fecha = hijo.getFechaNacimiento();
	                    	cout << fecha << endl;
	                        int edadHijo = calcularEdadHijo(hijo.getFechaNacimiento());
	                        cout << edadHijo << endl;
	                        string rangoEdades = obtenerRangoEdades(edadHijo);
	                        cout << rangoEdades <<endl;
	                        // Incrementar el contador en el mapa
	                        personasPorRango[rangoEdades]++;
	                        sinHijos = false; // Nuevo: el empleado tiene al menos un hijo
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
	                cout << "No se encontraron personas en la sucursal " << nombreSucursal << endl;
	            }
	        }
	        else
	        {
	            cout << "No se encontr? la sucursal " << nombreSucursal << " en la ciudad " << ciudad << endl;
	        }
	    }
	    else
	    {
	        cout << "No se encontr? la ciudad " << ciudad << endl;
	    }
	    system("pause");
	    return;
	}

// Consulta 2. Dado un partido mostrar la lista de candidatos a alcaldÃ­as de cada una de las diferentes ciudades (ciudad, nombre del candidato, sexo, edad).
/*
void OpcionesConsultas::consulta2(string partido)
{
    cout << endl
         << partido << endl;

    NodoArbol<string, ArbolConsultas<Ciudad>> *nodoAux = arbolPartidos->buscar(partido);

    Lista<NodoConsulta> auxCiudades = nodoAux->data->getRaiz()->listaConsulta;
    if (auxCiudades.getTam() > 0)
    {
        for (int i = 0; i < auxCiudades.getTam(); i++) // Mirar cada ciudad
        {
            Queue<Candidato> *auxCandidatos = auxCiudades.buscar(i).candidatos;
            if (auxCandidatos->getTam() > 0)
            {
                cout << "   " << auxCiudades.buscar(i).nombre << endl;
                if (auxCandidatos->retornarElemento(0, 'I')->getPuesto() == "Alcaldia")
                {
                    Candidato *c = auxCandidatos->retornarElemento(0, 'I');
                    int edad = calcularEdad(c);
                    cout << "       " << c->getNombre() << ", sexo: " << c->getSexo() << ", edad: " << edad << " - " << c->getNumIdentificacion() << endl;
                }
            }
            else
            {
                cout << "       No se encontraron candidatos para la ciudad: " << auxCiudades.buscar(i).nombre << endl;
            }
        }
    }
    else
    {
        cout << "    No se encontraron ciudades para el partido: " << partido << endl;
    }

    system("pause");
    return;
}
*/
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
            //cout << "   " << auxCiudades.buscar(i).nombre << endl;

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
                //cout << "       No se encontraron personas para la ciudad: " << auxCiudades.buscar(i).nombre << endl;
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

void OpcionesConsultas::consulta5(Lista<Ciudad> ciudades)
{
    for (int i = 0; i < ciudades.getTam(); i++)
    {
        Ciudad ciudad = ciudades.buscar(i);
        cout << "Ciudad: " << ciudad.getNombre() << endl;

        // Obtener la lista de nodos de la ciudad actual
        NodoArbol<string, ArbolConsultas<Sucursal>> *nodoCiudad = arbolCiudades->buscar(ciudad.getNombre());
        Lista<NodoConsulta> nodosSucursales = nodoCiudad->data->getRaiz()->listaConsulta;

        for (int j = 0; j < nodosSucursales.getTam(); j++)
        {
            NodoConsulta nodoSucursal = nodosSucursales.buscar(j);

            // Obtener la lista de empleados de la sucursal actual
            Queue<Empleado> *empleados = nodoSucursal.empleados;

            // Contadores para hombres y mujeres
            int hombres = 0;
            int mujeres = 0;

            for (int k = 0; k < empleados->getTam(); k++)
            {
                Empleado *empleado = empleados->retornarElemento(k, 'I');

                // Contar hombres y mujeres
                if ('M' == empleado->getSexo())
                {
                    hombres++;
                }
                else if (empleado->getSexo() == 'F')
                {
                    mujeres++;
                }
            }

            // Mostrar información por sucursal
            cout << "  Sucursal: " << nodoSucursal.nombre << endl;
            //cout << "    Gerente: " << nodoSucursal.gerenteSucursal.getNombre() << endl;
            cout << "    Número de hombres: " << hombres << endl;
            cout << "    Número de mujeres: " << mujeres << endl;
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

/*
// Consulta 4. Dada una ciudad, mostrar por cada partido, el candidato a la alcaldÃ­a y los candidatos al concejo.
void OpcionesConsultas::consulta4(string ciudad)
{

    NodoArbol<string, ArbolConsultas<Partido>> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoConsulta> auxPartidos = nodoAux->data->getRaiz()->listaConsulta;
    for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
    {
        if (auxPartidos.getTam() > 0)
        {
            cout << endl
                 << auxPartidos.buscar(i).nombre << endl;
            Queue<Candidato> *auxCandidatos = auxPartidos.buscar(i).candidatos;
            if (auxCandidatos->getTam() > 0)
            {

                int cAldalde = 0;
                if (auxCandidatos->retornarElemento(0, 'I')->getPuesto() == "Alcaldia")
                {
                    cAldalde++;
                    cout << "   Candidato alcaldia:" << endl;
                    cout << "       - " << auxCandidatos->retornarElemento(0, 'I')->getNombre() << endl;
                }
                if (auxPartidos.getTam() > 0)
                {
                    cout << "   Candidatos concejo:" << endl;

                    for (int j = 0 + cAldalde; j < auxCandidatos->getTam(); j++)
                    {
                        cout << "       - " << auxCandidatos->retornarElemento(j, 'I')->getNombre() << endl;
                    }
                }
            }
            else
            {
                cout << "   No se encontraron candidatos para el partido" << endl;
            }
        }
        else
        {
            cout << "No se encontraron candidatos para la ciudad: " << ciudad << endl;
        }
    }

    system("pause");
    return;
}

// Consulta 5. Dada una ciudad, mostrar el tarjetÃ³n de candidatos a la alcaldÃ­a. Incluye voto en blanco. (0.voto en blanco, 1. Candidato uno, 2. Candidato dos,â€¦..)
void OpcionesConsultas::consulta5(string ciudad)
{
    cout << endl
         << ciudad << endl;
    cout << "   0. voto en blanco" << endl;

    NodoArbol<string, ArbolConsultas<Partido>> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoConsulta> auxPartidos = nodoAux->data->getRaiz()->listaConsulta;
    if (auxPartidos.getTam() > 0)
    {

        for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
        {
            Queue<Candidato> *auxCandidatos = auxPartidos.buscar(i).candidatos;
            if (auxCandidatos->getTam() > 0)
            {

                if (auxCandidatos->retornarElemento(0, 'I')->getPuesto() == "Alcaldia")
                {
                    Candidato *c = auxCandidatos->retornarElemento(0, 'I');
                    cout << "   " << i + 1 << ". " << c->getNombre() << " - partido: " << c->getPartido().getNombre() << endl;
                }
            }
            else
            {
                cout << "   No se encontraron candidatos para el partido: " << auxPartidos.buscar(i).nombre << endl;
            }
        }
    }
    else
    {
        cout << "   No se encontraron partidos para la ciudad: " << ciudad << endl;
    }

    system("pause");
    return;
}

// Consulta 6. Dada una ciudad, mostrar el tarjetÃ³n de candidatos al concejo, incluye voto en blanco. Suponga que todas las listas aplican voto preferente. (0.voto en blanco, 1. Partido 1, 1.1. Candidato 1 del partido 1, etc. 2. Partido 2, 2.1 candidato 1 del partido 2, 2.2. candidato 2 del partido 2 , 3. Partido 3 â€¦).
void OpcionesConsultas::consulta6(string ciudad)
{
    cout << endl
         << ciudad << endl;
    cout << "   0. voto en blanco" << endl;

    NodoArbol<string, ArbolConsultas<Partido>> *nodoAux = arbolCiudades->buscar(ciudad);

    Lista<NodoConsulta> auxPartidos = nodoAux->data->getRaiz()->listaConsulta;
    if (auxPartidos.getTam() > 0)
    {

        for (int i = 0; i < auxPartidos.getTam(); i++) // Mirar cada partido
        {
            Queue<Candidato> *auxCandidatos = auxPartidos.buscar(i).candidatos;
            if (auxCandidatos->getTam() > 0)
            {
                int inicio = (auxCandidatos->retornarElemento(0, 'I')->getPuesto() == "Alcaldia")?1:0;
                cout << "   " << i + 1 << ". " << auxPartidos.buscar(i).nombre << endl;

                for (int j = inicio; j < auxCandidatos->getTam(); j++)
                {
                    cout << "       " << i + 1 << "." << j << " " << auxCandidatos->retornarElemento(j, 'I')->getNombre() << endl;
                }
            }
            else
            {
                cout << "   No se encontraron candidatos para el partido: " << auxPartidos.buscar(i).nombre << endl;
            }
        }
    }
    else
    {
        cout << "No se encontraron partidos para la ciudad: " << ciudad << endl;
    }

    system("pause");
    return;
}

// Consulta 7. Censo electoral. Por cada ciudad, mostrar la cantidad de personas habilitadas para votar.
void OpcionesConsultas::consulta7(Lista<Ciudad> ciudades)
{
    if (ciudades.getTam() > 0)
    {

        for (int i = 0; i < ciudades.getTam(); i++)
        {
            Ciudad ciudad = ciudades.buscar(i);
            cout << ciudad.getNombre() << ": " << ciudad.getCensoElectoral() << endl;
        }
    }
    else
    {
        cout << "No se ciudaddes." << endl;
    }
    system("pause");
    return;
}*/
