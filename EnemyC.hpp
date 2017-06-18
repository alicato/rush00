#ifndef ENEMYC_HPP
# define ENEMYC_HPP

# include "EnemyBase.hpp"

class EnemyC : public EnemyBase {

	private:
		Missile*	missile[MISS_NB];
		
	public:
		EnemyC(void);
		~EnemyC(void);
		EnemyC(EnemyC const &src);
		EnemyC &operator=(EnemyC const &src);

		void	display();
		void	move(Player& player);
		void	shoot();
		void	collide(Player& player);
};

#endif
