#include "modelXML.h"
#include "XMLParser.h"
#include "view.h"
#include "controller.h"

#include <iostream>

#include <fstream>

int main(){    
    ModelXML model("./assets/test.xml");
    XMLParser parser("./assets/test0.1.xml");
    View view;

    Controller controller(model, view);

    return 0;
}