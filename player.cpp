
#include <iostream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <ctime>
#include "player.h"
#include "card.h"
#include <fstream>
using namespace std;

Player::Player()
{

}
void Player::addCard(Card c)
{
	myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2)
{
	 myBook.push_back(c1);
	 myBook.push_back(c2);
}
bool Player::checkHandForBook(Card &c1, Card &c2)
{
   vector<Card>::iterator it = myHand.begin();
   vector<Card>::iterator it_next = myHand.begin();
   for(it = myHand.begin(); it != myHand.end(); ++it)
   {
	    for(it_next = it + 1; it_next != myHand.end(); ++it_next)
			{
		     if (it->getRank() == it_next->getRank())
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
   return myHand[rand() % myHand.size()];
}
bool Player::cardInHand(Card c) const
{
   vector<Card>::const_iterator it = myHand.begin();
   for(it = myHand.begin(); it != myHand.end(); ++it)
	 {
	    if(it->getRank() == c.getRank())
			{
		     return true;
	    }
   }
   return false;
}
Card Player::removeCardFromHand(Card c)
{
   vector<Card>::iterator it = myHand.begin();
   for(it = myHand.begin(); it != myHand.end(); ++it)
   {
	    if (it->getRank() == c.getRank())
			{
		     Card temp = *it;
		     myHand.erase(it);
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
   vector<Card>::const_iterator it = myHand.begin();
   for(it = myBook.begin(); it != myBook.end(); ++it)
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
   return ((myBook.size())/2);
}
//bool Player::checkHandForPair(Card &c1, Card &c2);
bool Player::sameRankInHand(Card c) const
{
   vector<Card>::const_iterator it = myHand.begin();
   for(it = myHand.begin(); it != myHand.end(); ++it)
	 {
	    if(it->getRank() == c.getRank())
			{
		     return true;
	    }
   }
   return false;
}
