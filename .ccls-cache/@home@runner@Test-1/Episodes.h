//Edmundo Ruelas Angulo - A01742824
#ifndef EPISODES_H
#define EPISODES_H
#include "Video.h"


class Episodes: public Video{
private:
    std::vector<Episodes> episodes;
public:
    Episodes();
    Episodes(std::string, std::string, std::string, double, int);
    void createVector();
    void showInfo_adicional();
};



#endif //EPISODES_H
