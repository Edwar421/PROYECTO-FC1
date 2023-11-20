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
	/*
    //2. Sucursales.
    void mostrarSucursales(Lista < Sucursal > * sucursales) {
        for (int i = 0; i < sucursales -> getTam(); i++) {
            //Guardar la sucursal buscada y devolver el atributo nombre
            Sucursal sucursal = sucursales -> buscar(i);
            cout << i << "." << "Nombre :"  << sucursal.getNombreSucursal() << "\n Barrio: " << sucursal.getBarrioSucursal() << "\n Dirección: " << sucursal.getDireccionSucursal() << "\n Gerente: " << sucursal.getGerenteSucursal();
        }
    }
    /*
	//3. Empleados.
    void mostrarEmpleados(Lista < Empleado > * empleados) {
        for (int i = 0; i < empleados -> getTam(); i++) {
            //Guardar el empleado y devolver sus atributos
            Empleado empleado = empleados -> buscar(i);
            cout << i << ". " << empleado.getNombre() << " " << empleado.getApellido() << " " << empleado.getNumIdentificacion() << " " << empleado.getSexo() << " " << empleado.getTelefonoCelular() << empleado.getTelefonoFijo() << empleado.getEmail() << empleado.getFechaNacimiento() << empleado.getCiudadNacimiento() << empleado.getPaisNacimiento() << empleado.getCiudadResidencia() << empleado.getDireccionResidencia() << empleado.getBarrioResidencia() << empleado.getSucursal() << "/n" << endl;
        }
        system("Pause");
    }*/
};
