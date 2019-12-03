#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "modelXML.h"
#include "view.h"

class Controller{
public:
    Controller();
    Controller(ModelXML model, View view);
    void SetModel(ModelXML model);
    void SetView(View view);
    std::string GetRequest();
    void Request(std::string req);
private:
    ModelXML * model;
    View * view;
};

#endif