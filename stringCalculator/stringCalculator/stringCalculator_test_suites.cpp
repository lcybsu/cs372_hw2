//
//  stringCalculator_test_suites.cpp
//  stringCalculator
//
//  Created by Chenyi Ling on 3/11/20.
// Includes for code to be tested
#include "stringCalculator.h"
#include "stringCalculator.h"

#define CATCH_CONFIG_FAST_COMPILE
                           // Disable some features for faster compile
#include "catch.hpp"       // For the "Catch" unit-testing framework
#include <string>
using std::string;


// *****************
// Test Cases
// *****************


TEST_CASE( "An empty string returns zero")
{
    string str1 = "";
    string str2 = " ";
    string str3 = "   \n   \n     ";
    
   {
   INFO( "Empty string, no space between quote" );
       int emptyStr1 = strVal(str1);
       int strLength1 = str1.length();
   REQUIRE( strLength1 == emptyStr1 );
   }

   {
   INFO( "Empty string, one space between quote" );
       int emptyStr2 = strVal(str1);
       int strLength2 = str2.length();
   REQUIRE( strLength2 == emptyStr2 );
   }

   {
   INFO( "Empty string, multi-line space between quote" );
        int emptyStr3 = strVal(str1);
       int strLength3 = str3.length();
   REQUIRE( strLength3 == emptyStr3);
   }

}
