//  stringCalculator.h
//  stringCalculator
//  For CS 372 HW2
//  Created by Chenyi Ling on 3/11/20.

#ifndef stringCalculator_h
#define stringCalculator_h

#include <iostream>
#include <regex>
using std::regex;
#include <string>
using std::string;

bool isEmptyInput (string str){
    int index;
    char letter;
       
    for (index = 0; index < str.length(); index++){
           letter = str[index];
        if(!isspace(letter)){
            return false;
        }
        else
            continue;
    }
    return true;
}

string extractNum (string str){
    string strExtracted;
    regex regNum ("[^0-9]*([0-9]+).*");
    strExtracted = std::regex_replace(str, regNum, "$1");
    return strExtracted;
}

unsigned long strVal (string str){
    unsigned long value;
    if (isEmptyInput(str)){
        value = 0;
    }
    else
    {
        string strNew = extractNum(str);
        value = stoi(strNew);
    }
        
    return value;
}

#endif /* stringCalculator_h */
