/* 
 * File:   Parser.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 23, 2014, 10:23 AM
 */

#include "Parser.h"

Parser::Parser()
{
    data = "";
}
Parser::~Parser()
{
    data = '\0';
}
void Parser::loadData(string newData)
{
    data = newData;
}
//Parses the local string data and returns as a Parse Tree
ParseTree* Parser::parse()
{
    ParseTree* parseTree = new ParseTree();
    
    return parseTree;
}
ParseTree* Parser::parse(string newData)
{
    ParseTree* parseTree = new ParseTree();
    
    return parseTree;
}

