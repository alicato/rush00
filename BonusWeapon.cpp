#include "BonusWeapon.hpp"

BonusWeapon::BonusWeapon( void ) {
	this->_color = 3;
	this->_patern = "WEAP";
}

BonusWeapon::~BonusWeapon( void ) {
	
}
BonusWeapon::BonusWeapon(BonusWeapon const & bonus) {
	_color 	= bonus._color;
	_patern = bonus._patern; 
}

BonusWeapon	&	BonusWeapon::operator=(BonusWeapon const & bonus) {
	_color 	= bonus._color;
	_patern = bonus._patern; 
	return *this;
}

void			BonusWeapon::action(Player & player) {
	player.addBonusTime();
}