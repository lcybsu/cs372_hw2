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

TEST_CASE("TEST 1: An empty string returns zero")
{
    string str1 = "";
    string str2 = "   ";
    string str3 = "     \n   \n     ";

   {
   INFO( "Empty string, no space between quote" );
       int emptyStr1 = strVal(str1);
       REQUIRE( emptyStr1 == 0 );
   }

   {
   INFO( "Empty string, one space between quote" );
       int emptyStr2 = strVal(str2);
       REQUIRE( emptyStr2 == 0 );
   }

   {
   INFO( "Empty string, multi-line space between quote" );
        int emptyStr3 = strVal(str3);
        REQUIRE( emptyStr3 == 0);
   }

}

TEST_CASE("TEST 2: A single number returns the value")
{
    {
    INFO( "Simple int without extra white space" );
        string numStr1 = "99";
        auto testVal1 = stoi(numStr1);
        auto numVal1 = strVal(numStr1);
        REQUIRE( testVal1 == numVal1);
    }
    
    {
    INFO( "Float num without extra white space" );
        string numStr2 = "3.141592698";
        auto testVal2 = stoi(numStr2);
        auto numVal2 = strVal(numStr2);
        REQUIRE( testVal2 == numVal2);
    }
    
    {
    INFO( "Simple int with extra white space before and after" );
        string numStr4 = "    25       ";
        auto testVal4 = stoi(numStr4);
        auto numVal4 = strVal(numStr4);
        REQUIRE( testVal4 == numVal4);
    }
    
    {
    INFO( "Simple int mixed with letters" );
        string numStr5 = " Two   18 point seven";
        auto testVal5 = stoi(numStr5);
        auto numVal5 = strVal(numStr5);
        REQUIRE( testVal5 == numVal5);
    }
}

