#ifndef ENEMY_BASE_HPP
# define ENEMY_BASE_HPP

# include "Entity.hpp"
# include "Missile.hpp"
# include "Player.hpp"

class EnemyBase : public Entity {
	private:
		int			direction;

	protected:
		int			leftLimit;
		int			rightLimit;

	public:
		EnemyBase(void);
		EnemyBase(int hp);
		~EnemyBase(void);
		EnemyBase(EnemyBase const &src);
		EnemyBase &operator=(EnemyBase const &src);

		void			setX(int x);
		void			setY(int y);
		virtual void	display() = 0;
		void			move();
		virtual void	shoot() = 0;
		virtual void	collide(Player& player) = 0;
};

#endif
