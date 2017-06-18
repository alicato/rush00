#ifndef BONUS_H
# define BONUS_H
#include <iostream> 
#include "Player.hpp"
#include "Entity.hpp"

class ABonus : public Entity
{
public:
					ABonus();
					~ABonus();
					ABonus( ABonus const & bonus );
	ABonus &		operator=(ABonus const & bonus);
	bool			move(Player & player);
	void			display();
	virtual void	action(Player & player) = 0;

protected:
	std::string		_patern;
	int				_color;

};

#endif