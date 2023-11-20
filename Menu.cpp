#include <stdlib.h>  //Libreria para limpiar pantalla
#include <iostream>
#include "LeerEntradas.h"
using namespace std;

#include "ClasesPrincipales/Inicializar.cpp"

class Menu {
private:
    Lista<Ciudad> *ciudades;
    Lista<Sucursal> *sucursales;
    /*Lista<Empleado> *empleados;
    Inicializar inicializar;*/
	OpcionesListas opcionLista;
public:
    int Opcion;

    void MostrarMenu();
    void SubMenuListas();
    void SubMenuConsultas();
    void SubMenuEstadisticas();
    void SubMenuInsercion();
    string elegirSucursal();
    string elegirCiudad();

    void Menus();

    void leerArchivos() {
        Archivos Ciudades("Ciudades");
        Archivos Sucursal("Sucursales");
        Archivos Empleados("Empleados");

        ciudades = Ciudades.leerCiudades();
        //sucursales = Sucursal.leerSucursales();
        //empleados = Empleados.leerEmpleados();*/
    }
};

void Menu::Menus() {
    bool programa = true;

    leerArchivos();

    //OpcionesConsultas opcionConsultas(ciudades /*sucursales, empleados*/); // Inicializa el objeto de la clase Opciones Consultas
    

    while (programa) { // Bucle infinito del programa
        system("cls");
        MostrarMenu();
        Opcion = leerEntrada(1,6);

        switch (Opcion) {
            case 1: {
                system("cls"); // Limpia pantalla
                SubMenuListas(); // Muestra menï¿½
                Opcion = leerEntrada(1,8);
                switch (Opcion) {
                    case 1: {
                        opcionLista.mostrarCiudades(ciudades);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }/*
                    case 2: {
                        opcionLista.mostrarSucursales(sucursales);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }/*
                    case 3: {
                        string ciudad;
                        cout << "Elige la ciudad que desees ver los empleados" << endl;
                    	opcionLista.mostrarCiudades(ciudades);
                    	Opcion = leerEntrada(0,ciudades->getTam()-1);
                        opcionLista.empleados(ciudades->buscar(Opcion).getNombre(), empleados);

                        break;
                    }*/
                }
                break;
            }
            case 2: {
                system("cls");
                SubMenuConsultas();
                Opcion = leerEntrada(1,7);
                switch (Opcion) {
                    case 1: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        //opcionConsultas.consulta1(ciudad);
                        break;
                    }
                    /*case 2: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta2(ciudad);
                        break;
                    }
                    case 3: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta3(ciudad);
                        break;
                    }
                    case 4: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta4(ciudad);
                        break;
                    }
                    case 5: {
                        opcionConsultas.consulta5();
                        break;
                    }
                    case 6: {
                        opcionConsultas.consulta6();
                        break;
                    }*/
                }
                break;
            }
            case 3: {
                system("cls");
                SubMenuInsercion();
                Opcion = leerEntrada(1,3);

                string caso;

                switch (Opcion) {
                    case 1: { //Opciones para insertar
                        /*EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: {
                                //Creaciï¿½n del Objeto partido
                                Sucursal nuevaSucursal = inicializar.inicializarSucursal(sucursales);
                                //Inserciï¿½n en la lista de sucursales
                                sucursales -> insertar(nuevaSucursal);

                                Opcion = 0;
                                break;
                            }
                            case 2: { // Insertar Empleado (Se necesita validaciï¿½n de puesto, fecha nacimiento, estado civil)

                                //Creacion del objeto Empleado para aï¿½adirlo en la lista
                                Empleado nuevoEmpleado = inicializar.inicializarEmpleado(sucursales, ciudades, empleados);
                                //Inserciï¿½n en la lista de empleados
                                if(!(nuevoEmpleado.getNombre() == ""))
                                    empleados -> insertar(nuevoEmpleado);
                                break;
                            }
                            case 3: {
                                //Se ingresan los datos de la nueva ciudad (Se necesita validaciï¿½n cuando la ciudad ya existe)
                                //Creaciï¿½n del Objeto Ciudad
                                Ciudad NuevaCiudad = inicializar.inicializarCiudad();
                                //Insercion en la lista de ciudades
                                ciudades -> insertar(NuevaCiudad);
                                break;
                            }*/
                        }
                        break;
                    }
                    /*case 2: { //Opciones para Modificar
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: {
                                //Encontrar el partido a modificar
                                string NombreSucursal;
                                cout << "¿Que sucursal deseas modificar?" << endl;
                                opcionLista.mostrarsucursales(sucursales);
                                Opcion = leerEntrada(0,sucursales->getTam()-1);

                                string auxNombreSucursal = sucursales->buscar(Opcion).getNombre();

                                //Inicializar Partido
                                Sucursal nuevaSucursal = inicializar.inicializarSucursal(sucursales);

                                sucursales -> modificar(nuevaSucursal, Opcion);

                                for(int i = 0; i < empleados->getTam(); i++)
                                {
                                    Empleado auxEmpleado = empleados->buscar(i);
                                    if(auxEmpleado.getSucursal().getNombre() == auxNombreSucursal)
                                    {
                                        auxEmpleado.setSucursal(nuevaSucursal);
                                        empleados->modificar(auxEmpleado,i);
                                    }

                                }

                                break;
                            }
                            case 2: { //Modificar Empleado

                                // Encontrar el Empleado a modificar
                                int Opcion;

                                cout << "Selecciona el Empleado que deseas modificar" << endl;
                                opcionLista.mostrarempleados(empleados);
                                Opcion = leerEntrada(0,empleados->getTam()-1);

                                // Creaciï¿½n del objeto Empleado para aï¿½adirlo en la lista
                                Empleado nuevoEmpleado = inicializar.inicializarEmpleado(sucursales, ciudades, empleados);

                                // Inserciï¿½n en la lista de empleados
                                empleados -> modificar(nuevoEmpleado, Opcion);
                                break;
                            }
                            case 3: { //Modificar Ciudad

                                //Enconntrar la ciudad a modificar (Se necesita validaciï¿½n cuando la ciudad ya existe)
                                string nombre;
                                int ciudad;
                                cout << "Selecciona la ciudad que desea modificar" << endl;
                                opcionLista.mostrarCiudades(ciudades);
                                ciudad = leerEntrada(0,ciudades->getTam()-1);

                                string auxNombreCiudad = ciudades->buscar(ciudad).getNombre();

                                //Creaciï¿½n del Objeto Ciudad
                                Ciudad NuevaCiudad = inicializar.inicializarCiudad();
                                //Insercion en la lista de ciudades
                                ciudades -> modificar(NuevaCiudad, ciudad);

                                for(int i = 0; i < empleados->getTam(); i++)
                                {
                                    Empleado auxEmpleado = empleados->buscar(i);
                                    if(auxEmpleado.getCiudadNacimiento().getNombre() == auxNombreCiudad)
                                    {
                                        auxEmpleado.setCiudadNacimiento(NuevaCiudad);
                                        empleados->modificar(auxEmpleado,i);
                                    }
                                    if(auxEmpleado.getCiudadResidencia().getNombre() == auxNombreCiudad)
                                    {
                                        auxEmpleado.setCiudadResidencia(NuevaCiudad);
                                        empleados->modificar(auxEmpleado,i);
                                    }

                                }
                                break;
                            }
                        }
                        break;
                    }
                    case 3: { //Opciones para Eliminar //Validaciï¿½n, Si se eliminan partido, los empleados con ese partido quedan sin partido
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: { //Eliminar Partido
                                int Eleccion;
                                cout << "ï¿Que sucursal deseas Eliminar?" << endl;
                                opcionLista.mostrarsucursales(sucursales);
                                Eleccion = leerEntrada(0,sucursales->getTam()-1);
                                //Guardar un partido auxiliar para eliminar los empleados con ese partido
								Partido sucursalAux = sucursales->buscar(Eleccion);
								
                                sucursales -> borrar(Eleccion);
                                
                                for(int i = 0; i < empleados->getTam(); i++){
                                	Empleado EmpleadoAux = empleados->buscar(i);
                                    string aux1 = EmpleadoAux.getSucursal().getNombre();
                                    string aux2 = partidoAux.getNombre();

                                	if(EmpleadoAux.getSucursal().getNombre() == sucursalAux.getNombre()){
                                		empleados->borrar(i);
									}
                                    EmpleadoAux = empleados->buscar(i);
                                    while(EmpleadoAux.getSucursal().getNombre() == sucursalAux.getNombre())
                                    {
                                        empleados->borrar(i);
                                        EmpleadoAux = empleados->buscar(i);
                                    }
								}

								system("Pause");
								
                                break;
                            }
                            case 2: { //Eliminar Empleado

                                cout << "¿Que Empleado deseas Eliminar?" << endl;
                                opcionLista.mostrarempleados(empleados);
                                Opcion = leerEntrada(0,empleados->getTam()-1);

                                empleados -> borrar(Opcion);

                                break;
                            }
                            case 3: { // Eliminar Ciudades

                                cout << "¿Que ciudades deseas Eliminar?" << endl;
                                opcionLista.mostrarCiudades(ciudades);
                                Opcion = leerEntrada(0, ciudades->getTam()-1);
								
								Ciudad ciudadAux = ciudades->buscar(Opcion);
								
                                ciudades -> borrar(Opcion);
                                
                                //Borrar los empleados que residan en esa ciudad
                                
                                for(int i = 0; i < empleados->getTam(); i++){
                                	Empleado EmpleadoAux = empleados->buscar(i);
                                	if(EmpleadoAux.getCiudadResidencia().getNombre() == ciudadAux.getNombre()){
                                		empleados->borrar(i);
									}
                                    EmpleadoAux = empleados->buscar(i);
                                    while(EmpleadoAux.getCiudadResidencia().getNombre() == ciudadAux.getNombre())
                                    {
                                        empleados->borrar(i);
                                        EmpleadoAux = empleados->buscar(i);
                                    }

								}
								
                                break;
                            }
                        }
                        break;
                    }
                }
                Opcion = 0;
                opcionConsultas.actualizar(ciudades, sucursales, empleados);*/
                break;
            }
            case 4: {
                /*system("cls");
                //FINALIZAR Y GUARDAR EN LOS ARCHIVOS PLANOS

                //Escribir en el archivo plano los sucursales de la lista
                Archivos sucursales("sucursales");
                string textosucursales;

                for (int i = 0; i < sucursales -> getTam(); i++) {
                    Sucursal sucursal = sucursales -> buscar(i); // Declaraciï¿½n del partido de la lista para aï¿½adir su informaciï¿½n al texto plano
                    textosucursales += sucursal.getNombre() + "\n";
                }

                sucursales.escribir(textosucursales);*/

                //Escribir en el archivo plano las ciudades de la lista

                Archivos Ciudades("Ciudades");
                string textoCiudades;

                for (int i = 0; i < ciudades -> getTam(); i++) {
                    Ciudad ciudad = ciudades -> buscar(i);
                    textoCiudades += ciudad.getNombreCiudad() + "\n";
                }

                Ciudades.escribir(textoCiudades);

                //Escribir en el archivo plano los empleados de la lista
/*
                Archivos empleados("empleados");
                string textoempleados;

                for (int i = 0; i < empleados -> getTam(); i++) {
                    Empleado Empleado = empleados -> buscar(i);
                    textoempleados += Empleado.getNombre() + "," + Empleado.getApellido() + "," + Empleado.getPuesto() + "," + Empleado.getNumIdentificacion() + "," + Empleado.getSexo() + "," + Empleado.getEstadoCivil() + "," + Empleado.getFechaNacimiento() + "," + Empleado.getCiudadNacimiento().getNombre() + "," + Empleado.getCiudadResidencia().getNombre() + "," + Empleado.getPartido().getNombre()+",0\n";
                }
                
                empleados.escribir(textoempleados);

                programa = false;
                break;
            }*/
        }
    }
}
}
void Menu::MostrarMenu() {
    cout << "Empresa X" << endl;
    cout << "Menu Principal" << endl;
    cout << "--------------------------------------------------" << endl;
    cout << "1. Buscar listas por categoria" << endl;
    cout << "2. Realizar consultas" << endl;
    cout << "3. Insertar, Modificar y Eliminar" << endl;
    cout << "4. Salir" << endl;
}

void Menu::SubMenuListas() {
    cout << "Buscar Listas por categoria" << endl;
    cout << "1. Ciudades." << endl;
    cout << "2. Sucursales" << endl;
    cout << "3. Todos los empleados de una ciudad." << endl;
    cout << "4. Todos los empleados de una sucursal." << endl;
}

void Menu::SubMenuConsultas() {
    cout << "Realizar una consulta" << endl;
    cout << "1. Número total de personas que trabajan en una sucursal dada." << endl;
    cout << "2. Listado de los nombres y apellidos de aquellos que tienen  un número de hijos dado." << endl;
    cout << "3. Nombre y apellidos de las personas que viven en una ciudad dada." << endl;
    cout << "4. Número de sucursales en las que trabaja un número de personas superior a un número dado." << endl;
    cout << "5. Obtener el número de hombres y el número de mujeres que trabajan en las diferentes sucursales." << endl;
    cout << "6. Dado un rango de edad y una actividad laborar mostrar la lista de trabajadores de esa edad." << endl;
}

void Menu::SubMenuInsercion() {
    cout << "1. Insertar" << endl;
    cout << "2. Modificar" << endl;
    cout << "3. Eliminar" << endl;
}
/*
void Menu::EleccionSubMenuInsercion() {
    cout << "1. Sucursal" << endl;
    cout << "2. Empleado" << endl;
    cout << "3. Ciudad" << endl;
}

string Menu::elegirPartido()
{
    int pos = 0;
    cout << "Escriba el número de sucursal que desea elegir: " << endl;
    opcionLista.mostrarsucursales(sucursales);
    pos = leerEntrada(0,sucursales->getTam()-1);
    return sucursales->buscar(pos).getNombre();
}
*/
string Menu::elegirCiudad()
{
    int pos = 0;
    cout << "Escriba el número de la ciudad que desea elegir: " << endl;
    opcionLista.mostrarCiudades(ciudades);
    pos = leerEntrada(0,ciudades->getTam()-1);
    return ciudades->buscar(pos).getNombreCiudad();
}


