#include "Player.hpp"

Player::Player(void) {
	this->hp = 8;
	this->x = WIN_W / 2;
	this->y = WIN_H - 3;
	this->time = clock();
	this->active = true;
	this->weapon_bonus = 0;
	for(int i = 0; i < MISS_NB; ++i)
		this->missile[i] = NULL;
	return;
}

Player::Player(Player const &src) { *this = src; }

Player::~Player(void) {
	for(int i = 0; i < MISS_NB * 2; ++i)
		if (this->missile[i] != NULL)
			delete this->missile[i];
	return;
}

Player			&Player::operator=(Player const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	this->active = src.getState();
	return *this;
}

void			Player::display() {

	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	attron(COLOR_PAIR(2));
	this->writePatern();
	attroff(COLOR_PAIR(2));
	for(int i = 0; i < MISS_NB; ++i)
	{
		if (this->missile[i] != NULL) {
			if (this->missile[i]->getY() <= 0) {
				delete this->missile[i];
				this->missile[i] = NULL;
			} else {
				time = ((actual - this->missile[i]->getTime()) / 1000000) * 1000;
				if (time > 50) 
				{
					this->missile[i]->move(true);
					this->missile[i]->setTime(actual);
				}
				this->missile[i]->display(4);
			}
		}
	}
}

void		Player::writePatern()
{
	mvwprintw(stdscr, this->y - 1, this->x, "%S", L"A");
	mvwprintw(stdscr, this->y, this->x - 1, "%S", L"/=\\");
	mvwprintw(stdscr, this->y + 1, this->x, "%S", L"\"");
	Player::width = 2;
	std::clock_t actual = clock();
	if (weapon_bonus > actual) {
		mvwprintw(stdscr, this->y, this->x - 3, "%S", L"I_(=)_I");
		Player::width = 4;
	}

}
void		Player::addBonusTime()
{
	std::clock_t actual = clock();

	if (weapon_bonus < actual)
		weapon_bonus = actual + 5000000;
	else
		weapon_bonus += 5000000;
}

void		Player::addMissile(int x, int y, std::wstring s)
{
	for(int i = 0; i < MISS_NB; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(x, y, s);
				return;
			}
}

void		Player::shoot() {
	std::clock_t actual = clock();
	double time = ((actual - this->shot) / (float)1000);
	if (time > 200) {
		if (weapon_bonus > actual)
		{
			addMissile(this->x - 3, this->y - 1, L"|");
			addMissile(this->x + 3, this->y - 1, L"|");
		}
		addMissile(this->x, this->y - 2, L"|");
		this->setShot(actual);
	}
}

void			Player::move(int c) {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	if (time > 30) {
		if (c == KEY_DOWN && this->y < WIN_H - Player::width)
			this->y += 1;
		else if (c == KEY_UP && this->y > WIN_H / 4)
			this->y -= 1;
		else if (c == KEY_LEFT && this->x > Player::width)
			this->x -= 1;
		else if (c == KEY_RIGHT && this->x < WIN_W - Player::width - 1)
			this->x += 1;
		this->time = actual;
	}
}

int	Player::width = 2;
