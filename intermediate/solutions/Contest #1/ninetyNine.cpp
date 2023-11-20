/*
PROBLEM: ACSL Ninety-Nine is a two-player card game played with a standard deck of 52-cards (2 – 9, T, J, Q, K, A).
 To start, each player is dealt 3 cards and the remaining cards are placed face down on the table (the pile).  
 In an actual game the point total is set to zero, but for this program an initial point total will be 
 given.  Each player in turn puts down one card and changes the point total according to the point value 
 of his card and then selects a card from the top of the pile.  Each card adds its face value in points 
 (e.g. a 5 is worth five points, a T is worth 10 points, a J is worth 11 points, a Q is worth 12 points,
  a K is worth 13  points and an A is worth 14 points) except for certain cards that have special values or meanings:
    • A 9 is a pass (and does not change point total).
    • A T subtracts 10 points from the total.
    • An A adds either 1 or 14 to the point total.  The 14 is played first as long as it does not put the point total over 99.
Cards are played using the following rule: Play the largest face value card.
The game ends when the card played puts the point total over 99.

INPUT:  There will be 5 lines of input.  Each line will contain an integer followed by 10 one-character strings.  The integer gives the
 initial point total. The first 3 one-character strings will represent the 3 cards dealt to the player. The remaining one-character strings
  will be, in order, the card picked by the player and the card played by the dealer.

OUTPUT:  For each line of input, print the point total when the game ends and who won (player or dealer).  We guarantee the data will always
produce a winner.

Ex:  In Sample Input #1, the point total starts at 75.  The player gets 3 cards: 7, 3 and 8.  He plays the largest card – the 8.  The point 
total is now 83.  The player picks the next card – an 8.  The dealer plays the 7.  The point total is now 90.  The player has a 7, a 3 and an 
8.  He plays the 8 and the point total is now 98.  The player picks the next card the T.  The dealer plays the 5.  The point total is now 103.  
The game ends and the player wins.  The remaining cards on the input line are not used.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <fstream>
#include <algorithm>

using namespace std;

#define FNAME "ninetyNine.data"

void trimString(string& x) {
    x.erase(0, x.find_first_not_of(" "));
} 

//defines the value of the cards. values are passed as string
int cardValue(string x, int points) {
    if(x == "T") {
      return 10;
    } else if(x == "J") {
        return 11;
    } else if(x == "Q") {
        return 12;
    } else if (x == "K"){
        return 13;
    } else if(x == "A") {
        return 14;
    }

    return stoi(x);
}

//plays the game
void game(string input) {
    int counter = 0;
    int points = 0;

    vector<int> playerCards;

    int pos;

    while( (pos = input.find(",")) != string::npos ) {
        string value = input.substr(0, pos);
        trimString(value);
        
        input.erase(0, pos + 1);

        //cout << "value = " << value << "/ input = " << input << endl;
        int cardV = cardValue(value, points);
        //cout << "cardValue = " << cardV << endl;

        //initial score
        if(counter == 0) {
            points = cardV;
        }

        //the following section is dedicated to picking up cards for either the player or the dealer

        //first cards the player gets
        if(counter >= 1 && counter <= 3) {
            playerCards.push_back(cardV);
        }

        //dealer plays
        if(counter > 4 && counter % 2 != 0) {
            int played_value = cardV;

            if(played_value == 10) {
                points -= 10;
            } else if (played_value == 9) {
                points += 0;
            } else if (played_value == 14) {
                if(points + 14 < 99) {
                    points += 14;
                } else {
                    points += 1;
                }
            } else {
                points += played_value;
            }

            if(points > 99) {
                cout << "points = " << points << ", player" << endl;
                return;
            }
        }

         //adds a card to the players stack
        if(counter >= 4 && counter % 2 == 0) {
            playerCards.push_back(cardV);
        }

        //player plays the highest card
        if(counter >= 3 && (counter % 2 == 0 || counter == 3)) {

            int played_value =  (int) *max_element(playerCards.begin(), playerCards.end());
            if(played_value == 10) {
                points -= 10;
            } else if (played_value == 9) {
                points += 0;
            } else if (played_value == 14) {
                if(points + 14 < 99) {
                    points += 14;
                } else {
                    points += 1;
                }
            } else {
                points += played_value;
            }

            playerCards.erase(max_element(playerCards.begin(), playerCards.end()));

            if(points > 99) {
                cout << "points = " << points << ", dealer" << endl;
                return;
            }
        }

        counter++;
    }
    
    //last card left in input
    int cardV = cardValue(input, points);

    if(counter % 2 == 0) {

        playerCards.push_back(cardV);

        points += (int) *max_element(playerCards.begin(), playerCards.end());

        if(points > 99) {
            cout << "points = " << points << ", dealer" << endl;
        }

    } else {
        points += cardV;

        if(points > 99) {
            cout << "points = " << points << ", player" << endl;
        }
    }

}

int main()
{
    ifstream fin;
    fin.open(FNAME);

    string input;

    while (getline(fin, input))
    {
      game(input);
    }
    

    return 0;
}