//Header.h
//Details
//Activity
//LAST YEAR
//
//You uploaded an item
//Sep 25, 2016
//Text
//Header.h
//No recorded activity before September 25, 2016
//New Team Drive

// Template doubly linked list class using code from
// Data Structures and Algorithms in C++, Goodrich, Tamassia, and Mount, 2nd Ed., 2011.
//

#pragma once
#include <stdexcept>
using namespace std;
template <typename E> class DLinkedList;	// forward declaration to be used when declaring DNode

template <typename E>
class DNode {					            // doubly linked list node
private:
	E elem;					               // node element value
	DNode<E> *prev;				         // previous node in the list
	DNode<E> *next;				         // next node in the list
	friend class DLinkedList<E>;		   // provide SLinkedList access
};

template <typename E>
class DLinkedList {	                  // a doubly linked list
public:
	DLinkedList();				            // empty list constructor
	~DLinkedList();				         // destructor
	bool empty() const;			         // is list empty?
	E& front();							// get front element
	E& back();							// get back element
	void addFront(const E& e);		      // add to front of list
	void addBack(const E& e);		      // add to back of list
	void removeFront();			         // remove from front
	void removeBack();			         // remove from back
	int size() const;					// list size
	//void swapFirstAndLast();			// Where node elements get swapped 
	void deal();
	void print();
	void printHead();
	DNode<E>* getHead();
	//void shuffle();
	void emptyList();
	
private:                               // local type definitions
	int     n;							// number of items
	DNode<E>* header;				         // header sentinel
	DNode<E>* trailer;                  // trailer sentinel
protected:
	void add(DNode<E>* v, const E& e);     // insert new node before v
	void remove(DNode<E>* v);              // remove node v
};

template <typename E>
void DLinkedList<E>::emptyList(){
	while (!empty()) removeFront();
}

//template <typename E>
//void DLinkedList<E>::shuffle(){
//	/*srand (time(NULL)); don't need to do this again*/
//
//	int shuffleProb = 0;
//	shuffleProb = rand() % n-1 + 0;
//
//	DNode<E>* middle = header -> next;
//	
//
//	for (int i = 0; i < shuffleProb; i++) //searching for a middle card to bring ontop
//	{
//		middle;
//		middle = middle ->next; //"middle" is searching
//
//	}
//		
//	DNode<E>* middleNext = middle -> next;
//	DNode<E>* middlePrev = middle -> prev;
//	DNode<E>* trailerPrev = trailer -> prev;
//
//	middle -> next = trailer;
//	trailer -> prev = middle;
//
//	trailerPrev->next = middle;
//	middle ->prev = trailerPrev;
//
//	middlePrev -> next = middleNext;
//	middleNext -> prev = middlePrev;
//			
//}

template <typename E>
DNode<E>* DLinkedList<E>::getHead()
{
	return header->next;
}

template <typename E>
void DLinkedList<E>::printHead()
{
	DNode<E>* topCard = trailer->prev;
	int a = topCard ->elem.getNumber();
	string b = topCard ->elem.getSuit();
	string c = topCard ->elem.getFace();

	cout << a << " " << b << " " << c << "\n";

}

template <typename E>
void DLinkedList<E>::print()
{
	DNode<E>* topCard = header->next;
	int a = topCard ->elem.getNumber();
	string b = topCard ->elem.getSuit();
	string c = topCard ->elem.getFace();

	int i = n;
	while (topCard->next != NULL)
	{
		cout << i << ": " << a << " " << b << " "  << c << " \n" ;
		topCard = topCard ->next;
		a = topCard->elem.getNumber();
		b = topCard->elem.getSuit();
		c = topCard ->elem.getFace();
		i--;
	}
	cout << endl;
}

template <typename E>
void DLinkedList<E>::deal(){
	//pick a random number
	srand (time(NULL)); //initialize random seed
	/*int diff = n;*/
	int prob = 0;
	/*prob = n - diff;*/
	prob = rand() % n-1;

	DNode<E>* topCard = header -> next; //make the topCard the temporary variable
	//searches the entire deck based on the probability

	for (int i = 0; i < prob; i++) //searching for card from probability
	{
		topCard = topCard ->next;
	}
	//topcard is now the card being dealt

	//these are the topcard's next and previous pointers
	DNode<E>* topCardNext = topCard -> next;
	DNode<E>* topCardPrev = topCard -> prev;

	//made the trailer previous one word to save space lol
	DNode<E>* trailerPrev = trailer -> prev;
	
	//when you deal the card, you want the dealt card to be removed
	//we are going to add it to the front so we can remove front

	//linking the topCard to trailer
	topCard -> next = trailer;
	trailer -> prev = topCard;

	//linking the former trailer previous next to topCard
	trailerPrev->next= topCard;
	topCard ->prev = trailerPrev;

	//linking the topCard's former previous to top card's former next
	topCardPrev -> next = topCardNext;
	topCardNext -> prev = topCardPrev;

}

//template <typename E>
//void DLinkedList<E>::swapFirstAndLast(){
//	// YOUR CODE TO SWAP NODES GOES HERE
//	if (n <2) throw length_error("List less than 2");
//	
//	DNode<E>* B = trailer ->prev;
//	DNode<E>* A = header ->next;
//
//	//H <-> A <-> 1 <-> 2 <-> 3 <-> B <-> T
//
//	header -> next = B; //H <- A <-> 1 <-> 2 <-> 3 <-> B <- T // H->B
//	A -> next-> prev = B; //H <- A -> 1 <-> 2 <-> 3 <-> B <- T// H -> B <- 1
//	B -> next = A -> next; //H <- A -> 1 <-> 2 <-> 3 <-> B <- T// H -> B <-> 1
//	A->next = trailer; // H <- A 1 <-> 2 <-> 3 <-> B <- T// H -> B <-> 1 A->T
//	B->prev->next=A; // H <- A 1 <-> 2 <-> 3 <- B <- T// H -> B <-> 1  3 -> A-> T
//	A->prev = B->prev; // H  1 <-> 2 <-> 3 -> B <- T// H -> B <-> 1  3 <-> A-> T
// 	B->prev= header; // H <-> B <-> 1 <-> 2 <-> 3 <-> A -> T
//	trailer -> prev = A; //H <-> B <-> 1 <-> 2 <-> 3 <-> A <-> T
//
//}

template <typename E>
DLinkedList<E>::DLinkedList() {        // constructor
	n = 0;							// initially empty
	header = new DNode<E>;              // create sentinels
	trailer = new DNode<E>;
	header->next = trailer;             // have them point to each other
	trailer->prev = header;
}

template <typename E>
bool DLinkedList<E>::empty() const	   // is list empty?
{
	return (header->next == trailer);
}

template <typename E>
E& DLinkedList<E>::front() 	// return front element
{
	if (empty()) throw length_error("empty list");
	return header->next->elem;
}

template <typename E>
E& DLinkedList<E>::back() 	// get back element
{
	if (empty()) throw length_error("empty list");
	return trailer->prev->elem;
}

template <typename E>
DLinkedList<E>::~DLinkedList() {	      // destructor
	while (!empty()) removeFront();     // remove all but sentinels
	delete header;				            // remove the sentinels
	delete trailer;
}

template <typename E>
void DLinkedList<E>::add(DNode<E>* v, const E& e) { //pretend v is trailer and t = header
	DNode<E>* u = new DNode<E>;              // create a new node for e
	u->elem = e;
	u->next = v;				                  // link u in between v u next -> v
	u->prev = v->prev;				            // ...and v->prev u prev ->t
	v->prev->next = u;							//t next -> u
	v->prev = u;								// v prev ->u
	n++;
}

template <typename E>
void DLinkedList<E>::addFront(const E& e)	   // add to front of list
{
	add(header->next, e);
}

template <typename E>
void DLinkedList<E>::addBack(const E& e)	   // add to back of list
{
	add(trailer, e);
}

template <typename E>
void DLinkedList<E>::remove(DNode<E>* v) {	// remove node v
	DNode<E>* u = v->prev;				         // predecessor
	DNode<E>* w = v->next;				         // successor
	u->next = w;				                  // unlink v from list
	w ->prev = u;
	delete v;
	n--;
}

template <typename E>
void DLinkedList<E>::removeFront()		// remove from font
{
	if (empty()) throw length_error("empty list");
	remove(header->next);
}

template <typename E>
void DLinkedList<E>::removeBack()		// remove from back
{
	if (empty()) throw length_error("empty list");
	remove(trailer->prev);	
	
}

template <typename E>
int DLinkedList<E>::size() const {				// list size
	return n;
}
