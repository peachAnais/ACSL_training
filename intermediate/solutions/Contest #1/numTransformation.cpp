//http://www.datafiles.acsl.org/samples/contest1/C_1_INT_Transform.pdf

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <string>

using namespace std;

ifstream fin("numTransformation.in");

//stores data read from a file in 2 vectors, the first containg the numbers which wil be transform, the second one contaiing their coresponding Pth position
void get_data(){

}

//transform given number into vector
vector<int> num_to_vector(int x){
    vector<int> res;

    while(x != 0){
        res.insert(res.begin(), x % 10);
        x /= 10;
    }
    return res;
}

//transform a vector into a number
int vector_to_num(vector<int> digits){
    int res = 0;

    for(int i = 0; i < digits.size(); i++){
        res= res * 10 + digits.at(i);
    }
    return res;
}

//returns th eindex of a certain value in the vector. it is guranteed that the value is found in th evector
int find_index(vector<int> vct, int val){
    for(int i = 0; i < vct.size(); i++){
        if(vct.at(i) == val){
            return i;
        }
    }
}

//solves problem
void solve(int num, int pos){

    vector<int> num_vct = num_to_vector(num);

    int val = num_vct.at(pos);
    int n = find_index(num_vct, val);

    for(int i = 0; i < n; i ++){
        num_vct.at(i) = num_vct.at(i) + val;
    }

    for(int i = num_vct.size() - 1; i > n; i--){
        num_vct.at(i) = abs(num_vct.at(i) - val);
    }

    cout << vector_to_num(num_vct) << endl;

}

int main(){

    int num = 102439;
    int pos = 3;

    solve(num, pos);

    return 0;
}