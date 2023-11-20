//ACSL 2015 - 2016

/*
1.  char_split (a$, n, ‘char’) – char_split divides a given string (a$) into substrings of length n separated by the given character.
2.  strrem (a$, b$) – removes all occurrences of b$
3.  strchr (a$, b$) – strchr searches a$ for the first occurrence of b$ and returns the characters of a$ before the first occurrence of b$
4.  strtok(a$, b$) – strtok splits a given string (a$) into substrings each time the character b$ is found.  Substrings must be separated by spaces.
5.  wordwrap(a$, n, b$) – wordwrap outputs the substrings of a$ that are a maximum of n characters in length or that begin with the character b$.  Substrings must be separated by spaces.


INPUT:  There will be 5 lines of input.  Each line of input will contain a character string (a$) and the data for the arguments needed for the like numbered functions above.  The length of 
a$ will be fewer than 25 characters.  

OUPUT:  For each line of input print the result of applying the like numbered function above.

SAMPLE INPUT					SAMPLE OUTPUT
	1.  MISSISSIPPI, 2, *				1.  MI*SS*IS*SI*PP*I
	2.  MISSISSIPPI, IS 				2.  MSSIPPI
	3.  MISSISSIPPI, P				3.  MISSISSI
	4.  MISSISSIPPI, I				4.  M ISS ISS IPP I
	5.  MISSISSIPPI, 2, I				5.  M IS S IS S IP P I
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//string to vector<char>
vector<char> str_to_vct(string str) {
    vector<char> result;

    for(int i = 0; i < str.length(); i++){
        result.push_back(str.at(i));
    }
    
    return result;
}

//vector<char> to string
string vct_to_str(vector<char> letters){
    string result;

    for(int i = i; i < letters.size(); i++){
        result += letters.at(i);
    }

    return result;
}

void char_split(string str, int n, char sep) {
    string new_string;
    vector<char> letters = str_to_vct(str);

    for(int i = 0; i < letters.size(); i++){
        new_string += letters.at(i);
        if(i % n == 0){
            new_string += sep;
        }
    }

    cout << new_string << endl;
}

void strrem() {

}

void strchr() {

}

void strtok() {

}

void word_wrap() {
    
}

int main() {
     char_split("MISSISSIPPI", 2, '*');

    return 0;
}