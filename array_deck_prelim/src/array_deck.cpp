/*
 * Arrays
 *
 *  Created on: Sep 27, 2020
 *      Author: cj6bo
 *      final version of homework 5 for review
 */

#include <fstream>
#include <iostream>
#include <stdlib.h>
#include <time.h>


using namespace std;

bool inDeckAlready(int newValue, int numberOfEntries, int deck[]) {
	for (int j=0; j< numberOfEntries; j++) {
		if (newValue == deck[j]) {
			return true;
		}
	}
	//not in deck
	return false;
}
void printDeck(int deck[]) {
	for (int i=0; i<52; i++) {
		int faceValue = deck[i]/4 + 1;
		switch ( faceValue ) {
		case 13: cout<<"King"; break;
		case 12: cout<<"Queen"; break;
		case 11: cout<<"Jack"; break;
		default : cout<<faceValue; break;
		}

		int suit = deck[i] % 4;

		switch ( suit ) {
		case 0: cout<<" of Hearts"<<std::endl; break;
		case 1: cout<<" of Diamonds"<<std::endl; break;
		case 2: cout<<" of Spades"<<std::endl; break;
		case 3: cout<<" of Clubs"<<std::endl; break;
		default: cout <<"no suit"<<std::endl; break;
		}
	}
}
int main() {
	srand (time(NULL));
	int deck[52];
	for (int i=0; i < 52; i++) {
		//generate random number -
		int newValue = rand() % 52;
		//see if it's been used already?
		//if so, repick until not seen
		while (inDeckAlready(newValue, i, deck) ) {
			newValue = rand() % 52;
		}
		deck[i] = newValue;
	}
	printDeck(deck);
}
