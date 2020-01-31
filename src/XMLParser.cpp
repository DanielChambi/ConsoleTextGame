#include "XMLParser.h"

#include <fstream>
#include <iostream>
#include <string>

/**
 * XMLParser
 */
XMLParser::XMLParser(std::string fPath){
    
    this->fPath = fPath;
    XMLNode *root;

    try{
        root = this->ParseSetFile();
        if(root){
            std::cout << root->tagName;
            std::cout << root->toString();
        }
    } catch(...){
        std::cout << "Error parsing";
    }
    
    
}

XMLNode* XMLParser::ParseSetFile(){
    
    char ch;
    std::string *text;              //When reading text, text currently being read is referenced here.
    std::stack<char> bracketStack;
    std::stack<XMLNode*> nodeStack;
    
    std::fstream fin( fPath, std::fstream::in );

    if(!fin.is_open()) {std::cerr << "file not found.";}

    while(fin >> std::noskipws >> ch){
        //TODO parse and create node
    }
    fin.close();
    
    XMLNode node;
    node.tagName = "test";
    return &node;
}



/**
 * XMLNode
 */

XMLNode::XMLNode(){

};

std::string XMLNode::toString(){
    std::cout << this->tagName;
    std::string s = "<"+this->tagName+">\n";
    std::vector<std::string> childrenStrings;

    for(auto &child : this->children){
        std::vector<std::string> childVector = child->toStringVector();        
        for(auto &line : childVector){
            line.insert(0, "|");
            line.append("\n");
            s.append(line);
        }
    }

    return s;
}
std::vector<std::string> XMLNode::toStringVector(){
    std::vector<std::string> stringV;
    stringV.push_back("<"+this->tagName+">");

    for(auto &child : this->children){
        std::vector<std::string> childVector = child->toStringVector();
        for(auto &line : childVector){
            line.insert(0, "|");
            stringV.push_back(line);
        }
    }

    return stringV;
}