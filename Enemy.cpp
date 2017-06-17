#include "Enemy.hpp"

void	Enemy::setX(int x) { this->x = x; }
void	Enemy::setY(int y) { this->y = y; }

Enemy::Enemy(void) {
	this->hp = 2;
	this->x = rand() % (WIN_W - 5) + 5;
	this->y = -(rand() % 10 + 2);
	if (this->x % 2 == 0)
		this->left = true;
	else
		this->left = false;
	this->time = clock();
	this->shot = this->time;
	this->missile = NULL;
	return;
}

Enemy::Enemy(Enemy const &src) { *this = src; }

Enemy::~Enemy(void) { return; }

Enemy &			Enemy::operator=(Enemy const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void		Enemy::move(Player & player) {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	if (time > 20) {
		if (this->left)
			this->x -= 1;
		else
			this->x += 1;
		if (this->x < 2)
		{
			this->y += 1;
			this->left = false;
		}
		if (this->x > WIN_W - 5)
		{
			this->left = true;
			this->y += 1;
		}
		for (int i = 0; i < MISS_NB;++i)
			if (player.missile[i] != NULL && ((abs(this->x - player.missile[i]->getX()) < 2 && abs(this->y - player.missile[i]->getY()) < 2))) {
				delete player.missile[i];
				player.missile[i] = NULL;
				*this -= 1;
				this->time = actual;
			}
		this->time = actual;
	}
}

void		Enemy::shoot() {
	if (this-> y < 0)
		return;
	std::clock_t actual = clock();
	double time = ((actual - this->shot) / (float)1000000) * 1000;
	if (time > 200) {
		if (this->missile == NULL)
		{
			this->missile = new Missile(this->x, this->y + 2);
			this->setShot(actual);
			return;
		}
	}
}

void			Enemy::display() {
	std::clock_t actual = clock();
	std::clock_t t;
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, this->y - 1, this->x - 1, "!Y!");
	mvwprintw(stdscr, this->y, this->x - 1, "|U|");
	mvwprintw(stdscr, this->y + 1, this->x - 1, "\\_/");
	attroff(COLOR_PAIR(1));
	if (this->missile != NULL) {
		if (this->missile->getY() > WIN_H) {
			delete this->missile;
			this->missile = NULL;
		} else {
			t = ((actual - this->missile->getTime()) / 1000000) * 1000;
			if (t > 50) 
			{
				this->missile->move(false);
				this->missile->setTime(actual);
			}
			this->missile->display(5, "o");
		}
	}

}

void		Enemy::collide(Player& player) {
	if (this->missile != 0 && ((abs(this->missile->getX() - player.getX()) < 2 && this->missile->getY() == player.getY()) || (abs(this->missile->getY() - player.getY()) < 2 && this->missile->getX() == player.getX()))) {
		delete this->missile;
		this->missile = NULL;
		player -= 1;
	}
}
