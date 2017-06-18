#ifndef BONUS_ACTION_H
# define BONUS_ACTION_H
#include <iostream> 
#include "Bonus.hpp"
#include "Entity.hpp"

class BonusLife : public ABonus
{
public:
					BonusLife();
					~BonusLife();
					BonusLife( BonusLife const & bonus );
	BonusLife &		operator=(BonusLife const & bonus);
	virtual void	action(Player & player);

protected:


};

#endif