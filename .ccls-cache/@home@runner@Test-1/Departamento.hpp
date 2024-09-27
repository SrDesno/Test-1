#include "Inmueble.hpp"
//Se crea la clase "Departamento"
class Departamento : public Inmueble {
//Se le asignan sus atributos (caracteristicas)
private:
    string piso;
//Se crean sus metodos
public:
    //Metodo constructor por defecto
    Departamento(const string& inmueble, double frente, double fondo, const string& ubicacion, double valor_catastral, const string& piso)
        : Inmueble(inmueble, frente, fondo, ubicacion, valor_catastral), piso(piso) {}
    //Metodo para imprimir las caracteristicas de la clase derivada utilizando override para     sobreescribir el metodo de la clase padre
    void imprimir_caracteristicas() override {
        Inmueble::imprimir_caracteristicas();
        cout << "Piso del departamento: " << piso << endl;
    }
    //Metodo para calcular el precio de venta acorde al valor catastral y los lineamientos utilizando override para sobreescribir el metodo de la clase padre
    double precio_venta() override {
        double incremento = (piso == "Primera planta") ? 80 : 50;
        return valor_catastral + (valor_catastral*incremento/100);
    }
};
