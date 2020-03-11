//  stringCalculator_test_suites.cpp
//  stringCalculator
//  For CS 372 HW2
//  Created by Chenyi Ling on 3/11/20.
//  Includes for code to be tested
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
       auto emptyStr1 = strVal(str1);
       REQUIRE( emptyStr1 == 0 );
   }

   {
   INFO( "Empty string, one space between quote" );
       auto emptyStr2 = strVal(str2);
       REQUIRE( emptyStr2 == 0 );
   }

   {
   INFO( "Empty string, multi-line space between quote" );
        auto emptyStr3 = strVal(str3);
        REQUIRE( emptyStr3 == 0);
   }

}

TEST_CASE("TEST 2: A single number returns the value")
{
    {
    INFO( "Simple int without extra white space" );
        string numStr1 = "99";
        auto numVal1 = strVal(numStr1);
        REQUIRE( numVal1 == 99);
    }
    
    {
    INFO( "Simple float without extra white space" );
        string numStr1 = "45.37";
        auto numVal1 = strVal(numStr1);
        REQUIRE( numVal1 == 45);
    }
    
    {
    INFO( "Simple int with extra white space before and after" );
        string numStr4 = "    25       ";
        auto numVal4 = strVal(numStr4);
        REQUIRE( numVal4 == 25);
    }
    
    {
    INFO( "Simple int mixed with letters" );
        string numStr5 = "   18 point seven";
        auto numVal5 = strVal(numStr5);
        REQUIRE( numVal5 == 18);
    }
    
    {
    INFO( "Simple int mixed with letters before and after number" );
        string numStr6 = " two  22 point six";
        auto numVal6 = strVal(numStr6);
        REQUIRE( numVal6 == 22);
    }
    
}

