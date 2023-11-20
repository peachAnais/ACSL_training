//ACSL 2017 - 2019
/*
PROBLEM:  Given string data input representing a mathematical expression, determine the possible location(s) of the missing symbol of enclosure.  Although we 
show spaces between characters for readability, the input strings will have no spaces.  All operands will be one-digit or two-digit integers. The order of 
evaluation for the symbols is parentheses and then brackets.
Given [ 2 + 3 * 8 – 3 ) ] + 6.  There is a missing parenthesis.  A left parenthesis is missing.  It could be correctly placed in several locations:
[ ( 2 + 3 * 8 – 3 ) ] + 6	Location 2

[ 2 + ( 3 * 8 – 3 ) ] + 6	Location 4

[ 2 + 3 * ( 8 – 3 ) ] + 6	Location 6
INPUT:  There will be five lines of input.  Each line will contain a string of characters with no spaces representing a mathematical expression.  Each symbol 
of enclosure will be used at most once.  Each expression will have just 1 missing symbol of enclosure.  The operators used will be:  +, −, * and  /.

OUTPUT: For each line of input, list all the locations in that expression where the missing   symbol of enclosure could be correctly placed.  
Note:single operands are never enclosed.

SAMPLE INPUT						SAMPLE OUTPUT
1.  [ 2 + 3 *  8 – 3 ) ] + 6					1.  2, 4, 6
2.  [ ( 2 – 5 ) + 6						2.  7, 9
3.  [ ( 5 + 5 – 2 ] * 5  					3.  6, 8
4.  13 – [ ( 6 + 18 ) / 3 * 22				4.  11, 13, 16
5.  [ 4 / ( 12 – 8 / 4 * 25 ]					5.  9, 11, 14
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//transforms string to car vector
vector<char> string_to_vector(string str) {
    vector<char> res;
    for(int i = 0; i < str.size(); i++){
        res.push_back(str.at(i));
    }
    reverse(res.begin(), res.end());
}

/*return the type of enclosure I am looking for
char encl_pair(char original_encl){
    if(original_encl == '('){
        return ')';
    } else if(original_encl == ')'){
        return '(';
    } else if(original_encl == '['){
        return ']';
    } else if(original_encl == ']') {
        return '[';
    } else if(original_encl == '{') {
        return '}';
    } else if(original_encl == '}') {
        return '}';
    }
}

//checks if encolsure has pair and return index of the pair, if exists
int check_enclosure_pair(char encl, string str){
    char look_for = encl_pair(encl);
    for(int i = 0; i < str.size(); i++){
        if(str.at(i) == look_for){
            return i;
        }
    }
    return -1;
}
*/

//determines the locations where the closing enclosure could be
void find_locations(string str){
    int start_bracket_index = -1, end_bracket_index = -1;
    int start_square_bracket_index = -1, end_square_bracket_index = -1;
    int start_accolade_index =-1, end_accolade_index = -1;

    for(int i = 0; i < str.size(); i++){

        if(str.at(i) == '('){
            start_bracket_index = i;
        }
        
        if(str.at(i) == ')') {
            end_bracket_index = i;
        }

        if(str.at(i) == '['){
            start_square_bracket_index = i;
        }

        if(str.at(i) == ']'){
            end_square_bracket_index = i;
        }

        if(str.at(i) == '{'){
            start_accolade_index = i;
        }

        if(str.at(i) == '}'){
            end_accolade_index = i;
        }
    }

    //check for accoldes first
    if(start_accolade_index == -1) {
        return;
    } else if(end_accolade_index == -1) {
        return;
    }

    //check for square_brackets
    if(start_square_bracket_index == -1) {
        return;
    } else if(end_square_bracket_index == -1){
        return;
    }

    //check for brackets
    if(start_bracket_index == -1) {
        return;
    } else if(end_bracket_index == -1) {
        return;
    }
}

void main(){

}