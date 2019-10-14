#include "model.h"

#include "tinyxml2.h"

#include <iostream>
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

XMLDocument xmlDoc;
XMLElement * pRoot;

int loadFile(const char * fPath){
    XMLError eResult = xmlDoc.LoadFile(fPath);
    XMLCheckResult(eResult);

    pRoot = xmlDoc.RootElement();
    if(pRoot == nullptr) return XML_ERROR_PARSING_ELEMENT;

    return 0;
}

const char * getTestText(){
    XMLElement * pElement = pRoot->FirstChildElement("text");
    if(pElement == nullptr) return "";
    const char* stringChar = pElement->GetText();
    return stringChar;
}