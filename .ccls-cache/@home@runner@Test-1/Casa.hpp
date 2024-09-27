#include "Inmueble.hpp"
//Se crea la clase "Casa"
class Casa : public Inmueble {
//Se le asignan sus atributos
private:
    string ubicacion_calle;
//Se crean los metodos
public:
    //Se crea el metodo constructor por defecto
    Casa(const string& inmueble, double frente, double fondo, const string& ubicacion, double valor_catastral, const string& ubicacion_calle)
        : Inmueble(inmueble, frente, fondo, ubicacion, valor_catastral), ubicacion_calle(ubicacion_calle) {}
    //Metodo para imprimir las caracteristicas de la clase derivada utilizando override para sobreescribir el metodo de la clase padre
    void imprimir_caracteristicas() override {
        Inmueble::imprimir_caracteristicas();
        cout << "Ubicación de la casa: " << ubicacion_calle << endl;
    }
    //Metodo para calcular el precio de venta acorde al valor catastral y los lineamientos utilizando override para sobreescribir el metodo de la clase padre
    double precio_venta() override {
        double incremento = (ubicacion_calle == "Privada") ? 120 : 80;
        return valor_catastral + (valor_catastral*incremento/100);
    }
};