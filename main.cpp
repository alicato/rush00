#include "game.hpp"

int main(void) {
	Window	win;
	Player*	player = new Player();
	Wave*	wave = new Wave(7, 0, 0);
	int 	loop = true;
	int		w = 0;
	int		c;

	srand(time(0));
	loop = win.menu();
	while (loop) {
		c = getch();
		erase();
		win.stars();
		if (c == KEY_DOWN || c == KEY_UP || c == KEY_LEFT || c == KEY_RIGHT)
			player->move(c);
		player->shoot();
		player->display();
		if (wave->update(*player))
		{
			delete wave;
			if (++w % 3 != 0)
				wave = new Wave(5 + w, w, w / 2); 
			else
				wave = new Wave(0, 0, 0);
		}
		win.borders(player->getHp(), w + 1);
		loop = win.size();
		if (loop == 2 || c == 32)
			loop = win.pause();
		if (player->getHp() <= 0)
			loop = win.lose();
	}
	delete player;
	return 0;
}
