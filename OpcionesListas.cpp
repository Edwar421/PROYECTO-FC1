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
        int cantidad = 0;
        
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

        system("Pause"); // Pausa el programa y espera a que se presione una tecla
    }
    
};
