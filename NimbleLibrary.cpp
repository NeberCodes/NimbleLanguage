/* 
 * File:   NimbleLibrary.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 26, 2014, 8:28 PM
 */

#include "NimbleLibrary.h"

NimbleLibrary::NimbleLibrary()
{
    name = "";
}

NimbleLibrary::NimbleLibrary(string newName)
{
    name = newName;
}

NimbleLibrary::~NimbleLibrary()
{
}
void NimbleLibrary::addLibrary(NimbleLibrary* newNimbleLibrary)
{
    libraryList.push_back(*newNimbleLibrary);
}

void NimbleLibrary::removeLibrary(string searchName)
{
    for(list<NimbleLibrary>::iterator iter = libraryList.begin(); iter != libraryList.end(); iter++)
    {
        if(iter->getName() == searchName)
            libraryList.erase(iter);
    }
}
NimbleLibrary* NimbleLibrary::findLibrary(string searchName)
{
    for(list<NimbleLibrary>::iterator iter = libraryList.begin(); iter != libraryList.end(); iter++)
    {
        if(iter->getName() == searchName)
        {
            return &(*iter);
        }
    }
    return 0;
}
NimbleLibrary* NimbleLibrary::findRLibrary(string searchName)
{
    NimbleLibrary* retList = 0;
    if(name == searchName)
        return this;
    for(list<NimbleLibrary>::iterator iter = libraryList.begin(); iter != libraryList.end(); iter++)
    {
        retList = iter->findRLibrary(searchName);
        if(retList != 0)
            return retList;
    }
    return 0;
}
string NimbleLibrary::getName()
{
    return name;
}
