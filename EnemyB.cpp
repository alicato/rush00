#include "EnemyB.hpp"

EnemyB::EnemyB(void) : EnemyBase(5) {
	this->x = rand() % (WIN_W - 6) + 3;
	this->y = -(rand() % 5 + 3);
	for (int i = 0; i < MISS_NB; i++)
		this->missile[i] = NULL;
	this->leftLimit = 5;
	this->rightLimit = WIN_W - 5;
	return;
}

EnemyB::EnemyB(EnemyB const &src) { *this = src; }

EnemyB::~EnemyB(void) {
	for(int i = 0; i < MISS_NB; ++i)
		if (this->missile[i] != NULL)
			delete this->missile[i];

	return;
}

EnemyB &			EnemyB::operator=(EnemyB const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void		EnemyB::shoot() {
	if (this->y < 0)
		return;
	std::clock_t actual = clock();
	double time = ((actual - this->shot) / (float)1000000) * 1000;
	if (time > 700) {
		for(int i = 0; i < MISS_NB; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x, this->y + 3);
				this->setShot(actual);
				return;
			}
	}
}

void		EnemyB::move(Player & player) {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	if (time > 50) {
		EnemyBase::move();
		for (int i = 0; i < MISS_NB;++i)
			if (player.missile[i] != NULL && ((abs(this->x - player.missile[i]->getX()) < 4 && abs(this->y - player.missile[i]->getY()) < 4))) {
				delete player.missile[i];
				player.missile[i] = NULL;
				*this -= 1;
			}
		this->time = actual;
	}
}

void			EnemyB::display() {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, this->y - 1, this->x - 2, "H\\_/H");
	mvwprintw(stdscr, this->y, this->x - 2, "\\[-]/");
	mvwprintw(stdscr, this->y + 1, this->x - 2, "\\[U]/");
	mvwprintw(stdscr, this->y + 2, this->x - 1, "\\_/");
	attroff(COLOR_PAIR(1));
	for(int i = 0; i < MISS_NB; ++i)
	{
		if (this->missile[i] != NULL) {
			if (this->missile[i]->getY() > WIN_H) {
				delete this->missile[i];
				this->missile[i] = NULL;
			} else {
				time = ((actual - this->missile[i]->getTime()) / 1000000) * 1000;
				if (time > 50) 
				{
					this->missile[i]->move(false);
					this->missile[i]->setTime(actual);
				}
				this->missile[i]->display(5, L"*");
			}
		}
	}
}

void		EnemyB::collide(Player& player) {
	for (int i = 0; i < MISS_NB; i++)
		if (this->missile[i] != 0 && ((abs(this->missile[i]->getX() - player.getX()) < Player::width && this->missile[i]->getY() == player.getY()) || (abs(this->missile[i]->getY() - player.getY()) < 2 && this->missile[i]->getX() == player.getX()))) {
			delete this->missile[i];
			this->missile[i] = NULL;
			player -= 1;
		}
}
