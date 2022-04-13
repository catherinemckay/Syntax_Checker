/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 4 - Syntax Checker: File 4 of 5
*@version 1.0
*Syntax Checker Class - Header File
*/

#ifndef SYNTAXCHECKER_H
#define SYNTAXCHECKER_H
#include <iostream>
#include "GenStack.h"
using namespace std;

class SyntaxChecker{
    public:
        SyntaxChecker();
        ~SyntaxChecker();

        GenStack<char> *stack = new GenStack<char>();

        // public member functions
        int checkSyntax(string file);
        bool checkLine(string line);
        bool checkDelimiter(char c);
        char delimiterMatch(char c);
        void correctSyntaxFound();
        void incorrectSyntaxFound();
        void missingDelimiter();

        // Acessors & Mutators
        int getLineNum();
        void setOpenedDelim(char c);
        char getOpenedDelim();
        void setClosedDelim(char c);
        char getClosedDelim();

    private:
        int lineNum;
        // To keep track of last delimiter popped onto stack:
        char openedDelim;
        // To keep track of last closed delimiter found:
        char closedDelim;

};

#endif
