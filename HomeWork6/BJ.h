#pragma once
#include <iostream>
#include <vector>
#include <string>

enum class cardSuits {
	heart,
	spade,
	cross,
	diamond
};
enum class cardValues {
	_A = 1,
	_2 = 2,
	_3 = 3,
	_4 = 4,
	_5 = 5,
	_6 = 6,
	_7 = 7,
	_8 = 8,
	_9 = 9,
	_10 = 10,
	_J = 11,
	_Q = 12,
	_K = 13
};

class Card {
private:
	cardSuits _suit;
	cardValues _value;
	bool _position;
	const std::vector<std::string> _suitPresentation{ "H", "S", "C", "D" };
	const std::vector<std::string> _valuePresentation{ "A", "2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K" };
public:
	Card(cardSuits suit, cardValues value, bool position = false) : _suit(suit), _value(value), _position(position) {};

	void Flip() {
		_position = !_position;
	};

	int GetValue() const {
		if (!_position)
			return 0;
		return static_cast<int>(_value) > 10 ? 10 : static_cast<int>(_value);
	};

	const std::string& getPrintSuit() const { 
		return _suitPresentation.at(static_cast<int>(_suit));
	};

	const std::string& getPrintValue() const {
		return _valuePresentation.at(static_cast<int>(_value) - 1);
	};

	const bool IsFlipped() const { return _position; };
};

class Hand {
private:
	int const MAX_CARDS = 7;
	int const BJ = 21;
	int const ACE_ADDITION = 10;
protected:
	std::vector<Card*> _cards;
public:
	Hand() {
		_cards.reserve(MAX_CARDS);
	};

	void Add(Card& card) {
		_cards.push_back(&card);
	};

	void Clear() {
		for (auto card : _cards)
			delete card;
		_cards.clear();
	};

	int GetTotal() const {
		bool hasAce = false;
		int result = 0;
		for (auto card : _cards) {
			int cardValue = card->GetValue();
			if (cardValue == 1)
				hasAce = true;
			result += card->GetValue();
		};
		if (((result + ACE_ADDITION) <= BJ) && hasAce)
			result += ACE_ADDITION;
		return result;
	};

	virtual ~Hand() { Clear(); };

	const std::vector<Card*>& getCards() const { return _cards; };
};

class GenericPlayer : public Hand {
protected:
	std::string _name;
public:
	virtual bool IsHitting() const = 0;
	bool IsBoosted() const { return GetTotal() > 21; };
	void Bust() { std::cout << _name << " has too much!" << std::endl; };
	const std::string& getName() const { return _name; };
	GenericPlayer(const std::string& name) : _name(name), Hand() {};
	virtual ~GenericPlayer() {};
};

class Player : public GenericPlayer {
public:
	virtual bool IsHitting() const {
		char answer;
		while (true)
		{
			std::cout << "Do you need more cards?(y/n): ";
			std::cin >> answer;
			switch (std::tolower(answer)) {
			case 'y':
				return true;
			case 'n':
				return false;
			default:
				std::cout << "unrecognised answer, try again." << std::endl;
				continue;
			}
		}
	};

	void Win() const {
		std::cout << _name << " wins!" << std::endl;
	};

	void Lose() const {
		std::cout << _name << " loses!" << std::endl;
	};

	void Push() const {
		std::cout << _name << " pushes!" << std::endl;
	};

	Player(const std::string& name) : GenericPlayer(name) {};

	virtual ~Player() {};
};

class House : public GenericPlayer {
public:
	virtual bool IsHitting() const { return GetTotal() <= 16; };
	void FlipFirstCard() { 
		if(_cards.size() > 0)
			_cards[0]->Flip(); 
	};
	House(const std::string& name) : GenericPlayer(name) {};
	virtual ~House() {};
};

std::ostream& operator<< (std::ostream& out, const Card& card)
{
	out << (card.IsFlipped() ? (card.getPrintValue() + "|" + card.getPrintSuit()) : "X|X");
	return out;
}

std::ostream& operator<< (std::ostream& out, const GenericPlayer& player)
{
	out << player.getName() << " ( ";
	auto _cards = player.getCards();
	for (auto card : _cards) {
		out << *card << " ";
	};
	out << ") " << player.GetTotal();
	return out;
}

