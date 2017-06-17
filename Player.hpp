#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Entity.hpp"
#include "Missile.hpp"

class Player : public Entity {


	public:
		Player(void);
		~Player(void);
		Player(Player const &src);
		Player &operator=(Player const &src);

		void		display();
		void		move(int c);
		void		shoot();

		Missile*	missile[MISS_NB];
};

#endif
