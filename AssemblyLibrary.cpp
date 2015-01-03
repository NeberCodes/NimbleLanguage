#include "AssemblyLibrary.h"

AssemblyLibrary::AssemblyLibrary()
{
}
AssemblyLibrary::AssemblyLibrary(string newName)
{
    name = newName;
}
AssemblyLibrary::~AssemblyLibrary()
{
}

void AssemblyLibrary::setName(string newName)
{
    name = newName;
}
void AssemblyLibrary::addFunction(AssemblyFunction* newFunction)
{
    functionList.push_back(*newFunction);
}
void AssemblyLibrary::removeFunction(string functionName)
{
    for(list<AssemblyFunction>::iterator iter = functionList.begin(); iter != functionList.end(); iter++)
    {
        if(iter->getName() == functionName)
            functionList.erase(iter);
    }
}
AssemblyFunction* AssemblyLibrary::findFunction(string functionName)
{
    for(list<AssemblyFunction>::iterator iter = functionList.begin(); iter != functionList.end(); iter++)
    {
        if(iter->getName() == functionName)
            return &(*iter);
    }
}
string AssemblyLibrary::getName()
{
    return name;
}
