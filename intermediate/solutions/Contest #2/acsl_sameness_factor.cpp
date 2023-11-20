//ACSL 2019 - 2020

/*
PROBLEM: Given 2 strings, separated by a space, calculate the ACSL Sameness Factor (ASF). Repeat the following 3 steps in order until no other deleting aligns like characters:
● Align the strings from left to right.
● Delete the like characters in the like locations from left to right.
● Proceeding from left to right, if the like location characters are not the same and deleting a character at a location in one of the strings which shifts the remaining characters to the
left causes like characters to be at that location, delete those characters and any other like characters at like locations. If there is a case as in NAPE and ANTI where it is possible
to delete a character at the same location in both strings, then delete it in the second string. Therefore, the A would be deleted and the NTI shifted to the left.
Calculate the ACSL Sameness Factor by doing the following:

● Calculate the difference in the alphabetic locations from the aligned string characters in the second string to the string character in the first string. B to D would add 2 to the
ASF. D to B would add -2 to the ASF.
● If there are characters remaining in one of the strings, add the number of those characters
to the ASF.

Example: ABCDEFT ABXCGBTZFP
ABCDEFT → ABCDEFT → CDEF → CDEF → DEF → DEF → DE
ABXCGBTZFP → ABXCGBTZFP →XCGBZFP → CGBZFP → GBZFP → GBFP → GBP
The ASF is calculated as: G to D = -3 B to E = + 3 P = + 1 (-3 + 3 + 1 = 1)

INPUT: There will be 5 inputs. Each input will contain 2 strings separated by a space and each
fewer than 200 characters.
OUTPUT: For each input, print the ASF as described above
*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

//deletes like chrachters in like locations
void del1(string& str1, string& str2) {
    int n;
    if(str1.length() > str2.length()) {
        n = str2.length();
    } else {
        n = str1.length();
    }

    for(int i = 0; i < n; i++) {
        if(str1.at(i) == str2.at(i)) {
            str1.erase(str1.begin() + i);
            str2.erase(str2.begin() + i);
        }
    }
}

//deletes character if by deleting at the location in one of the string will cause like charachets to be in like locations
void del2(string& str1, string& str2) {
    int n;
    if (str1.length() < str2.length()) {
        n = str1.length();
    } else {
        n = str2.length();
    }

    for(int i = 0; i < n; i++) {
        if(str1.at(i) == str2.at(i + 1)) {
            str2.erase(str2.begin() + i);
        }

        if(str1.at(i + 1) == str2.at(i)) {
            str1.erase(str1.begin() + i);
        }
    }

    del1(str1, str2);
}

//calculates ACSL sameness factor
void acsl_sameness_factor(string& str1, string& str2) {

    del1(str1, str2);
    del2(str1, str2);

    int acsl_factor = 0;
    string remainder;

    int n;
    if(str1.length() > str2.length()) {
        n = str2.length();
        remainder.append(str1.begin() + n, str1.end());
    } else {
        n = str1.length();
        remainder.append(str2.begin() + n, str2.end());
    }

    for(int i = 0; i < n; i++) {
        if(int(str1.at(i)) < int(str2.at(i))) {
            acsl_factor += int(str1.at(i)) - int(str2.at(i));
        }

        if(int(str1.at(i)) > int(str2.at(i))) {
            acsl_factor += int(str2.at(i)) - int(str1.at(i));
        }
    }

    for(int i = 0; i < remainder.length(); i++) {
        acsl_factor += int(remainder.at(i));
    }

    cout << acsl_factor << endl;
}

void main() {

    string a = "ABCDEFT";
    string b = "ABXCGBTZFP";
    acsl_sameness_factor(a, b);
}