//ACSL 2003-2004
/*
PROBLEM:  Given a positive integer, change the integer according to the following rules:  
1.  Find the mean of the digits.  Find the digit closest to the mean that is not larger than the mean. 
    If that digit appears more than once, the left most occurrence will be the digit used below.
2.  If that digit is a 0 or a 1 or a 2, replace it with the largest digit in the integer.
3.  If that digit is a 3 or a 4 or a 5, replace it with the smallest digit in the integer.
4.  If that digit is a 6 or a 7 or an 8, replace it with the sum of the digits.  If the sum is >9, use the 
     ones digit of the sum.
5.  If that digit is a 9, replace it with a 0.

INPUT:  There will be 5 inputs.  Each input will be a positive integer less than 100,000. 

OUTPUT:  Print the new integer.  There will be no spaces between the printed digits.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <algorithm>
#include <fstream>

using namespace std;


//transform given number to vector<int>
vector<int> num_to_vector(int x){
    vector<int> result;

    while(x != 0){
        result.push_back(x % 10);
        x /= 10;
    }
    reverse(result.begin(), result.end());

    return result;
}

int sum_of_digits(vector<int> digits){
    int sum = 0;
    for(int i = 0; i < digits.size(); i++){
        sum += digits.at(i);
    }
    return sum % 10;
}


//calculate mean of a vector<int>
int mean_of_digits(vector<int> num){
    //int sum = 0;
    // for(int i = 0; i < num.size(); i++){
    //     sum += num.at(i);
    // }
    return int(sum_of_digits(num) / num.size());
    // for(int i : num) {
    //     sum += i;
    // }

    // return int(sum / num.size());
}

//get largest digit in a vector<int>
int max_in_vct(vector<int> vct){
    int max = INT16_MIN;

    for(int i = 0; i < vct.size(); i++) {
        if(vct.at(i) > max){
            max = vct.at(i);
        }
    }
    return max;
}

//get smallest digit in a vector<int>
int min_in_vct(vector<int> vct){
    int min = INT16_MAX;

    for(int i = 0; i < vct.size(); i++){
        if(vct.at(i) < min){
            min = vct.at(i);
        }
    }
    return min;
}

//find the posistion of th enum that is < mean
int close_mean_pos(vector<int> num){
    int val = -1;
    int mean = mean_of_digits(num);
    for(int i = 0; i < num.size(); i++){
        if(num.at(i) <= mean && num.at(i) > val){
            val = num.at(i);
        }
    }

    for(int i = 0; i < num.size(); i++){
        if(num.at(i) == val){
            return i;
        }
    }
}

//case for 0, 1, 2
void case1(vector<int>& num, int pos){
    num.at(pos) = max_in_vct(num);
}

//case for 3, 4, 5
void case2(vector<int>& num, int pos){
    num.at(pos) = min_in_vct(num);
}

//case for 6, 7, 8
void case3(vector<int>& num, int pos){
    num.at(pos) = sum_of_digits(num);
}

//case for 9
void case4(vector<int>& num, int pos){
    num.at(pos) = 0;
}

//create number from vector<int>
int vct_to_num(vector<int> digits){
    int res = 0;
    for(int i = 0; i < digits.size(); i++){
        res = res * 10 + digits.at(i);
    }
    return res;
}

//solve
void solve(int x){
    vector<int> digits = num_to_vector(x);
    int pos = close_mean_pos(digits);
    
    if(digits.at(pos) == 0 || digits.at(pos) == 1 || digits.at(pos) == 2){
        case1(digits, pos);
    } else if (digits.at(pos) == 3 || digits.at(pos) == 4 || digits.at(pos) == 5){
        case2(digits, pos);
    } else if (digits.at(pos) == 6 || digits.at(pos) == 7 || digits.at(pos) == 8) {
        case3(digits, pos);
    } else if (digits.at(pos) == 9){
        case4(digits, pos);
    }

    cout << vct_to_num(digits) << endl;
}


int main(){

    solve(1232);

    return 0;
}