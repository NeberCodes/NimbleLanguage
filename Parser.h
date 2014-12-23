/* 
 * File:   Parser.h
 * Author: danielrigby
 *
 * Created on December 23, 2014, 10:23 AM
 */

#ifndef PARSER_H
#define	PARSER_H

#include <string>

using namespace std;

const char DELIMITERS[] = {';', ' '};
const char OPERATORS[] = {'+', '-', '*', '/'};
const char SYMBOLS[] = {'{', '}', '(', ')', '[', ']'};

class Parser 
{
public:
    Parser();
    ~Parser();
private:
    string data;
};

#endif	/* PARSER_H */

