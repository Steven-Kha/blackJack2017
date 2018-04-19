//main.cpp
//Details
//Activity
//LAST YEAR
//
//You uploaded an item
//Sep 25, 2016
//Text
//main.cpp
//No recorded activity before September 25, 2016
//New Team Drive

#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Header.h"

using std::string;
using namespace std;

class player {
private:
	int score;
public:
	player() {};
	player(int score) :score(score) {};
	~player() {};
	void setScore(int x) {
		score = x;
	}
	int getScore() {
		return score;
	}

};
class deck {
private:
	int number;
	string face;
	string suit;
	/*int size;*/
	//int turn;

	//8 decks
	//go through 8 cards...
	//delete one card
	//dll
	//delete a node
	//

public:
	deck() {};

	deck(int number, string suit, string face /*int size*/) :
		number(number), suit(suit), face(face)/*, size(size)*/ {};

	~deck() {};

	void setNumber(int x) {
		number = x;
	}

	/*void setTurn(int x){
	turn = x;
	}*/

	void setFace(string x) {
		face = x;
	}

	void setSuit(string x) {
		suit = x;
	}

	/*void setSize(int x){
	size = x;
	}*/

	int getNumber() {
		return number;
	}

	string getSuit() {
		return suit;
	}

	string getFace() {
		return face;
	}

	//int getSize(){
	//return size;
	//}

	/*int getTurn(int x){
	return turn;
	}*/
};


void buffer(DLinkedList<deck> dList, DLinkedList<deck> hList, DLinkedList<deck> hList2, player One, player Two, int turn);
void buffer2(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn);
void shown(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn);
void hidden(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn);
int value(DLinkedList<deck> & hList, player & One, player & Two, int & turn);
void waitingTime(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn);
void closingTime();

int main() {

	player One;
	One.setScore(0);
	player Two;
	Two.setScore(0);
	int turn = 1;

	DLinkedList<deck> dList;

	DLinkedList<deck> handList;

	DLinkedList<deck> hList2;

	buffer(dList, handList, hList2, One, Two, turn);

	system("pause");
	exit(1);
	return 0;
}

void buffer(DLinkedList<deck> dList, DLinkedList<deck> hList, DLinkedList<deck> hList2, player One, player Two, int turn)
{
	//creating the deck
	for (int i = 0; i < 52; i++)
	{
		deck *b = new deck(i + 2, "Diamonds", "");
		if (i < 9) {
			dList.addFront(*b);
		}

		if (i>8 && i<18)
		{
			deck *b = new deck(i - 7, "Clubs", "");
			dList.addFront(*b);
		}

		if (i>17 && i <27)
		{
			deck *b = new deck(i - 16, "Hearts", "");
			dList.addFront(*b);
		}

		if (i>26 && i<36)
		{
			deck *b = new deck(i - 25, "Spades", "");
			dList.addFront(*b);
		}

		if (i>35 && i <37)
		{
			deck *b = new deck(0, "Diamonds", "Ace");
			dList.addFront(*b);
		}

		if (i>36 && i <38)
		{
			deck *b = new deck(0, "Diamonds", "Jack");
			dList.addFront(*b);
		}

		if (i>37 && i <39)
		{
			deck *b = new deck(0, "Diamonds", "Queen");
			dList.addFront(*b);
		}

		if (i>38 && i <40)
		{
			deck *b = new deck(0, "Diamonds", "King");
			dList.addFront(*b);
		}

		if (i>39 && i <41)
		{
			deck *b = new deck(0, "Clubs", "Ace");
			dList.addFront(*b);
		}

		if (i>40 && i <42)
		{
			deck *b = new deck(0, "Clubs", "Jack");
			dList.addFront(*b);
		}

		if (i>41 && i <43)
		{
			deck *b = new deck(0, "Clubs", "Queen");
			dList.addFront(*b);
		}

		if (i>42 && i <44)
		{
			deck *b = new deck(0, "Clubs", "King");
			dList.addFront(*b);
		}
		if (i>43 && i <45) {
			deck *b = new deck(0, "Hearts", "Ace");
			dList.addFront(*b);
		}

		if (i>44 && i <46) {
			deck *b = new deck(0, "Hearts", "Jack");
			dList.addFront(*b);
		}

		if (i>45 && i <47) {
			deck *b = new deck(0, "Hearts", "Queen");
			dList.addFront(*b);
		}

		if (i>46 && i <48) {
			deck *b = new deck(0, "Hearts", "King");
			dList.addFront(*b);
		}

		if (i>47 && i <49) {
			deck *b = new deck(0, "Spades", "Ace");
			dList.addFront(*b);
		}

		if (i>48 && i <50) {
			deck *b = new deck(0, "Spades", "Jack");
			dList.addFront(*b);
		}

		if (i>49 && i <51) {
			deck *b = new deck(0, "Spades", "Queen");
			dList.addFront(*b);
		}

		if (i>50 && i <52) {
			deck *b = new deck(0, "Spades", "King");
			dList.addFront(*b);
		}
	}

	buffer2(dList, hList, hList2, One, Two, turn);

}

void buffer2(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn)
{
	char choice;

	if (turn > 4) //turn start at one
	{
		cout << "--------------------------------------------\n"
			<< "GAME SET\n"
			<< "---------------------------------------------\n";
		system("pause");
		system("cls");
		cout << "The winner is: ";
		if (One.getScore() > Two.getScore())
		{
			cout << "Player Two: ["; system("pause");
			cout << "] score: " << Two.getScore() << "\n";
			cout << "Player One: [";
			system("pause");
			cout << "] score: " << One.getScore() << "\n";
			cout << "Winner is Player One! " << endl << endl;
			cout << "Player 1 hand: " << endl;
			hList.print();
			cout << "Player 2 hand: " << endl;
			hList2.print();

		}
		else if (Two.getScore() > One.getScore())
		{

			cout << "Player One: [";
			system("pause");
			cout << "] score: " << One.getScore() << "\n";
			cout << "Player Two: [";
			system("pause");
			cout << "] score: " << Two.getScore() << "\n";
			cout << "Winner is Player Two! " << endl << endl;
			cout << "Player 1 hand: " << endl;
			hList.print();
			cout << "Player 2 hand: " << endl;
			hList2.print();

		}
		else
		{
			cout << "Draw!! " << endl;
			cout << "Player 1 hand: " << endl;
			hList.print();
			cout << "Player 2 hand: " << endl;
			hList2.print();

		}

		cout << "--------------------------------------------\n"
			<< "New Game? Or quit?\nEnter [E] key for new game.\nEnter any key to quit: ";

		cin >> choice;

		if (toupper(choice) == 'E')
		{
			system("cls");
			main();
		}
		else
		{

			hList.emptyList();
			hList2.emptyList();

			closingTime();
		}
	}

	shown(dList, hList, hList2, One, Two, turn);
}

void shown(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn) {

	char choice;
	int score = 0; //for turn > 2
	system("cls");
	//calcuating turns by modulus
	if ((turn % 2) != 0) //turn ==1
	{
		cout << "--------------------------------------------\n";
		cout << "Ready Player One? \n";
		cout << "--------------------------------------------\n";
		if (turn == 1)
		{
			system("pause");

		}
	}
	else //turn == 2
	{
		cout << "--------------------------------------------\n";
		cout << "Ready Player Two? \n";
		cout << "--------------------------------------------\n";
		if (turn > 1)
		{
			system("pause");
		}
	}

	if (turn < 3) //turn isn't three so give both players their shown and hidden card
	{

		//shuffling
		for (int i = 0; i < 5; i++)
		{
			dList.deal();
		}

		//print out top the dealt card... 
		cout << "This is the shown card: ";
		dList.printHead();

		//back to get the dealt card which is in the back
		deck *b = new deck(dList.back().getNumber(),
			dList.back().getSuit(), dList.back().getFace());

		//adding the card to the hand list
		if ((turn % 2) != 0)
		{

			hList.addFront(*b);
		}
		else
		{
			hList2.addFront(*b);
		}

		if (dList.size() == 1) {
			cout << "You drew all 52 cards \n";
			system("pause");
			exit(1);
		}
		else   //finally removing the dealt card
		{
			dList.removeBack();
			/*cout << "Deck size: " << dList.size() << endl;
			*/
		}
		hidden(dList, hList, hList2, One, Two, turn);
	}

	else //turn == 3 now
	{

		if ((dList.size()) == 1) //check if there is only one card left
		{
			deck *b = new deck(dList.back().getNumber(),
				dList.back().getSuit(), dList.back().getFace());

			hList.addFront(*b);
			cout << "You drew all 52 cards \n";
			cout << "Last card is: \n";

			dList.printHead();

			score = value(hList, One, Two, turn);
			cout << "Hand value is " << score << endl;

			system("pause");
			exit(1);

		}
		else //there is more than one card in the deck
		{

			if ((turn % 2) != 0)
			{
				cout << "--------------------------------------------\n";
				cout << "\nPlayer Two's shown card is: ";

				hList2.printHead();
				cout << "--------------------------------------------\n";

				cout << "Your hand: \n";
				hList.print();

				cout << "Hit? \nEnter [E] key to hit.\nPress any key and enter to end current turn:";
				cin >> choice;

				if (toupper(choice) == 'E')
				{
					/*hit(dList, hList, One, Two, turn);*/
					system("cls");
					cout << "--------------------------------------------\n";
					cout << "Current value: " << One.getScore() << endl;
					cout << "You drew a(n): ";
					dList.deal();
	
					dList.printHead();
					cout << "--------------------------------------------\n";
					deck *b = new deck(dList.back().getNumber(),
						dList.back().getSuit(), dList.back().getFace());
					//adding the card to the hand list		
					hList.addFront(*b);

					if (dList.size() == 1) {
						cout << "You drew all 52 cards \n";
						system("pause");
						exit(1);
					}
					else
					{
						dList.removeBack();						
					}

					cout << "--------------------------------------------\n";
					score = value(hList, One, Two, turn);
					if (score > 0)
					{
						cout << "Hand value is " << score << endl;

						cout << "Hand list: " << endl;
						hList.print();
						cout << "--------------------------------------------\n";
					}
					system("pause");
					waitingTime(dList, hList, hList2, One, Two, turn); //if player wants to hit again

				}
				else 
				{
					system("cls");
					cout << "--------------------------------------------\n";
					cout << "Hand over to next player.\n";
					cout << "--------------------------------------------\n";
					turn++;
					system("pause");
					system("cls");
					buffer2(dList, hList, hList2, One, Two, turn);
				}
			}
			else
			{
				cout << "--------------------------------------------\n";
				cout << "\nPlayer One's shown card is: ";
				hList.printHead();
				cout << "--------------------------------------------\n";

				cout << "Your hand: \n";
				hList2.print();

				cout << "Hit? \nEnter [E] key to hit.\nPress any key and enter to end current turn:";
				cin >> choice;

				if (toupper(choice) == 'E')
				{
					/*hit(dList, hList2, One, Two, turn);*/
					system("cls");
					cout << "--------------------------------------------\n";
					cout << "Current value: " << Two.getScore() << endl;
					cout << "You drew a(n): ";
					dList.deal();

					//print out top the delt card... 
					//maybe this should be a function?
					dList.printHead();
					deck *b = new deck(dList.back().getNumber(),
						dList.back().getSuit(), dList.back().getFace());

					cout << "--------------------------------------------\n";

					//adding the card to the hand list		
					hList2.addFront(*b);

					if (dList.size() == 1) {
						cout << "You drew all 52 cards \n";
						system("pause");
						exit(1);
					}
					else
					{
						dList.removeBack();
						/*cout << "Deck size: " << dList.size() << endl;
						*/
					}

					cout << "--------------------------------------------\n";
					score = value(hList2, One, Two, turn);
					cout << "Hand value is " << score << endl;

					cout << "Hand list: " << endl;
					hList2.print();
					cout << "--------------------------------------------\n";

					system("pause");
					if (turn < 5)
					{
						waitingTime(dList, hList, hList2, One, Two, turn);
					}
					else
					{
						system("cls");
						buffer2(dList, hList, hList2, One, Two, turn);
					}
				}
				else
				{
					turn++;
					system("cls");
					buffer2(dList, hList, hList2, One, Two, turn);
				}
			}
		}
	}
}

void hidden(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn) {


	DLinkedList<deck> tempList;

	int score;

	//shuffle card again
	for (int i = 0; i < 5; i++)
	{
		dList.deal();
	}

	cout << "Hidden card is: ";
	dList.printHead();


	//adding back card to your hand
	deck *b = new deck(dList.back().getNumber(),
		dList.back().getSuit(), dList.back().getFace());

	if ((turn % 2) != 0)
	{
		hList.addFront(*b);
		cout << "--------------------------------------------\n";
		score = value(hList, One, Two, turn);
		cout << "Hand value is " << score << endl;

		cout << "Hand list: " << endl;
		hList.print();
		cout << "--------------------------------------------\n";
	}
	else
	{
		hList2.addFront(*b);

		cout << "--------------------------------------------\n";
		score = value(hList2, One, Two, turn);
		cout << "Hand value is " << score << endl;

		cout << "Hand list: " << endl;
		hList2.print();
		cout << "--------------------------------------------\n";
	}

	dList.removeBack();

	turn++;
	cout << "Press any key to let the next player go. \n";
	system("pause");
	buffer2(dList, hList, hList2, One, Two, turn);

}

int value(DLinkedList<deck> & hList, player & One, player & Two, int & turn)
{

	int score = 0;

	DLinkedList<deck> tempList;

	char choice;


	int hSize = hList.size();
	for (int i = 0; i < hSize; i++) //moving the handlist of player one to a temporary scoring list
	{
		
		deck *b = new deck(hList.back().getNumber(),
			hList.back().getSuit(), hList.back().getFace());
		tempList.addFront(*b);

		hList.removeBack();
	}


	int size = tempList.size();
	for (int i = 0; i < size; i++)//now we're going to calculate each score in templist before putting it back in to handlist
		//unless there's a way to move pointers to move from the back of handlist to front, we will stick to this class
	{

		if (tempList.back().getFace() == "Ace")
		{
			cout << "You drew an Ace!\nEnter [E] key for 11. [Any] key for 1: ";
			cin >> choice;

			if (toupper(choice) == 'E')
			{
				score = score + 11;
				cout << "Current score: " << score << endl;
			}
			else
			{
				score = score + 1;
				cout << "Current score: " << score << endl;
			}

			//removing the last card from tempList and putting into a deck c
			//this lets us go to the next tempList card towards the front
			//popping each one we calculate and pushing it back to the handlist
			deck *c = new deck(tempList.back().getNumber(),
				tempList.back().getSuit(), tempList.back().getFace());
			hList.addFront(*c);

			tempList.removeBack();

		}
		else if (tempList.back().getFace() == "King" ||
			tempList.back().getFace() == "Queen" ||
			tempList.back().getFace() == "Jack")
		{
			score = score + 10;

			deck *e = new deck(tempList.back().getNumber(),
				tempList.back().getSuit(), tempList.back().getFace());
			hList.addFront(*e);

			tempList.removeBack();

		}

		else
		{
			score = score + tempList.back().getNumber();

			deck *f = new deck(tempList.back().getNumber(),
				tempList.back().getSuit(), tempList.back().getFace());
			hList.addFront(*f);

			tempList.removeBack();

		}
	}



	if ((turn % 2) != 0)
	{
		if (score > 21)
		{
			turn++;
			cout << "--------------------------------------------\n"
				<< score << " is over 21!\n"
				<< "BUSTED!!\n"
				<< "--------------------------------------------\n";
			system("pause");
			system("cls");
			cout << "--------------------------------------------\n";
			cout << "Hand over to next player\n";
			cout << "--------------------------------------------\n";

			score = 0;
		}

		One.setScore(score);
	}
	else
	{
		if (score > 21)
		{
			turn++;
			cout << "--------------------------------------------\n"
				<< score << " is over 21!\n"
				<< "BUSTED!!\n"
				<< "--------------------------------------------\n"
				<< endl;
			score = 0;
		}

		Two.setScore(score);
	}

	return score;

}


void closingTime() {

	exit(1);
}

void waitingTime(DLinkedList<deck> & dList, DLinkedList<deck> & hList, DLinkedList<deck> & hList2, player One, player Two, int turn)
{
	shown(dList, hList, hList2, One, Two, turn);
}

