//ACSL 2023 - 2024: Contest #1

//problem
/*
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


//returns how many times a given value appears in a num
//status: verified
int val_in_num(int num, int val){
    int res = 0;
    while(num != 0){
        if(num % 10 == val){
            res++;
        }
        num /= 10;
    }
    return res;
}

//num to vector<int>
//status: 
vector<int> num_to_vector(int num){
    vector<int> res;
    
    while(num != 0){
        res.push_back(num % 10);
        num /= 10;
    }
    reverse(res.begin(), res.end());
    
    return res;
}

//vector<int> to num
//status: verified
int vector_to_num(vector<int> digits){
    int res = 0;
    
    for(int i = 0; i < digits.size(); i++){
        res = res * 10 + digits.at(i);
    }
    return res; 
}

//changes number form base 10 to base b
//status: verified
int base_10_to_base_b(int num, int base){
    vector<int> base_b_digits;
    
    while(num != 0){
        base_b_digits.push_back(num % base);
        num /= base;
    }
    reverse(base_b_digits.begin(), base_b_digits.end());
    
    while(base_b_digits.at(0) == 0){
        base_b_digits.erase(base_b_digits.begin() + 0);
    }
    
    int return_num = vector_to_num(base_b_digits);
    
    return return_num;
}

//chages number from base b to base 10
//status: verified
int base_b_to_base_10(int num, int initial_base){
    int res = 0;
    vector<int> digits = num_to_vector(num);
    int exponent = 0;
    
    for(int i = digits.size() - 1; i >= 0; i--){
        res = res + digits.at(i) * pow(initial_base, exponent);
        exponent++;
    }
    return res;
}

int countLargestDigit(int num, int base, int start) {
    int largest_digit_cnt = 0;
    int max_num_in_base = base - 1;
    
    vector<int> num_in_base_10;
    int start_in_10 = base_b_to_base_10(start, base);
    num_in_base_10.push_back(start_in_10);
    
    for(int i = 1; i < num; i++){
        num_in_base_10.push_back((num_in_base_10.at(i - 1) + 1));
    }
    
    for(int i : num_in_base_10){
        int val = base_10_to_base_b(i, base);
        largest_digit_cnt += val_in_num(val, max_num_in_base);
    }
    
    return largest_digit_cnt;
}

int main(){

    cout << countLargestDigit(15, 8, 2) << endl;

    return 0;
}