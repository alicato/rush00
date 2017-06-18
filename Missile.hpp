#ifndef MISSILE_HPP
# define MISSILE_HPP

#include "Entity.hpp"

class	Missile : public Entity {
	private:
		std::wstring	s;

	public:
		Missile(void);
		Missile(int x, int y);
		Missile(int x, int y, std::wstring s);
		Missile(Missile const &src);
		~Missile(void);
		Missile &operator=(Missile const &src);

		void	move(bool player);
		void	display(int n);
		void	display(int n, std::string s);
		void	display(int n, std::wstring s);
};

#endif
