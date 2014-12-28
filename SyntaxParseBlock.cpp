/* 
 * File:   SyntaxParseBlock.cpp
 * Author: danielrigby
 * 
 * Created on December 23, 2014, 5:38 PM
 */

#include "SyntaxParseBlock.h"
#include <iostream>

using namespace std;

SyntaxParseBlock::SyntaxParseBlock()
{
    parseBlock = new ParseBlock();
    syntaxTree = new SyntaxTree();
    syntaxCountTree = new SyntaxTree();
}
SyntaxParseBlock::~SyntaxParseBlock()
{
//    delete countNode;
//    delete newNode;
//    delete tempNode;
//    delete tempNodeTwo;
//    delete parseTree;
//    delete countTree;
//    delete lastNode;
//    delete lastCountNode;
}