#ifndef ENEMYB_HPP
# define ENEMYB_HPP

# include "EnemyBase.hpp"

class EnemyB : public EnemyBase {

	private:
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
