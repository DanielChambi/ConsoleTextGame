#ifndef XMLPARSER_H
#define XMLPARSER_H

#include <fstream>
#include <string>
#include <stack>
#include <vector>


/**
 * XMLNode
 * 
 * Base node class for XML tree data structure.
 */
class XMLNode{
public:
    std::string tagName;
    std::string text;
    std::vector<XMLNode*> children;

    XMLNode();
    
    /**
     * Returns string represenatation of node and children.
     */
    std::string toString();

private:
    /**
     * Returns vector containing separate lines of string representation.
     */
    std::vector<std::string> toStringVector();
};

/**
 * XMLParser
 * 
 * Greater class design to parse an XML file into the strutures used in game.
 */
class XMLParser{
public:
    XMLParser(std::string fPath);
    XMLNode* ParseSetFile();
private:
    std::string fPath;
};



#endif