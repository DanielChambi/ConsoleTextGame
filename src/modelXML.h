#ifndef MODELXML_H
#define MODELXML_H

#include <string>

#include "tinyxml2.h"


class ModelXML{
public:
    ModelXML(std::string fPath);
    std::string GetTestText();
private:
    tinyxml2::XMLDocument * xmlDoc;
    tinyxml2::XMLElement * pRoot;
    int OpenFile(std::string fPath);
};
    
#endif