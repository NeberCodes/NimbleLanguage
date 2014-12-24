/* 
 * File:   Parser.cpp
 * Author: Daniel Rigby
 * 
 * Created on December 23, 2014, 10:23 AM
 */

#include "Parser.h"
#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;

Parser::Parser()
{
    data = "";
    block = 0;
}

Parser::Parser(string newData)
{
    data = newData;
    block = 0;
}

Parser::~Parser()
{
    data = '\0';
    delete block;
}
void Parser::loadData(string newData)
{
    data = newData;
}
//Parses the local string data and returns as a Parse Tree
//Probably faster to do with linked list, for future implementations
//Also can create a functions or possibly new class to handle repetitive code
//for each check
ParseBlock* Parser::parse()
{
    block = new ParseBlock();
    
    int parseCount = 0;
    string* curString = new string("");
    curString = new string("");
    int count = 1;
    char cur = 0, prev = 0;
    //Parse string data into parse tree
    for(int i = 0; i < data.length(); i++)
    {
        bool doContinue = false;
        cur = data.at(i);
        //check for brackets and start string again if found
        for(int j = 0; j < BRACKETS_LENGTH; j++)
        {
            if(cur == BRACKETS[j])
            {
                doContinue = block->handleElement(cur, &curString, count, false);
                break;
            }     
        }
        //check for delimiter and start string again if found
        for(int j = 0; j < DELIMITERS_LENGTH; j++)
        {
            if(cur == DELIMITERS[j])
            {
                doContinue = block->handleElement(cur, &curString, count, false);
                break;
            }     
        }
        if(doContinue)
        {
            doContinue = false;
            continue;
        }
        //check for operator
        if(!(prev == '+' || prev == '-') && !(cur == '+' || cur == '-'))
        {
            for(int j = 0; j < OPERATORS_LENGTH; j++)
            {
                if(cur == OPERATORS[j])
                {
                    doContinue = block->handleElement(cur, &curString, count, false);
                    break;
                }     
            }
            if(doContinue)
            {
                doContinue = false;
                continue;
            }
        }
        
        //check for symbols
        for(int j = 0; j < SYMBOLS_LENGTH; j++)
        {
            if(cur == SYMBOLS[j])
            {
                doContinue = block->handleElement(cur, &curString, count, false);
                break;
            }     
        }
        if(doContinue)
        {
            doContinue = false;
            continue;
        }
        
        if(cur == ' ')
        {
            if(block->getNode()->getSymbol() != '"')
            {
                block->handleElement(cur, &curString, count, false);
                continue;
            }
        }
        
        //encounter new line just prevent code from appending the newline
        if(cur == '\n')
        {
            count++;
            continue;
        }
        //continue appending characters to string as no checks were hit
        char appendString[2] = {cur, '\0'};
        *curString += appendString;
        if((i + 1) < data.length())
        {
            if(isToken(data.at(i+1)))
            {
                block->handleElement(0, &curString, count, false);
            }
        }
        prev = cur;
    }
    if(!curString->empty())
    {
        block->handleElement(0, &curString, count, true);
    }
    
    return block;
}
ParseBlock* Parser::parse(string newData)
{

    return block;
}

bool Parser::isToken(char c)
{
    //check for brackets and start string again if found
        for(int j = 0; j < BRACKETS_LENGTH; j++)
        {
            if(c == BRACKETS[j])
            return true;    
        }
        //check for delimiter and start string again if found
        for(int j = 0; j < DELIMITERS_LENGTH; j++)
        {
            if(c == DELIMITERS[j])
            return true;  
        }
        //check for operator
        for(int j = 0; j < OPERATORS_LENGTH; j++)
        {
            if(c == OPERATORS[j])
                return true;
        }
        //check for symbols
        for(int j = 0; j < SYMBOLS_LENGTH; j++)
        {
            if(c == SYMBOLS[j])
                return true;
        }
        
        if(c == ' ')
        {
            if(block->getNode()->getSymbol() != '"')
            {
                return true;
            }
        }
        return false;
}