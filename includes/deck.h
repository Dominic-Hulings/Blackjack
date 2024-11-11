#ifndef DECK_H
#define DECK_H

// #include <string>

#include "base.h"  // Includes base card data
#include "global.h"

class Deck : BaseCardData 
{
  public:
    Deck();
    Card GETTopMainDeck();                         
  protected:
    //Card GETTopMainDeck();
    void Shuffle();
};

#endif