/*
// PROBLEM: Given 2 strings, separated by a space, calculate the ACSL Sameness Factor (ASF). Repeat
// the following 3 steps in order until no other deleting aligns like characters:
// ● Align the strings from left to right.
// ● Delete the like characters in the like locations from left to right.
// ● Proceeding from left to right, if the like location characters are not the same and deleting
// a character at a location in one of the strings which shifts the remaining characters to the
// left causes like characters to be at that location, delete those characters and any other like
// characters at like locations. If there is a case as in NAPE and ANTI where it is possible
// to delete a character at the same location in both strings, then delete it in the second
// string. Therefore, the A would be deleted and the NTI shifted to the left.
// Calculate the ACSL Sameness Factor by doing the following:
// ● Calculate the difference in the alphabetic locations from the aligned string characters in
// the second string to the string character in the first string. B to D would add 2 to the
// ASF. D to B would add -2 to the ASF.
// ● If there are characters remaining in one of the strings, add the number of those characters
// to the ASF.
// Example: ABCDEFT ABXCGBTZFP
// ABCDEFT    → ABCDEFT    → CDEF    → CDEF   → DEF   → DEF  → DE
// ABXCGBTZFP → ABXCGBTZFP → XCGBZFP → CGBZFP → GBZFP → GBFP → GBP
// The ASF is calculated as: G to D = -3 B to E = + 3 P = + 1 (-3 + 3 + 1 = 1)
// Test Data:
// MYARTLOLLIPOPS MYLARBALLOONS
// MASSACHUSETTSBAYCOLONY MINUTEMANNATIONALHISTORICALPARK
// LOWERMACTOWNSHIPPA CRANBERRYTOWNSHIPPA
// AMERICANCOMPUTERSCIENCELEAGUE NATIONALACADEMICGAMESLEAGUE
// ABCDEFGHIJK ABDCEFGKILKJMN
// Test Results:
// 1. 23
// 2. 27
// 3. 11
// 4. 68
// 5. -9
*/

#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define FNAME "acsl_string_sameness_factor.dat"

vector<string> s1_transformations, s2_transformations;

void print_strings(const string func, const string& s1, const string& s2) {
    cout << std::left << std::setw(32) << func <<
        std::left << std::setw(32) << s1 << endl <<
        std::left << std::setw(32) << " " <<
        std::left << std::setw(32) << s2 << endl;
}

void print_transformations() {
    int width = max(s1_transformations.at(0).length(), s2_transformations.at(0).length());

    for(auto& s: s1_transformations) {
        cout << std::left << std::setw(width) << s << " -> ";
    }
    cout << endl;
    for(auto& s: s2_transformations) {
        cout << std::left << std::setw(width) << s << " -> ";
    }
    cout << endl;
}

bool remove_same_pos_chars(string& s1, string& s2) {
    int i = 0;
    bool removed = false;

    do {
        // we leave i at the same value in case another char at the same positions needs to be deleted
        if(s1.at(i) == s2.at(i)) {
            s1.erase(i, 1);
            s2.erase(i, 1);

            //print_strings("remove_same_pos_chars", s1, s2);
            s1_transformations.push_back(s1);
            s2_transformations.push_back(s2);
            removed = true;
        } else {
            i += 1;
        }
    } while(i < s1.length() && i < s2.length());

    return removed;
}

bool shift_strings(string& s1, string& s2) {
    bool shifted = false;

    size_t iter_sz = (s1.length() > s2.length()) ? s2.length() : s1.length();

    for(int i =  0; i < iter_sz; i++) {
        if( (i < s2.length() - 1) && (s1.at(i) == s2.at(i + 1)) ) {
            s2.erase(i, 1);
            s1_transformations.push_back(s1);
            s2_transformations.push_back(s2);
            //print_strings("shift_strings", s1, s2);
            shifted = true;
        }
    }

    return shifted;
}

int calculateASF(string s1, string s2) {
    int sum = 0;

    bool cont = false;
    do {
        cont = remove_same_pos_chars(s1, s2);
        cont = shift_strings(s1, s2) || cont;
        cont = remove_same_pos_chars(s2, s1) || cont;
        cont = shift_strings(s2, s1) || cont;
    } while(cont);

    print_transformations();
    //print_strings("calculateASF/endstr", s1, s2);

    int len = (s1.size() > s2.size()) ? s1.size() : s2.size();
    for(int i = 0; i < len; i++) {
        if(i < s1.size() && i < s2.size()) {
            // both strings have a letter so we make s1 - s2
            printf("%2d, sum = %3d + %d(%c) - %d(%c)", i, sum, (int) s1.at(i), s1.at(i), (int) s2.at(i), s2.at(i));
            sum += s1.at(i) - s2.at(i);
            std::cout << " = " << sum << endl;
        } else {
            std::cout << std::right << std::setw(2) << i << ", sum = " << sum++ << " + 1" << " = " << sum << endl;
            //sum += 1;
            //std::cout << " = " << sum << endl;
        }
    }

    return sum;
}

int main () {
    ifstream ifs;
    ifs.open(FNAME);

    string line;
    while(std::getline(ifs, line)) {
        string s1, s2, aux;
        int expected_result = 0;

        s1_transformations.clear();
        s2_transformations.clear();

        cout << "line: " << line << endl;
        size_t pos = line.find(" ");
        if(pos != string::npos) {
            s1 = line.substr(0, pos);
            aux = line.substr(pos + 1);
        }
        pos = aux.find(" ");
        if(pos != string::npos) {
            s2 = aux.substr(0, pos);
            expected_result = stoi(aux.substr(pos + 1));
        } else {
            s2 = aux;
        }

        //print_strings("main", s1, s2);
        s1_transformations.push_back(s1);
        s2_transformations.push_back(s2);
        int asf = calculateASF(s1, s2);

        cout << "ASF = " << asf << " expected_result = " << expected_result << endl << endl;
    }

    return 0;
}