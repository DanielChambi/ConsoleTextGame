#include "model.h"

#include "tinyxml2.h"

#include <iostream>

using namespace std;

int main(){
    loadFile("../test.xml");

    cout << getTestText();
}