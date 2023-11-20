/*
PROBLEM: CHMOD is a command in the UNIX computer system.  It is the command used for giving users permissions to access and change files and directories.  There are 3 classes of users.
They are the owner, the group and others.  The permissions given are: read(r), write(w) and execute(x).
The argument of the CHMOD command is a 3-character octal number (ex. 526).  When each digit of that number is converted to binary, the binary digits are paired to represent read,
write and execute in that order.  526 would convert to 101 010 110.  
The first binary conversion gives the user permissions.  The second gives the group permissions.  The third gives the others permissions.  So here, the owner has read and execute
permissions and that is represented by r-x.  The group has only write permission given by -w-.   The others class has read and write permissions as shown by rw-.
Putting all of the above together CHMOD 526 = 101 010 110 = r-x -w- rw-
INPUT:  There will be 5 lines of input.  Lines 1 and 2 will each contain 3 octal digits.  Lines 3 and 4 will each contain three 3-digit binary numbers.  Line 5 will contain three 
3-character stings.
OUTPUT:  For each line of input print the other two equivalent forms of the CHMOD result.  Print a space between each grouping as shown below.



SAMPLE INPUT					SAMPLE OUTPUT
1. 5, 2, 6						1. 101 010 110  and r-x -w- rw-
2. 7, 3, 0						2. 111 011 000  and rwx -wx ---
3  100, 001, 101 				3. 415 and r-- --x r-x
4. 010, 011, 100 				4. 234 and -w- -wx r--
5. r-x, rw-, rwx				5. 567 and 101 110 111
*/

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>

#define FNAME "chmod.data";

using namespace std;

//separate input string in 3 parts
vector<string> sepString (string &input) {

    vector<string> newVector;

    input.erase(input.begin(), input.begin() + 3);

    int i = 0;
    do {

        if(int(input.at(i)) > 47 &&  input.at(i) < 58) {

            string toAdd;

            toAdd.push_back(input.at(i));

            newVector.push_back(toAdd);

            toAdd.erase();
        }

        i++;

    } while (i != input.length());

    return newVector;
}

//converts a vector<string> to a vector <int>
vector<int> strVectorToIntVector (vector<string> string_vector){
    vector<int> resultingVector;

    for(int i = 0; i < string_vector.size(); i++){
        resultingVector.push_back(stoi(string_vector.at(i)));
    }
    
    return resultingVector;
}

//convert base 10 digit to base 2 and return result as vector <int>
vector <int> decToBin (int x) {

    vector<int> binary_digits;

    int newNum = 0;
    int grade = 0;

    while(x != 0) {
        int cif = x % 2;
        x /= 2;

        binary_digits.push_back(cif);
    }

    for(int i = 0; i < binary_digits.size() / 2; i++) {
        swap(binary_digits.at(i), binary_digits.at(binary_digits.size() - i - 1));
    }

    return binary_digits;
}

//convert base 2 to DEC digit
int binToDec (vector <int> binary_digits) {
    int digit = 0;

    for(int i = binary_digits.size() - 1; i >= 0; i--) {
        digit += pow(2, i) * binary_digits.at(i);
    }
    
    return digit;
}


//convert base 2 to r/w/x permissions
string chmod(vector<int> binary_digits) {
    string chmod;

    for(int i = 0; i < binary_digits.size(); i++) {
        if(i == 0) {

            if( binary_digits.at(i) == 1) {
                chmod.append("r");
            } else {
                chmod.append("-");
            }

        } else if (i == 1) {

             if( binary_digits.at(i) == 1) {
                chmod.append("w");
            } else {
                chmod.append("-");
            }

        } else if(i == 2) {

             if( binary_digits.at(i) == 1) {
                chmod.append("x");
            } else {
                chmod.append("-");
            }
        }
    }

    return chmod;
}


//convert r/w/x permission to binary ONLY for one group of 3 (will ve parsed as a string)
vector <int> binaryDigitsFromPermission(string permission) {

    vector <int> binary;
    
    for (int i = 0; i < permission.size(); i++) {

        if (i == 0) {

            if(permission.at(i) == 'r') {
                binary.push_back(1);
            } else {
                binary.push_back(0);
            }

        } else if (i == 1) {

            if(permission.at(i) == 'w') {
                binary.push_back(1);
            } else {
                binary.push_back(0);
            }

        } else if (i == 2) {

            if(permission.at(i) == 'x') {
                binary.push_back(1);
            } else {
                binary.push_back(0);
            }

        }
    }
    return binary;
}

// reate num from vector <int>
int createNum (vector <int> vector) {
    int newNum = 0;

    for(int i = 0; i < vector.size(); i++) {
        if(vector.at(i) == 0) {
            newNum = newNum * 10;
        } else {
            if(vector.at(i - 1) == 0) {
                newNum += vector.at(i);
            } else {
                newNum += newNum * 10 + vector.at(i);
            }
        }
    }

    return newNum;
}

//stores the digits of a num in a vector <int>
vector <int> digitVector (int x) {
    vector <int> digits;

    do {
        digits.push_back(x % 10);

        x /= 10;

    } while(x != 0);

    return digits;
}

//solves problem for DEC int sample input
string solveForDecInput(string input) {
    vector <string> workVector = sepString(input);

    vector <int> dec_vector = strVectorToIntVector(workVector);

    //every relevant will be stored in a RESULT string
    string binaryResults;
    string permisssionResults;
    string finalResult;

    for(int i = 0; i < dec_vector.size(); i++) {
        vector <int> binary = decToBin(dec_vector.at(i));

        binaryResults.append(to_string(createNum(binary)));
        binaryResults.append(" ");

        permisssionResults.append(chmod(binary));
        permisssionResults.append(" ");
    }

    finalResult = binaryResults.append(permisssionResults);

    return finalResult;
}

//solves input for BIN int sample input
string solveForBinInput (string input) {

    string permissionResult;
    int decResult = 0;
    string decNum;
    string finalResult;
    
    vector <string> work_vector = sepString(input);

    vector <int> binary_vector = strVectorToIntVector(work_vector);
    vector <int> dec_vector;

    for(int i  =0; i < binary_vector.size(); i++) {
        vector <int> binaryNumDigits = digitVector(binary_vector.at(i));

        string accesModifier = chmod(binaryNumDigits);
        permissionResult.append(accesModifier);

        decResult += decResult * 10 + binToDec(binaryNumDigits);
    }

    decNum = to_string(decResult);

    finalResult.append(decNum);
    finalResult.append(" and ");
    finalResult.append(permissionResult);

    return finalResult;
}

//solves problem for CHMOD input
string solveForStringInput(string input) {

    vector <string> workVector = sepString(input);

    string finalResult;

    vector <int> binaryDigits;
    string binaryString;

    vector <int> decimalVector;
    vector <string> decimalStrings;

    for(int i = 0; i < workVector.size(); i++) {

        binaryDigits = binaryDigitsFromPermission(workVector.at(i));
        decimalVector.push_back(binToDec(binaryDigits));

        string binStrAdd = to_string(createNum(binaryDigits));
        binaryString.append(binStrAdd);

    }

    int decNum = createNum(decimalVector);
    
    finalResult.append(to_string(decNum));
    finalResult.append(" and ");
    finalResult.append(binaryString);

    return finalResult;
    
}

int main(){
    
    string input;
    string result;

    int line_counter = 1;

    ifstream fin("chmod.data");

    while (line_counter <= 5){

        if (line_counter == 1 || line_counter == 2) {
            
            getline(fin, input);

            result = solveForDecInput(input);

            cout << "Result for decimal input is: " << result << endl;

            line_counter++;

            input.erase();

        } else if (line_counter == 3 || line_counter == 4) {

            getline(fin, input);

            result = solveForBinInput(input);

            cout << "Result for binary input is: " << result << endl;

            line_counter++;

            input.erase();

        } else if(line_counter == 5) {

            getline(fin, input);

            result = solveForStringInput(input);

            cout << "Result for CHMOD input is: " << endl;

            line_counter++;

            input.erase();

        }
    }

    return 0;
}