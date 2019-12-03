#include "modelXML.h"
#include "view.h"
#include "controller.h"

#include <iostream>


int main(){
    ModelXML model("./test.xml");
    View view;

    Controller controller(model, view);

    controller.Request(" ");

    return 0;
}