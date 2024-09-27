#include "Inmueble.hpp"
//Se crea la clase "Local"
class Local : public Inmueble {
//Se le asignan sus atributos
private:
    string tipo;
//Se crean los metodos de la clase
public:
    //Metodo constructor por defecto
    Local(const string& inmueble, double frente, double fondo, const string& ubicacion, double valor_catastral, const string& tipo)
        : Inmueble(inmueble, frente, fondo, ubicacion, valor_catastral), tipo(tipo) {}
  //Metodo para imprimir las caracteristicas del objeto
    void imprimir_caracteristicas() override {
        Inmueble::imprimir_caracteristicas();
        cout << "Tipo de local: " << tipo << endl;
    }
    
    double precio_venta() override {
        double incremento = (tipo == "Plaza comercial") ? 60 : 40;
        return valor_catastral + (valor_catastral*incremento/100);
    }
};