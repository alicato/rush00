#include "EnemyC.hpp"

EnemyC::EnemyC(void) : EnemyBase(10) {
	this->x = rand() % (WIN_W - 20) + 10;
	this->y = -(rand() % 7 + 4);
	for (int i = 0; i < MISS_NB;  i++)
		this->missile[i] = NULL;
	this->leftLimit = 8;
	this->rightLimit = WIN_W - 10;
	return;
}

EnemyC::EnemyC(EnemyC const &src) { *this = src; }

EnemyC::~EnemyC(void) { return; }

EnemyC &			EnemyC::operator=(EnemyC const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void		EnemyC::move(Player & player) {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	if (time > 80) {
		EnemyBase::move();
		for (int i = 0; i < MISS_NB;++i)
			if (player.missile[i] != NULL && ((abs(this->x - player.missile[i]->getX()) < 7 && this->y - 1 == player.missile[i]->getY()) || (abs(this->y - player.missile[i]->getY()) < 3 && abs(this->x - player.missile[i]->getX()) < 2))) {
				delete player.missile[i];
				player.missile[i] = NULL;
				*this -= 1;
			}
		this->time = actual;
	}
}

void		EnemyC::shoot() {
	if (this->y < 0)
		return;
	std::clock_t actual = clock();
	double time = ((actual - this->shot) / (float)1000000) * 1000;
	if (time > 500) {
		for(int i = 0; i < MISS_NB; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x - 3, this->y + 1);
				this->setShot(actual);
				break;
			}
		for(int i = 0; i < MISS_NB; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x + 3, this->y + 1);
				this->setShot(actual);
				return;
			}
	}
}

void			EnemyC::display() {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, this->y - 2, this->x - 2, "_/Y\\_");
	mvwprintw(stdscr, this->y - 1, this->x - 6, "<:/:::O:::\\:>");
	mvwprintw(stdscr, this->y, this->x - 3, "!\\|||/!");
	mvwprintw(stdscr, this->y + 1, this->x - 1, "|U|");
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
				this->missile[i]->display(5 ,"|");
			}
		}
	}
}

void		EnemyC::collide(Player& player) {
	for (int i = 0; i < MISS_NB; i++)
		if (this->missile[i] != 0 && ((abs(this->missile[i]->getX() - player.getX()) < 2 && this->missile[i]->getY() == player.getY()) || (abs(this->missile[i]->getY() - player.getY()) < 2 && this->missile[i]->getX() == player.getX()))) {
			delete this->missile[i];
			this->missile[i] = NULL;
			player -= 1;
		}
}
