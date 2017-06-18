#include "Boss.hpp"

void	Boss::setX(int x) { this->x = x; }
void	Boss::setY(int y) { this->y = y; }

Boss::Boss(void) {
	this->hp = 100;
	this->x = WIN_W / 2;
	this->y = 4;
	this->left = false;
	this->time = clock();
	this->shot = this->time;
	this->shot2 = this->time;
	for (int i = 0; i < MISS_NB * 2; i++)
		this->missile[i] = NULL;
	return;
}

Boss::Boss(Boss const &src) { *this = src; }

Boss::~Boss(void) { return; }

Boss &			Boss::operator=(Boss const &src) {
	this->x = src.getX();
	this->y = src.getY();
	this->hp = src.getHp();
	return *this;
}

void		Boss::move(Player & player) {

	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	if (time > 80) {
		if (this->left)
			this->x -= 1;
		else
			this->x += 1;
		if (this->x <= 35)
		{
			this->left = false;
		}
		if (this->x >= WIN_W - 35)
		{
			this->left = true;
		}
		for (int i = 0; i < MISS_NB;++i)
			if (player.missile[i] != NULL && (abs(this->x - player.missile[i]->getX()) < 32 && abs(this->y - player.missile[i]->getY()) < 2)) {
				delete player.missile[i];
				player.missile[i] = NULL;
				*this -= 1;
				this->time = actual;
			}
		this->time = actual;
	}
}

void			Boss::shoot() {
	std::clock_t actual = clock();
	double time = ((actual - this->shot) / (float)1000000) * 1000;
	if (time > 800) {
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x - 9, this->y + 2);
				this->shot = actual;
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x - 15, this->y + 2);
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x - 25, this->y + 2);
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x - 28, this->y + 2);
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x + 10, this->y + 2);
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x + 16, this->y + 2);
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x + 26, this->y + 2);
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x + 29, this->y + 2);
				break;
			}
	}
	time = ((actual - this->shot2) / (float)1000000) * 1000;
	if (time > 500) {
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x, this->y + 5);
				this->shot2 = actual;
				break;
			}
		for(int i = 0; i < MISS_NB * 2; ++i)
			if (this->missile[i] == NULL)
			{
				this->missile[i] = new Missile(this->x + 1, this->y + 5);
				break;
			}
	}
}

void			Boss::display() {
	std::clock_t actual = clock();
	double time = ((actual - this->time) / (float)1000000) * 1000;
	attron(COLOR_PAIR(1));
	mvwprintw(stdscr, this->y - 3, this->x - 19, "//           //    \"\"    \\\\           \\\\");
	mvwprintw(stdscr, this->y - 2, this->x - 24, "//   \\\\_/\"\\___/\"\\_\\\\___/||\\___//_/\"\\___/\"\\_//   \\\\");
	mvwprintw(stdscr, this->y - 1, this->x - 30, "//____\\\\____\\\\| |\\\\\\| |\\\\\\\\\\\\|::|//////| |///| |//____//____\\\\");
	mvwprintw(stdscr, this->y	 , this->x - 30, "\\\\\\\\\\\\\\\\\\\\\\\\\\\\| |\\\\\\| |\\\\\\\\\\\\|::|//////| |///| |//////////////");
	mvwprintw(stdscr, this->y + 1, this->x - 29, "\\_TT_/       \\X/   \\X/   \\|||::|||/   \\X/   \\X/       \\_TT_/");
	mvwprintw(stdscr, this->y + 2, this->x - 4, "!\\||/\\||/!");
	mvwprintw(stdscr, this->y + 3, this->x - 2, "\\|__|/");
	mvwprintw(stdscr, this->y + 4, this->x - 1, "\\__/");
	attroff(COLOR_PAIR(1));
	for(int i = 0; i < MISS_NB * 2; ++i)
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

void		Boss::collide(Player& player) {
	for (int i = 0; i < MISS_NB * 2; i++)
		if (this->missile[i] != 0 && ((abs(this->missile[i]->getX() - player.getX()) < Player::width && this->missile[i]->getY() == player.getY()) || (abs(this->missile[i]->getY() - player.getY()) < 2 && this->missile[i]->getX() == player.getX()))) {
			delete this->missile[i];
			this->missile[i] = NULL;
			player -= 1;
		}
}
