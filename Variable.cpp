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
    type = 0;
    name = "";
}

Variable::Variable(int newType, string newName)
{
    type = newType;
    name = newName;
}
Variable::~Variable()
{
}
void Variable::setVariable(int newType, string newName)
{
    type = newType;
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
int Variable::getType()
{
    return type;
}
string Variable::getName()
{
    return name;
}
void Variable::setType(int newType)
{
    type = newType;
}
void Variable::setName(string newName)
{
    name = newName;
}
