/* 
 * File:   main.cpp
 * Author: Daniel Rigby
 *
 * Created on December 23, 2014, 8:21 AM
 */

#include <iostream>
#include "ExpressionNode.h"
#include "ExpressionTree.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) 
{
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
    //(1+2*3.50)
    cout<<"Hello World"<<endl;
    
    cout<<"Print postfix of Expression Tree:"<<endl;
    expTree->printInOrder();
//    cout<<"Expression Nodes."<<endl;
//    for(int i = 0; i < 7; i++)
//    {
//        print(expNode[i]);
//    }
//    return 0;
}

