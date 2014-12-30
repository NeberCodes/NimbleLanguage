/* 
 * File:   NimbleTest.cpp
 * Author: danielrigby
 * 
 * Created on December 27, 2014, 11:50 AM
 */

#include "NimbleTest.h"

NimbleTest::NimbleTest()
{
    nimbleFunction = new NimbleFunction();
    syntaxTree = new SyntaxTree();
    syntaxParser = new SyntaxParser();
}
NimbleTest::~NimbleTest()
{
    delete syntaxParser;
    delete nimbleFunction;
    delete syntaxTree;
}
void NimbleTest::test()
{
    cout<<"Nimble Testing."<<endl;
    testFunction();
    testSyntaxTree();
    testAssemblyInstruction();
}

void NimbleTest::testAssemblyInstruction()
{
    cout<<"Testing Assembly Instruction"<<endl;
    //Prestatement, First Argument, Second Argument(0 = nothing, 1 = integer, 
    //2 = variable, 3 = string, 4 = integer/string)
    AssemblyInstruction::addStatementType("mov", false, 1, 1);
    AssemblyInstruction::addStatementType("db", true, 4, 0);
    AssemblyInstruction::addStatementType("inc", true, 2, 0);
    cout<<"Print all Assembly Statement Types: "<<endl;
    AssemblyInstruction::printStatements();
}
void NimbleTest::testFunction()
{
    cout<<"Testing Nimble functions."<<endl;
    cout<<"Nimble Function: "<<nimbleFunction->getName()<<endl;
    
    Variable* variable = new Variable("plain");
    variable->addType(Variable::getType("int"));
    nimbleFunction->addArgument(*variable);
            
    cout<<"Printing out Nimble function arguments."<<endl;
    for(Variable var:nimbleFunction->getArguments())
    {
        cout<<"Argument: ";
        for(int i:var.getTypes())
        {
            cout<<Variable::getType(i)<<" ";
        }
        cout<<var.getName()<<endl;
    }
    
    SyntaxTree* synTree = nimbleFunction->getSyntaxTree();
    cout<<"Printing Nimble function syntax tree in order: "<<endl;
    synTree->printInOrder();
    
}
void NimbleTest::testSyntaxTree()
{
//    NimbleSyntax* syntax= new NimbleSyntax[3];
//    syntax[0].setName("if");
//    syntax[0].setType(NimbleSyntax::getType("int"));
    cout<<"Testing Syntax tree."<<endl;
    string str = "print(\"Hello World\")";
    
    
    SyntaxParseBlock* parseBlock = syntaxParser->parse(str);
    cout<<"Printing Syntax tree in order: "<<endl;
    parseBlock->getTree()->printInOrder();
    cout<<endl;
    
}

