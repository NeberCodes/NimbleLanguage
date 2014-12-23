/* 
 * File:   ExpressionTree.cpp
 * Author: danielrigby
 * 
 * Created on December 23, 2014, 9:12 AM
 */

#include "ExpressionTree.h"

ExpressionTree::ExpressionTree()
{
    root = 0;
}
ExpressionTree::ExpressionTree(ExpressionNode* newRoot)
{
    root = newRoot;
}
ExpressionTree::~ExpressionTree()
{
    delete root;
}
ExpressionNode* ExpressionTree::search(ExpressionNode* expNode, int theInt)
{
    ExpressionNode* returnNode = 0;
    ExpressionNode* node;
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

ExpressionNode* ExpressionTree::search(ExpressionNode* expNode, double theDouble)
{
    ExpressionNode* returnNode = 0;
    ExpressionNode* node;
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

ExpressionNode* ExpressionTree::search(ExpressionNode* expNode, string theString)
{
    ExpressionNode* returnNode = 0;
    ExpressionNode* node;
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
ExpressionNode* ExpressionTree::search(ExpressionNode* expNode, char theSymbol)
{
    ExpressionNode* returnNode = 0;
    ExpressionNode* node;
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
void ExpressionTree::insertLeft(ExpressionNode* theNode, ExpressionNode* newNode)
{
    theNode->setLeft(newNode);
}
void ExpressionTree::insertRight(ExpressionNode* theNode, ExpressionNode* newNode)
{
    theNode->setRight(newNode);
}

void ExpressionTree::setRoot(ExpressionNode* newRoot)
{
    root = newRoot;
}
ExpressionNode* ExpressionTree::getRoot()
{
    return root;
}

void ExpressionTree::printInOrder(ExpressionNode* theNode)
{
    if(theNode != 0)
    {
        if(theNode->isBrace())
        {
            print(theNode);
            printInOrder(theNode->getRight());
        }
        else
        {
            printInOrder(theNode->getRight());
            print(theNode);
        }
        
        printPrefix(theNode->getLeft());
        
    }
}

void ExpressionTree::printPostfix(ExpressionNode* theNode)
{
    if(theNode != 0)
    { 
        printPostfix(theNode->getLeft());
        printPostfix(theNode->getRight());
        print(theNode);
    }
}

void ExpressionTree::printPrefix(ExpressionNode* theNode)
{
    if(theNode != 0)
    {
        print(theNode);
        printPostfix(theNode->getRight());
        printPrefix(theNode->getLeft());
    }
}

void ExpressionTree::printPostfix()
{
    printPostfix(root);
}

void ExpressionTree::printInOrder()
{
    printInOrder(root);
}