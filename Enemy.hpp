#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "Entity.hpp"
# include "Missile.hpp"
# include "Player.hpp"

class Enemy : public Entity {

	private:
		bool		left;
		Missile*	missile;

	public:
		Enemy(void);
		~Enemy(void);
		Enemy(Enemy const &src);
		Enemy &operator=(Enemy const &src);

		void	setX(int x);
		void	setY(int y);
		void	display();
		void	move(Player& player);
		void	shoot();
		void	collide(Player& player);
};

#endif
