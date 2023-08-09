/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:11:58 by chris             #+#    #+#             */
/*   Updated: 2023/08/09 19:53:41 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character( void ) {

    std::cout << B_GREEN << "Character -> Default Constructor called" << RESET << std::endl;
    
    _name = "default_Name";
    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }
    
    
    _throwedNb = 0;
    
    for ( int i = 0; i < 8; i++ ){
        _throwedMaterias[i] = nullptr;
    }
   
    return;

}

Character::Character( std::string const & name ) : _name( name ) {

    std::cout << B_GREEN << "Character -> Parametric Constructor called" << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }
    
    
    _throwedNb = 0;
    
    for ( int i = 0; i < 20; i++ ){
        _throwedMaterias[i] = nullptr;
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

    for ( int i = 0; i < 4; i++ ) {
        
        if ( _inventory[i] ) {

            delete _inventory[i];
        }
    }
    for ( int i = 0; i < 20; i++ ) {

        
        if ( _throwedMaterias[i] ) {

            delete _throwedMaterias[i];
            std::cout << "i = " << i << std::endl;
        }
        
    }
    
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

    for ( int i = 0; i < 4; i++ ) {

        if ( !_inventory[i] ) {
            
            std::cout << ORANGE << "***** EQUIP FUNCTION **************************" << RESET << std::endl;
            if ( m ) {

                _inventory[i] = m->clone();
                // _inventory[i] = m;
                std::cout << B_GRAY << this->getName() << RESET << BLUE << ITAL << " _inventory[" << i << "] equiped with " << m->getType() << RESET << NORM << std::endl;
                std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
                return;
            }
            else {
                std::cout << RED << "not valid materia" << RESET << std::endl;
                std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
                return;
            }
        }
    }
}

void Character::unequip(int idx) {

    if ( idx >= 0 && idx < 4 && _inventory[idx] ) {

        std::cout << ORANGE << "***** UNEQUIP FUNCTION ***************" << RESET << std::endl;
    
        std::cout << BLUE << ITAL << "Throwing materia " << _inventory[idx]->getType() << " from _inventory[" << idx << "]" << RESET << NORM << std::endl;

        this->_saveMatToFree( _inventory[idx] );
        _inventory[idx] = nullptr;
    
        std::cout << ORANGE << "**************************************\n" << RESET << std::endl;
    }
}

void Character::use(int idx, ICharacter& target) {

    if ( idx >= 0 && idx < 4 && _inventory[idx] ) {
        std::cout << ORANGE << "***** CHARACTER USE FUNCTION ******************" << RESET << std::endl;
        if ( !dynamic_cast<Character*>(&target) ) {
            
            std::cout << RED << "Error: Use: invalid parameter -> 'target'" << RESET << std::endl;
            std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
            return;
        }
        _inventory[idx]->use( target );
        std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
    }
}

void Character::printInventory( void ) const {

    std::cout << ORANGE << "***** PRINT INVENTORY *************************" << RESET << std::endl;

    std::cout << B_GRAY << "Character : " << B_ORANGE << this->getName() << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        if ( _inventory[i] )
            std::cout << GRAY << "_inventory [" << i << "] -> " << B_ORANGE << _inventory[i]->getType() << RESET << std::endl;
        else
            std::cout << GRAY << "_inventory [" << i << "] -> " << ITAL << GRAY << "empty" << RESET << std::endl;
    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

}

void Character::_saveMatToFree( AMateria* toFree ) {

    for ( int i = 0; i < 20; i++ ) {

        if ( !_throwedMaterias[i] ) {
            puts("AAAAA");
           _throwedMaterias[i] = toFree;
           _throwedNb++;
           std::cout << GRAY << ITAL << "Throwed Materia [" << _throwedNb << "]" << RESET << NORM << std::endl;
           
           return;
        }
    }
}

