#include "ExpressionNode.h"

ExpressionNode::ExpressionNode(string newString ) 
{
    // Constructor for making a node of type NUMBER.
    type = STRING;
    str = newString;
    left = 0;
    right = 0;
}

ExpressionNode::ExpressionNode(int newNumber ) 
{
  // Constructor for making a node of type NUMBER.
    type = INT;
    theInt = newNumber;
    left = 0;
    right = 0;
}

ExpressionNode::ExpressionNode(double newNumber ) 
{
  // Constructor for making a node of type DOUBLE.
    type = DOUBLE;
    theDouble = newNumber;
    left = 0;
    right = 0;
}

ExpressionNode::ExpressionNode( char newSymbol ) {
    // Constructor for making a node of type OPERATOR.
    type = SYMBOL;
    symbol = newSymbol;
    left = 0;
    right = 0;
}

ExpressionNode* ExpressionNode::getLeft()
{
    return left;
}

ExpressionNode* ExpressionNode::getRight()
{
    return right;
}

void ExpressionNode::setLeft(ExpressionNode* newLeft)
{
    left = newLeft;
}

void ExpressionNode::setRight(ExpressionNode* newRight)
{
    right = newRight;
}

double ExpressionNode::getDouble()
{
    return theDouble;
}

int ExpressionNode::getInt()
{
    return theInt;
}

string ExpressionNode::getString()
{
    return str;
}

char ExpressionNode::getSymbol()
{
    return symbol;
}

int ExpressionNode::getType()
{
    return type;
}

void print(ExpressionNode* expNode)
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

ExpressionNode::~ExpressionNode()
{
    delete left;
    delete right;
}

bool ExpressionNode::isBrace()
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