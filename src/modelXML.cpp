#include "modelXML.h"

#include "tinyxml2.h"

#include <iostream>
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace tinyxml2;

ModelXML::ModelXML(std::string fPath){
        xmlDoc = new XMLDocument(true, COLLAPSE_WHITESPACE);
        this->OpenFile(fPath);
}

std::string ModelXML::GetTestText(){
    if(pRoot){
        XMLElement * pElement = pRoot->FirstChildElement("text");
        if(pElement == nullptr) return "";
        std::string stringChar = pElement->GetText();
        return stringChar;
    } else {
        return "Error";
    }
}

int ModelXML::OpenFile(std::string fPath){
    XMLError eResult = xmlDoc->LoadFile(fPath.c_str());
    XMLCheckResult(eResult);

    pRoot = xmlDoc->RootElement();
    if(pRoot == nullptr) return XML_ERROR_PARSING_ELEMENT;

    return 0;
}

/*
int ModelXML::ParseTestEntry(){
    if(pRoot == nullptr) return XML_ERROR_FILE_NOT_FOUND;

    XMLElement * pElement = pRoot->FirstChildElement("entry");
    if(pElement == nullptr) return XML_ERROR_PARSING_ELEMENT;

    const XMLAttribute * pAttribute = pElement->FindAttribute("id");
    if(pAttribute == nullptr) return XML_ERROR_PARSING_ATTRIBUTE;

    //Entry testEntry;

    string id = pAttribute->Value();
    
    


    return 0;                
}
*/




/*
EntryType ParseType(string id){
    if(id == "EXIT"){
        return EXIT;
    }else{
        char t = id[0];
        switch (t){
            case 'M':
                return MESSAGE;
            break;
            default:
                return ERROR;
            break;
        }
    }
}
*/

enum EntryType{
    MESSAGE,
    ERROR,
    EXIT
};

class Entry{
    public:
        EntryType type;
        int index;
        std::string plainText;
};