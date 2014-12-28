/* 
 * File:   Nimble.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 26, 2014, 8:53 PM
 */

#include "Nimble.h"

Nimble::Nimble()
{
    parser = new Parser();
    library = new NimbleLibrary();
    nimbleTest = new NimbleTest();
    initializeVariables();
    initializeLibraries();
}
Nimble::~Nimble()
{
    delete parser;
}

void Nimble::compile(int argc, char** argv)
{
    //compile code into assembly and then machine code
}

void Nimble::initializeSyntax()
{
    string arrString[] = {"for", "if", "while", "dowhile", "class", "expression"
                            ,"call", "declare"};
    for(int i = 0; i < (sizeof(arrString)/ sizeof(*arrString)); i++)
    {
        NimbleSyntax::addType(arrString[i]);
    }
}
void Nimble::initializeVariables()
{
    //Initialize standard set of variables
    for(int i = 0; i < VARIABLE_TYPES_SIZE; i++)
    {
        Variable::addType(VARIABLE_TYPES[i]);
    }
}

void Nimble::initializeLibraries()
{
    library->addLibrary(new NimbleLibrary("system"));
}

void Nimble::test()
{
    testVariables();
    testLibraries();
    nimbleTest->test();
}
void Nimble::testVariables()
{
    for(int i = 0; i < VARIABLE_TYPES_SIZE; i++)
    {
        int result = Variable::getType(VARIABLE_TYPES[i]);
        cout<<"Result for getType Variable(string): "<<result<<endl;
        cout<<"Result for getType Variable(int): "<<Variable::getType(i)<<endl;
    }
}
void Nimble::testLibraries()
{
    //search using library
    NimbleLibrary* libResult = 0;
    libResult = library->findLibrary("Nothing");
    cout<<"Result for library->findLibrary(\"Nothing\");."<<endl;
    if(libResult == 0)
    {
        cout<<"Found nothing as expected"<<endl;
    }
    libResult = library->findLibrary("system");
    cout<<"Result for library->findLibrary(\"system\");."<<endl;
    if(libResult != 0)
    {
        cout<<"Library found: "<<libResult->getName()<<endl;
    }
    else
    {
        cout<<"Failed."<<endl;
    }
    libResult = library->findRLibrary("system");
    cout<<"Result for library->findRLibrary(\"system\");."<<endl;
    if(libResult != 0)
    {
        cout<<"Library found: "<<libResult->getName()<<endl;
    }
    else
    {
        cout<<"Failed."<<endl;
    }
    
}

Parser* Nimble::getParser()
{
    return parser;
}

