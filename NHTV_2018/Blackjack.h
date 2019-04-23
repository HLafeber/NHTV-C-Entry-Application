#pragma once

// blackjack.h
//

#ifndef LZZ_blackjack_h
#define LZZ_blackjack_h
#define LZZ_INLINE inline
#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <ctime>

class Card
{
public:
	enum rank
	{
		ACE = 1,
		TWO,
		THREE,
		FOUR,
		FIVE,
		SIX,
		SEVEN,
		EIGHT,
		NINE,
		TEN,
		JACK,
		QUEEN,
		KING
	};
	enum suit
	{
		CLUBS,
		DIAMONDS,
		HEARTS,
		SPADES
	};
	friend std::ostream & operator << (std::ostream & os, Card const & aCard);
	Card(rank r = ACE, suit s = SPADES, bool ifu = true);
	int GetValue() const;
	void Flip();
private:
	rank m_Rank;
	suit m_Suit;
	bool m_IsFaceUp;
};
class Hand
{
public:
	Hand();
	virtual ~Hand();
	void Add(Card * pCard);
	void Clear();
	int GetTotal() const;
protected:
	std::vector <Card*> m_Cards;
};
class GenericPlayer : public Hand
{
	friend std::ostream & operator << (std::ostream & os, GenericPlayer const & aGenericPlayer);
public:
	GenericPlayer(std::string const & name = "");
	virtual ~GenericPlayer();
	virtual bool IsHitting() const = 0;
	bool IsBusted() const;
	void Bust() const;
protected:
	std::string m_Name;
};
class BJPlayer : public GenericPlayer
{
public:
	BJPlayer(std::string const & name = "");
	virtual ~BJPlayer();
	virtual bool IsHitting() const;
	void Win() const;
	void Lose() const;
	void Push() const;
};
class House : public GenericPlayer
{
public:
	House(std::string const & name = "House");
	virtual ~House();
	virtual bool IsHitting() const;
	void FlipFirstCard();
};
class Deck : public Hand
{
public:
	Deck();
	virtual ~Deck();
	void Populate();
	void Shuffle();
	void Deal(Hand & aHand);
	void AdditionalCards(GenericPlayer & aGenericPlayer);
};
class Game
{
public:
	Game(std::vector <std::string> const & names);
	~Game();
	void Play();
private:
	Deck m_Deck;
	House m_House;
	std::vector <BJPlayer> m_Players;
};

std::ostream & operator << (std::ostream & os, Card const & aCard);
std::ostream & operator << (std::ostream & os, GenericPlayer const & aGenericPlayer);
int BJmain();
std::ostream & operator << (std::ostream & os, Card const & aCard);
std::ostream & operator << (std::ostream & os, GenericPlayer const & aGenericPlayer);
#undef LZZ_INLINE
#endif
