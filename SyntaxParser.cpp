/* 
 * File:   SyntaxParser.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 23, 2014, 10:23 AM
 */

#include "SyntaxParser.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

SyntaxParser::SyntaxParser()
{
    data = "";
    parser = new Parser();
}

SyntaxParser::SyntaxParser(string newData)
{
    data = newData;
    parser = new Parser(newData);
}

SyntaxParser::~SyntaxParser()
{
    data = "";
    delete parser;
}
void SyntaxParser::loadData(string newData)
{
    parser->loadData(newData);
    data = newData;
}
//Parse to parse tree then convert to syntax tree
SyntaxParseBlock* SyntaxParser::parse()
{
    ParseBlock* parseBlock = parser->parse();
    return 0;
}
SyntaxParseBlock* SyntaxParser::parse(string newData)
{
    data = newData;
    return parse();
}
