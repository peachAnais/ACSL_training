//ACSL 2019 - 2020

/*
PROBLEM: Given a positive integer (call it N) and a position in that integer (call it P) transform N. To transform N, find the Pth digit of N from the right. Replace each of the digits to
the left of the Pth digit by the sum of that digit and the Pth digit. If the sum is greater than 9, use just the units digits (see the second example below). Replace each of the digits to 
the right of the P th digit by the absolute value of the difference between it and the Pth digit. Do not change the Pth digit.

Example 1: N=102439, P=3. Answer is: (1+4)(0+4)(2+4)4(|3-4|)(|9-4|) => 546415

Example 2: N=4329, P=1. Answer is: (4+9)(3+9)(2+9)9 => (13)(12)(11)9 => 3219

INPUT: There will be 5 sets of data. Each set contains two positive integers: N and P. N will be
less than 10 , and P will be valid. No input will cause an output to have a leading digit of 0. 15

OUTPUT: The transformed value of each input set. The printed number may not have any
spaces between the digits.
*/

#include <iostream>
#include <vector>
#include <fstream>
#include <algorithm>

using namespace std;

//number to vector<int>
vector<long> num_to_vector(long x){
    vector<long> res;

    while(x != 0){
        res.push_back(x % 10);
        x /= 10;
    }
    reverse(res.begin(), res.end());
    return res;
}

//vector<int> to num
int vector_to_num(vector<long> digits){
    int res = 0;
    for(int i : digits){
        res = res * 10 + i;
    }
    return res;
}

//changes to the digits situated at the left of the Pth position
void changes_left(vector<long>& num, int pos){
    for(int i = 0; i < pos; i++){
        num.at(i) = (num.at(i) + num.at(pos)) % 10;
    }
}

//canges to the digits situated to the right of te Pth position
void changes_right(vector<long>& num, int pos){
    for(int i = pos + 1; i < num.size(); i++){
        num.at(i) = (abs(num.at(i) - num.at(pos))) % 10;
    }
}

//solve
void solve(long x, int pos){
    vector<long> num = num_to_vector(x);
    changes_left(num, pos);
    changes_right(num, pos);

    cout << vector_to_num(num) << endl;
}

int main(){

    solve(102439, 3);

    return 0;
}