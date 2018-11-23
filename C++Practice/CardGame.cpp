#include <iostream>

using namespace std;

const int clubs = 0; //suits
const int diamonds = 1;
const int hearts = 2;
const int spades = 3;

const int jack = 11; //face cards
const int queen = 12;
const int king = 13;
const int ace = 14;

struct card {
    int number;     //2 to 10, jack, queen, king, ace
    int suit;       //clubs, diamonds, hearts, spades
};

int main() {
    card temp, chosen, prize;
    int position;

    card card1 = { 7, clubs };          //initialize card1
    cout << "Card 1 is the 7 of clubs\n";

    card card2 = { jack, hearts };      //initialize card2
    cout << "Card 2 is the jack of hearts\n";

    card card3 = { ace, spades };       //initialize card3
    cout << "Card 3 is the ace of spades\n";

    prize = card3;

    cout << "I am swapping cards 1 and 3\n";
    temp = card3;
    card3 = card1;
    card1 = temp;

    cout << "I am swapping cards 2 and 3\n";
    temp = card3;
    card3 = card2;
    card2 = temp;

    cout << "I am swapping cards 1 and 2\n";
    temp = card2;
    card2 = card1;
    card1 = temp;

    cout << "Now where(1, 2, 3) is the ace of spades? ";
    cin >> position;

    switch (position) {
        case 1:
            chosen = card1;
            break;
        case 2:
            chosen = card2;
            break;
        case 3:
            chosen = card3;
            break;
    }

    if (chosen.number == prize.number && chosen.suit == prize.suit)
        cout << "That's right/n";
    else
        cout << "You lose/n";
}