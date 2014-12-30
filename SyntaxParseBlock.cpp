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

int SyntaxParseBlock::getType(ParseNode* node)
{
    int type = 0;
    //Convert Parse Node into NimbleSyntax
    if(node->getType() == SYMBOL)
        type = SYMBOL_TYPE;
    else if(node->getType() == INT)
        type = NimbleSyntax::getType("int");
    else if(node->getType() == FLOAT)
        type = NimbleSyntax::getType("float");
    else if(node->getType() == DOUBLE)
        type = NimbleSyntax::getType("double");
    else
    {
        type = NimbleSyntax::getType(node->getString());
    }
    return type;
}

NimbleSyntax* SyntaxParseBlock::newSyntax(int newType, ParseNode* node)
{
    if(node->getType() == STRING)
    {
        NimbleSyntax* result = new NimbleSyntax(node->getString(), newType);
        return result;
    }
    else if(node->getType() == INT)
    {
        NimbleSyntax* result = new NimbleSyntax(node->getInt(), newType);
        return result;
    }
    else if(node->getType() == DOUBLE)
    {
        NimbleSyntax* result = new NimbleSyntax(node->getDouble(), newType);
        return result;
    }
    else if(node->getType() == FLOAT)
    {
        NimbleSyntax* result = new NimbleSyntax(node->getFloat(), newType);
        return result;
    }
    else if(node->getType() == SYMBOL)
    {
        NimbleSyntax* result = new NimbleSyntax(node->getSymbol(), newType);
        return result;
    }
    return 0;
}
void SyntaxParseBlock::addToTree(ParseNode* node)
{
    if(node != 0)
    {
        int type = getType(node);
        NimbleSyntax* newSyntaxa = newSyntax(type, node);
        
        syntaxTree->setRoot(newSyntaxa);
        addToTreeLeft(newSyntaxa, node->getLeft());
        addToTreeRight(newSyntaxa, node->getRight());
    }
}
void SyntaxParseBlock::addToTreeLeft(NimbleSyntax* syntax, ParseNode* node)
{
    if(node != 0)
    {
        int type = getType(node);
        NimbleSyntax* newSyntaxa = newSyntax(type, node);
        syntaxTree->insertLeft(syntax, newSyntaxa);
        addToTreeLeft(newSyntaxa, node->getLeft());
        addToTreeRight(newSyntaxa, node->getRight());
    }
}

void SyntaxParseBlock::addToTreeRight(NimbleSyntax* syntax, ParseNode* node)
{
    if(node != 0)
    {
        int type = getType(node);
        NimbleSyntax* newSyntaxa = newSyntax(type, node);
        syntaxTree->insertRight(syntax, newSyntaxa);
        addToTreeLeft(newSyntaxa, node->getLeft());
        addToTreeRight(newSyntaxa, node->getRight());
    }
}
void SyntaxParseBlock::addToCountTree(ParseNode* node)
{
    if(node != 0)
    {
        int count = node->getInt();
        NimbleSyntax* newSyntaxa = newSyntax(count, node);
        syntaxCountTree->setRoot(newSyntaxa);
        addToCountTreeLeft(newSyntaxa, node->getLeft());
        addToCountTreeRight(newSyntaxa, node->getRight());
    }
}
void SyntaxParseBlock::addToCountTreeLeft(NimbleSyntax* syntax, ParseNode* node)
{
    if(node != 0)
    {
        int count = node->getInt();
        NimbleSyntax* newSyntaxa = new NimbleSyntax(count, INT_TYPE);
        syntaxCountTree->insertLeft(syntax, newSyntaxa);
        addToCountTreeLeft(newSyntaxa, node->getLeft());
        addToCountTreeRight(newSyntaxa, node->getRight());
    }
}
void SyntaxParseBlock::addToCountTreeRight(NimbleSyntax* syntax, ParseNode* node)
{
    if(node != 0)
    {
        int count = node->getInt();
        NimbleSyntax* newSyntaxa = new NimbleSyntax(count, INT_TYPE);
        syntaxCountTree->insertRight(syntax, newSyntaxa);
        addToCountTreeLeft(newSyntaxa, node->getLeft());
        addToCountTreeRight(newSyntaxa, node->getRight());
    }
}
SyntaxTree* SyntaxParseBlock::getTree()
{
    return syntaxTree;
}
SyntaxTree* SyntaxParseBlock::getCountTree()
{
    return syntaxCountTree;
}