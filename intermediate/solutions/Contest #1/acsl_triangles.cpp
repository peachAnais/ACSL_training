/*
ACSL 2007-2008

PROBLEM:  Two triangles are congruent if for some pairing of their sides the lengths of those paired sides are equal.
In the diagram above ∆ ABC is congruent to ∆ EFD.  Note that the length of side AB equals the length of side EF, the length of side BC is equal to the length of side FD and the length 
of side AC is equal to the length of side ED.  This is the pairing of the sides that makes the triangles congruent.

INPUT:  There will be 5 lines of data.  Each line will contain 6 positive rational numbers that represent the lengths of the sides of two triangles. The first 3 numbers are the lengths 
for the first triangle (∆ ABC) in the order AB, BC, AC and the last 3 numbers are the lengths for the second triangle  (∆ DEF) in the order DE, EF, DF.

OUTPUT:  For each data line, print the name of the triangle that is congruent to ∆ ABC.  If no pairing makes the triangles congruent print NONE

example:
SAMPLE INPUT					SAMPLE OUTPUT

1.  2, 3, 4, 2, 3, 4			1.  DEF

*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

//gets data

//gets index of a given value in a vector
int find_value(vector<long> vct, int val){
    for(int i = 0; i< 3; i++){
        if(vct.at(i) == val){
            return i;
        }
    }
    return -1;
}

//return letter for each position
char get_pos_letter(int pos){
    if(pos == 0){
        return 'D';
    } else if(pos == 1){
        return 'E';
    }else if(pos == 2){
        return 'F';
    }
}

//verifies if any permutation of the second triangle has the same side lengths aas the first on
void solve(vector<long> triangle1, vector<long> triangle2){
    vector<char> perm_triangle;
    for(int i = 0; i < 3; i++){
        int val = triangle1.at(i);
        if(find_value(triangle2, val) != -1){
            perm_triangle.push_back(get_pos_letter(find_value(triangle2, val)));
        } else if(find_value(triangle2, val) == -1){
            cout << "none" << "\n";
            return;
        }
    }
 
    for(int i = 0; i < 3; i++){
        cout << perm_triangle.at(i);
    }
    cout << "\n";

}

int main(){

    vector<long> triangle1 = {2, 3, 4};
    vector<long> triangle2 ={2, 3, 4};

    solve(triangle1, triangle2);

    return 0;
}