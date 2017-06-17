#ifndef ENTITY_HPP
# define ENTITY_HPP

# define WIN_H 50
# define WIN_W 90
# define MISS_NB 30

# include <ncurses.h>
# include <iostream>
# include <ctime>
# include <cstdlib>

class Entity {
	public:
		Entity(void);
		virtual ~Entity(void);
		Entity(Entity const &src);
		Entity &operator=(Entity const &src);

		void			operator+=(int amount);
		void			operator-=(int amount);
		int				getX(void) const;
		int				getY(void) const;
		int				getHp(void) const;
		bool			getState(void) const;
		float			getTime(void) const;
		void			setTime(float t);
		float			getShot(void) const;
		void			setShot(float t);

		void			move(int c);
		void			die();


	protected:
		int				x;
		int				y;
		int				hp;
		clock_t			time;
		clock_t			shot;
		bool			active;
};

#endif
