/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:11:58 by chris             #+#    #+#             */
/*   Updated: 2023/08/10 18:12:53 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"


Character::Character( void ) {

    std::cout << B_GREEN << "Character -> Default Constructor called" << RESET << std::endl;
    
    _name = "default_Name";
    _inventory = new AMateria*[4];
    _throwedNb = 0;
    _throwedInMemory = 0;

    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }
    
    return;
}

Character::Character( std::string const & name ) : _name( name ) {

    std::cout << B_GREEN << "Character -> Parametric Constructor called" << RESET << std::endl;
    
    _inventory = new AMateria*[4];
    _throwedNb = 0;
    _throwedInMemory = 0;

    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }
 
    return;
}


Character::Character( Character const & src ) {

    std::cout << B_GREEN << "Character -> Copy Constructor called" << RESET << std::endl;
    this->_name = src._name;
    // this->_throwedNb = src._throwedNb;
    // _dupThrowedTab( this->_throwedMaterias, src->_throwedMaterias );


    return;

}

Character::~Character( void ) {

    std::cout << B_RED << "Character -> Destructor called" << RESET << std::endl;

  
        
    delete[] _inventory;
    
    // if ( _throwedNb > 0 ) {

        delete[] _throwedMaterias;
    // }

    
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

        std::cout << ORANGE << "***** UNEQUIP FUNCTION ***************" << RESET << std::endl;
    
        std::cout << BLUE << ITAL << "Throwing materia " << _inventory[idx]->getType() << " from _inventory[" << idx << "]" << RESET << NORM << std::endl;

        this->_saveMatToFree( _inventory[idx] );
    
        _inventory[idx] = nullptr;

        std::cout << GRAY << ITAL << "throwed Materia[" << _throwedNb << "]" << RESET << NORM << std::endl;
        std::cout << GRAY << ITAL << "throwed in memory[" << _throwedInMemory << "]" << RESET << NORM << std::endl;
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

    if ( !_throwedMaterias ) {
        
        _throwedMaterias = new AMateria*[_throwedNb +1];
        _throwedMaterias[_throwedNb ] = toFree;
    }
    else if ( _checkDblPtr( _throwedMaterias, toFree ) == false ) {

        _dupThrowedTab( _throwedTmp, _throwedMaterias );
        delete[] _throwedMaterias;
      
        _throwedMaterias = new AMateria*[_throwedNb +1];

        for ( int i = 0; i < _throwedNb; i++ ) {

            _throwedMaterias[i] = _throwedTmp[i];
        }
        _throwedMaterias[_throwedNb ] = toFree;

        delete[] _throwedTmp;
        _throwedInMemory++;
        for ( int i = 0; _throwedMaterias[i]; i++ ) {
            std::cout << _throwedMaterias[i] << std::endl;
        }
    }
    _throwedNb++;
    
}

void Character::_dupThrowedTab( AMateria** & dst, AMateria** & src ) {

    int size = 0;
    
    while ( src[size] )
        size++;
    
    dst = new AMateria*[size +1];

    for ( int i = 0; i < size; i++ ) {

        dst[i] = src[i];
    }
    dst[size +1] = nullptr;
}

bool Character::_checkDblPtr( AMateria** tab, AMateria* src ) const{

    for ( int i = 0; tab[i]; i++ ) {

        if ( tab[i] == src )
            return ( true );
    }
    return ( false );

}
