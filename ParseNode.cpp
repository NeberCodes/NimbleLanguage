/* 
 * File:   ParseNode.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 23, 2014, 11:29 AM
 */

#include "ParseNode.h"
#include "Debug.h"

ParseNode::ParseNode(string newString ) 
{
    // Constructor for making a node of type NUMBER.
    type = STRING;
    str = newString;
    left = 0;
    right = 0;
}

ParseNode::ParseNode(int newNumber ) 
{
  // Constructor for making a node of type NUMBER.
    type = INT;
    theInt = newNumber;
    left = 0;
    right = 0;
}

ParseNode::ParseNode(double newNumber ) 
{
  // Constructor for making a node of type DOUBLE.
    type = DOUBLE;
    theDouble = newNumber;
    left = 0;
    right = 0;
}

ParseNode::ParseNode( char newSymbol ) {
    // Constructor for making a node of type OPERATOR.
    type = SYMBOL;
    symbol = newSymbol;
    left = 0;
    right = 0;
}

ParseNode* ParseNode::getLeft()
{
    return left;
}

ParseNode* ParseNode::getRight()
{
    return right;
}

void ParseNode::setLeft(ParseNode* newLeft)
{
    left = newLeft;
    left->setBranch(this);
}

void ParseNode::setRight(ParseNode* newRight)
{
    right = newRight;
    right->setBranch(this);
}

double ParseNode::getDouble()
{
    return theDouble;
}

int ParseNode::getInt()
{
    return theInt;
}

string ParseNode::getString()
{
    return str;
}

char ParseNode::getSymbol()
{
    return symbol;
}

int ParseNode::getType()
{
    return type;
}

void print(ParseNode* expNode)
{
    switch(expNode->getType())
    {
        case INT:
            cout<<expNode->getInt();
            break;
        case DOUBLE:
            cout<<expNode->getDouble();
            break;
        case STRING:
            cout<<expNode->getString();
            break;
        case SYMBOL:
            cout<<expNode->getSymbol();
            break;
    }
}

ParseNode::~ParseNode()
{
    left = 0;
    right = 0;
    branch = 0;
}

bool ParseNode::isBrace()
{
    for(int i = 0; i < SYMBOLS_LENGTH; i++)
    {
        if(symbol == SYMBOLS[i])
        {
            return true;
        }
    }
    return false;
}

bool ParseNode::isNotOperator()
{
    if(type != SYMBOL)
        return true;
    else
    {
        for(int i = 0; i < OPERATORS_LENGTH; i++)
        {
            if(OPERATORS[i] == symbol)
                return false;
        }
    }
    return true;
}

bool ParseNode::isType(const char theType[], const int length)
{
    for(int i = 0; i < length; i++)
    {
        if(theType[i] == symbol)
            return true;
    }
    return false;
}

ParseNode* ParseNode::getBranch()
{
    return branch;
}
void ParseNode::setBranch(ParseNode* newBranch)
{
    branch = newBranch;
}