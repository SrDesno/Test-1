//Se incluyen todas las librerias desde la clase padre para no volverlas a llamar en las otras clases
#include <iostream>
#include <string>
//Pragma once para que no de error el programa debido a que todas las clases derivadas llaman a esta clase a la vez
#pragma once

using namespace std;
//Se crea la clase padre "Inmueble"
class Inmueble {
//Se le asignan atributos de tipo protected para que las clases derivadas puedan acceder a ellos
protected:
    double frente, fondo, valor_catastral;
    string ubicacion, inmueble;
//Se le crean sus metodos
public:
    //Metodo constructor
    Inmueble(const string& inmueble, double frente, double fondo, const string& ubicacion, double valor_catastral)
        : inmueble(inmueble), frente(frente), fondo(fondo), ubicacion(ubicacion), valor_catastral(valor_catastral) {}
    //Metodo para imprimir la informacion
    virtual void imprimir_caracteristicas() {
        cout << "Tipo de inmueble: " << inmueble << endl;
        cout << "Frente: " << frente << " metros" << endl;
        cout << "Fondo: " << fondo << " metros" << endl;
        cout << "Ubicación: " << ubicacion << endl;
        cout << "Valor Catastral: $" << valor_catastral << endl;
    }
    //Metodo para regresar el valor catastral
    virtual double precio_venta() {
        return valor_catastral;
    }
};