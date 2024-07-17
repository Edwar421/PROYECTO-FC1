Gestión de Información de Empleados, Sucursales y Ciudades

Este proyecto tiene como objetivo desarrollar un sistema de gestión de información de empleados, sucursales y ciudades para una empresa. El sistema permite realizar consultas eficientes y manejar datos de manera óptima utilizando estructuras de datos avanzadas como listas, multilistas, pilas, colas y árboles. El programa se implementa en C++ aplicando programación orientada a objetos, principios de alta cohesión y bajo acoplamiento, y optimización de algoritmos.


Descripción
La empresa desea recopilar información de sus empleados para identificar perfiles que optimicen el desarrollo de labores. Los gerentes han ordenado la creación de formularios distribuidos en todas las sucursales ubicadas en países de habla hispana. La información recopilada incluye datos personales y laborales de los empleados, así como información de las sucursales.

Datos Recolectados:
Empleados:

Nombre
Apellido
Tipo de identificación: Cédula de ciudadanía, cédula de extranjería, tarjeta de identidad
Número de identificación
Sexo: F o M
Teléfono celular
Teléfono fijo
Email
Fecha de nacimiento
Ciudad de nacimiento
País de nacimiento
Ciudad de residencia
Dirección
Barrio
Actividad laboral: Artes, ciencias sociales, ingenierías, áreas de la salud, otros
Tiene hijos: S o N
Número de hijos
Listado con nombre y fecha de nacimiento de cada hijo: 0-5, 6-10, 11-15, mayor de 15
Nombre de la sucursal en la que trabaja
Sucursales:

Nombre de la sucursal
Dirección de la sucursal
Barrio
Nombre del gerente de la sucursal
Estructura de Datos:
En Memoria Secundaria:

Información almacenada en archivos planos actualizados al final del día o al terminar el programa.
Archivos planos para empleados y sucursales.
En Memoria Principal:

Listas, multilistas, arreglos, pilas, colas o árboles para optimizar búsquedas.
Listas enlazadas clasificadas por sexo, edad, actividad laboral, número de hijos, localidad y sucursal.

Consultas Disponibles
Número total de personas en una sucursal, clasificados por rangos de edad de los hijos.
Listado de nombres y apellidos de personas con un número de hijos dado, clasificados por ciudad y país.
Nombre y apellidos de personas en una ciudad dada, clasificados por ciudad de nacimiento y actividad laboral.
Número de sucursales con más de un número dado de empleados, incluyendo detalles de la sucursal y el gerente.
Número de hombres y mujeres en diferentes sucursales, clasificados por país y ciudad.
Lista de trabajadores en un rango de edad y actividad laboral, clasificados por barrio y sucursal.
Requisitos Funcionales
Utilización de listas y multilistas para optimizar búsquedas.
Estructuras de datos eficientes en tiempo y memoria.
Menú interactivo para facilitar las consultas.
Capacidad de calcular la edad de cada persona registrada.
Actualización de archivos planos al finalizar el programa.
