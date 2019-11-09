
#include <iostream>
#include <string>
#include <vector>

#include "player.h"
#include "card.h"

using namespace std;

Player::Player()
{

}
void Player::addCard(Card c)
{
	cout << myName << "drew a" << c << endl;
	myHand.push_back(c);
}
void Player::bookCards(Card c1, Card c2)
{
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
bool Player::rankInHand(Card c) const
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
Card Player::chooseCardFromHand() const
{

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
	for(vector<Card>::const_iterator it = myHand.begin(); it != myHand.end(); ++it)
	{
		 if(c == *it)
		 {
			 
				return true;
		 }
	}
}
string Player::showHand() const
{

}
string Player::showBooks() const
{

}
int Player::getHandSize() const
{

}
int Player::getBookSize() const
{

}
bool Player::checkHandForPair(Card &c1, Card &c2)
{

}
bool Player::sameRankInHand(Card c) const
{

}
