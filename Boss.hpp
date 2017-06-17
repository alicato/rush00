#ifndef BOSS_HPP
# define BOSS_HPP

# include "Entity.hpp"
# include "Player.hpp"

class Boss : public Entity {

	private:
		bool	left;
		Missile*	missile[MISS_NB * 2];
		std::clock_t	shot2;

	public:
		Boss(void);
		~Boss(void);
		Boss(Boss const &src);
		Boss &operator=(Boss const &src);

		void	setX(int x);
		void	setY(int y);
		void	display();
		void	move(Player & player);
		void	shoot();
		void	collide(Player & player);
};

#endif
