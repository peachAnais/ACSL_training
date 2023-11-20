/*
PROBLEM:  Every computer language has different string functions.  For this program you will be asked to code algorithms that replicate the ACSL string functions listed below, all of 
which split strings up into separate parts:

1.  char_split (a$, n, ‘char’) – char_split divides a given string (a$) into substrings of length n separated by the given character.
2.  strrem (a$, b$) – removes all occurrences of b$
3.  strchr (a$, b$) – strchr searches a$ for the first occurrence of b$ and returns the characters of a$ before the first occurrence of b$
4.  strtok(a$, b$) – strtok splits a given string (a$) into substrings each time the character b$ is found.  Substrings must be separated by spaces.
5.  wordwrap(a$, n, b$) – wordwrap outputs the substrings of a$ that are a maximum of n characters in length or that begin with the character b$.  Substrings must be separated by 
spaces.
INPUT:  There will be 5 lines of input.  Each line of input will contain a character string (a$) and the data for the arguments needed for the like numbered functions above.
The length of a$ will be fewer than 25 characters.  

OUPUT:  For each line of input print the result of applying the like numbered function above.
SAMPLE INPUT					SAMPLE OUTPUT
	1.  MISSISSIPPI, 2, *			1.  MI*SS*IS*SI*PP*I
	2.  MISSISSIPPI, IS 			2.  MSSIPPI
	3.  MISSISSIPPI, P				3.  MISSISSI
	4.  MISSISSIPPI, I				4.  M ISS ISS IPP I
	5.  MISSISSIPPI, 2, I			5.  M IS S IS S IP P I
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

ifstream fin("asclString.in");

//separate input to find the function we will be using
string sepInput(string& input, int& functionNum) {

    functionNum =  int(input.at(0));

    input.erase(input.begin(), input.begin() + 2);

    return input;
}

//separates the work string in string vector
vector <string> createStringVector (string workStr) {

    int pos;
    vector <string> resultVector;

    while (pos = workStr.find(", ")) {

        resultVector.push_back(workStr.substr(0, pos));

        workStr.erase(0, pos);
    }

    return resultVector;
}


//char_split (a$, n, ‘char’) – char_split divides a given string (a$) into substrings of length n separated by the given character
string char_split(string str, int n, char divider) {

    string resultString;
    
    for(int i = 0; i < str.length(); i++) {

        resultString += str.at(i);
         
        if ((i + 1) % n == 0) {
            resultString += divider;
        }
    }

    return resultString;
}

//strrem (a$, b$) – removes all occurrences of b$
string strrem (string str, string remove) {

    int rmStrLgt = remove.length();

    for(int i = 0; i < str.length(); i++) {
        int pos = str.find(remove);

        str.erase(i, pos);
    }

    return str;
}

//strchr (a$, b$) – strchr searches a$ for the first occurrence of b$ and returns the characters of a$ before the first occurrence of b$
string strchr(string str, string search) {
    
    int pos = str.find(search);

    str.erase(pos, str.size() - pos);

    return str;
}

//strtok(a$, b$) – strtok splits a given string (a$) into substrings each time the character b$ is found.  Substrings must be separated by spaces
string strtok(string str, char find) {

    string resultString;

    for(int i = 0; i < str.length(); i++) {

        if(str.at(i) == find) {
            resultString.append(" ");
            resultString += str.at(i);
        }

        resultString += str.at(i);

    }

    return resultString;

}

//wordwrap outputs the substrings of a$ that are a maximum of n characters in length or that begin with the character b$. substrings will be separated by spaces
string wordwrap (string str, int lgt, char find) {

    string resultString;

    for (int i = 0; i < str.size(); i++) {
        
        if(str.at(i + 1) == find) {
            
            resultString += " ";

            for(int j = i; j< lgt; j++) {

                resultString += str.at(j);

            }
        } else {
            
            resultString += str.at(i);
        }
    }

    return resultString;

}

int main(){

    int functionNum;
    string input;
    string workString;
    vector <string> data;

    while(fin >> input) {

        fin >> input;

        workString = sepInput(input, functionNum);

        data = createStringVector (workString);

        string baseString = data.at(0);

        if (functionNum == 1) {


            int n = stoi(data.at(1));

            string aux = data.at(2);

            char divider = aux.at(0);

            cout << char_split(baseString, n, divider) << endl;

            baseString.erase();

        } else if (functionNum == 2) {

            string remove = data.at(1);

            cout << strrem(baseString, remove) << endl;

            baseString.erase();

        } else if (functionNum == 3) {

            string search = data.at(1);

            cout << strchr(baseString, search) << endl;

            baseString.erase();

        } else if (functionNum = 4) {

            string aux = data.at(1);

            char find = aux.at(0);

            cout << strtok(baseString, find) << endl;

            baseString.erase();

        } else if (functionNum = 5) {

            int lgt = stoi(data.at(1));

            string aux = data.at(2);

            char find = aux.at(0);

            cout << wordwrap(baseString, lgt, find) << endl;

            baseString.erase();

        }

    }

    return 0;
}