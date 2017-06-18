#ifndef BONUS_WEAPON_H
# define BONUS_WEAPON_H
#include <iostream> 
#include "Bonus.hpp"
#include "Entity.hpp"

class BonusWeapon : public ABonus
{
public:
					BonusWeapon();
					~BonusWeapon();
					BonusWeapon( BonusWeapon const & bonus );
	BonusWeapon &	operator=(BonusWeapon const & bonus);
	virtual void	action(Player & player);

protected:


};

#endif