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
            std::cout << root->toString();
            delete root;
        }
    } catch(...){
        std::cout << "Error parsing";
    }
    
    
}

XMLNode* XMLParser::ParseSetFile(){
    
    char ch;
    std::string *text = NULL;              //When reading text, text currently being read is referenced here.
    std::stack<char> bracketStack;
    std::stack<XMLNode*> nodeStack;

    XMLNode *root = NULL;

    
    std::fstream fin( fPath, std::fstream::in );

    if(!fin.is_open()) {std::cerr << "file not found.";}

    while(fin >> std::noskipws >> ch){
        
        switch (ch){
            case '<':
                std::cout << "new tag" << std::endl;
                bracketStack.push(ch);
            break;
            case '/':
                std::cout << "marked as closing tag" << std::endl;
                bracketStack.push(ch);
            break;
            case '>':
                std::cout << "end of tag" << std::endl;
                
                if(bracketStack.top() == '/'){
                    std::cout << "end of node: " << *text << std::endl;
                    XMLNode *node = nodeStack.top();
                    nodeStack.pop();

                    if(!nodeStack.empty()){
                        XMLNode *parent = nodeStack.top();
                        parent->children.push_back(node);
                    } else {
                        root = node;
                    }
                    
                } else {
                    std::cout << "creating node: " << *text << std::endl;
                    nodeStack.push(new XMLNode(text));
                }

                text = NULL;
            break;
            default:
                if(text == NULL){
                    text = new std::string();
                    *text = "";
                }

                if(ch != ' ' &&  ch != '\n'){
                    *text += ch;
                }
            break;
        }
        
    }
    fin.close();
    
    
    return root;
}

/**
 * XMLNode
 */

XMLNode::XMLNode(){}
XMLNode::XMLNode(std::string *name){
    this->tagName = name;
}

std::string XMLNode::toString(){
    std::string s = "<"+*(this->tagName)+">\n";
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
    stringV.push_back("<"+*(this->tagName)+">");

    for(auto &child : this->children){
        std::vector<std::string> childVector = child->toStringVector();
        for(auto &line : childVector){
            line.insert(0, "|");
            stringV.push_back(line);
        }
    }

    return stringV;
}

XMLNode::~XMLNode(){
    delete tagName;
    if(text != NULL){
        delete text;
    }
    for(auto &child : this->children){
        delete child;
    }
}