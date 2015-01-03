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
    testAssembler();
    testAssemblyInstruction();
}
void NimbleTest::testAssembler()
{
    cout<<"Testing Assembler"<<endl;
    int MYLEN = AssemblyAddress::addVariable("mylen"),
            MYMSG = AssemblyAddress::addVariable("mymsg");
    AssemblyLibrary* library = new AssemblyLibrary("main");
    AssemblyFunction* function = new AssemblyFunction();
    AssemblyInstruction* instruction = new AssemblyInstruction();
    AssemblyAddress* address = new AssemblyAddress();
    
    
    function->setName("print");
    
    instruction->setStatement("push");
    address->setVariable(MYLEN);
    instruction->setSecondAddress(address);
    function->addInstruction(instruction);
    
    instruction = new AssemblyInstruction();
    address = new AssemblyAddress();
    instruction->setStatement("push");
    instruction->setFirstSArgument("dword");
    address->setVariable(MYMSG);
    instruction->setSecondAddress(address);
    cout<<"SECOND ADDRESS: "<<instruction->getSecondAddress()->toString()<<endl;
    cout<<"FIRST ARGUMENT: "<<instruction->getFirstSArgument()<<endl;
    function->addInstruction(instruction);
    
    cout<<"Printing all instructions of: "<<function->getName()<<endl;
    function->printInstructions();
    cout<<endl;
    
    
}
void NimbleTest::testAssemblyInstruction()
{
    cout<<"Testing Assembly Instruction"<<endl;
    cout<<"Print all Assembly Statement Types: "<<endl;
    AssemblyInstruction::printStatements();
    
    cout<<"Testing Assembly Address when adding arguments"<<endl;
    AssemblyAddress* address = new AssemblyAddress();
    address->setArgument(1);
    cout<<"Value of Assembly address with argument: 1: "<<address->getAddress()
            <<endl;
    cout<<"Number of argument for address: "<<address->getArgument()<<endl;
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

