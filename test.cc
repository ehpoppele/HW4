//Slides in class said we should include tests for all subsequent programs we write. I wasn't sure if this was included but I decided to try anyways
//In any case, this test isn't very great because it only tests to make sure the function gridpi is producing the same outputs, so if the program were
//Modified so that it calculates pi more accurately, it would fail the test. However, we could change this fairly easily by making a new test checking
//For ouputs between the ones given here and a more accurate calculation of pi, something like 3.14159265 etc.

#define CATCH_CONFIG_MAIN //My experience shows we need to let catch define a main to let things work, so we let that happen here
#include "gridpi.cc" //And then we include only the function we seek to test so that we don't have any conflicting definitions of main
#include "catch.hpp" //Include the testing frame work

TEST_CASE( "Estimations of Pi are calculated", "[gridpi]" ) {//Tests the girdpi function for a few of its outputs
    REQUIRE( gridpi(10) == 2.92 );
    REQUIRE( gridpi(500) == 3.136784 ); //This varies slightly from what will actually print with my pi program running 500; some rounding occurs somewhere between gridpi computing and main printing that I can't identify.
    REQUIRE( gridpi(10000) == 3.141361 ); //Same applies to this; my program prints 3.141361, as described in the README, but I trust that Catch is calling my function more directly.
}