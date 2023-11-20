
#include <locale.h>
#include <iostream>
#include "Menu.cpp"

int main() {
    setlocale(LC_ALL, "Spanish");
    cout << "Inicializando ..." << endl;
    Menu menu;
    
    menu.Menus();
    
    return 0;
}
