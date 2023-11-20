/*
PROBLEM: CHMOD is a command in the UNIX computer system.  It is the command used for giving users permissions
to access and change files and directories.  There are 3 classes of users.
They are the owner, the group and others.  The permissions given are: read(r), write(w) and execute(x).
The argument of the CHMOD command is a 3-character octal number (ex. 526).  When each digit of that number
is converted to binary, the binary digits are paired to represent read,
write and execute in that order.  526 would convert to 101 010 110.
The first binary conversion gives the user permissions.  The second gives the group permissions.
 The third gives the others permissions.  So here, the owner has read and execute
permissions and that is represented by r-x.  The group has only write permission given by -w-.
The others class has read and write permissions as shown by rw-.
Putting all of the above together CHMOD 526 = 101 010 110 = r-x -w- rw-
INPUT:  There will be 5 lines of input.  Lines 1 and 2 will each contain 3 octal digits.
Lines 3 and 4 will each contain three 3-digit binary numbers.  Line 5 will contain three 3-character stings.

OUTPUT:  For each line of input print the other two equivalent forms of the CHMOD result.
Print a space between each grouping as shown below.


SAMPLE INPUT					SAMPLE OUTPUT
1.  5, 2, 6						1.  101 010 110  and r-x -w- rw-
2.  7, 3, 0						2.  111 011 000  and rwx -wx ---
3   100, 001, 101 					3,  415 and r-- --x r-x
4.  010, 011, 100 					4.  234 and -w- -wx r--
5.  r-x, rw-, rwx					5.  567 and 101 110 111
*/

#include <iostream>
#include <fstream>
#include <regex>
#include <vector>
#include <bitset>
#include <cmath>

#define FNAME "acsl_chmod.dat"

std::string dec2bin(const std::string s) {
    std::bitset<3> bset(std::stoi(s));

    return bset.to_string();
}

std::string bin2dec(const std::string s) {
    int dec = 0, i = 0, rem;
    long long n = std::stoll(s);

    while(n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * pow(2, i);
        ++i;
    }

    return std::to_string(dec);
}

std::string get_mask(int v) {
    std::string ret = "---";

    if(v & 4) {
        ret.at(0) = 'r';
    }
    if(v & 2) {
        ret.at(1) = 'w';
    }
    if(v & 1) {
        ret.at(2) = 'x';
    }

    return ret;
}

std::string get_mask(const std::string& s) {
    return get_mask(std::stoi(s));
}

std::string mask2str(const std::string& s) {
    int ret = 0;

    for(auto ch: s) {
        switch(ch) {
            case 'r' :
                ret += 4;
                break;
            case 'w' :
                ret += 2;
                break;
            case 'x':
                ret += 1;
                break;
        }
    }

    return std::to_string(ret);
}

int main() {
    std::ifstream fin;
    std::string input;

    fin.open(FNAME);
    int count = 0;
    while(std::getline(fin, input)) {
        std::cout << "INPUT = " << input << std::endl;

        std::regex re(R"([\s|,]+)");
        std::sregex_token_iterator it { input.begin(), input.end(), re, -1 };
        std::vector<std::string> parts {it, {}};

        if(count == 0 || count == 1) {
            std::string no = dec2bin(parts[0]);
            std::string no2 = dec2bin(parts[1]);
            std::string no3 = dec2bin(parts[2]);

            std::cout << no << " " << no2 << " " << no3 << " and "
                << get_mask(no) << " " << get_mask(no2) << " " << get_mask(no3) << std::endl;
        }
        if(count == 2 || count == 3) {
            std::string no = bin2dec(parts[0]);
            std::string no2 = bin2dec(parts[1]);
            std::string no3 = bin2dec(parts[2]);

            std::cout << no << no2 << no3 << " and "
                << get_mask(no) << " " << get_mask(no2) << " " << get_mask(no3) << std::endl;
        }
        if(count == 4) {
            std::string no = mask2str(parts[0]);
            std::string no2 = mask2str(parts[1]);
            std::string no3= mask2str(parts[2]);

            std::cout << no << no2 << no3 << " and "
                << dec2bin(no) << " " << dec2bin(no2) << " " << dec2bin(no3) << std::endl;
        }

        count += 1;
    }
}