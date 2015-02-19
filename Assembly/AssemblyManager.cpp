/* 
 * File:   assemblyManager.cpp
 * Author: danielrigby
 * 
 * Created on February 19, 2015, 1:07 PM
 */

#include "assemblyManager.h"

AssemblyManager::AssemblyManager()
{
    libraries = 0;
    dataMap = 0;
}
    
list<AssemblyLibrary> AssemblyManager::getLibraries()
{
    return libraries;
}
map<unsigned int, unsigned int> AssemblyManager::getDataMap()
{
    return dataMap;
}

void AssemblyManager::addLibrary(AssemblyLibrary* newLibrary)
{
    libraries.push_back(*newLibrary);
}
void AssemblyManager::addData(unsigned int newID, unsigned int newAddress)
{
    dataMap.insert(std::pair<unsigned int, unsigned int>(newID, newAddress));
}

AssemblyLibrary* AssemblyManager::findLibrary(string libraryName)
{
    AssemblyLibrary* result = 0;
    for(list<AssemblyLibrary>::iterator iter = libraries.begin(); iter != libraries.end(); iter++)
    {
        if((result = (*iter)->getName()) == libraryName)
        {
            return result;
        }
    }
    return 0;
}

AssemblyFunction* AssemblyManager::findFunction(string libraryName, string functionName)
{
    AssemblyFunction* result = 0;
    AssemblyLibrary* library = findLibrary(libraryName);
    if(library != 0)
    {
        result = library->findFunction(functionName);
        if(result != 0)
        {
            return result;
        }
    }
    return 0;
}
AssemblyFunction* AssemblyManager::findFunction(string functionName)
{
    AssemblyFunction* result = 0;
    for(list<AssemblyLibrary>::iterator iter = libraries.begin(); iter != libraries.end(); iter++)
    {
       result = (*iter)->findFunction(functionName);
       if(result != 0)
       {
           return result;
       }
    }
    return 0;
}

unsigned int AssemblyManager::findData(unsigned int);