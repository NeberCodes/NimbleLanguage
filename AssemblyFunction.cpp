#include "AssemblyFunction.h"

AssemblyFunction::AssemblyFunction()
{
}
AssemblyFunction::~AssemblyFunction()
{
}

list<AssemblyInstruction> AssemblyFunction::getParams()
{
    return params;
}

list<AssemblyInstruction> AssemblyFunction::getInstructions()
{
    return instructions;
}

void AssemblyFunction::addParam(AssemblyInstruction* newParam)
{
    params.push_back(*newParam);
}
void AssemblyFunction::addInstruction(AssemblyInstruction* newInstruction)
{
    instructions.push_back(*newInstruction);
}
string AssemblyFunction::getName()
{
    return name;
}
void AssemblyFunction::setName(string newName)
{
    name = newName;
}

void AssemblyFunction::printInstructions()
{
    for(list<AssemblyInstruction>::iterator iter = instructions.begin(); iter 
            != instructions.end(); iter++)
    {
        if(iter->getStatement() != 0)
            cout<<"ITER = 0"<<endl;
        iter->print();
        cout<<endl;
    }
}