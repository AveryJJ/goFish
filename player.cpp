
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "player.h"
#include "card.h"

using namespace std;

Player::Player()
{

}
void Player::addCard(Card c)
{
	cout << myName << " drew a " << c << endl;
	myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2)
{
   c1 = this->removeCardFromHand(c1);
   c2 = this->removeCardFromHand(c2);
	 cout << myName << "creates a book of" << c1.getRank() << "'s" << endl;
	 myBook.push_back(c1);
	 myBook.push_back(c2);
}
bool Player::checkHandForBook(Card &c1, Card &c2)
{
	 for(vector<Card>::iterator it = myHand.begin(); it != myHand.end();++it)
	 {
      for(vector<Card>::iterator it_next = it+1; it != myHand.end();++it)
      {
         if(it->getRank() == it_next->getRank())
				 {
				    c1 = *it;
						c2 = *it_next;

						return true;
				 }
      }
   }
	 return false;
}
//bool Player::rankInHand(Card c) const;
Card Player::chooseCardFromHand() const
{
   return (myHand[rand() % myHand.size()]);
}
bool Player::cardInHand(Card c) const
{
   for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); ++it)
   {
      if(c == *it)
      {
         return true;
      }
   }
}
Card Player::removeCardFromHand(Card c)
{
	for(vector<Card>::iterator it = myHand.begin(); it != myHand.end(); ++it)
	{
		 if(c.getRank() == it->getRank())
		 {
			  Card temp = *it;
				myHand.erase(it); //Erases card from hand. this is a standard function.
				return temp;
		 }
	}
}
string Player::showHand() const
{
   string s_hand;
	 for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); ++it)
	 {
	    if(it == myHand.begin())
	 	  {
	       s_hand = it->toString();
	    }
		  else
		  {
		     s_hand = s_hand + ", " + it->toString();
      }
	 }
	 return s_hand;
}
string Player::showBooks() const
{
   string s_book;
	 for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); ++it)
	 {
		  if(it == myHand.begin())
		  {
			   s_book = it->toString();
		  }
		  else
		  {
			   s_book = s_book + ", " + it->toString();
	    }
	 }
	 return s_book;
}
int Player::getHandSize() const
{
   return myHand.size();
}
int Player::getBookSize() const
{
   return myBook.size();
}
//bool Player::checkHandForPair(Card &c1, Card &c2);
bool Player::sameRankInHand(Card c) const
{
   for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end();++it)
	 {
	    if(c.getRank() == it->getRank())
		  {
				return true;
		  }
		  else
		  {
				return false;
		 }
	}
}
