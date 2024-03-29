#include "card.h"
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

Card::Card()
{
   myRank = 1;
   mySuit = spades;
}

Card::Card(int rank, Suit s)
{
   myRank = rank;
   mySuit = s;
}

string Card::toString() const
{
   string s = rankString(myRank) + suitString(mySuit);
   return s;
}

bool Card::sameSuitAs(const Card& c) const
{
   return (mySuit == c.mySuit);
}

int Card::getRank() const
{
   return myRank;
}

string Card::suitString(Suit s) const
{
   switch(s)
   {
      case spades:
         return "s";
	       break;
      case hearts:
	       return "h";
	        break;
      case diamonds:
	       return "d";
	       break;
      case clubs:
	       return "c";
	       break;
   }
}

string Card::rankString(int r) const
{
   switch(r)
   {
      case 1:
         return "A";
         break;
      case 2:
         return "2";
         break;
      case 3:
         return "3";
         break;
      case 4:
         return "4";
         break;
      case 5:
         return "5";
         break;
      case 6:
         return "6";
         break;
      case 7:
         return "7";
         break;
      case 8:
         return "8";
         break;
      case 9:
         return "9";
         break;
      case 10:
         return "10";
         break;
      case 11:
         return "J";
         break;
      case 12:
         return "Q";
         break;
      case 13:
	       return "K";
	       break;
   }
}

bool Card::operator == (const Card& rhs) const
{
   return((mySuit == rhs.mySuit) && (myRank == rhs.myRank));
}

bool Card::operator != (const Card& rhs) const
{
   return((mySuit != rhs.mySuit) && (myRank != rhs.myRank));
}
ostream& operator << (ostream& out, const Card& c)
{
   out << c.toString();
   return out;
}
