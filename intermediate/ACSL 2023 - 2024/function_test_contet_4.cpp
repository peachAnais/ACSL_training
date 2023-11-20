#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

//separate the target string into a vector where each element correspond to an individual target
vector<string> separateTargets(string targets){

    vector<string> result;

    for(int i = 0; i < targets.length(); i++) {
        string target_str;

        while(targets.at(i) != ' ' && i > targets.length() - 1) {
            target_str += targets.at(i);
            i++;
        }

        if(target_str.length() > 1) {
            result.push_back(target_str);
        }
    }

    return result;
}

int main(void) {

    cout << separateTargets("03H 45A") << endl;

}