#ifndef LEERENTRADAS_H
#define LEERENTRADAS_H

#include <iostream>
#include <limits>

int leerEntrada(int min, int max)
{
    int num;
    while (!(std::cin >> num) || num < min || num > max  || std::cin.peek() != '\n') {
        std::cin.clear();                       // Restablecer el estado de cin
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   // Ignorar caracteres inválidos ingresados
        std::cout << "Entrada invalida. Por favor, ingrese un numero valido: ";
    }
    return num;
}

#endif
