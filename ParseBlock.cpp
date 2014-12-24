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
    parseTree = new ParseTree();
    countTree = new ParseTree();
}
ParseBlock::~ParseBlock()
{
    delete countNode;
    delete newNode;
    delete tempNode;
    delete tempNodeTwo;
    delete parseTree;
    delete countTree;
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
bool ParseBlock::handleElement(char cur, string* *curString, int count, bool isOperator)
{
    countNode = new ParseNode(count);
    //keep track of numbers and strings if they exist and insert them
    if(!(*curString)->empty())
    {
        if(isNumber(**curString))
        {
            if(tempNode != 0)
            {
                parseTree->insertRight(node, tempNode);
                countTree->insertRight(curCountNode, tempNodeTwo);
            }
            tempNode = new ParseNode(atoi((*curString)->c_str()));
            tempNodeTwo = new ParseNode(count);
        }
        else
        {
            if(tempNode != 0)
            {
                parseTree->insertRight(node, tempNode);
                countTree->insertRight(curCountNode, tempNodeTwo);
            }
            tempNode= new ParseNode(**curString);  
            tempNodeTwo = new ParseNode(count); 
        }
    }
    if(!isOperator && !(*curString)->empty())
    {
        parseTree->insertLeft(node, tempNode);
        countTree->insertLeft(curCountNode, tempNodeTwo);
        node = tempNode;
        curCountNode = tempNodeTwo;
        tempNode = 0;
        tempNodeTwo = 0;
        
    }
    newNode = new ParseNode(cur);
    parseTree->insertLeft(node, newNode);
    countTree->insertLeft(curCountNode, countNode);
    node = newNode;
    curCountNode = countNode;
    //when symbol is not an operator add the stored node to the right

    *curString = new string("");
    return true;
}

bool isNumber(const std::string s)
{
    std::string::const_iterator it = s.begin();
    while (it != s.end() && std::isdigit(*it)) ++it;
    return !s.empty() && it == s.end();
}