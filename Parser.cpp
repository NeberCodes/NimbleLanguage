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
    delete block;;
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
    //Count Number of lines, number of parse elements
//    for(int i = 0; i < data.length(); i++)
//    {
//        char cur = data.at(i);
//        //check for delimiter and start string again if found
//        for(int j = 0; j < DELIMITERS_LENGTH; j++)
//        {
//            if(cur == DELIMITERS[j])
//            {
//                if(curString->length() > 0)
//                    parseCount+= 2;
//                else
//                    parseCount++;
//                curString = new string("");
//                continue;
//            }     
//        }
//        //check for operator
//        //Handle operators by storing numbers in separate nodes then joining
//        //them together once it reaches next symbol
//        for(int j = 0; j < OPERATORS_LENGTH; j++)
//        {
//            if(cur == OPERATORS[j])
//            {
//                if(curString->length() > 0)
//                    parseCount+= 2;
//                else
//                    parseCount++;
//                //curString = new string("");
//                *curString = "";
//                continue;
//            }     
//        }
//            //check for operator
//        for(int j = 0; j < SYMBOLS_LENGTH; j++)
//        {
//            if(cur == SYMBOLS[j])
//            {
//                if(curString->length() > 0)
//                    parseCount+= 2;
//                else
//                    parseCount++;
//                curString =  new string("");
//                continue;
//            }     
//        }
//        if(cur == ' ')
//        {
//            if(block->getNode()->getSymbol() != '\"')
//            {
//                if(curString->length() > 0)
//                    parseCount+= 2;
//                else
//                    parseCount++;
//                *curString =  "";
//                continue;
//            }
//        }
//        //encounter new line just prevent code from appending the newline
//        if(cur == '\n')
//            continue;
//        //continue appending characters to string as no checks were hit
//        char appendString[1] = {cur};
//        //*curString += appendString;
//        
//    }
    curString = new string("");
    //Parse string data into parse tree
    for(int i = 0, count = 1; i < data.length(); i++)
    {
        bool doContinue = false;
        char cur = data.at(i);
        //check for delimiter and start string again if found
        for(int j = 0; j < DELIMITERS_LENGTH; j++)
        {
            if(cur == DELIMITERS[j])
            {
                cout<<"Delimiter"<<endl;
                doContinue = block->handleElement(cur, curString, count, false);
                break;
            }     
        }
        if(doContinue)
        {
            doContinue = false;
            continue;
        }
        //check for operator
        for(int j = 0; j < OPERATORS_LENGTH; j++)
        {
            if(cur == OPERATORS[j])
            {
                cout<<"Operator"<<endl;
                doContinue = block->handleElement(cur, curString, count, true);
                break;
            }     
        }
        if(doContinue)
        {
            doContinue = false;
            continue;
        }
        
        //check for symbols
        for(int j = 0; j < SYMBOLS_LENGTH; j++)
        {
            if(cur == SYMBOLS[j])
            {
                cout<<"Symbol "<<cur<<endl;
                doContinue = block->handleElement(cur, curString, count, false);
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
                cout<<"Whitespace"<<endl;
                block->handleElement(cur, curString, count, false);
                //curString = new string("");
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
        char appendString[1] = {cur};
        cout<<"CurString: "<<*curString<<endl;
        *curString += appendString;

    }
    return block;
}
ParseBlock* Parser::parse(string newData)
{

    return block;
}