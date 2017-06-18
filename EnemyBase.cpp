#include "EnemyBase.hpp"

void	EnemyBase::setX(int x) { this->x = x; }
void	EnemyBase::setY(int y) { this->y = y; }

EnemyBase::EnemyBase(void) {}

EnemyBase::EnemyBase(int hp) {
	this->hp = hp;
	this->direction = (this->x % 2 == 0) ? -1 : 1;
	this->time = clock();
	this->shot = this->time;
	return;
}

EnemyBase::EnemyBase(EnemyBase const &src) { *this = src; }

EnemyBase::~EnemyBase(void) { return; }

EnemyBase &			EnemyBase::operator=(EnemyBase const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void		EnemyBase::move() {
	x += direction;
	if (x < leftLimit || x > rightLimit)
	{
		x = (x < leftLimit) ? leftLimit : rightLimit;
		y++;
		direction = -direction;
	}
	if (y < 1 && y > -3)
		y++;
}
