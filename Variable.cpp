/* 
 * File:   Variable.cpp
 * Author: danielrigby
 * 
 * Created on December 26, 2014, 8:33 PM
 */

#include "Variable.h"

map<int, string> Variable::types;
int Variable::types_size;

Variable::Variable()
{
    name = "";
}

Variable::Variable(string newName)
{
    name = newName;
}
Variable::~Variable()
{
}
void Variable::setVariable(string newName)
{
    name = newName;
}
int Variable::addType(string newName)
{
    Variable::types[Variable::types_size] = newName;
    return(++(Variable::types_size));
}
int Variable::getType(string searchName)
{
    for(map<int, string>::iterator iter = Variable::types.begin(); iter != Variable::types.end(); iter++)
    {
        if(iter->second == searchName)
            return iter->first;
    }
    return 0;
}

string Variable::getType(int theType)
{
    for(map<int, string>::iterator iter = Variable::types.begin(); iter != Variable::types.end(); iter++)
    {
        if(iter->first == theType)
            return iter->second;
    }
    return 0;
}

list<int> Variable::getTypes()
{
    return myTypes;
}
string Variable::getName()
{
    return name;
}
void Variable::addType(int newType)
{
    myTypes.push_back(newType);
}
void Variable::setName(string newName)
{
    name = newName;
}
