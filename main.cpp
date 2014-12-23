/* 
 * File:   main.cpp
 * Author: Daniel Rigby
 *
 * Created on December 23, 2014, 8:21 AM
 */

#include <iostream>
#include "ExpressionTree.h"
#include "ParseTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
    //Test Expression Node and Expression Tree
    //Expression (1+2*3.50)
    ExpressionNode* expNode[10];
    ExpressionTree* expTree = new ExpressionTree();
    expNode[0] = new ExpressionNode('(');
    expTree->setRoot(expNode[0]);
    expNode[1] = new ExpressionNode(1);
    
    expNode[2] = new ExpressionNode('+');
    expTree->insertLeft(expNode[0], expNode[2]);
    expTree->insertRight(expNode[0], expNode[1]);
    expNode[3] = new ExpressionNode(2);
    expTree->insertRight(expNode[2], expNode[3]);
    expNode[4] = new ExpressionNode('*');
    expTree->insertLeft(expNode[2], expNode[4]);
    expNode[5] = new ExpressionNode(3.50);
    expTree->insertRight(expNode[4], expNode[5]);
    expNode[6] = new ExpressionNode(')');
    expTree->insertLeft(expNode[4], expNode[6]);
    
    //Test Parse Tree with Expression print("Hello World");
    ParseTree* parseTree = new ParseTree();
    ParseNode* parseNode[7];
    parseNode[0] = new ParseNode("print");
    parseNode[1] = new ParseNode('(');
    parseNode[2] = new ParseNode('\"');
    parseNode[3] = new ParseNode("Hello World");
    parseNode[4] = new ParseNode('\"');
    parseNode[5] = new ParseNode(')');
    parseNode[6] = new ParseNode(';');
    
    parseTree->setRoot(parseNode[0]);
    //use for loop to put parse nodes into parse tree as it's simply adding
    //all the nodes to the left leaf
    for(int i = 0; i < 6; i++)
    {
        parseTree->insertLeft(parseNode[i], parseNode[i+1]);
    }
    

    cout<<"Nimble Compiler v0.1"<<endl;
    
    cout<<"Print in order of Expression Tree:"<<endl;
    expTree->printInOrder();
    cout<<endl;
    
    cout<<"Print in order of Parse Tree:"<<endl;
    parseTree->printInOrder();
    cout<<endl;
    
}

