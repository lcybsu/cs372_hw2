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
        string numStr1 = "45";
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

TEST_CASE("TEST 3: Two numbers, comma delimited, returns the sum")
{
    {
    INFO( "Two int addition" );
        string numInt1 = "3,8";
        auto addNumInt1 = strVal(numInt1);
        REQUIRE( addNumInt1 == 11 );
    }
    
    {
    INFO( "Two int with space addition" );
        string numInt2 = "12  ,    4";
        auto addNumInt2 = strVal(numInt2);
        REQUIRE( addNumInt2 == 16 );
    }
    
}

TEST_CASE("TEST 4: Two numbers, newline delimited, returns the sum")
{
    {
    INFO( "Two int addition" );
        string numInt1 = "1\n13";
        auto addNumInt1 = strVal(numInt1);
        REQUIRE( addNumInt1 == 14 );
    }
    
    {
    INFO( "Two int with space addition" );
        string numInt2 = "    12 \n   9";
        auto addNumInt2 = strVal(numInt2);
        REQUIRE( addNumInt2 == 21 );
    }
    
}

TEST_CASE("TEST 5: Three numbers, delimited either way, returns the sum")
{
    {
    INFO( "Three int addition delimited with comma" );
        string numInt3 = "2,4,6";
        auto addNumInt3 = strVal(numInt3);
        REQUIRE( addNumInt3 == 12 );
    }
    
    {
    INFO( "Three int addition delimited with newline" );
        string numInt4 = "2\n4\n6\n";
        auto addNumInt4 = strVal(numInt4);
        REQUIRE( addNumInt4 == 12 );
    }
    
}

TEST_CASE("TEST 6: Negative numbers throw an exception")
{
    {
    INFO( "Negative int exception" );
        string negInt1 = "-17";
        REQUIRE_THROWS(strVal(negInt1));
    }
    
}

TEST_CASE("TEST 7: Numbers greater than 1000 are ignored")
{
    
    {
    INFO( "Single number greater than 1000" );
        string largeNum1 = "1500";
        REQUIRE( strVal(largeNum1) == 0);
        REQUIRE_NOTHROW(strVal(largeNum1));
    }
    
    {
    INFO( "One of two numbers is greater than 1000" );
        string largeNum1 = "9999,1";
        REQUIRE( strVal(largeNum1) == 1);
        REQUIRE_NOTHROW(strVal(largeNum1));
    }
    
}

TEST_CASE("TEST 8: A single char delimiter can be defined on the first line ")
{
    {
    INFO( "Self defined '#' delimiter" );
        string selfDefined1 = "1#2#3";
        REQUIRE( strVal(selfDefined1) == 6);
    }
    
    {
    INFO( "Self defined '!' delimiter");
        string largeNum2 = "4!5!6";
        REQUIRE( strVal(largeNum2) == 15);
    }
}

TEST_CASE("TEST 9: A multi char delimiter can be defined on the first line ")
{
    {
    INFO( "Self defined '###' delimiter" );
        string selfDefined1 = "1###2###3";
        REQUIRE( strVal(selfDefined1) == 6);
    }
    
    {
    INFO( "Self defined '!!!' delimiter");
        string selfDefined2 = "4!!!5!!!6";
        REQUIRE( strVal(selfDefined2) == 15);
    }
}


TEST_CASE("TEST 10: Many single or multi-char delimiters can be defined")
{
    {
    INFO( "Self defined '[@@]' delimiter" );
        string selfDefined3 = "1[@@]2[@@]3";
        REQUIRE( strVal(selfDefined3) == 6);
    }
    
    {
    INFO( "Self defined '[%$]' delimiter");
        string largeNum4 = "4[%$]5[%$]6";
        REQUIRE( strVal(largeNum4) == 15);
    }
}
