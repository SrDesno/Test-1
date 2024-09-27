#include "Inmueble.hpp"

//Se crea la clase derivada "Terreno"
class Terreno : public Inmueble {
//Se crea solo un atributo de tipo booleano para saber si tiene servicios o no
private:
    bool servicios;
//Se le asignan sus metodos
public:
    //Metodo condtructor
    Terreno(const string& inmueble, double frente, double fondo, const string& ubicacion, double valor_catastral, bool servicios)
        : Inmueble(inmueble, frente, fondo, ubicacion, valor_catastral), servicios(servicios) {}
    //Metodo para imprimir las caracteristicas de la clase derivada utilizando override para sobreescribir el metodo de la clase padre
    void imprimir_caracteristicas() override {
        Inmueble::imprimir_caracteristicas();
        cout << "Servicios disponibles: " << (servicios ? "Sí" : "No") << endl;
    }
    //Metodo para calcular el precio de venta acorde al valor catastral y los lineamientos utilizando override para sobreescribir el metodo de la clase padre
    double precio_venta() override {
        double incremento = servicios ? 40 : 20;
        return valor_catastral + (valor_catastral*incremento/100);
    }
};