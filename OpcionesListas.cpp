#include <string>
//#include <ctime>

class OpcionesListas {
private:

public:
    //1. Ciudades en las que hay registradas sucursales.
    void mostrarCiudades(Lista < Ciudad > * ciudades) {
        for (int i = 0; i < ciudades -> getTam(); i++) {
            //Guardar la ciudad buscada en una variable y devolver atributo nombre
            Ciudad ciudad = ciudades -> buscar(i);
            cout << i << ". Ciudad: " << ciudad.getNombreCiudad() << ", Pais: " << ciudad.getPais() << endl;
        }
    }
	
    //2. Sucursales.
    void mostrarSucursales(Lista < Sucursal > * sucursales) {
        for (int i = 0; i < sucursales -> getTam(); i++) {
            //Guardar la sucursal buscada y devolver el atributo nombre
            Sucursal sucursal = sucursales -> buscar(i);
            cout << i << "." << "Nombre:"  << sucursal.getNombreSucursal() << " Ciudad: " << sucursal.getCiudadSucursal().getNombreCiudad() << " Barrio: " << sucursal.getBarrioSucursal() << " Dirección: " << sucursal.getDireccionSucursal() << " Gerente: " << sucursal.getGerenteSucursal() << endl;
        }
    }
    
	//3. Empleados.
    void mostrarEmpleados(Lista < Empleado > * empleados) {
        for (int i = 0; i < empleados -> getTam(); i++) {
            //Guardar el empleado y devolver sus atributos
            Empleado empleado = empleados -> buscar(i);
            cout << i << ". " << empleado.getNombre() << " " << empleado.getApellido()<< endl; // " " << empleado.getNumIdentificacion() << " " << empleado.getSexo() << " " << empleado.getTelefonoCelular() << empleado.getTelefonoFijo() << empleado.getEmail() << empleado.getFechaNacimiento() << empleado.getCiudadNacimiento() << empleado.getPaisNacimiento() << empleado.getCiudadResidencia() << empleado.getDireccionResidencia() << empleado.getBarrioResidencia() << empleado.getSucursal() << "/n" << endl;
        }
        system("Pause");
    }
    
    //4. Sexo.
    void empleadosSexo(char sexo, Lista < Empleado > * empleados) {
        
        Lista<Empleado> empleadosGenero; // Lista para almacenar empleados del género deseado
	    int cantidad = 0;
	
	    if (sexo == 'M') {
	        cout << "Empleados Hombres" << endl;
	    } else {
	        cout << "Empleadas Mujeres" << endl;
	    }
	
	    for (int i = 0; i < empleados->getTam(); i++) {
	        Empleado empleado = empleados->buscar(i);
	        if (empleado.getSexo() == sexo) {
	            cout << empleado.getNombre() << " " << empleado.getNumIdentificacion() << endl;
	            cantidad++;
	            empleadosGenero.insertar(empleado); // Almacena el empleado del género deseado en la lista
	        }
	    }
	
	    // Utiliza una pila para mostrar los empleados en orden inverso
	    while (!empleadosGenero.lista_vacia()) {
	        Empleado empleado = empleadosGenero.buscar(empleadosGenero.getTam() - 1);
	        cout << "Invertido: " << empleado.getNombre() << " " << empleado.getNumIdentificacion() << endl;
	        empleadosGenero.borrar(empleadosGenero.getTam() - 1);
	    }
	
	    cout << "Cantidad de empleados: " << cantidad << endl;
	
	    system("Pause");
    }
    
    //5. Actividad Laboral
    void mostrarActividadesLaborales(Lista<Empleado> *empleados) {
	    Lista<string> actividadesUnicas; // Lista para almacenar actividades laborales únicas

	    // Recorre la lista de empleados y agrega las actividades laborales a la lista
	    for (int i = 0; i < empleados->getTam(); i++) {
	        Empleado empleado = empleados->buscar(i);
	        string actividad = empleado.getActividadLaboral();
	
	        // Si la actividad laboral no existe en la lista, agrégala
	        if (!actividadesUnicas.existe(actividad)) {
	            actividadesUnicas.insertar(actividad);
	        }
	    }
	
	    // Muestra las actividades laborales únicas
	    int index = 1;
	    cout<< "Actividades Laborales"<<endl;
	    for (int i = 0; i < actividadesUnicas.getTam(); i++) {
	        cout << index << ". " << *actividadesUnicas.buscarApuntador(i) << endl;
	        index++;
	    }
	    
	    int opcion;
	    cout << "Seleccione una actividad por su número: ";
	    cin >> opcion;
	
	    // Verifica si la opción es válida
	    if (opcion >= 1 && opcion <= actividadesUnicas.getTam()) {
	        string actividadSeleccionada = *actividadesUnicas.buscarApuntador(opcion - 1);
	
	        // Muestra los empleados que tienen esa actividad laboral
	        cout << "Empleados con la actividad laboral '" << actividadSeleccionada << "':" << endl;
	        for (int j = 0; j < empleados->getTam(); j++) {
	            Empleado empleado = empleados->buscar(j);
	            if (empleado.getActividadLaboral() == actividadSeleccionada) {
	                cout << "   - " << empleado.getNombre() << endl;
	            }
	        }
	    } else {
	        cout << "Opción no válida." << endl;
	    }
	
	}
	
	
	//6.Cantidad de Hijos
	void mostrarPorCantidadHijos(int seleccion, Lista<Empleado> *empleados) {
	    int cantidad = 0;
		
		if(seleccion==1){
		    cout << "Empleados sin hijos:" << endl;
		    for (int i = 0; i < empleados->getTam(); i++) {
		        Empleado empleado = empleados->buscar(i);
		        if (empleado.getNumHijos() == 0) {
		            cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion() << endl;
		            cantidad++;
		        }
		    }
		} else if (seleccion==2)	{
		    cout << "\nEmpleados con 1-2 hijos:" << endl;
		    for (int i = 0; i < empleados->getTam(); i++) {
		        Empleado empleado = empleados->buscar(i);
		        int numHijos = empleado.getNumHijos();
		        if (numHijos >= 1 && numHijos <= 2) {
		            cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion() << endl;
		            cantidad++;
		        }
		    }
	    } else if (seleccion==3){
		    cout << "\nEmpleados con 3-4 hijos:" << endl;
		    for (int i = 0; i < empleados->getTam(); i++) {
		        Empleado empleado = empleados->buscar(i);
		        int numHijos = empleado.getNumHijos();
		        if (numHijos >= 3 && numHijos <= 4) {
		            cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion() << endl;
		            cantidad++;
		        }
		    }
		} else {
		    cout << "\nEmpleados con más de 4 hijos:" << endl;
		    for (int i = 0; i < empleados->getTam(); i++) {
		        Empleado empleado = empleados->buscar(i);
		        int numHijos = empleado.getNumHijos();
		        if (numHijos > 4) {
		            cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion() << endl;
		            cantidad++;
		        }
		    }
		}
	
	    system("Pause"); // Pausa el programa y espera a que se presione una tecla
	}
	
	//7. Lista de empleados por sucursal
	void empleadosPorSucursal(string sucursal, Lista<Empleado> *empleados) {
        int cantidad = 0;
        cout << "Empleados en la sucursal: " << sucursal << endl;
        for (int i = 0; i < empleados -> getTam(); i++) {
            //Guardar el empleado buscado y devolver los atributos necesarios dada la validacion
            Empleado empleado = empleados->buscar(i);
            
            if (empleado.getSucursal().getNombreSucursal() == sucursal) {
                cout << empleados -> buscar(i).getNombreCompleto() << endl;
                cantidad++;
            }
        }

        if (cantidad == 0) {
            cout << "Esta sucursal no tiene empleados para esta categoria, verifique el ingreso" << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }
    /*
    //8. Lista por edad (18 a 24, 25 a 35, 36 a 45, 45 a 60, más de 60) y por sexo.
	//Primero debemos crear una funcion que nos permita calcular la edad de los empleados
	int calcularEdad(Empleado *auxPersona){
	    if(auxPersona->getFechaNacimiento().length() != 10)
	        return 0;
	
	    // Se calcular la edad partiendo en sub string con las posiciones necesarias para obtener dia, mes, anio
	    int diaNacimiento = stoi(auxPersona->getFechaNacimiento().substr(0, 2));
	    int mesNacimiento = stoi(auxPersona->getFechaNacimiento().substr(3, 2));
	    int anioNacimiento = stoi(auxPersona->getFechaNacimiento().substr(6, 4));
	    // Obtener la fecha actual
	    time_t tiempoActual = time(nullptr);
	    tm *fechaActual = localtime(&tiempoActual);
	
	    int diaActual = fechaActual->tm_mday;
	    int mesActual = fechaActual->tm_mon + 1;      // tm_mon estÃ¡ basado en 0
	    int anioActual = fechaActual->tm_year + 1900; // tm_year cuenta los aÃ±os desde 1900
	
	    // Calcular la edad
	    int edad = anioActual - anioNacimiento;
	    if (mesActual < mesNacimiento || (mesActual == mesNacimiento && diaActual < diaNacimiento))
	    {
	        // No se ha cumplido el cumpleaÃ±os este aÃ±o
	        edad--;
	    }
	
	    return edad;
	}
	
	void clasificarPorEdadEmpleados(Lista<Empleado> *empleados) {
	    vector<Empleado> edad18a24, edad25a35, edad36a45, edad46a60, masDe60;
	
	    // Iterar sobre la lista de personas
	    for (int i = 0; i < empleados->getTam(); i++) {
	        Empleado empleado = empleados->buscar(i);
	        int edad = calcularEdad(&empleado);
	
	        // Clasificar por rango de edad
	        if (edad >= 18 && edad <= 24) {
	            edad18a24.push_back(empleado);
	        } else if (edad >= 25 && edad <= 35) {
	            edad25a35.push_back(empleado);
	        } else if (edad >= 36 && edad <= 45) {
	            edad36a45.push_back(empleado);
	        } else if (edad >= 46 && edad <= 60) {
	            edad46a60.push_back(empleado);
	        } else {
	            masDe60.push_back(empleado);
	        }
	    }
	}
	
void mostrarEdadYSexo(int seleccion, char sexo, Lista<Empleado> *empleados) {
	    int cantidad = 0;
		
		if (seleccion == 1) {
	        cout << "Empleados de 18 a 24 años y sexo " << sexo << ":" << endl;
	        for (int i = 0; i < empleados->getTam(); i++) {
	            Empleado empleado = empleados->buscar(i);
	            int edad = calcularEdad(&empleado);
	            if (edad >= 18 && edad <= 24 && empleado.getSexo() == sexo) {
	                cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion()
	                     << " Edad: " << edad << " Sexo: " << empleado.getSexo() << endl;
	                cantidad++;
	            }
	        }
		} else if (seleccion==2)	{
		    cout << "Empleados de 25 a 35 años y sexo " << sexo << ":" << endl;
	        for (int i = 0; i < empleados->getTam(); i++) {
	            Empleado empleado = empleados->buscar(i);
	            int edad = calcularEdad(&empleado);
	            if (edad >= 25 && edad <= 35 && empleado.getSexo() == sexo) {
	                cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion()
	                     << " Edad: " << edad << " Sexo: " << empleado.getSexo() << endl;
	                cantidad++;
	            }
	        }
	    } else if (seleccion==3){
		    cout << "Empleados de 36 a 45 años y sexo " << sexo << ":" << endl;
	        for (int i = 0; i < empleados->getTam(); i++) {
	            Empleado empleado = empleados->buscar(i);
	            int edad = calcularEdad(&empleado);
	            if (edad >= 36 && edad <= 45 && empleado.getSexo() == sexo) {
	                cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion()
	                     << " Edad: " << edad << " Sexo: " << empleado.getSexo() << endl;
	                cantidad++;
	            }
	        }
		} else if (seleccion == 4) {
		    cout << "Empleados de 45 a 60 años y sexo " << sexo << ":" << endl;
	        for (int i = 0; i < empleados->getTam(); i++) {
	            Empleado empleado = empleados->buscar(i);
	            int edad = calcularEdad(&empleado);
	            if (edad >= 45 && edad <= 60 && empleado.getSexo() == sexo) {
	                cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion()
	                     << " Edad: " << edad << " Sexo: " << empleado.getSexo() << endl;
	                cantidad++;
	            }
	        }
		} else if (seleccion == 5) {
			cout << "Empleados de más de 60 años y sexo " << sexo << ":" << endl;
	        for (int i = 0; i < empleados->getTam(); i++) {
	            Empleado empleado = empleados->buscar(i);
	            int edad = calcularEdad(&empleado);
	            if (edad >= 60 && edad <= 150 && empleado.getSexo() == sexo) {
	                cout << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion()
	                     << " Edad: " << edad << " Sexo: " << empleado.getSexo() << endl;
	                cantidad++;
	            }
	        }
		} else {
			cout << "Opción no válida." << endl;
		}
	    system("Pause"); // Pausa el programa y espera a que se presione una tecla
	}
	*/
	
};
