//ACSL 2001 - 2002

/*
PROBLEM:  This is yet another in a long list of ACSL code programs.  You would think we would have run out of them by now.  In this program you will be given a set of letters to encode.  
The difference here is that different rules are used for different letters and the counting process starts where the last letter ends. Using the numerical value of each letter (
A=1, B=2, … Z= 26) the rules are as follows: 

If the letter is between the given letters, inclusive:
The number of letters to count is given by:
A – E
Multiply its numerical value by 2
F – J
Divide its numerical value by 3.  Multiply the integer remainder by 5
K – O
Divide its numerical value by 4.  Multiply the integer part of the quotient by 8.  
P – T
Multiply the sum of the digits of its numerical value by 10
U- Z
Find the largest integer factor of its numerical value less than the value itself.  Multiply it by 12.

As an example, if the set of letters to encode consists of the letters B, G and Z, then the B with a numerical value of 2 encodes to a 4.  Counting 4 letters from A produces an E.  The G,
with a numerical value of 7, encodes to a 5.  Counting down 5 letters from the E produces the letter J.  The Z with a numerical value of 26 has 13 as its largest factor. Counting 156 
letters ( 12 * 13) has the effect of wrapping around the alphabet 6 complete times and ending at J.  The encoded solution for the letter set B, G, I is E J J.

INPUT:  There will be 5 input lines.  Each will consist of a series of upper case letters and will end with a $.  You may enter the letters one at a time. The commas shown are for 
clarification and do not have to be entered. The $ is not encoded.
*/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//case A - E
char caseA_E(char chars){
    int num_val = int(chars) - 64;
    int new_pos = int(chars) + 2 * num_val;

    return char(new_pos);
} 

//case F - J
char caseF_J(char letter){
    int num_val = int(letter) - 64;
    int new_pos = int(letter) + (num_val / 3) * 5;

    return char(new_pos);
}

//case K - O

//case P - T 

//case U - Z

//solve problem

int main(){
    return 0;
}