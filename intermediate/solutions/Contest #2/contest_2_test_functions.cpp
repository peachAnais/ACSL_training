#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//string to vector<char>
//status: unknown
vector<char> str_to_vct_char(string str){
    vector<char> result;

    for(int i = 0; i < str.size(); i++) {
        result.push_back(str.at(i));
    }

    return result;
}

//vector to num
//status: verified
int vct_to_num(vector<int> vct){
    int res = 0;

    for(int i = 0; i < vct.size(); i++) {
        res = res * 10 + vct.at(i);
    }
    return res;
}

//base 10 to base 2
//status: verified
string dec_to_bin(int x){
    vector<int> bin_digits;
    while(x >= 1) {
        bin_digits.push_back(x % 2);
        x = x/2;
    }
    reverse(bin_digits.begin(), bin_digits.end());
    bin_digits.insert(bin_digits.begin(), 0);

    string res;
    for(int i = 0; i < bin_digits.size(); i++) {
        res.append(to_string(bin_digits.at(i)));
    }
    return res;
}

//ascii code to binary
//status: unknown
vector<string> ascii_code_to_bin(vector<char> chr) {
   vector<string> bin_codes;

   for(int i = 0; i < chr.size(); i++) {
        int ascii_code = int(chr.at(i));
        bin_codes.push_back(dec_to_bin(ascii_code));
   } 

   return bin_codes;
}

//concat the string
//status: unknown
string concat_bin_str(vector<string> bin_codes){
    string str;

    for(int i = 0; i < bin_codes.size(); i++) {
        str.append(bin_codes.at(i));
    }

    return str;
}

int main() {

    cout << dec_to_bin(82) << endl;
    
    return 0;
}