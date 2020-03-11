//
//  stringCalculator.h
//  stringCalculator
//
//  Created by Chenyi Ling on 3/11/20.
//  Copyright © 2020 Chenyi Ling. All rights reserved.
//

#ifndef stringCalculator_h
#define stringCalculator_h


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

int strVal (string str){
    int value;
    if (isEmptyInput(str)){
        value = 0;
    }
    else
        value = str.length();

    return value;
}

#endif /* stringCalculator_h */
