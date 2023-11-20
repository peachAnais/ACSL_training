//ACSL 2006-2007
/*
PROBLEM:  Red marbles and Blue marbles are placed in a bag.  One or more is selected without looking in the bag.  Find the probability of that event occurring.  In this program you will 
have 4 cases to examine:

Case 1: Just one marble is selected.  As an example if 8 Red marbles and 2 Blue marbles are placed in the bag, what is the probability of selecting a Red marble?  The definition of
probability states the answer is found by counting the number of ways a Red marble can occur and dividing by the total number of possible outcomes.  This answer is .

Case 2:  Two marbles are selected with the first being replaced before the second is drawn.  As an example if 8 Red marbles and 2 Blue marbles are placed in the bag, what is the 
probability of selecting a Red and a Blue in that order?  By replacing the first marble, the two events are independent.  That is the selection of the first marble does not affect
the probability of the selecting the second marble.  The answer is found by multiplying the probability of the 2 events:  .

Case 3:  Two marbles are selected but this time the first marble is not replaced before the second is drawn.  As an example if 8 Red marbles and 2 Blue marbles are placed in the bag,
what is the probability of selecting a Red and a Blue in that order?  By not replacing the first marble, the two events are not independent.  That is the selection of the first marble 
does affect the probability of the selecting the second marble.  The answer is found by multiplying the probability of the 2 events:  .

Case 4:  Using the probability of NOT Red ( r ) or NOT Blue ( b ) in any of the above.   NOT Red is equal to 1 minus the probability of Red.  As an example if 8 Red marbles and 2 Blue 
marbles are placed in the bag, what is the probability of selecting, with replacement, a NOT Red and a NOT Blue in that order?  The answer is found by multiplying the probability of the
2 events: 

1.  1, 8, 2, R						    1.  8/10
2.  2, 8, 2, N, R, B					2.  16/90
3.  2, 8, 2, Y, R, B					3.  16/100
4.  2, 8, 2, Y, r, b					4.  16/100
5.  2, 8, 2, Y, R, r					5.  16/100
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

//get data

//case 1
void solve_case1(vector<int> data){

}

//case 2
void solve_case2(vector<int> data){

}

//case 3
void solve_case3(vector<int> data){

}

//case 4
void solve_case4(vector<int> data){

}

//solve
void solve(){

}

int main(){

    ifstream file("probability.in");


    return 0;
}