/* 
 * File:   AssemblyInstruction.cpp
 * Author: danielrigby
 * 
 * Created on December 30, 2014, 4:12 PM
 */

#include "AssemblyInstruction.h"
#include "Debug.h"

map<int, string> AssemblyInstruction::statements;
map<int, AssemblyStatement*> AssemblyInstruction::statementList;
int AssemblyInstruction::statement_size = 0;
AssemblyInstruction::AssemblyInstruction()
{
    prestatement = "";
    firstAddress = 0;
    secondAddress = 0;
    firstArgument = 0;
    secondArgument = 0;
    firstSArgument = "";
    secondSArgument = "";
}
AssemblyInstruction::~AssemblyInstruction()
{
    delete firstAddress;
    delete secondAddress;
}
void AssemblyInstruction::setPrestatement(string newPrestatement)
{
    prestatement = newPrestatement;
}
void AssemblyInstruction::setStatement(int newStatement)
{
    statement = newStatement;
}
void AssemblyInstruction::setStatement(string newStatement)
{
    statement = AssemblyInstruction::getStatement(newStatement);
}
void AssemblyInstruction::setFirstAddress(AssemblyAddress* newAddress)
{
    firstAddress = newAddress;
}
void AssemblyInstruction::setSecondAddress(AssemblyAddress* newAddress)
{
    secondAddress = newAddress;
}
void AssemblyInstruction::setFirstArgument(int newArgument)
{
    firstArgument = newArgument;
}
void AssemblyInstruction::setSecondArgument(int newArgument)
{
    secondArgument = newArgument;
}
void AssemblyInstruction::setFirstSArgument(string newArgument)
{
    firstSArgument = newArgument;
}
void AssemblyInstruction::setSecondSArgument(string newArgument)
{
    secondSArgument = newArgument;
}

string AssemblyInstruction::getPrestatement()
{
    return prestatement;
}
int AssemblyInstruction::getStatement()
{
    return statement;
}
AssemblyAddress* AssemblyInstruction::getFirstAddress()
{
    return firstAddress;
}
AssemblyAddress* AssemblyInstruction::getSecondAddress()
{
    return secondAddress;
}
int AssemblyInstruction::getFirstArgument()
{
    return firstArgument;
}
int AssemblyInstruction::getSecondArgument()
{
    return secondArgument;
}
string AssemblyInstruction::getFirstSArgument()
{
    return firstSArgument;
}
string AssemblyInstruction::getSecondSArgument()
{
    return secondSArgument;
}
    
int AssemblyInstruction::addStatementType(string statement, bool preStatement, int firstArgument, int secondArgument)
{
    AssemblyInstruction::statements[AssemblyInstruction::statement_size] = statement;
    AssemblyStatement* assemblyStatement = new AssemblyStatement(preStatement, 
            AssemblyInstruction::statement_size, firstArgument, secondArgument);
    AssemblyInstruction::statementList[AssemblyInstruction::statement_size] =
            assemblyStatement;
    AssemblyInstruction::statement_size++;
    return (AssemblyInstruction::statement_size - 1);
}
AssemblyStatement* AssemblyInstruction::getStatementType(string statementType)
{
    return statementList[AssemblyInstruction::getStatement(statementType)];
}
int AssemblyInstruction::getStatement(string statementType)
{
    for(map<int, string>::iterator iter = AssemblyInstruction::statements.begin(); 
            iter != AssemblyInstruction::statements.end(); iter++)
    {
        if(iter->second == statementType)
        {
            return iter->first;
        }
    }
    return 0;
}

void AssemblyInstruction::printStatements()
{
    for(map<int, string>::iterator iter = AssemblyInstruction::statements.begin(); 
            iter != AssemblyInstruction::statements.end(); iter++)
    {
        cout<<"Statement: "<<iter->second<<" "<<
                (AssemblyInstruction::statementList[iter->first]->getPrestatement()?"true":"false")
                <<" "<<iter->first<<" "<<AssemblyInstruction::statementList[iter->first]->getFirstArgument()
                " "<<AssemblyInstruction::statementList[iter->first]->getSecondArgument()<<endl;
    }
}