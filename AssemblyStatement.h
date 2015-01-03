/* 
 * File:   AssemblyStatement.h
 * Author: danielrigby
 *
 * Created on December 30, 2014, 4:19 PM
 */

#ifndef ASSEMBLYSTATEMENT_H
#define	ASSEMBLYSTATEMENT_H

class AssemblyStatement 
{
public:
    AssemblyStatement(bool, int, int, int);
    ~AssemblyStatement();
    bool getPrestatement();
    int getStatement();
    int getFirstArgument();
    int getSecondArgument();
private:
    bool prestatement;
    int statement;
    int firstArgument, secondArgument;
};

#endif	/* ASSEMBLYSTATEMENT_H */

