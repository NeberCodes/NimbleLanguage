/* 
 * File:   NimbleSyntax.cpp
 * Author: danielrigby
 * 
 * Created on December 27, 2014, 11:02 AM
 */

#include "NimbleSyntax.h"
#include <iostream>

int DOUBLE_TYPE = 0, FLOAT_TYPE = 0, INT_TYPE = 0, SYMBOL_TYPE = 0;

using namespace std;

map<int, string> NimbleSyntax::types;
int NimbleSyntax::types_size = 0;

NimbleSyntax::NimbleSyntax()
{
    left = 0;
    right = 0;
    branch = 0;
    name = "";
    type = 0;
}
NimbleSyntax::NimbleSyntax(string newName, int newType)
{
    left = 0;
    right = 0;
    branch = 0;
    name = newName;
    type = newType;
}

NimbleSyntax::NimbleSyntax(double newD, int newType)
{
    d = newD;
    left = 0;
    right = 0;
    branch = 0;
    type = newType;
}

NimbleSyntax::NimbleSyntax(float newF, int newType)
{
    f = newF;
    left = 0;
    right = 0;
    branch = 0;
    type = newType;
}

NimbleSyntax::NimbleSyntax(int newNumber, int newType)
{
    number = newNumber;
    left = 0;
    right = 0;
    branch = 0;
    type = newType;
}

NimbleSyntax::NimbleSyntax(char c, int newType)
{
    symbol = c;
    left = 0;
    right = 0;
    branch = 0;
    type = newType;
}

NimbleSyntax::~NimbleSyntax()
{
    delete left;
    delete right;
    delete branch;
}
NimbleSyntax* NimbleSyntax::getLeft()
{
    return left;
}
NimbleSyntax* NimbleSyntax::getRight()
{
    return right;
}
NimbleSyntax* NimbleSyntax::getBranch()
{
    return branch;
}
string NimbleSyntax::getName()
{
    return name;
}
int NimbleSyntax::getType(string searchName)
{
    for(map<int, string>::iterator iter = NimbleSyntax::types.begin(); iter != NimbleSyntax::types.end(); iter++)
    {
        if(iter->second == searchName)
        {
            return iter->first;
        }
    }
    return -1;
}

string NimbleSyntax::getType(int searchType)
{
    for(map<int, string>::iterator iter = NimbleSyntax::types.begin(); iter != NimbleSyntax::types.end(); iter++)
    {
        if(iter->first == searchType)
        {
            return iter->second;
        }
    }
    return "";
}
int NimbleSyntax::getType()
{
    return type;
}

void NimbleSyntax::setLeft(NimbleSyntax* newLeft)
{
    left = newLeft;
}
void NimbleSyntax::setRight(NimbleSyntax* newRight)
{
    right = newRight;
}
void NimbleSyntax::setBranch(NimbleSyntax* newBranch)
{
    branch = newBranch;
}
void NimbleSyntax::setName(string newName)
{
    name = newName;
}
void NimbleSyntax::setType(int newType)
{
    type = newType;
}

void NimbleSyntax::addType(string newType)
{
    NimbleSyntax::types[NimbleSyntax::types_size] = newType;
    cout<<"Added Type: "<<newType<<" ["<<NimbleSyntax::types_size<<"] = "<<
            NimbleSyntax::types[NimbleSyntax::types_size]<<"."<<endl;
    NimbleSyntax::types_size++;
}
void print(NimbleSyntax* syntax)
{
    int type = syntax->getType();
    if(type == INT_TYPE)
        cout<<syntax->getNumber();
    else if(type == DOUBLE_TYPE)
        cout<<syntax->getDouble();
    else if(type == FLOAT_TYPE)
        cout<<syntax->getFloat();
    else if(type == SYMBOL_TYPE)
        cout<<syntax->getSymbol();
    else
        cout<<syntax->getName();
}

void NimbleSyntax::setSymbol(char c)
{
    type = SYMBOL_TYPE;
    symbol = c;
}

char NimbleSyntax::getSymbol()
{
    return symbol;
}

int NimbleSyntax::getNumber()
{
    return number;
}
float NimbleSyntax::getFloat()
{
    return f;
}
double NimbleSyntax::getDouble()
{
    return d;
}