//  stringCalculator.h
//  stringCalculator
//  For CS 372 HW2
//  Created by Chenyi Ling on 3/11/20.

#ifndef stringCalculator_h
#define stringCalculator_h

#include <iostream>
#include <vector>
using std::vector;
#include <regex>
using std::regex;
using std::smatch;
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

vector<int> extractNum(string str){
  regex r("([-]|[0-9]+)");
  std::vector<int> results;
  for(std::sregex_iterator i = std::sregex_iterator(str.begin(), str.end(), r);
      i != std::sregex_iterator();
      i++)
     {
         smatch m = *i;
         results.push_back(std::stoi( m[1].str().c_str() ));
     }
    return results;
}

int strVal (string str){
    int value = 0;
    if (isEmptyInput(str)){
        return value;
    }
    else
    {
        vector<int> numVec = extractNum(str);
        
        for (auto n : numVec){
            
            try{
                if(n < 0){
                    throw n;
                    std::cout<<"negative number! \n";
                }
                else if (n > 1000){
                    continue;
                }
            }
            catch (int n){
                std::cout<<"Exception caught! \n";
            }
            value += n;
        }
    }
    return value;
}



#endif /* stringCalculator_h */
