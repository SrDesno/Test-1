//Edmundo Ruelas Angulo - A01742824
// Video.cpp
#include "Video.h"

//Constructor por defecto
Video::Video() {
    id = 0000;
    type = "N/O";
    title = "N/O";
    genre = "N/O";
    overview="N/0";
    runtime="N/O";
    vote_average=0;
    vote_count=0;
}

//Constructor con parametros
Video::Video(int _id, std::string _type, std::string _title, std::string _genre, std::string _overview, std::string _runtime, double _vote_average, int _vote_count){
    id = _id;
    type = _type;
    title = _title;
    genre = _genre;
    overview=_overview;
    runtime=_runtime;
    vote_average=_vote_average;
    vote_count=_vote_count;
}

//Metodos getters
int Video::getId() {
    return id;
}

std::string Video::getType() {
    return type;
}

std::string Video::getTitle() {
    return title;
}

std::string Video::getGenre() {
    return genre;
}

std::string Video::getOverview() {
    return overview;
}

std::string Video::getRuntime() {
    return runtime;
}

double Video::getVote_average() {
    return vote_average;
}

int Video::getVote_count() {
    return vote_count;
}

//Metodos setters
void Video::setId(int _id) {
    id = _id;
}

void Video::setTitle(std::string _title) {
    title = _title;
}

void Video::setOverview(std::string _overview) {
    overview = _overview;
}

void Video::setRuntime(std::string _runtime) {
    runtime = _runtime;
}

void Video::setVote_average(double _vote_average) {
    vote_average = _vote_average;
}

void Video::setVote_count(int _vote_count) {
    vote_count = _vote_count;
}

//Metodo para mostrar la informacion de los objetos
void Video::showInfo() {
    std::cout << "ID: " << id << "\n";
    std::cout << "Type: " << type << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout << "Genre: " << genre << "\n";
}

//Metodo para mostrar la informacion adicional de los objetos
void Video::showInfo_adicional() {
    std::cout << "-----------------------\n";
    std::cout << "ID: " << id << "\n";
    std::cout << "Title: " << title << "\n";
    std::cout<<"Overview: "<<overview<<"\n";
    std::cout<<"Runtime: "<<runtime<<"\n";
    std::cout<<"Vote Average: "<<vote_average<<"\n";
}


//Metodo para crear el vector y asignar los valores del .txt a los atributos de la clase
void Video::createVector() {
    //Se abre el archivo con la ruta espesisificada
    std::ifstream archive("video.txt");
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

            std::getline(ss, data, ';');
            id = std::stoi(data);

            std::getline(ss, type, ';');
            std::getline(ss, title, ';');
            std::getline(ss, genre, ';');
            std::getline(ss,overview,';');
            std::getline(ss,runtime,';');

            std::getline(ss,data,';');
            vote_average=std::stod(data);

            std::getline(ss,data,';');
            vote_count=std::stoi(data);


            //Se crea un nuevo objeto con los datos obtenidos del .txt y se agrega al vector
            videos.push_back(Video(id, type, title, genre, overview, runtime, vote_average, vote_count));
        }
        //Se cierra el archivo cuando se termina de recorrer
        archive.close();

    }
    //En caso de que no se pueda abrir el archivo se imprime un mensaje
    else {
        std::cout << "Cannot open the archive.\n";
    }
}

//Metodo para imprimir todos los objetos de la clase video
void Video::showVideo() {
    for (auto& video : videos) {
        //Se imprimen los datos de cada objeto con la ayuda del metodo showInfo
        video.showInfo();
        std::cout << "-----------------------\n";
    }
}

//Metodo para buscar un objeto por su id
Video* Video::findVideoById(int _id) {
    //Se recorre el vector de objetos
    for (auto& video : videos) {
        //Se compara el id del objeto con el id que se busca
        if (video.getId() == _id) {
            //Si se encuentra el objeto se regresa el objeto
            return &video;
        }
    }
    //Si no se encuentra el objeto se regresa un nullptr
    return nullptr;
}

//Metodo que muestra el menu detalles
void Video::menuDetails() {
    //Se crea una variable para almacenar el id del video que se desea ver
    int idmenu;
    std::cout << "-----------------------\n";
    std::cout<<"Enter the ID of the video you want to see the details: ";
    std::cin>>idmenu;
    //Se asigna el id del video a una variable temporal para futuras referencias
    temp_Id=idmenu;

    //Se busca el video por su id
    Video* video = Video::findVideoById(idmenu);
    //Si se encuentra el video se muestra la informacion adicional y se muestra el menu de calificar
    if (video != nullptr) {
        video->showInfo_adicional();
        menuQualify();
    }
    //Si no se encuentra el video se imprime un mensaje
    else {
        std::cout << "-----------------------\n";
        std::cout<<"Video not found\n";
    }
}

//Metodo que muestra el menu principal
void Video::mainMenu() {
    //Se crean las variables necesarias
    int option;
    //Se llama el metodo createVector para crear el vector y asignar los valores del .txt a los atributos de la clase
    createVector();
    //Se llama el metodo showVideo para mostrar los videos esto para que el usuario pueda ver los id de los videos
    //cada que se vuelva a inciar el menu principal
    showVideo();
    //Se crea un ciclo do while para mostrar el menu principal
    do {
        std::cout<<"1. Show Video details\n";
        std::cout<<"2. Exit\n";
        std::cout<<"Choose an option: ";
        std::cin>>option;


        //Se crea un switch para las opciones del menu
        switch (option) {
            case 1:
                //Si el usuario digita 1 se llama el metodo menuDetails para mostrar el menu de detalles
                menuDetails();
                break;
            case 2:
                //Si el usuario digita 2 se imprime un mensaje de despedida y se sale del programa
                    //con la ayuda de la funcion exit(0) perteneciente a la libreria cstdlib
                std::cout << "-----------------------\n";
                std::cout<<"Goodbye\n";
                exit(0);
                break;
            default:
                //Si el usuario digita una opcion invalida se imprime un mensaje
                std::cout << "-----------------------\n";
                std::cout<<"Invalid option\n";
                break;
        }
    }
    //El ciclo se repite mientras el usuario no digite 2 por lo que evita problemas de
    while (option != 2);
}


//Metodo para calificar un video
void Video::functionQualify() {
    //Se crea una variable para almacenar la calificacion
    double qualify;
    std::cout << "-----------------------\n";
    std::cout << "Qualify the video from 1 to 5: ";
    std::cin >> qualify;

    //Se busca el video con la ayuda del id temporal que se asigno en el metodo menuDetails
    //asi no es necesario que el usuario digite el id de nuevo
    Video* video = Video::findVideoById(temp_Id);
    //Si se encuentra el video se califica y se imprime un mensaje
    if (video == nullptr) {
        std::cout << "-----------------------\n";
        std::cout << "Video not found\n";
        return;
    }

    //Se verifica que la calificacion  este dentro del rango de 1 a 5
    if (qualify >= 1 && qualify <= 5) {
        //Se crean las variables necesarias para calcular la nueva calificacion
        //para no codificar tanto dentro del setter
        int new_vote_count = video->getVote_count() + 1;
        double new_vote_average = ((video->getVote_average() * video->getVote_count()) + qualify) / new_vote_count;
        //Se asignan los nuevos valores al video
        video->setVote_count(new_vote_count);
        video->setVote_average(new_vote_average);
        //Se imprime un mensaje con la nueva calificacion
        std::cout << "-----------------------\n";
        std::cout << "The video has been qualified\n";
        std::cout << "The new average is: " << video->getVote_average() << "\n";
        //Se llama el metodo saveToFile para guardar los cambios en el archivo
        saveToFile();

    //Si la calificacion no esta en el rango se imprime un mensaje
    } else {
        std::cout << "-----------------------\n";
        std::cout << "Invalid qualification\n";
    }
}

//Metodo del menu calificar
void Video::menuQualify() {
    //Se crea una variable para almacenar la opcion del menu
    int option;
    //Se crea un ciclo do while para mostrar el menu de calificar
    do {
        std::cout << "-----------------------\n";
        std::cout<<"1. Qualify video\n";
        std::cout<<"2. Go to main menu\n";
        std::cout<<"3. Exit program\n";
        std::cout<<"Choose an option: ";
        std::cin>>option;

        //Se crea un switch para las opciones del menu
        switch (option) {
            //Si el usuario digita 1 se llama el metodo functionQualify para calificar el video
            case 1:
                functionQualify();
                break;
            //Si el usuario digita 2 se llama el metodo mainMenu para regresar al menu principal
            case 2:
                mainMenu();
                break;
            //Si el usuario digita 3 se imprime un mensaje de despedida y se sale del programa
                //con la ayuda de la funcion exit(0)
            case 3:
                std::cout << "-----------------------\n";
                std::cout<<"Goodbye\n";
                exit(0);
                break;
        }
    }
    //El ciclo se repite mientras el usuario no digite 3
    while (option != 3);
}

//Metodo para guardar los cambios en el archivo
void Video::saveToFile() {
    //Se abre el archivo con la ruta especificada
    std::ofstream outfile("video.txt");
    //Se imprime la primer linea del archivo que son los encabezados
    outfile << "'id';'type';'title';'genres';'overview';'runtime';'vote_average';'vote_count'\n";
    //Se recorre el vector de objetos y se imprimen los datos de cada objeto en el archivo
    for (auto& video : videos) {
        //Se imprimen los datos de cada objeto con la ayuda de los metodos getters siendo
        //el unico que cambia el que el usuario califico
        outfile << video.getId() << ";"
                << video.getType() << ";"
                << video.getTitle() << ";"
                << video.getGenre() << ";"
                << video.getOverview() << ";"
                << video.getRuntime() << ";"
                << video.getVote_average() << ";"
                << video.getVote_count() << "\n";
    }
    //Se cierra el archivo cuando se termina de recorrer
    outfile.close();
}