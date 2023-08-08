/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:11:58 by chris             #+#    #+#             */
/*   Updated: 2023/08/08 19:56:31 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character( void ) {

    std::cout << B_GREEN << "Character -> Default Constructor called" << RESET << std::endl;
    
   
    return;

}

Character::Character( std::string const & name ) : _name( name ) {

    std::cout << B_GREEN << "Character -> Parametric Constructor called" << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        inventory[i] = nullptr;
    }
    return;

}


Character::Character( Character const & src ) {

    std::cout << B_GREEN << "Character -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

Character::~Character( void ) {

    std::cout << B_RED << "Character -> Destructor called" << RESET << std::endl;

    return;

}

Character & Character::operator=( Character const & rhs ) {

    std::cout << B_GREEN << "Character -> Assignment operator called" << RESET << std::endl;
    this->_name = rhs.getName();
    return *this;

}

std::string const & Character::getName() const {

    return _name;

}

void Character::equip(AMateria* m) {

    std::cout << ORANGE << "********** EQUIP FUNCTION *********************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {

        if ( !inventory[i] ) {

            inventory[i] = m;
            std::cout << B_GRAY << this->getName() << BLUE << ITAL << " inventory[" << i << "] equiped with " << m->getType() << RESET << NORM << std::endl;
            std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

            return;
        }

    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

    
}

void Character::unequip(int idx) {

    std::cout << ORANGE << "********** UNEQUIP FUNCTION **********" << RESET << std::endl;

    std::cout << "idx = " << idx << " IN UNEQUIP FUNCTION" << std::endl;

    std::cout << ORANGE << "**************************************\n" << RESET << std::endl;


    
}

void Character::use(int idx, ICharacter& target) {

    std::cout << ORANGE << "********** CHARACTER USE FUNCTION *************" << RESET << std::endl;
    
    inventory[idx]->use( target );
        
        
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
}

void Character::printInventory( void ) const {

    std::cout << ORANGE << "********** PRINT INVENTORY ***********************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {

        if ( inventory[i] )
            std::cout << B_CYAN << "inventory [" << i << "] " << B_ORANGE << inventory[i]->getType() << RESET << std::endl;
        else
            std::cout << B_CYAN << "inventory [" << i << "] " << ITAL << GRAY << "empty" << RESET << std::endl;
    }
    std::cout << ORANGE << "**************************************************\n" << RESET << std::endl;

}


