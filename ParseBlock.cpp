/* 
 * File:   ParseBlock.cpp
 * Author: danielrigby
 * 
 * Created on December 23, 2014, 5:38 PM
 */

#include "ParseBlock.h"
#include <iostream>

using namespace std;

ParseBlock::ParseBlock()
{
    countNode = 0;
    newNode = 0;
    tempNode = 0;
    tempNodeTwo = 0;
    curCountNode = 0;
    lastNode = 0;
    lastCountNode = 0;
    signedNode = 0;
    signedCountNode = 0;
    bottomNode = 0;
    bottomCountNode = 0;
    isFirst= true;
    isNil = true;
    parseTree = new ParseTree();
    countTree = new ParseTree();
}
ParseBlock::~ParseBlock()
{
//    delete countNode;
//    delete newNode;
//    delete tempNode;
//    delete tempNodeTwo;
//    delete parseTree;
//    delete countTree;
//    delete lastNode;
//    delete lastCountNode;
}

ParseNode* ParseBlock::getNode()
{
    return node;
}
ParseNode* ParseBlock::getCountNode()
{
    return countNode;
}
ParseNode* ParseBlock::getNewNode()
{
    return newNode;
}
ParseNode* ParseBlock::getTempNode()
{
    return tempNode;
}
ParseNode* ParseBlock::getTempNodeTwo()
{
    return tempNodeTwo;
}
ParseNode* ParseBlock::getCurCountNode()
{
    return curCountNode;
}
ParseTree* ParseBlock::getParseTree()
{
    return parseTree;
}
ParseTree* ParseBlock::getCountTree()
{
    return countTree;
}

void ParseBlock::setNode(ParseNode* newNode)
{
    node = newNode;
}
void ParseBlock::setCountNode(ParseNode* newCountNode)
{
    countNode = newCountNode;
}
void ParseBlock::setNewNode(ParseNode* newNewNode)
{
    newNode = newNewNode;
}
void ParseBlock::setTempNode(ParseNode* newTempNode)
{
    tempNode = newTempNode;
}
void ParseBlock::setTempNodeTwo(ParseNode* newTempNodeTwo)
{
    tempNodeTwo = newTempNodeTwo;
}
void ParseBlock::setCurCountNode(ParseNode* newCurCountNode)
{
    curCountNode = newCurCountNode;
}

//handles when a new element is encountered when parsing and adds it to the
//parse tree
bool ParseBlock::handleElement(char cur, string* *curString, int count, bool lastElem, int &brackets)
{
    countNode = new ParseNode(count);
    //keep track of numbers and strings if they exist and insert them
    cout<<"1"<<endl;
    if(!(*curString)->empty())
    {
        if(isNumber(**curString))
        {
            tempNode = new ParseNode(atoi((*curString)->c_str()));
            tempNodeTwo = new ParseNode(count);
        }
        else
        {
            tempNode= new ParseNode(**curString);  
            tempNodeTwo = new ParseNode(count); 
        }
    }
    cout<<"2"<<endl;
    if(cur != 0)
    {
        newNode = new ParseNode(cur);
        cout<<"Adding new symbol: "<<cur<<endl;
        if(node != 0)
        {
            if(brackets)
            {
                //if isFirst is true then add to top of tree
                //else add to right of current node
                if(!isFirst)
                {
                    isFirst = true;
                }
                else
                {
                    cout<<"Set bottom node"<<endl;
                    isFirst = false;
                    brackets = NONE;
                    bottomNode = newNode;
                    bottomCountNode = countNode;
                }
                if(isFirst)
                {
                    cout<<"Inserting as new root(brackets): "<<cur<<endl;
                    parseTree->setRoot(newNode);
                    countTree->setRoot(countNode);
                    cout<<"Fixing up old to left: ";
                    print(node);
                    cout<<endl;
                    parseTree->insertLeft(newNode, node);
                    countTree->insertLeft(countNode, curCountNode);
                }
                else
                {
                    cout<<"Adding to the right: "<<cur<<endl;
                    parseTree->insertRight(node, newNode);
                    countTree->insertRight(curCountNode, countNode);
                }
                node = newNode;
                curCountNode = countNode;
            }
            else
            {
                cout<<"Adding to the left: "<<cur<<endl;
                parseTree->insertLeft(newNode, node);
                countTree->insertLeft(countNode, curCountNode);
                parseTree->setRoot(newNode);
                countTree->setRoot(countNode);
                if(isFirst)
                {
                    cout<<"DOES THIS EVER HAPPEN"<<endl;
                    bottomNode = node;
                    bottomCountNode = curCountNode;
                }
                node = newNode;
                curCountNode = countNode;
            }
        }
        else
        {
            parseTree->insertLeft(node, newNode);
            countTree->insertLeft(curCountNode, countNode);
            node = newNode;
            curCountNode = countNode;
            bottomNode = node;
            bottomCountNode = curCountNode;
        }
        if(!node->isNotOperator())
        {
            isNil = false;
        }
        else
        {
            isNil = true;
        }
    }
    cout<<"3"<<endl;
    if(node != 0)
    {
        //if((!isNil || lastElem) && tempNode != 0)
        if( tempNode != 0)
        {
            //check if it's a signed number if so add to the left
            cout<<"Adding: ";
            print(tempNode);
            cout<<endl;
            if((node->getRight()) == 0 && !isFirst)
            {
                cout<<"Adding to the right"<<endl;
                parseTree->insertRight(node, tempNode);
                countTree->insertRight(curCountNode, tempNodeTwo);
                tempNode = 0;
                tempNodeTwo = 0;
            }
            else
            {
                if(bottomNode != 0)
                {
                    cout<<"Adding first to left: "<<endl;
                    print(bottomNode);
                    cout<<endl;
                    parseTree->insertLeft(bottomNode, tempNode);
                    countTree->insertLeft(bottomCountNode, tempNodeTwo);
                    bottomNode = 0;
                    bottomCountNode = 0;
                    isFirst = false;
                    tempNode = 0;
                    tempNodeTwo = 0;
                }
                else if(lastElem)
                {
                    cout<<"Adding to the right"<<endl;
                    parseTree->insertRight(node, tempNode);
                    countTree->insertRight(curCountNode, tempNodeTwo);
                    tempNode = 0;
                    tempNodeTwo = 0;
                }
            }
        }
    }
    else
    {
        if(lastElem)
        {
            parseTree->insertRight(node, tempNode);
            countTree->insertRight(curCountNode, tempNodeTwo);
        }
    }
    
    *curString = new string("");
    return true;
}

bool isNumber(const std::string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}