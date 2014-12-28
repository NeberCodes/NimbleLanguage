/* 
 * File:   ParseTree.cpp
 * Author: danielrigby
 * 
 * Created on December 23, 2014, 11:19 AM
 */

#include "ParseTree.h"

ParseTree::ParseTree()
{
    root = 0;
}
ParseTree::ParseTree(ParseNode* newRoot)
{
    root = newRoot;
}
ParseTree::~ParseTree()
{
    delete root;
}

void ParseTree::deleteNode(ParseNode* node)
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

ParseNode* ParseTree::search(ParseNode* expNode, int theInt)
{
    ParseNode* returnNode = 0;
    ParseNode* node;
    if(expNode->getInt() == theInt)
    {
        return expNode;
    }
    if(node->getLeft() != 0)
    {
        returnNode = search(node->getLeft(), theInt);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    if(node->getRight() != 0)
    {
        returnNode = search(node->getRight(), theInt);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    return 0;
}

ParseNode* ParseTree::search(ParseNode* expNode, double theDouble)
{
    ParseNode* returnNode = 0;
    ParseNode* node;
    if(expNode->getDouble() == theDouble)
    {
        return expNode;
    }
    if(node->getLeft() != 0)
    {
        returnNode = search(node->getLeft(), theDouble);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    if(node->getRight() != 0)
    {
        returnNode = search(node->getRight(), theDouble);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    return 0;
}

ParseNode* ParseTree::search(ParseNode* expNode, string theString)
{
    ParseNode* returnNode = 0;
    ParseNode* node;
    if(expNode->getString() == theString)
    {
        return expNode;
    }
    if(node->getLeft() != 0)
    {
        returnNode = search(node->getLeft(), theString);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    if(node->getRight() != 0)
    {
        returnNode = search(node->getRight(), theString);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    return 0;
}
ParseNode* ParseTree::search(ParseNode* expNode, char theSymbol)
{
    ParseNode* returnNode = 0;
    ParseNode* node;
    if(expNode->getSymbol() == theSymbol)
    {
        return expNode;
    }
    if(node->getLeft() != 0)
    {
        returnNode = search(node->getLeft(), theSymbol);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    if(node->getRight() != 0)
    {
        returnNode = search(node->getRight(), theSymbol);
        if(returnNode != 0)
        {
            return returnNode;
        }
    }
    return 0;
}
void ParseTree::insertLeft(ParseNode* theNode, ParseNode* newNode)
{
    if(root == 0)
        root = newNode;
    else
        theNode->setLeft(newNode);
}
void ParseTree::insertRight(ParseNode* theNode, ParseNode* newNode)
{
    if(root == 0)
        root = newNode;
    else
        theNode->setRight(newNode);
}

void ParseTree::setRoot(ParseNode* newRoot)
{
    root = newRoot;
}
ParseNode* ParseTree::getRoot()
{
    return root;
}

void ParseTree::printInOrder(ParseNode* theNode)
{
    if(theNode != 0)
    {
            printInOrder(theNode->getLeft());
            print(theNode);
            printInOrder(theNode->getRight());
            
    }
}

void ParseTree::printPostfix(ParseNode* theNode)
{
    if(theNode != 0)
    { 
        printPostfix(theNode->getLeft());
        printPostfix(theNode->getRight());
        print(theNode);
    }
}

void ParseTree::printPrefix(ParseNode* theNode)
{
    if(theNode != 0)
    {
        print(theNode);
        printPrefix(theNode->getLeft());
        printPostfix(theNode->getRight());
        
    }
}

void ParseTree::printPostfix()
{
    printPostfix(root);
}

void ParseTree::printInOrder()
{
    printInOrder(root);
}
