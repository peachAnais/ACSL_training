//ACSL 2004 - 2005

/*
This game is from the book On Numbers and Games by John Conway (Academic Press, 1976).

PROBLEM: Given a sequence of digits, modify the sequence by:

1.  Deleting a all zeros, if any, and all the digits to the left of them
2.  Changing a digit to a value less than that digit (by some set of rules).  No negatives allowed.

In a real game the player who removes the last digit loses.

For this program, given the sequence, in one move remove all the zeros, if any, and all the digits to their left.  Then find the digit that appears most frequently.  Use the rightmost
occurrence of that digit, and if it is even subtract 2 from it or if it is odd subtract 1 from it. If two or more digits tie as the most frequent digit, then use the largest such digit.  If all the digits appear just once, use the largest digit.  Repeat the application of the rules to the sequence.  How many moves were required to delete the sequence?  Two examples are shown below:

2 0 4 3 2 3 1       5 2 0 3 3 1 1 2
4 3 2 3 1           3 3 1 1 2
4 3 2 2 1           3 2 1 1 2
4 3 2 0 1           3 2 1 1 0
1                   EMPTY
0
EMPTY


INPUT:  There will be 5 lines of input.  Each input will consist of a sequence of positive integers.  The first integer will tell how many integers are in the sequence follow.

OUTPUT:  Print the number of moves required to delete all the digits.

	SAMPLE INPUT						        SAMPLE OUTPUT
	1. 7, 2, 0, 4, 3, 2, 3, 1					1. 6
	2. 8, 5, 2, 0, 3, 3, 1, 1, 2				2. 4
	3. 5, 0, 6, 6, 0, 4						    3. 4
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;


void main() {

}