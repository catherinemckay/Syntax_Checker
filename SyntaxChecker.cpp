/**
*@author Catherine McKay
*2378275
*camckay@chapman.edu
*CPSC350-01
*Assignment 4 - Syntax Checker: File 5 of 5
*@version 1.0
*Syntax Checker Class:
    Checks file for delimiter syntax.
    Informs user of correct syntax or the error that was found
*/

#include "SyntaxChecker.h"
#include "GenStack.h"
#include "DoublyLinkedList.h"
#include <iostream>
#include <fstream>
#include <string>

// Constructor
SyntaxChecker::SyntaxChecker(){}

// Destructor
SyntaxChecker::~SyntaxChecker(){}

/* checkSyntax():
    Takes file from parameter,
    checks one line at a time for delimiters,
    Calls appropriate method for correct or incorrect syntax found
*/
int SyntaxChecker::checkSyntax(string file){
    ifstream inFS;
    inFS.open(file);
    string line;

    while(getline(inFS, line)){
        lineNum++;
        if(!checkLine(line)){
            incorrectSyntaxFound(); // when error is found in middle of file
            return -1;
        }
    }

    // End of file is met:
    if(stack->isEmpty()){
        correctSyntaxFound();
    }else{
        missingDelimiter();
    }

    inFS.close();
    return 1;
}

/* checkLine():
    Takes in a single line to check for delimiters,
    pushes open delimiters to stack,
    if closed delmiter found, checks if it the correct one
    returns true if line is okay, false if error was found
*/
bool SyntaxChecker::checkLine(string line){
    for(int i = 0; i <= line.length(); ++i){
        if(line[i] == '/' && line[i+1] == '/' || line[i] == '#'){ //to avoid comments
            return true;
        } else if(line[i] == '(' || line[i] == '{' || line[i] == '['){ // if open delim found:
            stack->push(line[i]);
            return true;
        } else if(line[i] == ')' || line[i] == '}' || line[i] == ']'){ // if closed delim found:
            setClosedDelim(line[i]);
            if(!checkDelimiter(line[i])){
                return false; // if they dont match
            } else{
                return true; // if they do match
            }
        }
    }
    return true;
}

/* checkDelimiter():
    Passes in closed delimiter,
    checks if current delimiter matches last element popped off stack,
    returns false if delimiters don't match, true if they do match
*/
bool SyntaxChecker::checkDelimiter(char c){
    setOpenedDelim(stack->pop());
    if(delimiterMatch(c) != getOpenedDelim()){
        return false;
    } else{
        return true;
    }
}

/* delimiterMatch():
    returns whatever the matching delimiter is to the passed in param
*/
char SyntaxChecker::delimiterMatch(char c){
    switch(c){
        case ')':
            return '(';
            break;
        case '}':
            return '{';
            break;
        case ']':
            return '[';
            break;
        case '(':
            return ')';
            break;
        case '{':
            return '}';
            break;
        case '[':
            return ']';
            break;
    }
}

/* correctSyntaxFound():
    Tells user the file had correct syntax,
    asks if they want to proceed to check another file
*/
void SyntaxChecker::correctSyntaxFound(){
    int userChoice;
    string fileName;
    cout << "Delimiter syntax was correct." << endl;
    cout << "Would you like to check the syntax for another file?" << endl;
    cout << "1 yes" << endl;
    cout << "2 no" << endl;
    cin >> userChoice;
    if(userChoice == 1){
        cout << "What is the name of the source code file you would like to check now?" << endl;
        cin >> fileName;
        checkSyntax(fileName);
    } else if(userChoice == 2){
        cout << "Goodbye." << endl;
    }
}

/* incorrectSyntaxFound():
    Tells user line num the error was found on
    and what delimiter was misisng
*/
void SyntaxChecker::incorrectSyntaxFound(){
    cout << "SYNTAX ERROR FOUND: " << endl;
    cout << "Line " << getLineNum() << ": expected " << delimiterMatch(getOpenedDelim()) << " but found " << getClosedDelim() << endl;

}

/* missingDelimiter():
    This method is only called when end of file was reached, and
    stack was not empty, therefore a closing delimiter was missing
*/
void SyntaxChecker:: missingDelimiter(){
    cout << "Reached end of file: missing " << delimiterMatch(stack->pop()) << endl;
}

// Accessor for line number
int SyntaxChecker::getLineNum(){
    return lineNum;
}

// Mutator for last opened delimiter
void SyntaxChecker::setOpenedDelim(char c){
    openedDelim = c;
}

// Acessor for last opened delimiter
char SyntaxChecker::getOpenedDelim(){
    return openedDelim;
}

// Mutator for last closed delimiter
void SyntaxChecker::setClosedDelim(char c){
    closedDelim = c;
}

// Acessor for last closed delimiter
char SyntaxChecker::getClosedDelim(){
    return closedDelim;
}
