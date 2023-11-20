//ACSL 2007-2008
/*
PROBLEM:  Wikipedia defines data compression as “the process of encoding information using fewer bits than an unencoded representation would use through the 
use of specific encoding schemes.”  If you download files, you are familiar with .zip and .jar formats that compress the original file in order to make the 
transfer time faster.  

In the article “How File Compression Works” by Tom Harris on the web site howstuffworks.com, Mr. Harris notes that most types of computer files are redundant.  
That is they have the same information listed over and over again.  Think back to how many IF-THEN statements you used to solve the Contest #1 program.

John F. Kennedy’s famous 1961 speech contained the following famous line:  “ASK NOT WHAT YOUR COUNTRY CAN DO FOR YOU – ASK WHAT YOU CAN DO FOR YOUR COUNTRY.”  
The line has 17 words, 61 letters, 17 spaces, one dash and one period.  To compress the line, you need to look for redundancies.  
The following table summarizes the data:
    The line using redundant compressed format can be compressed as follows: 

                         2ASK1NOT2WHAT2YOUR2COUNTRY2CAN2DO2FOR2YOU1–1.

1.  YES I CAN! YES I CAN! YES I CAN!		1.  3YES3I3CAN3!
2.  SHE LOVES YOU! YEAH! YEAH! YEAH!		2.  1SHE1LOVES1YOU3YEAH4!
3.  SEA SHELLS SEA SHELLS BY THE SEA SHORE.	3.  3SEA2SHELLS1BY1THE1SHORE1.
*/

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

using namespace std;

//string to vector<string>
vector<string> string_to_vct_string(string in) {
    vector<string> res;
    string to_append;

    for(int i = 0; i < in.size(); i++) {
        // check if current char in string is punctuation
        bool is_pct = std::ispunct(int(in.at(i)));
        // check if current char is space
        bool is_space = std::isspace(int(in.at(i)));

        // to_append can be empty if previous character was punctuation
        if(is_space) {
            // if the curret character is space:
            // 1. add the existing to_append string to the return vector
            // 2. empty the to_append string
            // 3. move to next character
            if(!to_append.empty()) {
                res.push_back(to_append);
            }
            to_append.clear();

            continue;
        }

        if(is_pct) {
            // if the current char is punctuation
            // 1. add the current to_append to the return vector if not empty
            // 2. add the current punctuation char to the vector
            // 3. empty the to_append string
            if(!to_append.empty()) {
                // to_append can be emtpy if multiple punctuation chars (like !!!!!)
                res.push_back(to_append);
            }
            res.push_back(in.substr(i, 1));
            to_append.clear();
            continue;
        }

        // add current char to current word
        to_append += in.at(i);
    }

    return res;
}

//frequency vector -> hashmap
map<string, int> word_frequency(vector<string> str) {
    map<string, int> freq_map;

    for(int i = 0; i < str.size(); i++){
        if(freq_map.count(str.at(i)) > 0) {
            freq_map.at(str.at(i))++;
        } else {
            freq_map.insert(pair <string, int>(str.at(i), 1));
        }
    }

    return freq_map;
}

//construct compressed string from hashmap
string compressed_str(map<string, int> str, vector<string> map_source) {
    string res;

    for(int i = 0; i < str.size(); i++){
       res.append(to_string(str.at(map_source.at(i))));
        res.append(map_source.at(i));
    }

    return res;
}

//solve problem
void solve(string initial_string) {

    vector<string> work_vector;
    map<string, int> freq_map;

    work_vector = string_to_vct_string(initial_string);
    freq_map = word_frequency(work_vector);

    cout << compressed_str(freq_map, work_vector) << endl;
}


int main(){

    solve("YES I CAN! YES I CAN! YES I CAN!");

    return 0;
}