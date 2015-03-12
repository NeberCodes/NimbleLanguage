/* 
 * File:   NimbleConverter.cpp
 * Author: danielrigby
 * 
 * Created on February 25, 2015, 3:02 PM
 */

#include "NimbleConverter.h"

map<NimbleFunction*, AssemblyFunction*> NimbleConverter::conversionLinks;

NimbleConverter::NimbleConverter() 
{
}

void NimbleConverter::addLink(NimbleFunction* newNimbleFunc, AssemblyFunction* newAssemblyFunc)
{
    if(getLink(newNimbleFunc) != 0)
    {
        
    }
}
AssemblyFunction* NimbleConverter::getLink(NimbleFunction* nimbleFunc)
{
    return NimbleConverter::conversionLinks[nimbleFunc];
}

