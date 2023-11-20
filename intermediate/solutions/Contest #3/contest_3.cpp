//ACSL 2023-2024

#include <iostream>
#include <stdlib.h>
#include <vector>
#include <algorithm>
#include <string>
#include <bits/stdc++.h>

using namespace std;

//generate the final string
string gen_result_string(vector<char> v_letters, vector<int> v_values) {
    string str1;
    string str2;
    string res;

    bool str1_pass;
    bool str2_pass;

    for(int i = 0; i < v_letters.size(); i++) {
        str1_pass =false;
        str2_pass = false;
        char current_letter = v_letters.at(i);
        char start_value = v_values.at(i);

        //check if current_letter coresponds to str1
        for(int j = i - 1; j >= 0; j--) {
            if(v_values.at(j) < start_value) {
                 break;
            } else if(v_values.at(j) - start_value == 1) {
                str1_pass = true;
            }
        }

        //check if current_letter coresponds to str2
        for(int j = i + 1; j < v_values.size(); j++) {
            if(v_values.at(j) < start_value) {
                 break;
            } else if(v_values.at(j) - start_value == 1) {
                str2_pass = true;
            }
        }

        if(str1_pass == true && str2_pass == false) {
            str1 += current_letter;
        }  else if(str1_pass == false && str2_pass == true) {
            str2 += current_letter;
        }
    }

    if(str1.empty() && str2.empty()) {
        return "NONE";
    } else if(str1.empty()) {
        return "NONE " + str2;
    } else if(str2.empty()) {
        return str1 + " NONE";
    } else {
        return str1 + " " + str2;
    }
}

//return the letter and vector values
//works
void gen_arrays(vector<char> &v_letters, vector<int> &v_values, string input) {

    int pos_in_str = 0;
    while(pos_in_str < input.length()) {
        //initilize the count with 0
        char current_letter = input[pos_in_str];
        if(v_letters.empty()) {
            v_letters.push_back(current_letter);
            v_values.push_back(0);
            //we filles the first position, move to next letter in str before comparing
            pos_in_str++;
            current_letter = input[pos_in_str];
        }
        for(int i = 0; i < v_letters.size(); i++) {

            if(int(current_letter) <= v_letters[i]) {
                int val;
                if(i == 0) {
                    val = v_values[0] + 1;
                    v_letters.insert(v_letters.begin() + i, current_letter);
                    v_values.insert(v_values.begin() + i, val);
                    break;
                } else if(i == v_letters.size() - 1){
                    val = v_values[i] + 1;
                    v_letters.push_back(current_letter);
                    v_values.push_back(val);
                    break;
                } else {
                    if(v_values[i - 1] < v_values[i]) {
                        val = v_values[i] + 1;
                    } else {
                        val = v_values[i - 1] + 1;
                    }
                    v_letters.insert(v_letters.begin() + i, current_letter);
                    v_values.insert(v_values.begin() + i, val);
                    break;
                }
                
            } else {
                //if curr_letter is higher than the v_letter[i]
                int val;
                if(i == v_letters.size() - 1) {
                    //break because we are adding an element and te vector size will change
                    val = v_values[0] + 1;
                    v_letters.push_back(current_letter);
                    v_values.push_back(val);
                    break;
                } else {
                    while(current_letter > v_letters[i] && i < v_letters.size()) {
                        i++;
                    }

                    if(i == v_letters.size() - 1 && current_letter > v_letters[v_letters.size() - 1]) {
                        val = v_values[v_values.size() - 1] + 1;
                        v_letters.push_back(current_letter);
                        v_values.push_back(val);
                        break;
                    }

                    if(v_values[i - 1] < v_values[i]) {
                        val = v_values[i] + 1;
                    } else {
                        val = v_values[i - 1] + 1;
                    }
                    v_letters.insert(v_letters.begin() + i, current_letter);
                    v_values.insert(v_values.begin() + i, val);
                    break;
                }
            }
        }
        pos_in_str++;
    }
}


string onlyLeftOrRight(string input) {
    string result;
    vector<int> v_values;
    vector<char> v_letters;

    gen_arrays(v_letters, v_values, input);

    result = gen_result_string(v_letters, v_values);

    return result;
}

int main() {

    //works: string input = "PYTHONN";

    cout << "Result string: " << onlyLeftOrRight("CORONAVIRUS") << endl;
    

    return 0;
}