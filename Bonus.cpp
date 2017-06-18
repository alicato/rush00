#include "Bonus.hpp"

ABonus::ABonus( void ) {
	this->y = 0;
	this->x = std::rand()%(WIN_W - 8) + 4;
}

ABonus::~ABonus( void ) {
	
}
ABonus::ABonus(ABonus const & bonus) {
	this->y = bonus.y;
	this->x = bonus.x;
}

ABonus	&	ABonus::operator=(ABonus const & bonus) {
	this->y = bonus.y;
	this->x = bonus.x;
	return *this;
}

bool	ABonus::move(Player & player) {
		std::clock_t actual = clock();
		double time = ((actual - this->time) / (float)1000000) * 1000;
		if (time > 100) {
			this->y += 1;
			if (this->y >= WIN_H)
				return false;
			if (((abs(this->x - player.getX()) < Player::width && abs(this->y - player.getY()) < 2))) {
				this->action(player);
				return false;
			}
			this->time = actual;
		}
		return true;
}


void			ABonus::display() {
	attron(COLOR_PAIR(this->_color));
	for(size_t i = 0; i < this->_patern.size() ; ++i){
		mvwprintw(stdscr, this->y-3+i, this->x, this->_patern.substr(i,1).c_str());
	}
	attroff(COLOR_PAIR(this->_color));
}