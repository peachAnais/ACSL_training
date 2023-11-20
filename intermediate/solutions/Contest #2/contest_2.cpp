//ACSL 2023-2024

/*
*Problem text here*
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <bitset>

using namespace std;

//string to vector<char>
//status: working
vector<char> str_to_vct_char(string str){
    vector<char> result;

    for(int i = 0; i < str.size(); i++) {
        result.push_back(str.at(i));
    }

    return result;
}


//base 10 to base 2
//status: working
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
//status: working
vector<string> ascii_code_to_bin(vector<char> chr) {
   vector<string> bin_codes;

   for(int i = 0; i < chr.size(); i++) {
        int ascii_code = int(chr.at(i));
        string str_to_add = dec_to_bin(ascii_code);
        bin_codes.push_back(str_to_add);
   } 

   return bin_codes;
}

//concat the string
//status: working
string concat_bin_str(vector<string> bin_codes){
    string str;

    for(int i = 0; i < bin_codes.size(); i++) {
        str.append(bin_codes.at(i));
    }

    return str;
}

//function solves problem
//status:unknown
int find_last_binary(string s) {
    vector<char> chars = str_to_vct_char(s);
    vector<string> chars_to_bins_vct = ascii_code_to_bin(chars);
    string work_str = concat_bin_str(chars_to_bins_vct);

    int count = 0;
    //string search_for = dec_to_bin(count); 
     
    while(!work_str.empty()){

        string search_for = dec_to_bin(count);
        if(search_for.length() > 1) {
            search_for.erase(search_for.begin() + 0); 
        }
        bool modified_string = false;
        //searches for string at the beginning
        size_t found_at_beginning = work_str.find(search_for);
        if(found_at_beginning != string::npos) {
            work_str.erase(work_str.begin() + found_at_beginning, work_str.begin() + found_at_beginning + search_for.length());
            modified_string = true;
        }

        //search for string at end
        reverse(work_str.begin(), work_str.end());
        reverse(search_for.begin(), search_for.end());
        size_t found_at_end = work_str.find(search_for);
        if(found_at_end != string::npos) {
            work_str.erase(work_str.begin() + found_at_end, work_str.begin() + found_at_end + search_for.length());
            modified_string = true;
        }
        reverse(work_str.begin(), work_str.end());
        reverse(search_for.begin(), search_for.end());

        //see if search should continue
        if(modified_string){
            count++;
        } else {
            return count - 1;
        }

    }
    return -1;
}

int main(){
    cout << find_last_binary("Roses are red.") << endl;
    return 0;
}