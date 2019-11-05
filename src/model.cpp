#include "model.h"

#include "tinyxml2.h"

#include <iostream>
#include <string>

#ifndef XMLCheckResult
	#define XMLCheckResult(a_eResult) if (a_eResult != XML_SUCCESS) { printf("Error: %i\n", a_eResult); return a_eResult; }
#endif

using namespace std;
using namespace tinyxml2;

ModelXML::ModelXML(){
        xmlDoc = new XMLDocument(true, COLLAPSE_WHITESPACE);
}

const char * ModelXML::GetTestText(){
    if(pRoot){
        XMLElement * pElement = pRoot->FirstChildElement("text");
        if(pElement == nullptr) return "";
        const char* stringChar = pElement->GetText();
        return stringChar;
    } else {
        return "Error";
    }
}

int ModelXML::OpenFile(const char * fPath){
    XMLError eResult = xmlDoc->LoadFile(fPath);
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

    const char * id = pAttribute->Value();
    
    


    return 0;                
}
*/




/*
EntryType ParseType(const char * id){
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
        const char * plainText;
};