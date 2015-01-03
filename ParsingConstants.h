/* 
 * File:   ParsingConstants.h
 * Author: Daniel 
 *
 * Created on December 23, 2014, 11:30 AM
 */

#ifndef PARSINGCONSTANTS_H
#define	PARSINGCONSTANTS_H

//Values representing types of node data
const int INT = 0, DOUBLE = 1, FLOAT = 2, STRING = 3, SYMBOL = 4;
const int NONE = 0, OPEN_BRACKETS = 1, CLOSED_BRACKETS = 2;
//List of delimiters, operators and symbols, signs to help with parsing
const char SIGNS[] = {'+', '-'};
const int SIGNS_LENGTH = sizeof(SIGNS) / sizeof(*SIGNS);
const char DELIMITERS[] = {';'};
const int DELIMITERS_LENGTH = sizeof(DELIMITERS) / sizeof(*DELIMITERS);
const char OPERATORS[] = {'+', '-', '*', '/', '^'};
const int OPERATORS_LENGTH = sizeof(OPERATORS) / sizeof(*OPERATORS);
const char SYMBOLS[] = {'{', '}', '[', ']'};
const int SYMBOLS_LENGTH = sizeof(SYMBOLS) / sizeof(*SYMBOLS);
const char BRACKETS[] = {'(', ')'};
const int BRACKETS_LENGTH = sizeof(BRACKETS) / sizeof(*BRACKETS);

#endif	/* PARSINGCONSTANTS_H */

