//ACSL 2019 - 2020
/*
PROBLEM: Given a Boolean expression with at most 4 variables, describe its Veitch Diagram. Each Boolean expression will use just the OR operator to combine terms and the terms will be joined using just
the AND operator. Note that variables are eliminated from a term’s representation if the variable and its negation are included in its grid representation.
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>

using namespace std;

//returns hex value of an input
string intToHex(int num) {
    stringstream stream;
    stream << hex << num;  // Convert the integer to hexadecimal using stringstream
    return stream.str();  // Return the hexadecimal value as a string
}

//creates DEC number from bin
int vct_to_dec(vector<int> bin_digits) {
    int res = 0;

    for(int i = 0; i < bin_digits.size(); i++) {
        res = res * 10 + bin_digits.at(i);
    }

    return res;
}

void solve(vector<vector<int>> diagram, string text_input) {
    vector<int> bin_digits;
    //letter A -> we consider it to be the first row, first 2 are A, next 2 ~A
    //letter B - > we consider it to be the first column, first 2 are B, next 2 are ~B
    //letter C -> we consider it toe be the last row, first and last cell are ~C, cells in the middle are C
    //letter D -> we consider it to be the last column, first and last cell are ~D, cells in the middle are D

    //populate matrix with 0s
    for(int i = 0; i < 6; i++) {
        for(int j = 0; j < 6; j++) {
            diagram[i][j] = 0;
        }
    }

    //therefore, we consider that we refer to A on row 0, A on column 1 and 2, ~A on column 3 and 4
    //B on column 0, B row 1 and 2, ~B row 3 and 4
    //C on row 4, C column 1 and 2, ~C column 3 and 4
    //D on column 4, row 1 and 2, ~B row 3 and 4
    //populate arrays wit correspoding 1s

    for(int i = 0; i < text_input.length(); i++) {
        if(text_input[i] == '~') {
            if(text_input[i + 1] == 'A') {
                diagram[1][3] = 1;
                diagram[1][4] = 1;
            }

            if(text_input[i + 1] == 'B') {
                diagram[3][1] = 1;
                diagram[4][1] = 1;
            }

            if(text_input[i + 1] == 'C') {
                diagram[4][1] = 1;
                diagram[4][4] = 1;
            }

            if(text_input[i + 1] == 'D') {
                diagram[4][1] = '1';
                diagram[4][4] = '1';
            }
        } else {
            if(text_input[i] == 'A') {
                diagram[1][1] = 1;
                diagram[1][2] = 1;
            }

            if(text_input[i] == 'B') {
                diagram[1][1] = 1;
                diagram[2][1] = 1;
            }


            if(text_input[i] == 'C') {
                diagram[4][2] = 1;
                diagram[4][3] = 1;
            }


            if(text_input[i] == 'D') {
                diagram[4][2] = 1;
                diagram[4][3] = 1; 
            }
        }
    }

    for(int i = 0; i < 6; i++) {
        for(int  j = 0; j < 6; i++){
            bin_digits.push_back(diagram[i][j]);
        }
    }

    //create a BIN number from the matrix which we then transform to HEX
    int bin_number = vct_to_dec(bin_digits);
    string hex_number = intToHex(bin_number);

    //print result to console
    cout << "Result: " << hex_number << endl;
    
}

int main(void) {
    vector<vector<int>> diagram(6, vector<int>(6));
    string input_text = "~A";

    solve(diagram, input_text);

}