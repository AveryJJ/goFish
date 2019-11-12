// FILE: card_demo.cpp
// This is a small demonstration program showing how the Card and Deck classes are used.
#include <iostream>    // Provides cout and cin
#include <cstdlib>     // Provides EXIT_SUCCESS
#include "card.h"
#include "player.h"
#include "deck.h"
#include <iostream>
#include <fstream>
using namespace std;


// PROTOTYPES for functions used by this demonstration program:
void dealHand(Deck &d, Player &p, int numCards);

int main( )
{
   ofstream myfile ("gofish_results.txt");
   int numCards = 7;
   int PlayerTurn = 1;
   Player p1("Joe");
   Player p2("Jane");

   Deck d;  //create a deck of cards

   d.shuffle();

   dealHand(d, p1, numCards);
   dealHand(d, p2, numCards);
	 myfile << "The player's starting hands are dealt..." << endl;
	 myfile << p1.getName() << "'s Hand: " << p1.showHand() << endl;
	 myfile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
   Card c1;
   Card c2; //variable names reflect the parameters of function's in Player class.
   Card c;
	 myfile << "The players organize their hands..." << endl;
   while(p1.checkHandForBook(c1,c2))
   {
      p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2));
      myfile << p1.getName() << " creates a book of " << c1.rankString(c1.getRank()) << "s" << endl;
   }
   while(p1.checkHandForBook(c1, c2))
   {
      p2.bookCards(p2.removeCardFromHand(c1), p2.removeCardFromHand(c2));
      myfile << p2.getName() << " creates a book of " << c1.rankString(c1.getRank()) << "s" << endl;
   }
   while(((p1.getHandSize() > 0)||(p2.getHandSize() > 0)) && (d.size() > 0))
   {

      if(PlayerTurn == 1)
      {
				 myfile << "******** Cards ********" << endl;
				 myfile << p1.getName() << "'s Hand: " << p1.showHand() << endl;
				 myfile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
				 myfile << "******** " << p1.getName() << "'s Turn ********" << endl;
         if(p1.getHandSize() == 0)
         {
            if(d.size() > 0)
            {
						   c = d.dealCard();
 						   p1.addCard(c);
 						   myfile << p1.getName() << " drew a " << c << endl;
            }
            else
						{
						   return 0; //game would have ended in this case
				    }
				 }
         Card c1 = p1.chooseCardFromHand();
         Card c2;
         myfile << p1.getName() << " asks for " << c1.rankString(c1.getRank()) << "'s" << endl;
         if(p2.cardInHand(c1))
         {
            myfile << p2.getName() << " says: Yes." << endl;
            p1.bookCards(p1.removeCardFromHand(c1), p2.removeCardFromHand(c1));
            myfile << p1.getName() << " creates a book of " << c1.rankString(c1.getRank()) << "s" << endl;
						myfile << p1.getName() << "'s turn continues..." << endl;
            PlayerTurn = 1;
         }
         else
         {
            myfile << p2.getName() << " says: No, go fish." << endl;
            c = d.dealCard();
            p1.addCard(c);
            myfile << p1.getName() << " drew a " << c << endl;
            if(p1.checkHandForBook(c1,c2))
            {
				       myfile << p1.getName() << " creates a book of " << c1.rankString(c1.getRank()) << "s" << endl;
					     p1.bookCards(p1.removeCardFromHand(c1), p1.removeCardFromHand(c2));
							 myfile << p1.getName() << "'s turn continues..." << endl;
					     PlayerTurn = 1;
				    }
				    else
				    {
				       PlayerTurn = 2;
							 myfile << p1.getName() << "'s turn ends..." << endl;
				    }
			   }
      }
		  else if(PlayerTurn == 2)
		  {
		     myfile << "******** Cards ********" << endl;
				 myfile << p1.getName() << "'s Hand: " << p1.showHand() << endl;
				 myfile << p2.getName() << "'s Hand: " << p2.showHand() << endl;
				 myfile << "******** " << p2.getName() << "'s Turn ********" << endl;
			   if(p2.getHandSize() == 0)
			   {
				    if(d.size() > 0)
				    {
				       c = d.dealCard();
					     p2.addCard(c);
					     myfile << p2.getName() << " drew a " << c << endl;
				    }
				    else
				    {
					     return 0;
				    }
			   }
			   Card c1 = p2.chooseCardFromHand();
			   Card c2;
			   myfile << p2.getName() << " asks for " << c1.rankString(c1.getRank()) << "'s" << endl;
			   if(p1.cardInHand(c1))
			   {
			      myfile << p1.getName() << " says: Yes." << endl;
				    myfile << p2.getName() << " creates a book of " << c1.rankString(c1.getRank()) << "s" << endl;
				    p2.bookCards(p2.removeCardFromHand(c1),p1.removeCardFromHand(c1));
						myfile << p2.getName() << "'s turn continues..." << endl;
			   }
			   else
			   {
				    myfile << p1.getName() << " says: No, go fish." << endl;
				    c = d.dealCard();
				    p2.addCard(c);
				    myfile << p2.getName() << " drew a " << c << endl;
				    if(p2.checkHandForBook(c1,c2))
				    {
					     myfile << p2.getName() << " creates a book of " << c1.rankString(c1.getRank()) << "s" << endl;
					     p2.bookCards(p2.removeCardFromHand(c1),p1.removeCardFromHand(c2));
					     PlayerTurn = 2;
							 myfile << p2.getName() << "'s turn continues..." << endl;
				    }
				    else
				    {
					     PlayerTurn = 1;
							 myfile << p2.getName() << "'s turn ends..." << endl;
				    }
			   }
		  }
		  myfile << endl;
	 }
	 myfile << "******** RESULTS ********" << endl;
	 myfile << p1.getName() << "'s Books: " << p1.getBookSize() << endl;
	 myfile << p2.getName() << "'s Books: " << p2.getBookSize() << endl;
   if(p1.getBookSize() > p2.getBookSize())
	 {
	    myfile << p1.getName() << " wins." << endl;
	 }
	 else if(p1.getBookSize() == p2.getBookSize())
	 {
		  myfile <<" draw" << endl;
	 }
	 else if(p1.getBookSize() < p2.getBookSize())
	 {
		  myfile << p2.getName() << " wins." << endl;
	 }
	 myfile.close();
   return EXIT_SUCCESS;
}



void dealHand(Deck &d, Player &p, int numCards)
{
   for (int i=0; i < numCards; i++)
   p.addCard(d.dealCard());
}
