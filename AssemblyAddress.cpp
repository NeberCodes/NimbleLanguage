/* 
 * File:   AssemblyAddress.cpp
 * Author: danielrigby
 * 
 * Created on December 30, 2014, 4:06 PM
 */

#include "AssemblyAddress.h"
#include "Debug.h"

map<int, string> AssemblyAddress::variables;
int AssemblyAddress::variables_size = 1;

AssemblyAddress::AssemblyAddress()
{
    address = 0;
    variable = false;
    argument = false;
}
AssemblyAddress::~AssemblyAddress()
{
    
}
void AssemblyAddress::setAddress(int newAddress)
{
    variable = false;
    argument = false;
    address = newAddress;
}
void AssemblyAddress::setVariable(int newVariable)
{
    variable = true;
    argument = false;
    address = newVariable;
}
int AssemblyAddress::getAddress()
{
    return address;
}
int AssemblyAddress::getVariable()
{
    return address;
}
bool AssemblyAddress::isVariable()
{
    return variable;
}
bool AssemblyAddress::isArgument()
{
    return argument;
}

void AssemblyAddress::setArgument(int newArgument)
{
    variable = false;
    argument = true;
    address =  (2 << ((sizeof(int) * 8) - 2)) - newArgument;
}

int AssemblyAddress::getArgument()
{
    return (((2 << ((8 * sizeof(int)) - 2)) - address));
}

string AssemblyAddress::toString()
{
    if(argument)
    {
        return (to_string(address));
    }
    else if(address != 0)
    {
        return (to_string(address));
    }
    else
    {
        return "";
    }
}

int AssemblyAddress::getVariable(string theVariable)
{
    for(map<int, string>::iterator iter = AssemblyAddress::variables.begin();
            iter != AssemblyAddress::variables.end(); iter++)
    {
        if(iter->second == theVariable)
        {
            return iter->first;
        }
    }
}
int AssemblyAddress::addVariable(string theVariable)
{
    AssemblyAddress::variables[AssemblyAddress::variables_size]
            = theVariable;
    AssemblyAddress::variables_size++;
    return (AssemblyAddress::variables_size - 1);
}