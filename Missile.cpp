#include "Missile.hpp"

Missile::Missile(void) {
	this->hp = 40;
	this->x = 0;
	this->y = 0;
	this->time = 0;
}

Missile::Missile(int x, int y) {
	this->hp = 50;
	this->x = x;
	this->y = y;
	this->time = clock();
}

Missile::Missile(int x, int y, std::wstring s) {
	this->hp = 50;
	this->x = x;
	this->y = y;
	this->s = s;
	this->time = clock();
}

Missile::Missile(Missile const &src) { *this = src; }

Missile::~Missile(void) { return; }

Missile			&Missile::operator=(Missile const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void	Missile::move(bool player) {
	if (player)
		this->y -= 1;
	else
		this->y += 1;
}

void	Missile::display(int n, std::string s) {
	attron(COLOR_PAIR(n));
	mvwprintw(stdscr, this->y, this->x, s.c_str());
	attroff(COLOR_PAIR(n));
}

void	Missile::display(int n, std::wstring s) {
	attron(COLOR_PAIR(n));
	mvwprintw(stdscr, y, x, "%S", s.c_str());
	attroff(COLOR_PAIR(n));
}

void	Missile::display(int n) {
	attron(COLOR_PAIR(n));
	mvwprintw(stdscr, this->y, this->x, "%S", this->s.c_str());
	attroff(COLOR_PAIR(n));
}
