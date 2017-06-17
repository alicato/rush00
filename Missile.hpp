#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "Entity.hpp"

class	Missile : public Entity {

	public:
		Missile(void);
		Missile(int x, int y);
		Missile(Missile const &src);
		~Missile(void);
		Missile &operator=(Missile const &src);

		void	move(bool player);
		void	display(int n, std::string s);
};

#endif
