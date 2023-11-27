#include <stdlib.h>  //Libreria para limpiar pantalla
#include <iostream>
#include "LeerEntradas.h"
#include "OpcionesConsultas.cpp"
#include <cctype>
using namespace std;

#include "ClasesPrincipales/Inicializar.cpp"

class Menu {
private:
    Lista<Ciudad> *ciudades;
    Lista<Sucursal> *sucursales;
    Lista<Empleado> *empleados;
    Inicializar inicializar;
	OpcionesListas opcionLista;
public:
    int Opcion;
	string ciudadElegida;
    void MostrarMenu();
    void SubMenuListas();
    void SubMenuConsultas();
    void SubMenuNumeroDeHijos();
    void SubMenuEdad();
    void SubMenuInsercion();
    void EleccionSubMenuInsercion();
    string elegirSucursal(string ciudadElegida);
    string elegirCiudad();
    string elegirActividadLab();

    void Menus();

    void leerArchivos() {
        Archivos Ciudades("Ciudades");
        Archivos Sucursal("Sucursales");
        Archivos Empleados("Empleados");

        ciudades = Ciudades.leerCiudades();
        sucursales = Sucursal.leerSucursales();
        empleados = Empleados.leerEmpleados();
    }
};
////cambio
void Menu::Menus() {
    bool programa = true;
	leerArchivos();
    OpcionesConsultas opcionConsultas(ciudades, sucursales, empleados); // Inicializa el objeto de la clase Opciones Consultas
    

    while (programa) { // Bucle infinito del programa
        system("cls");        
        MostrarMenu();
        Opcion = leerEntrada(1,4);

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
                    }
                    case 2: {
                        opcionLista.mostrarSucursales(sucursales);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }
                    case 3: {
                        opcionLista.mostrarEmpleados(empleados);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }
                    case 4: {
                    	char sexoBuscado;
                        cout << "Ingrese el sexo por el cual desea filtrar (F/M): ";
                		cin >> sexoBuscado;
                		sexoBuscado = toupper(sexoBuscado);
                		
                		if (sexoBuscado == 'F' || sexoBuscado == 'M') {
					        opcionLista.empleadosSexo(sexoBuscado, empleados);
					    } else {
					        cout << "Entrada no válida. Debe ingresar 'F' o 'M'." <<endl;
					        system("Pause"); // Pausa el programa y espera a que se presione una tecla
					    }
                        break;
                    }
                    case 5: {
                        opcionLista.mostrarActividadesLaborales(empleados);
						system("Pause");
						break;
                    }
                    case 6: {
                    	SubMenuNumeroDeHijos();
                    	int seleccion = leerEntrada(1,4);
                        opcionLista.mostrarPorCantidadHijos(seleccion, empleados);
                        system("Pause"); // Pausa el programa y espera a que se presione una tecla
                        break;
                    }
                    case 7: {
                        cout << "Elige la sucursal que desees ver los empleados" << endl;
                    	opcionLista.mostrarSucursales(sucursales);
                        Opcion = leerEntrada(0,sucursales->getTam()-1);
                        opcionLista.empleadosPorSucursal(sucursales->buscar(Opcion).getNombre(), empleados);
                        break;
                    }
					case 8: {
                        SubMenuEdad();
                    	int seleccion = leerEntrada(1,5);
                        char sexoBuscado;
                        cout << "Ingrese el sexo por el cual desea filtrar (F/M): ";
                		cin >> sexoBuscado;
                		sexoBuscado = toupper(sexoBuscado);
                		
                		if (sexoBuscado == 'F' || sexoBuscado == 'M') {
					        opcionLista.mostrarEdadYSexo(seleccion, sexoBuscado, empleados);
					    } else {
					        cout << "Entrada no válida. Debe ingresar 'F' o 'M'." <<endl;
					        system("Pause"); // Pausa el programa y espera a que se presione una tecla
					    }

                        break;
                    }
                }
                break;
            }
            case 2: {
                system("cls");
                SubMenuConsultas();
                Opcion = leerEntrada(1,7);
                switch (Opcion) {
                    case 1: {
                        string ciudad, nombreSucursal;
                    	ciudad = elegirCiudad();
                    	nombreSucursal = elegirSucursal(ciudad);
			            opcionConsultas.consulta1(ciudad, nombreSucursal);
			            break;
                    }
                    case 2: {
                        SubMenuNumeroDeHijos();
                    	int seleccion = leerEntrada(1,4);
                    	opcionConsultas.consulta2(seleccion);
                        break;
                    }
                    case 3: {
                        string ciudad;
                        ciudad = elegirCiudad();
                        opcionConsultas.consulta3(ciudad);
                        break;
                    }
                    case 4: {
                        int numPersonas;
                        cout<<"Ingresa el número mínimo de personas que solicitas: ";
                        cin>>numPersonas;
                        if(numPersonas > 0){
                        	opcionConsultas.consulta4(numPersonas);
						}else{
							cout<<"Número inválido";
						}
                        break;
                    }
                    case 5: {
                        opcionConsultas.consulta5(*ciudades);
                        break;
                    }
                    case 6: {
                    	int edadMin, edadMax;
                        cout<<"Ingresa la edad mínima que solicitas: ";
                        cin>>edadMin;
                        cout<<"\nIngresa la edad máxima que solicitas: ";
                        cin>>edadMax;
                        string actividadLaboral = elegirActividadLab();
                        if(edadMin > 0 && edadMax > 0){
                        	opcionConsultas.consulta6(edadMin, edadMax, actividadLaboral);
						}else{
							cout<<"Número inválido";
						}
                        opcionConsultas.consulta6(25, 45, "Abogada");
                        break;
                    }
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
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: {
                                //Creaciï¿½n del Objeto Sucursal
                                Sucursal nuevaSucursal = inicializar.inicializarSucursal(sucursales, ciudades);
                                //Inserciï¿½n en la lista de sucursales
                                sucursales -> insertar(nuevaSucursal);

                                Opcion = 0;
                                break;
                            }
                            case 2: { // Insertar Empleado (Se necesita validaciï¿½n de puesto, fecha nacimiento, estado civil)

                                //Creacion del objeto Empleado para aï¿½adirlo en la lista
                                Empleado nuevoEmpleado = inicializar.inicializarEmpleado(sucursales, ciudades, empleados);
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
                            }
                        }
                        break;
                    }
                    case 2: { //Opciones para Modificar
                    //Uso de auxiliares para guardar datos y no perder la información
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: {
                                //Encontrar el sucursal a modificar
                                string NombreSucursal;
                                cout << "¿Que sucursal deseas modificar?" << endl;
                                opcionLista.mostrarSucursales(sucursales);
                                Opcion = leerEntrada(0,sucursales->getTam()-1);

                                string auxNombreSucursal = sucursales->buscar(Opcion).getNombre();

                                //Inicializar Sucursal
                                Sucursal nuevaSucursal = inicializar.inicializarSucursal(sucursales, ciudades);

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
                                opcionLista.mostrarEmpleados(empleados);
                                Opcion = leerEntrada(0,empleados->getTam()-1);

                                // Creaciï¿½n del objeto Empleado para aï¿½adirlo en la lista
                                Empleado nuevoEmpleado = inicializar.inicializarEmpleado(sucursales, ciudades, empleados);

                                // Inserciï¿½n en la lista de empleados
                                empleados -> modificar(nuevoEmpleado, Opcion);
                                break;
                            }
                            case 3: { //Modificar Ciudad

                                //Encontrar la ciudad a modificar (Se necesita validaciï¿½n cuando la ciudad ya existe)
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
                    case 3: { //Opciones para Eliminar //Validaciï¿½n, Si se eliminan sucursal, los empleados con sucursal quedan sin Sucursal
                        EleccionSubMenuInsercion();
                        Opcion = leerEntrada(1,3);
                        switch (Opcion) {
                            case 1: { //Eliminar Sucursal
                                int Eleccion;
                                cout << "ï¿Que sucursal deseas Eliminar?" << endl;
                                opcionLista.mostrarSucursales(sucursales);
                                Eleccion = leerEntrada(0,sucursales->getTam()-1);
                                //Guardar una sucursal auxiliar para eliminar los empleados con esa sucursal
								Sucursal sucursalAux = sucursales->buscar(Eleccion);
								
								//Se eliminan a todos los empleados que se pertenecian a esa sucursal
                                sucursales -> borrar(Eleccion);
                                
                                for(int i = 0; i < empleados->getTam(); i++){
                                	Empleado EmpleadoAux = empleados->buscar(i);
                                    string aux1 = EmpleadoAux.getSucursal().getNombre();
                                    string aux2 = sucursalAux.getNombre();

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
                                opcionLista.mostrarEmpleados(empleados);
                                Opcion = leerEntrada(0,empleados->getTam()-1);

                                empleados -> borrar(Opcion);

                                break;
                            }
                            case 3: { // Eliminar Ciudades

                                cout << "¿Que ciudad deseas Eliminar?" << endl;
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
                opcionConsultas.actualizar(ciudades, sucursales, empleados);
                break;
            }
            case 4: {
                system("cls");
                //FINALIZAR Y GUARDAR EN LOS ARCHIVOS PLANOS

                //Escribir en el archivo plano los sucursales de la lista
                Archivos Sucursales("sucursales");
                string textosucursales;

                for (int i = 0; i < sucursales -> getTam(); i++) {
                    Sucursal sucursal = sucursales -> buscar(i); // Declaraciï¿½n de la sucursal de la lista para aï¿½adir su informaciï¿½n al texto plano
                    textosucursales += sucursal.getNombre() + "," + sucursal.getCiudadSucursal().getNombre() + "," + sucursal.getBarrioSucursal()+ 
										"," + sucursal.getDireccionSucursal() + "," + sucursal.getGerenteSucursal() + "\n";
        		};
                

                Sucursales.escribir(textosucursales);

                //Escribir en el archivo plano las ciudades de la lista

                Archivos Ciudades("Ciudades");
                string textoCiudades;

                for (int i = 0; i < ciudades -> getTam(); i++) {
                    Ciudad ciudad = ciudades -> buscar(i);
                    textoCiudades += ciudad.getNombre() + "," + ciudad.getPais() + "\n";
                }

                Ciudades.escribir(textoCiudades);

                //Escribir en el archivo plano los empleados de la lista

                Archivos Empleados("empleados");
				string textoempleados;
				for (int i = 0; i < empleados->getTam(); i++) {
				    Empleado empleado = empleados->buscar(i);
				    vector<Hijo> hijos = empleado.getHijos(); // Obtener los hijos de cada empleado
				    string textoHijos = " ";
				    for (size_t j = 0; j < hijos.size(); j++) {
				        textoHijos += hijos[j].getNombre() + "; " + hijos[j].getFechaNacimiento();
						if (j != hijos.size() - 1) {
						    textoHijos += "; ";
						}
				    }
				    textoempleados += empleado.getNombre() + "," + empleado.getApellido() + "," + empleado.getTipoIdentificacion() + "," + empleado.getNumIdentificacion() + "," +
				                      empleado.getSexo() + "," + empleado.getTelefonoCelular() + "," + empleado.getTelefonoFijo() + "," + empleado.getEmail() + "," + empleado.getFechaNacimiento() + "," +
				                      empleado.getPaisNacimiento() + "," + empleado.getCiudadNacimiento().getNombre() + "," + empleado.getCiudadResidencia().getNombre() + "," +
				                      empleado.getDireccionResidencia() + "," + empleado.getBarrioResidencia() + "," + empleado.getActividadLaboral() + "," + empleado.getTieneHijos() + "," +
				                      to_string(empleado.getNumHijos()) + "," + textoHijos + "," + empleado.getSucursal().getNombre() + "\n";
				}
				Empleados.escribir(textoempleados);
				
				programa = false;
				break;
            }
        }
    }
}

void Menu::MostrarMenu() {
    cout << "MENÚ PRINCIPAL" << endl;
    cout << "----------------------------------" << endl;
    cout << "1. Buscar listas por categoria" << endl;
    cout << "2. Realizar consultas" << endl;
    cout << "3. Insertar, Modificar y Eliminar" << endl;
    cout << "4. Salir" << endl;
}

void Menu::SubMenuListas() {
    cout << "1. Buscar Listas por categoria\n" << endl;
    cout << "SUBMENÚ LISTAS" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Ciudades." << endl;
    cout << "2. Sucursales" << endl;
    cout << "3. Todos los empleados de la empresa." << endl;
    cout << "4. Sexo." << endl;
    cout << "5. Actividad Laboral." << endl;
    cout << "6. Numero de Hijos." << endl;
    cout << "7. Empleados por sucursal." << endl;
    cout << "8. Edad y sexo de los empleados." << endl;
}

void Menu::SubMenuConsultas() {
    cout << "2. Realizar una consulta \n" << endl;
    cout << "SUBMENÚ CONSULTAS" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Número total de personas que trabajan en una sucursal dada." << endl;
    cout << "2. Listado de los nombres y apellidos de aquellos que tienen  un número de hijos dado." << endl;
    cout << "3. Nombre y apellidos de las personas que viven en una ciudad dada." << endl;
    cout << "4. Número de sucursales en las que trabaja un número de personas superior a un número dado." << endl;
    cout << "5. Obtener el número de hombres y el número de mujeres que trabajan en las diferentes sucursales." << endl;
    cout << "6. Dado un rango de edad y una actividad laborar mostrar la lista de trabajadores de esa edad." << endl;
}

void Menu::SubMenuNumeroDeHijos() {
	cout << "SUBMENÚ NÚMERO DE HIJOS" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Sin Hijos" << endl;
    cout << "2. 1-2 hijos" << endl;
    cout << "3. 3-4 hijos" << endl;
    cout << "4. 4 o mas hijos" << endl;
}

void Menu::SubMenuEdad() {
	cout << "SUBMENÚ RANGOS DE EDAD" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. 18 - 24 años" << endl;
    cout << "2. 25 - 35 años" << endl;
    cout << "3. 36 - 45 años" << endl;
    cout << "4. 45 - 60 años" << endl;
    cout << "5. Mas de 60 años" << endl;
}

void Menu::SubMenuInsercion() {
	cout << "INSERCIÓN, MODIFICACIÓN, ELIMINACIÓN" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Insertar" << endl;
    cout << "2. Modificar" << endl;
    cout << "3. Eliminar" << endl;
}

void Menu::EleccionSubMenuInsercion() {
	cout << "EN CUAL DESEA HACER LA MODIFICACIÓN?" << endl;
    cout << "--------------------------------------" << endl;
    cout << "1. Sucursal" << endl;
    cout << "2. Empleado" << endl;
    cout << "3. Ciudad" << endl;
}

string Menu::elegirCiudad()
{
    int pos = 0;
    cout << "CIUDAD" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Escriba el n?mero de la ciudad que desea elegir: " << endl;
    opcionLista.mostrarCiudades(ciudades);
    pos = leerEntrada(0,ciudades->getTam()-1);
    return ciudades->buscar(pos).getNombre();
}

string Menu::elegirActividadLab()
{
    int pos = 0;
    cout << "ACTIVIDAD LABORAL" << endl;
    cout << "--------------------------------------" << endl;
    cout << "Escriba el n?mero de la actividad laboral que desea elegir: " << endl;
    opcionLista.mostrarActividadesLaborales(empleados);
    pos = leerEntrada(0,empleados->getTam()-1);
    return empleados->buscar(pos).getNombre();
}

string Menu::elegirSucursal(string ciudadElegida)
{
	int opc;
    string sol;
	cout << "SUCURSAL" << endl;
    cout << "--------------------------------------" << endl;
    // Mostrar las sucursales disponibles en la ciudad
    for (int i = 0; i < sucursales->getTam(); i++) {
        Sucursal sucursal = sucursales->buscar(i);
        if (sucursal.getCiudadSucursal().getNombre() == ciudadElegida) {
            cout << i << ". " << sucursal.getNombre() << endl;
        }
    }

    // Solicitar al usuario que elija una sucursal
    cout << "Seleccione una sucursal: ";
    cin >> opc;

    // Verificar que la opci?n sea v?lida
    if (opc >= 0 && opc < sucursales->getTam()) {
        // Obtener el nombre de la sucursal seleccionada y asignarlo a la variable sol
        sol = sucursales->buscar(opc).getNombre();
    } else {
        // Opci?n inv?lida, manejar seg?n sea necesario
        cout << "Opci?n inv?lida." << endl;
    }

    return sol;
}

