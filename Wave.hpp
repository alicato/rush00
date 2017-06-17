#ifndef WAVE_HPP
# define WAVE_HPP

# include "Enemy.hpp"
# include "EnemyB.hpp"
# include "EnemyC.hpp"
# include "Boss.hpp"

class	Wave {
	
	private:
		int			a;
		int			b;
		int			c;
		Enemy*		groupA;
		EnemyB*		groupB;
		EnemyC*		groupC;
		Boss*		boss;

	public:
		Wave();
		Wave(Wave const & src);
		Wave(int a, int b, int c);
		~Wave();
		Wave &	operator=(Wave const & rhs);

		int		getA() const;
		int		getB() const;
		int		getC() const;

		bool	update(Player & player);
};

#endif
