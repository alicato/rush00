#ifndef ENEMYC_HPP
# define ENEMYC_HPP

# include "Entity.hpp"
# include "Missile.hpp"
# include "Player.hpp"

class EnemyC : public Entity {

	private:
		bool		left;
		Missile*	missile[MISS_NB];
		
	public:
		EnemyC(void);
		~EnemyC(void);
		EnemyC(EnemyC const &src);
		EnemyC &operator=(EnemyC const &src);

		void	setX(int x);
		void	setY(int y);
		void	display();
		void	move(Player& player);
		void	shoot();
		void	collide(Player& player);
};

#endif
