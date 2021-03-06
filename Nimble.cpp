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
    initializeSyntax();
    initializeVariables();
    initializeLibraries();
    initializeAssembler();
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
    string arrString[] = {"for", "if", "while", "dowhile", "class", "symbol"
                            ,"call", "declare", "double", "int", "float", "char"};
    for(int i = 0; i < (sizeof(arrString)/ sizeof(*arrString)); i++)
    {
        NimbleSyntax::addType(arrString[i]);
    }
    FLOAT_TYPE = NimbleSyntax::getType("float");
    DOUBLE_TYPE = NimbleSyntax::getType("double");
    INT_TYPE = NimbleSyntax::getType("int");
    SYMBOL_TYPE = NimbleSyntax::getType("symbol");
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

void Nimble::initializeAssembler()
{
    //Prestatement, First Argument, Second Argument(0 = nothing, 1 = integer, 
    //2 = address, 3 = string, 4 = integer/string, 5 = optional address)
    AssemblyInstruction::addStatementType("mov", false, STATEMENT_ADDRESS, 
            STATEMENT_INT);
    AssemblyInstruction::addStatementType("push", false, STATEMENT_OPTIONAL
    , STATEMENT_ADDRESS);
    AssemblyInstruction::addStatementType("db", true, STATEMENT_ALL, 
            STATEMENT_STRING);
    AssemblyInstruction::addStatementType("inc", true, STATEMENT_ADDRESS, 
            NOTHING);
    AssemblyInstruction::addStatementType("call", false, STATEMENT_STRING, 
            NOTHING);
}
void Nimble::test()
{
    testVariables();
    testLibraries();
    nimbleTest->test();
    prototypeConverter();
    
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

/*
 NimbleConverter class holds list of conversion from which nimble types to
 which assembly types (NimbleConversion Class: pointer to nimble function, pointer to assemblyfunction
 Has ability to loop through NimbleSyntaxTree converting them into a list of assembly instructions
 NOTE: add ability for assembly instructions to output as an assembly instruction may need to link variables in
 Need iterator to go through syntax tree, maybe NimbleSyntaxTreeIterator.
 Loop through syntax tree converting nimble function to assembly*/

void Nimble::prototypeConverter()
{
    //Create relevant Nimble and Assembly print functions and library. 
    NimbleLibrary* nimble = new NimbleLibrary("Nimble");
    NimbleFunction* nimblePrintFunc = new NimbleFunction("print");
    nimble->addFunction(nimblePrintFunc);
    
        //add arguments to function
    Variable* varOne = new Variable("output");
    
    int key = Variable::addType("string");
    varOne->addType(key);
    nimblePrintFunc->addArgument(*varOne);
    
    AssemblyLibrary* assembly = new AssemblyLibrary("Assembly");
    AssemblyFunction* assemblyPrintFunc = new AssemblyFunction("print");
    //Create list of nimble->assembly conversion links for functions
//    map<NimbleFunction*, AssemblyFunction*> conversionLinks;
    
    //simply create a print function link
}