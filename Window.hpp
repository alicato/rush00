#ifndef WINDOW_HPP
# define WINDOW_HPP

# include "game.hpp"

class Window {

	public:
		Window(void);
		~Window(void);
		Window(Window const &src);
		Window &operator=(Window const &src);

		int		menu(void);
		int		size(void);
		void	borders(int hp, int wave);
		bool	pause(void);
		bool	lose(void);
		void	stars();
		void	title(void);
};

#endif
