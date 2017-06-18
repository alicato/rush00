#include "Wave.hpp"

int			Wave::getA() const { return this->a; }
int			Wave::getB() const { return this->b; }
int			Wave::getC() const { return this->c; }

Wave::Wave() { return; }
Wave::Wave(Wave const & src) { *this = src; }

Wave::Wave(int a, int b, int c) : a(a), b(b), c(c) {
	if (a == 0 && b == 0 && c == 0)
		this->boss = new Boss;
	else {
		if (a != 0)
			this->groupA = new Enemy[a];
		if (b != 0)
			this->groupB = new EnemyB[b];
		if (c != 0)
			this->groupC = new EnemyC[c];
		this->boss = NULL;
	}
	for (int i = 0; i < 10 ; i++) {
		 this->bonus[i] = NULL;
	}
	this->bonusTimer = randNum(2000,5000);
	return;
}

Wave::~Wave() {
	if (a > 0)
		delete [] groupA;
	else {
		delete boss;
		return;
	}
	if (b > 0)
		delete [] groupB;
	if (c > 0)
		delete [] groupC;
	for (int i = 0; i < 10; i++) {
		if (this->bonus[i] != NULL) {
			delete this->bonus[i];
		}
	}
	return;
}

Wave &		Wave::operator=(Wave const & rhs) {
	this->a = rhs.getA();
	this->b = rhs.getB();
	this->c = rhs.getC();
	return *this;
}

bool		Wave::update(Player &player) {

	int	i = -1;
	bool	over = true;

	if (this->boss != NULL) {
		if (this->boss->getHp() > 0)
		{
			over = false;
			this->boss->move(player);
			this->boss->shoot();
			this->boss->display();
			this->boss->collide(player);
		}
		
	}
	else {
		while (++i < this->a)
		{
			if (this->groupA[i].getHp() > 0) {
				over = false;
				this->groupA[i].move(player);
				this->groupA[i].shoot();
				this->groupA[i].display();
				this->groupA[i].collide(player);
			}
		}
		i = -1;
		while (++i < this->b)
		{
			if (this->groupB[i].getHp() > 0) {
				over = false;
				this->groupB[i].move(player);
				this->groupB[i].shoot();
				this->groupB[i].display();
				this->groupB[i].collide(player);
			}
		}
		i = -1;
		while (++i < this->c)
		{
			if (this->groupC[i].getHp() > 0) {
				over = false;
				this->groupC[i].move(player);
				this->groupC[i].shoot();
				this->groupC[i].display();
				this->groupC[i].collide(player);
			}
		}
		if (ABonus *test = spawnBonus())
		{
			for (int i = 0; i < 10; i++)
			{
				if (this->bonus[i] == NULL)
				{
					this->bonus[i] = test;
					break;
				}
				if (i == 9)
					delete test;
			}
		}
		for (int i = 0; i < 10 ; i++) {
			if ( this->bonus[i] != NULL ) {
				if ( !this->bonus[i]->move(player) ) {
					delete this->bonus[i];
					this->bonus[i] = NULL;
				} else {
					this->bonus[i]->display();
				}
			}
		}
	}
	return over;
}


ABonus		*Wave::spawnBonus() {
	if ((std::clock() - this->lastBonus)/(float)1000 > this->bonusTimer) {
		int rand = this->randNum(0, 1);
		this->bonusTimer = randNum(5000,10000);
		this->lastBonus = std::clock();
		switch(rand){
			case BONUS_LIFE: return new BonusLife();
				break;
			case BONUS_WEAPON: return new BonusWeapon();
				break;	
			default: return NULL;
		}
	}
	return NULL;
}

int			Wave::randNum(int min, int max) {
	return std::rand()%(max - min + 1) + min;
}