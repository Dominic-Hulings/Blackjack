#include <iostream>
#include <algorithm>
#include <vector>

#include "dealer.h"

using std::string, std::pair, std::vector, std::cout, std::cin;
typedef CT::Card Card;

Dealer::Dealer()
{
  this->dealerName = "DealerName";
}

string Dealer::GETDealerName()
{
  return this->dealerName;
}

Deck* Dealer::GETDealerDeck()
{
  return &this->DealerDeck;
}

vector<Card> Dealer::GETDealerHand()
{
  return this->dealerHand;
}

Player* Dealer::GETpPlayer()
{
  return this->pPlayer;
}

void Dealer::SETp2Player(Player* p2Player)
{
  this->pPlayer = p2Player;
}

void Dealer::TAKECard(Card cardGiven, bool isFaceDown)
{
  this->dealerHand.push_back(cardGiven);
}

int Dealer::EvalHandValue(vector<Card> hand)
{
  int totalHandValue = 0;
  for (Card card : hand)
  {
    auto it = find(Values.begin(), Values.end(), card.first);

    if (it == Values.end())
    {
      cout << "Card not found.\n";
    }

    if (it - Values.begin() + 1 > 1 && it - Values.begin() + 1 < 11)
    {
      totalHandValue += it - Values.begin() + 1;
    }

    else if (it - Values.begin() + 1 >= 11)
    {
      totalHandValue += 10;
    }

    else
    {
      if (totalHandValue + 11 > 21)
      {
        totalHandValue += 1;
      }

      else
      {
        totalHandValue += 11;
      }
    }
  }

  return totalHandValue;
}

pair<int, int> Dealer::Hand()
{
  //* BETTING ------------------------------------------------------

  int inNumToBet = 20;
  int amtBet = 0;
  cout << "How much to bet on this hand?\n";
  cout << "You have " << pPlayer->GETPlayerStack() << " total.\n";
  cout << inNumToBet << "\n"; //? change to cin?

  amtBet = inNumToBet; //TODO: Add check to make sure they have enough

  //* END OF BETTING -----------------------------------------------
  //* INITIAL DEAL -------------------------------------------------

  this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
  this->TAKECard(this->DealerDeck.GETTopMainDeck(), true);

  //* END OF INITIAL DEAL ------------------------------------------
  //* PLAYER TURN --------------------------------------------------

  int playerHandVal;
  bool endTurn = false;
  bool playerOver = false;

  cout << "Dealer's hand:\n";
  for (Card card : this->GETDealerHand())
  {
    cout << card.first << " of " << card.second << "\n";
  }

  while (!endTurn)
  {
    cout << "Player's hand:\n";
    for (Card card : this->pPlayer->GETPlayerHand())
    {
      cout << card.first << " of " << card.second << "\n";
    }

    cout << "Value: " << EvalHandValue(this->pPlayer->GETPlayerHand()) << "\n";

    if (EvalHandValue(this->pPlayer->GETPlayerHand()) > 21)
    {
      cout << "Player over 21.\n";
      playerOver = true;
      break;
    }

    int playerChoice = 0;
    cout << "Hit(1) or stand(2)?\n";
    cin >> playerChoice;

    switch (playerChoice)
    {
      case 1:
        cout << "Hit.\n";
        this->pPlayer->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
        break;
      case 2:
        cout << "Stand.\n";
        endTurn = true;
        playerHandVal = EvalHandValue(this->pPlayer->GETPlayerHand());
        break;
      default:
        cout << "Input not recognized.\n";
        break;
    }
  }

  //* END OF PLAYER TURN -------------------------------------------
  //* DEALER TURN --------------------------------------------------

  int dealerHandVal;
  int dealerChoice = 0;
  endTurn = false;
  bool dealerOver = false;

  while (true)
  {
    cout << "Dealer's hand:\n";
    for (Card card : this->GETDealerHand())
    {
      cout << card.first << " of " << card.second << "\n";
    }

    cout << "Value: " << EvalHandValue(this->GETDealerHand()) << "\n";

    if (EvalHandValue(this->GETDealerHand()) > 21)
    {
      cout << "Dealer over 21.\n";
      dealerOver = true;
      break;
    }

    else if (EvalHandValue(this->GETDealerHand()) >= 17)
    {
      cout << "Dealer stands.\n";
      dealerHandVal = EvalHandValue(this->GETDealerHand());
      break;
    }

    else
    {
      this->TAKECard(this->DealerDeck.GETTopMainDeck(), false);
    }
  }

  //* END OF DEALER TURN -------------------------------------------
  //* WIN EVAL -----------------------------------------------------

  if (playerOver)
  {
    return {2, amtBet};
  }

  else if (dealerOver)
  {
    return {1, amtBet};
  }

  else
  {
    if (playerHandVal > dealerHandVal)
    {
      return {1, amtBet};
    }

    else if (playerHandVal == dealerHandVal)
    {
      return {3, amtBet};
    }

    else
    {
      return {2, amtBet};
    }
  }

  //* END OF WIN EVAL ----------------------------------------------
}

void Dealer::WonHand(pair<int, int> wonAndAmt)
{
  switch (wonAndAmt.first)
  {
    case 1:
      cout << "Player won " << wonAndAmt.second << "\n";
      this->pPlayer->FundTransfer(wonAndAmt.second, false);
      break;
    case 2:
      cout << "Dealer won " << wonAndAmt.second << "\n";
      this->pPlayer->FundTransfer(wonAndAmt.second, true);
      break;
    case 3:
      cout << "Push" << "\n";
      break;
    default:
      cout << "error 2" << "\n";;
      break;
  }
}