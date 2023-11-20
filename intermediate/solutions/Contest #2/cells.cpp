//ACSL 2012 - 2013

/*
PROBLEM:  The ACSL cell always has 8-character bits.  The bits are always some combination of A, B, C, D, E, F, G, and H. The cell performs operations as listed below:  
DIVIDE – The cell divides into two cells with one cell taking the first four bits and the second cell taking the last four bits.  Then each partial cell replicates and concatenates to get 
back to 8 bits each.  
e.g.  DIVIDE ABCDEFGH becomes ABCDABCD and EFGHEFGH

ADDn - The first n (0 ≤ n ≤ 4) bits replicate and are concatenated to the first n bits.  The last n bits are deleted
e.g. ADD3 ABCDEFGH becomes ABCABCDE

SUBTRACTn - The first n (0 ≤ n ≤ 4) bits are deleted and the last n bits replicate and are concatenated on the right.
e.g. SUBTRACT3 ABCDEFGH becomes DEFGHFGH

UNION - Two cells become one by deleting the first four bits of the first cell and the last four bits of the second cell. The remaining bits of the second cell are concatenated to the right of the remaining bits of the first cell.  
		e.g.  UNION ABCDEFGH, AABBCCDD becomes EFGHAABB

INTERSECT - Two cells become one by deleting the middle four bits of the first cell and the middle four bits of the second cell. The remaining bits of the second cell are concatenated to the right of the remaining bits of the first cell.  
		e.g.  INTERSECT ABCDEFGH, AABBCCDD becomes  ABGHAADD

SAMPLE INPUT						        SAMPLE OUTPUT
1.   DIVIDE, ABBCDFGG					    1.  ABBCABBC and DFGGDFGG
2.   ADD2, ABBCDFGG					        2.  ABABBCDF
3.   SUBTRACT1, ABBCDFGG	    			3.  BBCDFGGG
4.   UNION, ABBCDFGG, DEFABCGH    			4.  DFGGDEFA
5.   INTERSECT, ABBCDFGG, DEFABCGH			5.  ABGGDEGH

*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void divide() {

}

void add_n() {

}

void subtract_n() {

}

void union() {

}

void intersect() {
    
}


int main() {
    return 0;
}