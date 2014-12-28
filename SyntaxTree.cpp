/* 
 * File:   SyntaxTree.cpp
 * Author: danielrigby
 * 
 * Created on December 27, 2014, 11:18 AM
 */

#include "SyntaxTree.h"

SyntaxTree::SyntaxTree()
{
    root = 0;
}
SyntaxTree::SyntaxTree(NimbleSyntax* newRoot)
{
    root = newRoot;
}
SyntaxTree::~SyntaxTree()
{
    delete root;
}

void SyntaxTree::deleteNode(NimbleSyntax* node)
{
    if(node->getLeft() != 0)
    {
        deleteNode(node->getLeft());
    }
    if(node->getRight() != 0)
    {
        deleteNode(node->getRight());
    }
    delete node;
}

//NimbleSyntax* SyntaxTree::search(NimbleSyntax* expNode, int theType)
//{
//    NimbleSyntax* returnNode = 0;
//    NimbleSyntax* node;
//    if(expNode->getType() == theType)
//    if(node->getLeft() != 0)
//    {
//        returnNode = search(node->getLeft(), theInt);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    if(node->getRight() != 0)
//    {
//        returnNode = search(node->getRight(), theInt);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    return 0;
//}
//
//NimbleSyntax* SyntaxTree::search(NimbleSyntax* expNode, double theDouble)
//{
//    NimbleSyntax* returnNode = 0;
//    NimbleSyntax* node;
//    if(expNode->getDouble() == theDouble)
//    {
//        return expNode;
//    }
//    if(node->getLeft() != 0)
//    {
//        returnNode = search(node->getLeft(), theDouble);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    if(node->getRight() != 0)
//    {
//        returnNode = search(node->getRight(), theDouble);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    return 0;
//}
//
//NimbleSyntax* SyntaxTree::search(NimbleSyntax* expNode, string theString)
//{
//    NimbleSyntax* returnNode = 0;
//    NimbleSyntax* node;
//    if(expNode->getString() == theString)
//    {
//        return expNode;
//    }
//    if(node->getLeft() != 0)
//    {
//        returnNode = search(node->getLeft(), theString);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    if(node->getRight() != 0)
//    {
//        returnNode = search(node->getRight(), theString);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    return 0;
//}
//NimbleSyntax* SyntaxTree::search(NimbleSyntax* expNode, char theSymbol)
//{
//    NimbleSyntax* returnNode = 0;
//    NimbleSyntax* node;
//    if(expNode->getSymbol() == theSymbol)
//    {
//        return expNode;
//    }
//    if(node->getLeft() != 0)
//    {
//        returnNode = search(node->getLeft(), theSymbol);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    if(node->getRight() != 0)
//    {
//        returnNode = search(node->getRight(), theSymbol);
//        if(returnNode != 0)
//        {
//            return returnNode;
//        }
//    }
//    return 0;
//}
void SyntaxTree::insertLeft(NimbleSyntax* theNode, NimbleSyntax* newNode)
{
    if(root == 0)
        root = newNode;
    else
        theNode->setLeft(newNode);
}
void SyntaxTree::insertRight(NimbleSyntax* theNode, NimbleSyntax* newNode)
{
    if(root == 0)
        root = newNode;
    else
        theNode->setRight(newNode);
}

void SyntaxTree::setRoot(NimbleSyntax* newRoot)
{
    root = newRoot;
}
NimbleSyntax* SyntaxTree::getRoot()
{
    return root;
}

void SyntaxTree::printInOrder(NimbleSyntax* theNode)
{
    if(theNode != 0)
    {
            printInOrder(theNode->getLeft());
            print(theNode);
            printInOrder(theNode->getRight());
            
    }
}

void SyntaxTree::printPostfix(NimbleSyntax* theNode)
{
    if(theNode != 0)
    { 
        printPostfix(theNode->getLeft());
        printPostfix(theNode->getRight());
        print(theNode);
    }
}

void SyntaxTree::printPrefix(NimbleSyntax* theNode)
{
    if(theNode != 0)
    {
        print(theNode);
        printPrefix(theNode->getLeft());
        printPostfix(theNode->getRight());
        
    }
}

void SyntaxTree::printPostfix()
{
    printPostfix(root);
}

void SyntaxTree::printInOrder()
{
    printInOrder(root);
}