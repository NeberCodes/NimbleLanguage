/* 
 * File:   NimbleSyntax.cpp
 * Author: danielrigby
 * 
 * Created on December 27, 2014, 11:02 AM
 */

#include "NimbleSyntax.h"
#include <iostream>

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
    return 0;
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
    //NimbleSyntax::types[newType] = NimbleSyntax::types_size;
    NimbleSyntax::types_size++;
}
void print(NimbleSyntax* syntax)
{
    cout<<syntax->getName()<<" "<<NimbleSyntax::getType(syntax->getType());
}

