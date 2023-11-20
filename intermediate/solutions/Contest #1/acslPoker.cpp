//intermediate: 2004 - 2005

/*
PROBLEM:  A deck of playing cards has 52 cards.  The cards are separated into 4 suits: diamonds, hearts, spades and clubs.  Each suit has 13 cards that are labeled ace, 2 –10, jack, queen
and king.  For this program diamonds will be numbered 1 –13 to represent the cards ace through king, hearts will be numbered 14 – 26, spades will be numbered 27 – 39 and clubs will be 
numbered 40 – 52.   In ACSL Poker you will be dealt 5 cards.  Your task is to determine the best hand possible using those cards.  The hands, in order of rank from low to high, to test for 
are:

A PAIR – Exactly 2 cards with the same label but of any suit - example:  a 5 of hearts and a five of clubs.  This would be cards - 18 and 44.

TWO PAIRS – 2 different pairs – example: a 5 of hearts and a 5 of clubs and an 8 of spades and an 8 of hearts.  This would be cards - 18, 44, 34 and 21.

THREE OF A KIND – Exactly 3 cards with the same label but of any suit – example: a 5 of hearts, a 5 of clubs and a five of spades. This would be cards - 18, 44 and 31.

FLUSH – 5 cards of the same suit - example: 5, 6, 7, 8 and 10 of diamonds.  This would be cards – 5, 6, 7, 8 and 10.

FULL HOUSE – A pair and three of a kind – example: a 5 of hearts, a 5 of clubs and a five of spades and an 8 of spades and an 8 of hearts.  This would be cards - 18, 44, 31, 34 and 21.  

FOUR OF A KIND – Exactly 4 cards with the same label – example:  a 5 of hearts, a 5 of clubs, a 5 of spades and a 5 of diamonds.  This would be cards - 18, 44, 31 and 5.


INPUT: There will be 5 lines of input.  Each line will consist of 5 unique integers from 1 to 52 inclusive.  

OUTPUT:  For each line of input print the name of the highest hand possible.  If no listed hand is possible, print NONE.
*/

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <algorithm>
#include <climits>

using namespace std;

//returns the real value of any given card
int get_real_value(int card_val){
    if(card_val >= 1 && card_val <= 13){
        return card_val;
    } else if(card_val >= 14 && card_val <= 26){
        return card_val - 13;
    } else if(card_val >= 27 && card_val <= 39) {
        return card_val - 26;
    } else if(card_val >= 40 && card_val <= 52){
        return card_val - 39;
    }
}

//return the suit of a card: 1 - diamond, 2 - hearts, 3 - spades, 3 - clubs
int suit(int val){
    if(val >= 1 && val <= 13){
        return 1;
    } else if(val >= 14 && val <= 26){
        return 2;
    } else if(val >= 27 && val <= 39) {
        return 3;
    } else if(val >= 40 && val <= 52){
        return 4;
    }
}

//returns the maximum valule in a given set of cards
int max_in_cards(vector<int> cards){
    int max_val = INT16_MIN;

    for(int i = 0; i < cards.size(); i++){
        if(cards.at(i) > max_val){
            max_val = cards.at(i);
        }
    }
    return max_val;
}


//the follwing functions will test for a hand

//function tests for pair
bool is_pair(vector<int> cards){

    vector<int> map_vector;
    for(int i = 0; i < max_in_cards(cards) + 1; i++){
        map_vector.push_back(0);
    }

    for(int i = 0; i <= cards.size(); i++){
        map_vector.at(get_real_value(cards.at(i)))++;
    }

    for(int i = 0; i <= map_vector.size(); i++){
        if(map_vector.at(i) == 2){
            return true;
        } else {
            return false;
        }
    }
}

//function tests for 2 pairs
bool double_pair(vector<int> cards){
    vector<int> map_vector;

    for(int i = 0; i < max_in_cards(cards); i++){
        map_vector.push_back(0);
    }

    for(int i = 0; i <= cards.size(); i++){
        map_vector.at(get_real_value(cards.at(i)))++;
    }

    int pair_cnt = 0;
    for(int i = 0; i <= map_vector.size(); i++){
        if(map_vector.at(i) == 2){
            pair_cnt++;
        }

        if(pair_cnt == 2){
            break;
        }
    }

    if(pair_cnt == 2){
        return true;
    } else {
        return false;
    }
}

//function tests for 3 of a kind
bool kind_3(vector<int> cards){
    vector<int> map_vector;
    for(int i = 0; i < max_in_cards(cards); i++){
        map_vector.push_back(0);
    }

    for(int i = 0; i <= cards.size(); i++){
        map_vector.at(get_real_value(cards.at(i)))++;
    }

    int cards_3 = 0;
    for(int i = 0; i <= map_vector.size(); i++){
        if(map_vector.at(i) == 3){
            cards_3 = 1;
            return true;
        }
    }

    if(cards_3 == 0) {
        return false;
    }
}

//function tests for a flush
bool flush(vector<int> cards){

    vector<int> suit_mapper;
    for(int i = 0; i < 5; i++){
        suit_mapper.push_back(0);
    }

    vector<int> card_suits;
    for(int i = 0; i < cards.size(); i++){
        card_suits.push_back(suit(cards.at(i)));
    }

    for(int i = 0; i < 5; i++){
        suit_mapper.at(card_suits.at(i))++;
    }

    int flush = 0;
    for(int i = 0; i < 5; i++){
        if(suit_mapper.at(i) == 5){
            flush = 1;
            return true;
        }
    }

    if(flush == 0) {
        return false;
    }
}

//function tests for a full house
bool full_house(vector<int> cards){
    if(is_pair(cards) == true && kind_3(cards) == true){
        return true;
    } else {
        return false;
    }
}

//function tests for 4 of a kind
bool kind_4(vector<int> cards){
    vector<int> map_vector;
    for(int i = 0; i < max_in_cards(cards); i++){
        map_vector.push_back(0);
    }

    for(int i = 0; i <= cards.size(); i++){
        map_vector.at(get_real_value(cards.at(i)))++;
    }

    int cards_4 = 0;
    for(int i = 0; i <= map_vector.size(); i++){
        if(map_vector.at(i) == 4){
            cards_4 = 1;
            return true;
        }
    }

    if(cards_4 == 0) {
        return false;
    }
}

//solve problem
void solve(vector<int> cards){
    string best_hand = "NONE";

    if(is_pair(cards) == true){
        best_hand = "PAIR";
    }

    if(double_pair(cards) == true){
        best_hand = "TWO PAIRS";
    }

    if(kind_3(cards) == true){
        best_hand = "THREE OF A KIND";
    }

    if(flush(cards) == true){
        best_hand = "FLUSH";
    }

    if(full_house(cards) == true){
        best_hand = "FULL HOUSE";
    }

    if(kind_4(cards) == true){
        best_hand = "FOUR OF A KIND";
    }
}

int main(){

    vector<int> cards = {18, 44, 7, 21, 23};
    is_pair(cards);
    double_pair(cards);
    kind_3(cards);
    flush(cards);
    full_house(cards);
    kind_4(cards);
    solve(cards);

    return 0;
}