#ifndef ENEMYB_HPP
# define ENEMYB_HPP

# include "Entity.hpp"
# include "Missile.hpp"
# include "Player.hpp"

class EnemyB : public Entity {

	private:
		bool		left;
		Missile*	missile[MISS_NB];

	public:
		EnemyB(void);
		~EnemyB(void);
		EnemyB(EnemyB const &src);
		EnemyB &operator=(EnemyB const &src);

		void	setX(int x);
		void	setY(int y);
		void	display();
		void	move(Player& player);
		void	shoot();
		void	collide(Player& player);
};

#endif
