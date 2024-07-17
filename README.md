Gestión de Información de Empleados, Sucursales y Ciudades

Este proyecto tiene como objetivo desarrollar un sistema de gestión de información de empleados, sucursales y ciudades para una empresa. El sistema permite realizar consultas eficientes y manejar datos de manera óptima utilizando estructuras de datos avanzadas como listas, multilistas, pilas, colas y árboles. El programa se implementa en C++ aplicando programación orientada a objetos, principios de alta cohesión y bajo acoplamiento, y optimización de algoritmos.


Descripción
La empresa desea recopilar información de sus empleados para identificar perfiles que optimicen el desarrollo de labores. Los gerentes han ordenado la creación de formularios distribuidos en todas las sucursales ubicadas en países de habla hispana. La información recopilada incluye datos personales y laborales de los empleados, así como información de las sucursales.

Datos Recolectados:

Empleados:

1. Nombre
2. Apellido
3. Tipo de identificación: Cédula de ciudadanía, cédula de extranjería, tarjeta de identidad
4. Número de identificación
5. Sexo: F o M
6. Teléfono celular
7. Teléfono fijo
8. Email
9. Fecha de nacimiento
10. Ciudad de nacimiento
11. País de nacimiento
12. Ciudad de residencia
13. Dirección
14. Barrio
15. Actividad laboral: Artes, ciencias sociales, ingenierías, áreas de la salud, otros
16. Tiene hijos: S o N
17. Número de hijos
18. Listado con nombre y fecha de nacimiento de cada hijo: 0-5, 6-10, 11-15, mayor de 15
19. Nombre de la sucursal en la que trabaja
    
Sucursales:

1. Nombre de la sucursal
2. Dirección de la sucursal
3. Barrio
4. Nombre del gerente de la sucursal
5. Estructura de Datos:

En Memoria Secundaria:

Información almacenada en archivos planos actualizados al final del día o al terminar el programa.

Archivos planos para empleados y sucursales.

En Memoria Principal:

- Listas, multilistas, arreglos, pilas, colas o árboles para optimizar búsquedas.
- Listas enlazadas clasificadas por sexo, edad, actividad laboral, número de hijos, localidad y sucursal.

Consultas Disponibles
1. Número total de personas en una sucursal, clasificados por rangos de edad de los hijos.
2. Listado de nombres y apellidos de personas con un número de hijos dado, clasificados por ciudad y país.
3. Nombre y apellidos de personas en una ciudad dada, clasificados por ciudad de nacimiento y actividad laboral.
4. Número de sucursales con más de un número dado de empleados, incluyendo detalles de la sucursal y el gerente.
5. Número de hombres y mujeres en diferentes sucursales, clasificados por país y ciudad.
6. Lista de trabajadores en un rango de edad y actividad laboral, clasificados por barrio y sucursal.

Requisitos Funcionales
1. Utilización de listas y multilistas para optimizar búsquedas.
2. Estructuras de datos eficientes en tiempo y memoria.
3. Menú interactivo para facilitar las consultas.
   
4 .Capacidad de calcular la edad de cada persona registrada.
5. Actualización de archivos planos al finalizar el programa.
