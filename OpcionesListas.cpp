#include <string>

class OpcionesListas {
private:

public:
    //1. Ciudades en las que hay registradas sucursales.
    void mostrarCiudades(Lista < Ciudad > * ciudades) {
        for (int i = 0; i < ciudades -> getTam(); i++) {
            //Guardar la ciudad buscada en una variable y devolver atributo nombre
            Ciudad ciudad = ciudades -> buscar(i);
            cout << i << ". " << ciudad.getNombreCiudad() << endl;
        }
    }
	
    //2. Sucursales.
    void mostrarSucursales(Lista < Sucursal > * sucursales) {
        for (int i = 0; i < sucursales -> getTam(); i++) {
            //Guardar la sucursal buscada y devolver el atributo nombre
            Sucursal sucursal = sucursales -> buscar(i);
            cout << i << "." << "Nombre :"  << sucursal.getNombreSucursal() << "Barrio: " << sucursal.getBarrioSucursal() << "Dirección: " << sucursal.getDireccionSucursal() << " Gerente: " << sucursal.getGerenteSucursal() << endl;
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
        /*int cantidad = 0;
        
        if (sexo == 'M'){
        	cout<<"Empleados Hombres"<<endl;
		}else{
			cout<<"Empleadas Mujeres"<<endl;
		}
        
        for (int i = 0; i < empleados -> getTam(); i++) {
            //Guardar el candidato buscado y devolver los atributos necesarios dada la validacion
            Empleado empleado = empleados -> buscar(i);
            if (empleado.getSexo() == sexo) {
                cout << empleado.getNombre() <<" "<<empleado.getNumIdentificacion()<<endl;
                cantidad++;
            }
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla*/
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
	/*void empleadosSucursal(string sucursal, Lista<Empleado> *empleados) {
        int cantidad = 0;
        for (int i = 0; i < empleados -> getTam(); i++) {
            //Guardar el empleado buscado y devolver los atributos necesarios dada la validacion
            Empleado empleado = empleados->buscar(i);
            if (empleado.getSucursal().getNombreSucursal() == sucursal) {
                cout << empleados -> buscar(i).getNombreCompleto() << endl;
                cantidad++;
            }
        }

        if (cantidad == 0) {
            cout << "Esta ciudad no tiene empleados para esta categoria, verifique el ingreso" << endl;
        }

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }*/
};
