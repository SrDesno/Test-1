//Edmundo Ruelas Angulo - A01742824
#include "Episodes.h"

//Constructor por defecto
Episodes::Episodes() {
    setTitle("N/O");
    setOverview("N/O");
    setRuntime("N/O");
    setVote_average(0);
    setVote_count(0);
}

//Constructor con parametros
Episodes::Episodes(std::string _title, std::string _overview, std::string _runtime, double _vote_average, int _vote_count) {
    setTitle(_title);
    setOverview(_overview);
    setRuntime(_runtime);
    setVote_average(_vote_average);
    setVote_count(_vote_count);
}

//Metodo para crear el vector y asignar los valores del .txt a los atributos de la clase
void Episodes::createVector() {
    //Se abre el archivo con la ruta espesisificada
    std::ifstream archive("C:\\Users\\Desno\\Documents\\CLION\\Proyecto entrega 2\\"+getTitle()+".txt");
    //Se crean las variables necesarias
    std::string line;
    //Se verifica si el archivo se abrio correctamente
    if (archive.is_open()) {
        //Se ignora la primer linea del .txt porque son los encabezados
        std::getline(archive, line);
        //Se recorre el archivo con un ciclo while para recorrer el .txt
        while (std::getline(archive, line)) {
            std::stringstream ss(line);
            std::string data;

            std::getline(ss, title, ';');
            std::getline(ss,overview,';');
            std::getline(ss,runtime,';');

            std::getline(ss,data,';');
            vote_average=std::stod(data);

            std::getline(ss,data,';');
            vote_count=std::stoi(data);


            //Se crea un nuevo objeto con los datos obtenidos del .txt y se agrega al vector
            episodes.push_back(Episodes(title, overview, runtime, vote_average, vote_count));
        }
        archive.close();

    }
    //En caso de que no se pueda abrir el archivo se imprime un mensaje
    else {
        std::cout << "Cannot open the archive.\n";
    }
}

void Episodes::showInfo_adicional() {
    Video::showInfo_adicional(); // Call base class method

    std::cout << "-----------------------\n";
    std::cout << "Title: " << title << "\n";
    std::cout<<"Overview: "<<overview<<"\n";
    std::cout<<"Runtime: "<<runtime<<"\n";
    std::cout<<"Vote Average: "<<vote_average<<"\n";

}

