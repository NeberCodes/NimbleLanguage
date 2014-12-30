/* 
 * File:   AssemblyAddress.cpp
 * Author: danielrigby
 * 
 * Created on December 30, 2014, 4:06 PM
 */

#include "AssemblyAddress.h"

AssemblyAddress::AssemblyAddress()
{
    address = 0;
    variable = false;
}
AssemblyAddress::~AssemblyAddress()
{
    
}
void AssemblyAddress::setAddress(int newAddress)
{
    variable = false;
    address = newAddress;
}
void AssemblyAddress::setVariable(int newVariable)
{
    variable = true;
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

