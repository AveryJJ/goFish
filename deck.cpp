#include "deck.h"
#include "card.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

Deck::Deck()
{

}

void Deck::shuffle()
{
   srand(time(0));
   for(int i=0; i<SIZE; i++)
   {
      int i_rand = 1+(rand()%(SIZE-1));
      swap(myCards[i], myCards[i_rand]);
   }
}

Card Deck::dealCard()
{
//what do I include for a Fail?
   Card temp = myCards[myIndex];
   myIndex--;
   return temp;
}

int Deck::size() const
{
   switch (myIndex)
   {
      case 0:
         return myIndex;
	 break;
      default:
	 return myIndex+1;
   }
}
