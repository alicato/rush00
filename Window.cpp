#include "Window.hpp"
# define WIN_W 90
# define WIN_H 50

Window::Window(void) {
	initscr();
	start_color();
	cbreak();
	curs_set(FALSE);
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, true);
	srand(time(NULL));
	init_pair(1, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(2, COLOR_RED, COLOR_BLACK);
	init_pair(3, COLOR_BLACK, COLOR_WHITE);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_BLUE, COLOR_BLACK);
	init_pair(6, COLOR_WHITE, COLOR_RED);
	
	return;
}

Window::Window(Window const &src) { *this = src; }

Window::~Window(void) {
	endwin();
	return;
}

Window			&Window::operator=(Window const &src) { (void)src; return *this; }

void			Window::title(void) {
	mvwprintw(stdscr, 3, WIN_W / 2 - 32, " _______ _________   _______  _______ _________ _______  _______");
	mvwprintw(stdscr, 4, WIN_W / 2 - 32, "(  ____ \\\\__   __/  (  ____ )(  ____ \\\\__   __/(  ____ )(  ___  )");
	mvwprintw(stdscr, 5, WIN_W / 2 - 32, "| (    \\/   ) (     | (    )|| (    \\/   ) (   | (    )|| (   ) |");
	mvwprintw(stdscr, 6, WIN_W / 2 - 32, "| (__       | |     | (____)|| (__       | |   | (____)|| |   | |");
	mvwprintw(stdscr, 7, WIN_W / 2 - 32, "|  __)      | |     |     __)|  __)      | |   |     __)| |   | |");
	mvwprintw(stdscr, 8, WIN_W / 2 - 32, "| (         | |     | (\\ (   | (         | |   | (\\ (   | |   | |");
	mvwprintw(stdscr, 9, WIN_W / 2 - 32, "| )         | |     | ) \\ \\__| (____/\\   | |   | ) \\ \\__| (___) |");
	mvwprintw(stdscr, 10, WIN_W / 2 - 32, "|/          )_(_____|/   \\__/(_______/   )_(   |/   \\__/(_______)");
	mvwprintw(stdscr, 11, WIN_W / 2 - 32, "              (_____)");
}

int				Window::menu(void) {
	bool loop = true;
	int c;

	loop = this->size();
	while (loop) {
		erase();
		this->borders(0, 0);
		this->title();
		attron(COLOR_PAIR(2));
		mvwprintw(stdscr, WIN_H / 2 - 4, WIN_W / 2 - 7, "Welcome");
		mvwprintw(stdscr, WIN_H / 2, WIN_W / 2 - 14, "Press       to launch the game");
		attroff(COLOR_PAIR(2));
		attron(COLOR_PAIR(4) | A_BOLD);
		mvwprintw(stdscr, WIN_H / 2, WIN_W / 2 - 8, "Space");
		attroff(COLOR_PAIR(4));
		attron(COLOR_PAIR(5) | A_UNDERLINE);
		mvwprintw(stdscr, WIN_H / 2 - 4, WIN_W / 2 + 2, "Judge");
		attroff(COLOR_PAIR(5) | A_UNDERLINE | A_BOLD);
		attron(COLOR_PAIR(1) | A_BLINK);
		mvwprintw(stdscr, WIN_H - 1, 2, "daltman & jthomas");
		attroff(COLOR_PAIR(1) | A_BLINK);
		refresh();
		c = getch();
		if (c == 27)
			return false;
		else if (c == 32)
			return true;
		loop = this->size();
	}
	return false;
}

int				Window::size(void) {
	int	y;
	int	x;
	int c;

	refresh();
	getmaxyx(stdscr, y, x);
	if (x >= WIN_W && y > WIN_H)
		return true;
	while (x < WIN_W || y < WIN_H) {
		erase();
		mvwprintw(stdscr, 0, 0, "Game paused. Window too small.");
		refresh();
		c = getch();
		if (c == 27)
			return false;
		getmaxyx(stdscr, y, x);
	}
	return 2;
}

void			Window::borders(int hp, int wave) {
	attron(COLOR_PAIR(3));
	for (int y = 0;y < WIN_H;y++) {
		mvwprintw(stdscr, y, 0, " ");
		mvwprintw(stdscr, y, WIN_W - 1, " ");
	}
	mvwprintw(stdscr, WIN_H, 0, "                                                                                          ");
	if (hp > 0) {
		mvwprintw(stdscr, WIN_H, 0, "LIFE:%d   WAVE:%d", hp, wave);
	}
	attroff(COLOR_PAIR(3));
}

bool			Window::pause(void) {
	int		c;
	bool	choice = false;

	erase();
	while (true) {
		this->size();
		this->borders(0, 0);
		this->title();
		attron(A_UNDERLINE);
		mvwprintw(stdscr, WIN_H / 2 - 2, WIN_W / 2 - 6, "Game paused");
		attroff(A_UNDERLINE);
		if (!choice)
			attron(A_REVERSE);
		mvwprintw(stdscr, WIN_H / 2, WIN_W / 2 - 4, "Resume");
		attroff(A_REVERSE);
		if (choice)
			attron(A_REVERSE);
		mvwprintw(stdscr, WIN_H / 2 + 1, WIN_W / 2 - 3, "Quit");
		attroff(A_REVERSE);
		refresh();
		c = getch();
		if (c == KEY_DOWN)
			choice = true;
		if (c == KEY_UP)
			choice = false;
		if (c == 32 && choice)
			return false;
		else if (c == 32)
			return true;
	}
}

bool		Window::lose() {
	int c;
	erase();
	while (true) {
		this->size();
		this->borders(0, 0);
		this->title();
		mvwprintw(stdscr, WIN_H / 2 - 1, WIN_W / 2 - 4, "You lost !");
		mvwprintw(stdscr, WIN_H / 2 + 1, WIN_W / 2 - 9, "Press SPACE to      !");
		attron(COLOR_PAIR(2));
		mvwprintw(stdscr, WIN_H / 2 + 1, WIN_W / 2 + 6, "FLEE");
		attroff(COLOR_PAIR(2));
		refresh();
		c = getch();
		if (c == 32)
			return false;
	}
}

void	Window::stars() {
	int	y = 0;

	while (y < WIN_H)
	{
		mvwprintw(stdscr, y, rand() % WIN_W, ".");
		y += 4;
	}
}
