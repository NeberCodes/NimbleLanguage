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
    block = new SyntaxParseBlock();
}

SyntaxParser::SyntaxParser(string newData)
{
    data = newData;
    parser = new Parser(newData);
    block = new SyntaxParseBlock();
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
    cout<<"Parser->Parsing"<<endl;
    ParseBlock* parseBlock = parser->parse();
    parseBlock->getParseTree()->printInOrder();
    cout<<endl;
    cout<<"Done Parsing adding to tree"<<endl;
    //Convert parse tree into a syntax tree
    block->addToTree(parseBlock->getParseTree()->getRoot());
    cout<<"Done adding to tree adding to count tree"<<endl;
    block->addToCountTree(parseBlock->getCountTree()->getRoot());
    cout<<"Done adding to count tree"<<endl;
    return block;
}
SyntaxParseBlock* SyntaxParser::parse(string newData)
{
    parser->loadData(newData);
    return parse();
}
