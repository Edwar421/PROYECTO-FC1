#include "../Archivos.h"

#include "../OpcionesListas.cpp"

#include <string>
using namespace std;

class Inicializar {
private: OpcionesListas opcionLista;
public:
	
    //Metodos para inicializar las sucursales , ciudades y los empleados
    
    //Con el fin de obtener los datos a la hora de insertar o modificar sin necesidad de repetir codigo
    
    //Declaración las funciones que se van a utilizar
    Sucursal inicializarSucursal(Lista < Sucursal > * sucursales, Lista < Ciudad > * ciudades);
    Ciudad inicializarCiudad();
    Empleado inicializarEmpleado(Lista < Sucursal > * sucursales, Lista < Ciudad > * ciudades, Lista < Empleado > * empleados);
};

//1. Primer método: Inicializar sucursal
Sucursal Inicializar::inicializarSucursal(Lista < Sucursal > * sucursales, Lista < Ciudad > * ciudades) {
    //Insertar Sucursal
	string nombreSucursal;
    Ciudad ciudadSucursal; 
    string barrioSucursal;
    string direccionSucursal;
    string gerenteSucursal;
    
    //para elegir la ciudad de las ya existentes
	int opcionCiudadSucursal;
    bool SucursalValido = false;
    int i = 0;

    while (!SucursalValido) {
	    cout << "Ingrese el nombre del Sucursal: ";
	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
	    getline(cin, nombreSucursal);
	    
	    //elegir ciudad
	    cout << "De las siguientes ciudades, ¿Cual de ella se encuentra la sucursal?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        opcionCiudadSucursal = leerEntrada(0,ciudades->getTam()-1);
        
        cout << "Ingrese el nombre del Barrio donde se encuentra la Sucursal: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		
	    getline(cin, barrioSucursal);
	    
	    cout << "Ingrese la direccion de la Sucursal: ";		
	    getline(cin, direccionSucursal);
	
	    cout << "Ingrese el nombre del Gerente de la Sucursal: ";		
	    getline(cin, gerenteSucursal);

        for (i = 0; i < sucursales -> getTam(); i++) {
            Sucursal SucursalAuxiliar = sucursales -> buscar(i);
            if (SucursalAuxiliar.getNombre() == nombreSucursal || SucursalAuxiliar.getGerenteSucursal() == gerenteSucursal) {
                cout << "El Nombre de la Sucursal ya existe o ya hay un gerente en otra Sucursal" << endl;
                break;
            }
        }

        // Si el bucle for se completï¿½ sin encontrar coincidencias, el Sucursal es vï¿½lido
        if (i == sucursales -> getTam()) {
            SucursalValido = true;
        }
    }
    
    ciudadSucursal = ciudades -> buscar(opcionCiudadSucursal);
    
    Sucursal Sucursal(nombreSucursal, ciudadSucursal, barrioSucursal, direccionSucursal, gerenteSucursal);

    return Sucursal;
}

//2.Inicializar ciudad
Ciudad Inicializar::inicializarCiudad() {
    //Se ingresan los datos de la nueva ciudad (Se necesita validaciï¿½n cuando la ciudad ya existe)
    string nombreCiudad, nombreBarrio, direccion, pais;
    cout << "Ingrese el nombre de la ciudad" << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, nombreCiudad);
    
    cout << "Ingrese el Pais" << endl;
    getline(cin, pais);

    Ciudad ciudad(nombreCiudad, pais);

    return ciudad;
}

//3. Inicializar empleado
Empleado Inicializar::inicializarEmpleado(Lista < Sucursal > * sucursales, Lista < Ciudad > * ciudades, Lista < Empleado > * empleados) {
    // Insertar Empleado (Se necesita validaciï¿½n de puesto, fecha nacimiento, estado civil)

    int OpcionSucursal, OpcionNacimiento, OpcionResidencia;
    string nombre, apellido, tipoIdentificacion, numIdentificacion, telefonoCelular, telefonoFijo, email, fechaNacimiento, paisNacimiento, direccionResidencia, 
			barrioResidencia, actividadLaboral, sucursal;
    char sexo;
    bool EmpleadoValido = false;
    int i = 0;

    while (!EmpleadoValido) {
		bool encontrado = false;
        //Buscar el Sucursal perteneciente de la lista de sucursales y guardarla en el objeto Sucursal

        cout << "De los siguientes sucursales constituidos ,ï¿½ cual de ellos pertenece el Empleado ?" << endl;
        opcionLista.mostrarSucursales(sucursales);
        OpcionSucursal = leerEntrada(0,sucursales->getTam()-1);

        // Buscar la ciudad de nacimiento y residencia de la lista de ciudades y guardarla en los objetos propios
        
        cout << "Ingrese el pais de nacimiento del empleado: ";	
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	
	    getline(cin, paisNacimiento);

        cout << "De las siguientes ciudades, ï¿½Cual de ella nacio el Empleado?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        OpcionNacimiento = leerEntrada(0,ciudades->getTam()-1);

        cout << "De las siguientes ciudades, ï¿½Cual de ellas reside el Empleado?" << endl;
        opcionLista.mostrarCiudades(ciudades);
        OpcionResidencia = leerEntrada(0,ciudades->getTam()-1);
        
        cout << "Ingrese el nombre del Barrio de residencia del empleado: ";
		cin.ignore(numeric_limits<streamsize>::max(), '\n');		
	    getline(cin, barrioResidencia);
	    
	    cout << "Ingrese la direccion de residencia del empleado: ";		
	    getline(cin, direccionResidencia);

        // Aï¿½adir los demï¿½s datos del Empleado

        cout << "Ingrese el nombre de Empleado" << endl;
        //cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nombre);

        cout << "Ingrese el apellido del Empleado" << endl;
        getline(cin, apellido);

        cout << "Ingrese el tipo de identificacion que el Empleado posee 1.Cedula de Ciudadania - 2.Cedula de Extranjeria " << endl;
        int opcion = leerEntrada(1,2);
        
        if (opcion == 1) {
            tipoIdentificacion = "Cedula de Ciudadania";
        } else {
            tipoIdentificacion = "Cedula de Extranjeria";
        }
        
        
        cout << "Ingrese el documento de identidad del Empleado" << endl;
        numIdentificacion = to_string(leerEntrada(0, 999999999));
        
        
        cout << "Ingrese el telefono fijo  del Empleado" << endl;
        telefonoFijo = to_string(leerEntrada(0, 999999999));
        
        
        cout << "Ingrese el telefono celular  del Empleado" << endl;
        telefonoCelular = to_string(leerEntrada(0, 999999999));
        
        cout << "Ingrese el email del empleado: ";	
		cin.ignore(numeric_limits<streamsize>::max(), '\n');	
	    getline(cin, email);
	    
	    
	    cout << "Ingrese la Actividad Laboral del Empleado: ";		
	    getline(cin, actividadLaboral);


        cout << "Ingrese la fecha de nacimiento de Empleado " << endl;
        cout << "Dia: " << endl;
        int dia = leerEntrada(1,31);
        cout << "Mes: " << endl;
        int mes = leerEntrada(1,12);
        cout << "AÃ±o: " << endl;
        int anio = leerEntrada(1950, 2005);
        string sdia = (dia>9)? to_string(dia):"0"+to_string(dia);
        string smes = (mes>9)? to_string(mes):"0"+to_string(mes);
        string sanio = to_string(anio);
        fechaNacimiento = sdia+"/"+smes+"/"+sanio;

        cout << "Ingrese el sexo del Empleado 1.F 2.M " << endl;
        int genero = leerEntrada(1, 2);
        if (genero == 1) {
            sexo = 'F';
        } else {
            sexo = 'M';
        }

        for (int i = 0; i < empleados -> getTam(); i++) {
            Empleado EmpleadoAuxiliar = empleados -> buscar(i);
            if (EmpleadoAuxiliar.getNumIdentificacion() == numIdentificacion) {
                cout << "Ya hay un Empleado con este numero de identificacion" << endl;
                encontrado = true;
                break;
            }
        }

	    if (!encontrado) {
	        EmpleadoValido = true;
	    }
    }
    
    cout << "El Empleado tiene hijos? (S/N): ";
    char tieneHijos;
    cin >> tieneHijos;
    
	 int numHijos =0;
    if (toupper(tieneHijos) == 'S') {
        cout << "Ingrese el número de hijos: ";
        numHijos = leerEntrada(0, 10);
    }

    //Creacion del objeto Empleado para aï¿½adirlo en la lista
    //Opciones
    Sucursal sucursalBuscada = sucursales -> buscar(OpcionSucursal);
    Ciudad ciudadNacimiento = ciudades -> buscar(OpcionNacimiento);
    Ciudad ciudadResidencia = ciudades -> buscar(OpcionResidencia);
    Sucursal sucursalCopia(sucursalBuscada);

    Empleado empleado(nombre, apellido, tipoIdentificacion, numIdentificacion, sexo, telefonoCelular,
        telefonoFijo, email, fechaNacimiento, paisNacimiento, ciudadNacimiento, ciudadResidencia, direccionResidencia,
        barrioResidencia, actividadLaboral, tieneHijos, numHijos,  sucursalCopia);

    // Solicitar información sobre los hijos
        cin.ignore(); // Limpiar el buffer antes de la entrada de cadena

        for (int i = 0; i < numHijos; ++i) {
        	cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	string nombreHijo;
            cout << "Ingrese el nombre del hijo #" << i + 1 << ": ";
            getline(cin, nombreHijo);

            cout << "Ingrese la fecha de nacimiento del hijo #" << i + 1 << ": ";
            cout << "Dia: " << endl;
	        int dia = leerEntrada(1,31);
	        cout << "Mes: " << endl;
	        int mes = leerEntrada(1,12);
	        cout << "AÃ±o: " << endl;
	        int anio = leerEntrada(2000, 2022);
	        string sdia = (dia>9)? to_string(dia):"0"+to_string(dia);
	        string smes = (mes>9)? to_string(mes):"0"+to_string(mes);
	        string sanio = to_string(anio);
	        string fechaNacimientoHijo = sdia+"/"+smes+"/"+sanio;

            Hijo hijo(nombreHijo, fechaNacimientoHijo);
            empleado.agregarHijo(hijo);
        }
    return empleado;
}
