#include "tinyxml2.h"

#ifndef MODEL_H
#define MODEL_H
class ModelXML{
private:
    tinyxml2::XMLDocument * xmlDoc;
    tinyxml2::XMLElement * pRoot;
public:
    ModelXML();
    int OpenFile(const char * fPath);
    const char * GetTestText();
};
    
#endif