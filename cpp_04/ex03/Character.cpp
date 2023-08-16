/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:11:58 by chris             #+#    #+#             */
/*   Updated: 2023/08/15 13:09:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character( void ) {

    std::cout << B_GREEN << "Character -> Default Constructor called" << RESET << std::endl;
    
    _name = "default_Name";
    _inventory = new AMateria*[4];
    _throwedNb = 0;
    _instanceNb++;

    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }
    
    return;
}

Character::Character( std::string const & name ) : _name( name ) {

    std::cout << B_GREEN << "Character -> Parametric Constructor called" << RESET << std::endl;
    
    _inventory = new AMateria*[4];
    _throwedNb = 0;
    _instanceNb++;

    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }

    return;
}


Character::Character( Character const & src ) {

    std::cout << B_GREEN << "Character -> Copy Constructor called" << RESET << std::endl;

    this->_instanceCopy++;
    std::stringstream ss;
    ss << _instanceCopy;
    std::string addCpyNb = ss.str();

    this->_name = src._name + "_copy_" + addCpyNb;
    this->_throwedNb = src._throwedNb;
    this->_inventory = new AMateria*[4];

    for ( int i = 0; i < 4; i++ ) {

        if ( src._inventory[i] )
            this->_inventory[i] = src._inventory[i]->clone();
    }

    return;
}

Character::~Character( void ) {

    std::cout << B_RED << "Character -> Destructor called" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {

        if ( _inventory[i] ) {
            
            delete _inventory[i];
        }
    }
    delete[] _inventory;

   _instanceNb--;

    if ( _throwedNb > 0 && _instanceNb == 0 ) {

        for ( int i = 0; _throwedMaterias[i]; i++ ) {

            delete _throwedMaterias[i];
        }
    }
    
    return;
}

Character & Character::operator=( Character const & rhs ) {

    std::cout << B_GREEN << "Character -> Assignment operator called" << RESET << std::endl;
    
    this->_name = rhs._name;
    this->_throwedNb = rhs._throwedNb;
    for ( int i = 0; i < 4; i++ ) {

        if ( rhs._inventory[i] ) {

            this->_inventory[i] = rhs._inventory[i]->clone();
        }
    }
    return *this;

}

std::string const & Character::getName() const {

    return _name;

}

int Character::getInstNb( void ) {

    return _instanceNb;
 }

void Character::equip(AMateria* m) {

    
    for ( int i = 0; i < 4; i++ ) {

        if ( !_inventory[i] ) {
            
            std::cout << ORANGE << "***** EQUIP FUNCTION **************************" << RESET << std::endl;
            if ( m ) {
                
                _inventory[i] = m;
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

        std::cout << ORANGE << "***** UNEQUIP FUNCTION ************************" << RESET << std::endl;
        std::cout << GRAY << ITAL << "Called from '" << ORANGE << _name << GRAY << "'" << RESET << NORM << std::endl;
    
        std::cout << BLUE << ITAL << "Throwing materia " << _inventory[idx]->getType() << " from _inventory[" << idx << "]" << RESET << NORM << std::endl;

        this->_saveMatToFree( _inventory[idx] );
    
        _inventory[idx] = nullptr;

        std::cout << GRAY << ITAL << "throwed Materia[" << _throwedNb << "]" << RESET << NORM << std::endl;
        std::cout << GRAY << ITAL << "throwed in memory[" << _throwedInMemory << "]" << RESET << NORM << std::endl;
        std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
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

void Character::_saveMatToFree( AMateria* toSave ) {

    if ( !_throwedMaterias ) {
        
        _throwedMaterias = new AMateria*[ 2 ];
        _throwedMaterias[ 0 ] = toSave;
        _throwedMaterias[ 1 ] = nullptr;
        _throwedInMemory++;

    }
    else if ( _checkDblPtr( _throwedMaterias, toSave ) == false ) {
        
        _dupThrowedTab( _throwedTmp, _throwedMaterias, toSave );

        delete[] _throwedMaterias;
       
        _throwedMaterias = _throwedTmp;
        _throwedInMemory++;
    }
    _throwedNb++;
}

void Character::_dupThrowedTab( AMateria** & dst, AMateria** src, AMateria* toSave ) {

    int size = 0;
    
    while ( src[size] )
        size++;
    
    dst = new AMateria*[size +2];

    for ( int i = 0; i < size; i++ ) {

        dst[i] = src[i];
    }
    dst[size] = toSave;
    dst[size +1] = nullptr;
}

bool Character::_checkDblPtr( AMateria** tab, AMateria* src ) const{

    for ( int i = 0; tab[i]; i++ ) {

        if ( tab[i] == src )
            return ( true );
    }
    return ( false );
}

void Character::printInventory( void ) const {

    std::cout << ORANGE << "***** PRINT INVENTORY *************************" << RESET << std::endl;

    std::cout << B_GRAY << "Character : " << B_ORANGE << this->getName() << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        if ( _inventory[i] )
            std::cout << GRAY << "_inventory[" << i << "] -> " << B_ORANGE << std::setw(4) << std::right << _inventory[i]->getType() << RESET << GRAY << " " << _inventory[i] << RESET << std::endl;
        else
            std::cout << GRAY << "_inventory[" << i << "] -> " << ITAL << GRAY << "empty" << RESET << std::endl;
    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

}

void Character::printMatToFree( void ) {

    if ( _throwedMaterias ) {

        std::cout << ORANGE << "***** MATERIA'S SAVED IN MEMORY ***************" << RESET << std::endl;

        for ( int i = 0; _throwedMaterias[i]; i++ ) {

            std::cout << GRAY << "saved[" << i << "] -> " << _throwedMaterias[i] << " " << B_BLUE << _throwedMaterias[i]->getType() << RESET << std::endl;
        }
        std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
    }
}

int             Character::_instanceNb = 0;
int             Character::_instanceCopy = 0;
int             Character::_throwedInMemory = 0;
AMateria**      Character::_throwedMaterias = nullptr;
AMateria**      Character::_throwedTmp = nullptr;