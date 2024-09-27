//Edmundo Ruelas Angulo - A01742824
#ifndef VIDEO_H
#define VIDEO_H
//Se incluyen las librerias necesarias
#include <iostream>
#include <fstream>
#include <sstream>
#include <iostream>
#include <locale>
#include <codecvt>
#include <vector>
#include <cstdlib>


class Video {
private:
    //Se crean los atributos de la clase
    int id;
    std::string type;
    std::string title;
    std::string genre;
    std::string overview;
    std::string runtime;
    double vote_average;
    int vote_count;
    int temp_Id;
    //Vector que almacena los objetos de la clase Video
    std::vector<Video> videos;
public:
    //Constructor por defecto y constructor con parametros
    Video();
    Video(int, std::string, std::string, std::string, std::string, std::string, double, int);
    //Metodo para mostrar la informacion del objeto
    virtual void showInfo();
    //Metodo para mostrar la informacion adicional de los objetos
    virtual void showInfo_adicional();
    //Metodos getters
    int getId();
    std::string getType();
    std::string getTitle();
    std::string getGenre();
    std::string getOverview();
    std::string getRuntime();
    double getVote_average();
    int getVote_count();
    int getTemp_Id();
    //Metodos setters
    void setId(int);
    void setTitle(std::string);
    void setOverview(std::string);
    void setRuntime(std::string);
    void setVote_average(double);
    void setVote_count(int);
    //Metodo para crear el vector y asignar los valores del .txt a los atributos de la clase
    virtual void createVector();
    //Metodo para imprimir todos los objetos de la clase video
    virtual void showVideo();
    //Metodo para buscar un objeto por su id
    Video*findVideoById(int);
    //Metodo que muestra el menu principal
    void mainMenu();
    //Metodo que muestra el menu de detalles
    void menuDetails();
    //Metodo para calificar un video
    void functionQualify();
    //Metodo del menu califcar
    void menuQualify();
    //Metodo para guardar los cambios en el archivo
    void saveToFile();
};



#endif //VIDEO_H
