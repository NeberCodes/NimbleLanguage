/* 
 * File:   AssemblyStatement.cpp
 * Author: danielrigby
 * 
 * Created on December 30, 2014, 4:19 PM
 */

#include "AssemblyStatement.h"

AssemblyStatement::AssemblyStatement(bool newPrestatement, int newStatement, 
        int newFirstArgument, int newSecondArgument)
{
    prestatement = newPrestatement;
    statement = newStatement;
    firstArgument = newFirstArgument;
    secondArgument = newSecondArgument;
}
AssemblyStatement::~AssemblyStatement()
{
    
}
bool AssemblyStatement::getPrestatement()
{
    return prestatement;
}
int AssemblyStatement::getStatement()
{
    return statement;
}
int AssemblyStatement::getFirstArgument()
{
    return firstArgument;
}
int AssemblyStatement::getSecondArgument()
{
    return secondArgument;
}
