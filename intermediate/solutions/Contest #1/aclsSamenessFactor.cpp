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


note on solving: before going in a for that requires a number of itterations equal to the size of the 
smaller string, we must compare the two sizes as to not get a comparisaon between a char and a NULL pointer
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

ifstream fin("acslSamenessFactor.data");

//chooses the size of the smaller string
int smallStrLgt(string str1, string str2) {
    if(str1.length() < str2.length()) {
        return str1.length();
    } else {
        return str2.length();
    }

}

//deletes like from like positions
void deleteSameChars(string &str1, string &str2){

    //we verify if there are any like chars on like positions
    bool madeChange = false;
    int i = 0;
   do{

        if(str1.at(i) == str2.at(i)) {

            str1.erase(str1.begin() + i);
            str2.erase(str2.begin() + i);
            
            madeChange = true;
        }

        if(madeChange == false) {
            i++;
        } else {
            madeChange = false;
        }      

   } while(i < str1.length() && i < str2.length());

}

//solves probelm
void problem(string &str1, string &str2){

    deleteSameChars(str1, str2);
    //we verify if by deleting a char we would get like chars on like position
    //if true, we delete the chars
    int pos = smallStrLgt(str1, str2);

    int i = 0;

    do{
        if((str2.length() > i + 1) && (str1.at(i) == str2.at(i + 1))) {
            str2.erase(str2.begin() + i);

            i -= 1;
            pos = smallStrLgt(str1, str2);
        }

        if((str1.length() > i + 1) && (str2.at(i) == str1.at(i + 1))) {
            str1.erase(str1.begin() + i);

            i -= 1;
            pos = smallStrLgt(str1, str2);
        }

    
        i++;
    } while(i < pos);

    deleteSameChars(str1, str2);

}

//acsl sameness factor
int samenessFactor(string str1, string &str2) {
    int iterrations = str2.length();
    int factor = 0;
    
    int i;
    for(i = 0; i < iterrations; i++) {
        
        if(i > str1.length() - 1){
            break;
        } else {
            factor = factor + (int(str1.at(i)) - int(str2.at(i)));
        }
    }

    if(str2.length() > str1.length()) {
        str2 = str2.erase(0, i);
        factor += str2.length();

        return factor;
    }

    if(str1.length() > str2.length()){
        str1 = str1.erase(0, iterrations);
        factor += str1.length();

        return factor;
    }

    return factor;
}

int main()
{
    string str1;
    string str2; 
 

    fin >> str1 >> str2;

    problem(str1, str2);

    cout << "The ASCL sameness factor is: " << samenessFactor(str1, str2) << endl;

    return 0;
}