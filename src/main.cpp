#include "model.h"

#include "tinyxml2.h"

#include <iostream>

using namespace std;

int main(){
    ModelXML model;

    model.OpenFile("./test.xml");
    
    cout << model.GetTestText();
}