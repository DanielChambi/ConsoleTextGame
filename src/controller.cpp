#include "modelXML.h"
#include "view.h"
#include "controller.h"

#include <iostream>


Controller::Controller(){}

Controller::Controller(ModelXML model, View view){
    this->model = &model;
    this->view = &view;
}

void Controller::SetModel(ModelXML model){
    this->model = &model;
}

void Controller::SetView(View view){
    this->view = &view;
}

std::string Controller::GetRequest(){
    std::string req;
    
    std::cin >> req;

    return req;
}

void Controller::Request(std::string req){
    std::string str = this->model->GetTestText();
    this->view->ShowText(str);
}