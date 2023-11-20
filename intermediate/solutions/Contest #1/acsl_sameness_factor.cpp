//ACSL 2019 - 2020

/*
PROBLEM: Given 2 strings, separated by a space, calculate the ACSL Sameness Factor (ASF). Repeat
the following 3 steps in order until no other deleting aligns like characters:

● Align the strings from left to right.

● Delete the like characters in the like locations from left to right.

● Proceeding from left to right, if the like location characters are not the same and deleting
a character at a location in one of the strings which shifts the remaining characters to the
left causes like characters to be at that location, delete those characters and any other like
characters at like locations. If there is a case as in NAPE and ANTI where it is possible
to delete a character at the same location in both strings, then delete it in the second
string. Therefore, the A would be deleted and the NTI shifted to the left.

Calculate the ACSL Sameness Factor by doing the following:
● Calculate the difference in the alphabetic locations from the aligned string characters in
the second string to the string character in the first string. B to D would add 2 to the
ASF. D to B would add -2 to the ASF.
● If there are characters remaining in one of the strings, add the number of those characters
to the ASF.

ex: MYARTLOLLIPOPS MYLARBALLOONS  -> 23
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//string to vector<char>

//vector<char> string

//deletes like chars from like locations

int main(){
    return 0;
}