//Edmundo Ruelas Angulo - A01742824
#include <iostream>
#include "Video.h"

int main() {
    //Se crea un objeto de la clase Video para poder invocar el metodo mainMenu ya que no es static
    //Se invoca solo el metodo mainMenu porque todos los demas metodos
    //son invocados dentro de la clase en un ciclo hasta que el usuario desee salir
    Video v1;
    v1.mainMenu();

    return 0;
}
