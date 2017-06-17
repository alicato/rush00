#include "Entity.hpp"

Entity::Entity(void) { return; }

Entity::Entity(Entity const &src) { *this = src; }

Entity::~Entity(void) { return; }

Entity			&Entity::operator=(Entity const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void			Entity::operator+=(int amount) { this->hp += amount; }
void			Entity::operator-=(int amount) { this->hp -= amount; }

int				Entity::getX(void) const { return this->x; }
int				Entity::getY(void) const { return this->y; }
int				Entity::getHp(void) const { return this->hp; }
bool			Entity::getState(void) const { return this->active; }
float			Entity::getTime(void) const { return this->time; }
float			Entity::getShot(void) const { return this->shot; }

void			Entity::setTime(float t) { this->time = t; }
void			Entity::setShot(float t) { this->shot = t; }

void			Entity::move(int c) {
	(void)c;
	return;
}

void			Entity::die() {
	this->hp = 0;
	return;
}
