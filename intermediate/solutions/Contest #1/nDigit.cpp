/*
PROBLEM: Given a number less than 1050 and a length n, find the sum of all the n-digit numbers (starting on the left) that are formed such that, after the first n-digit number is formed all others are formed by deleting the leading digit and taking the next n-digits.  

EXAMPLE: Given , the 2-digit numbers formed are 13, 32, 25, 56, 67, 78, 89, 90, and 05.  The sum is 455.

INPUT: There will 5 lines of input.  Each will contain a positive integer less than 1050 and a positive integer n.

OUTPUT: For each line of input, print the sum of the n-digit numbers formed. 
*/

#include <iostream>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;

#define FNAME "ndigit.data"

//separates string into 2 substrings and the ndigit for the nums formed
void sepString(string input, long long &n, int &nDigit) {
    
    int pos  = input.find(" ");
    
    n = std::stoll(input.substr(0, pos));

    input.erase(input.begin() + 0, input.begin() + pos);

    nDigit = std::stoi(input);
}

//return the length of a number
int numLength(long long x) {
    int lgt = 0;

    while(x != 0) {
        x /= 10;

        lgt++;
    }

    return lgt;
}

//return the reverse of one number
long long reverseNum(long long x) {
    long long newNum = 0;
    long long aux = x;

    while(aux != 0) {
        int digit = aux % 10;
        aux /= 10;

        newNum = newNum * 10 + digit;
    }

    return newNum;
}

//creates a new num using elements from a given <int> vector, starting with a given position pos, using n digits (vector <int>, pos and n are passed as parameters)
long long createNDigitNum(vector<int> &vector, int pos, int nDigit) {
    long long num = 0;

    for(int i = pos; i < pos + nDigit; i++ ) {
        num = num * 10 + vector.at(i);
    }

    cout << "We add " << num << endl;

    return num;
}

//OBS: Code works for nums in long long range.

//calculates the sum specified in the problem
long long sum(long long n, int nDigit){
    int lgt = numLength(n);
    cout << "The num length is " << lgt << endl;

    //the num we work with to create the vector
    cout << "The initial number is: " << n << endl;

    long long num = reverseNum(n);
    cout << "The reverse number is: " << num << endl;

    vector <int> digitsOfN;

    long long sum = 0;

    int i;
    for(i = 0; i < lgt; i++) {
        digitsOfN.push_back(num % 10);
        num /= 10;
    }

    for(i = 0; i < lgt; i++) {
        if(i + nDigit <= lgt){
            sum += createNDigitNum(digitsOfN, i, nDigit);
            cout << "The sum for i = " << i << " is " << sum << endl;
        }
    }

    return sum;
}


int main()
{
    long long n;
    int nDigit;

    ifstream fin;
    fin.open(FNAME);

    string input;

    while(getline(fin, input)) {
        sepString(input, n, nDigit);

        cout << "The sum of nDigit numbers = " << sum(n, nDigit) << endl;
    }

    return 0;
}