#ifndef ENEMY_HPP
# define ENEMY_HPP

# include "EnemyBase.hpp"

class Enemy : public EnemyBase {
	private:
		Missile *missile;
	public:
		Enemy(void);
		~Enemy(void);
		Enemy(Enemy const &src);
		Enemy &operator=(Enemy const &src);

		void	move(Player& player);
		void	display();
		void	shoot();
		void	collide(Player& player);
};

#endif
