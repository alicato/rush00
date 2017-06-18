#ifndef PLAYER_HPP
# define PLAYER_HPP

#include "Entity.hpp"
#include "Missile.hpp"

class Player : public Entity {
	private:
		void		addMissile(int x, int y);
		double		weapon_bonus;

	public:
		Player(void);
		~Player(void);
		Player(Player const &src);
		Player &operator=(Player const &src);

		void		display();
		void		move(int c);
		void		shoot();
		void		addBonusTime();

		Missile*	missile[MISS_NB];
};

#endif
