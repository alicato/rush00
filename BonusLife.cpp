#include "BonusLife.hpp"

BonusLife::BonusLife( void ) {
	this->_color = 6;
	this->_patern = "LIFE";
}

BonusLife::~BonusLife( void ) {
	
}
BonusLife::BonusLife(BonusLife const & bonus) {
	_color 	= bonus._color;
	_patern = bonus._patern; 
}

BonusLife	&	BonusLife::operator=(BonusLife const & bonus) {
	_color 	= bonus._color;
	_patern = bonus._patern; 
	return *this;
}

void			BonusLife::action(Player & player) {
	player += 1;
}