/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:11:58 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 11:25:50 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {

   if (printConstDest){ std::cout << B_GREEN << "Character -> Default Constructor called" << RESET << std::endl; }
    
    _name = "default_Name";
    for ( int i = 0; i < 4; i++ ) { _inventory[i] = NULL; }
    _throwedNb = 0;
    
    return;
}

Character::Character( std::string const & name ) : _name( name ) {

    if (printConstDest){ std::cout << B_GREEN << "Character -> Parametric Constructor called" << RESET << std::endl; }
    for ( int i = 0; i < 4; i++ ) { _inventory[i] = NULL; }
    _throwedNb = 0;
    
    return;
}

Character::Character( Character const & src ) {

    if (printConstDest){ std::cout << B_GREEN << "Character -> Copy Constructor called" << RESET << std::endl; }

    _instanceCopy++;
    std::stringstream ss;
    ss << _instanceCopy;
    std::string addCpyNb = ss.str();
    _name = src._name + "_copy_" + addCpyNb;
    _throwedNb = src._throwedNb;
   
    for ( int i = 0; i < 4; i++ ) { _inventory[i] = NULL; }
   
    for ( int i = 0; i < 4; i++ ) {

        if ( src._inventory[i] ) {

            if (printConstDest){ std::cout << GREEN << ITAL << "cloning  _inventory[" << i << "] from " << src._name << " to " << _name << " " << RESET << NORM; }
            _inventory[i] = src._inventory[i]->clone();
        }
    }
    return;
}

Character::~Character( void ) {

    if (printConstDest){ std::cout << B_RED << _name << " Character -> Destructor called" << RESET << std::endl; }

    for ( int i = 0; i < 4; i++ ) {
        
        if ( _inventory[i] ) {
            if (printConstDest){ std::cout << RED << ITAL << "deleting _inventory[" << i << "] of " << _name << RESET << NORM << std::endl; }
            delete _inventory[i];
        }
    }
 
    if ( _throwedInMemory > 0 ) {

        for ( int i = 0; _throwedMaterias[i]; i++ ) {
            
            if (printConstDest){ std::cout << RED << ITAL << "deleting _throwedMaterias[" << i << "] of " << _name << RESET << NORM << std::endl; }
            delete _throwedMaterias[i];
            _throwedInMemory--;
        }
        delete[] _throwedMaterias;
    }
    return;
}

Character & Character::operator=( Character const & rhs ) {

    if (printConstDest){ std::cout << B_GREEN << "Character -> Assignment operator called" << RESET << std::endl; }
    
    for ( int i = 0; i < 4; i++ ) {

        if ( _inventory[i] ) {
            
            if (printConstDest){ std::cout << RED << ITAL << "deleting _inventory[" << i << "] of " << _name << RESET << NORM << std::endl; }
            delete _inventory[i];
        }
    }

    for ( int i = 0; i < 4; i++ ) {

        if ( rhs._inventory[i] ) {

            if (printConstDest){ std::cout << GREEN << ITAL << "cloning  _inventory[" << i << "] from " << rhs._name << " to " << _name << " " << RESET << NORM; }
            _inventory[i] = rhs._inventory[i]->clone();
        }
    }
    _name = rhs._name;
    _throwedNb = rhs._throwedNb;
    return *this;
}

std::string const & Character::getName() const {

    return _name;

}

void Character::equip(AMateria* m) {

    std::cout << ORANGE << "***** EQUIP FUNCTION **************************" << RESET << std::endl;

    if ( m ) {

        if ( m->getEquiped() ) {
            std::cout << B_RED << "Materia [" << m->getType() << " " << m << "] already equiped" << RESET << std::endl;
            return;
        }
        for ( int i = 0; i < 4; i++ ) {

            if ( !_inventory[i] ) {

                _inventory[i] = m;
                m->setEquiped( true );
                for ( int j = 0; j < _throwedInMemory; j++ )    
                    if ( _throwedMaterias[j] == m ) {
                        std::cout << ORANGE << ITAL << getName() << " picked up a materia from the ground" << RESET << NORM << std::endl;
                        _delMatThrowedTab( m );
                    }
                std::cout << B_GRAY << getName() << RESET << BLUE << ITAL << " _inventory[" << i << "] equiped with " << m->getType() << RESET << NORM << std::endl;
                std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
                return;
            }
            else if ( i == 3 ) {
                std::cout << B_GRAY << _name << " is fully equiped" << std::endl; 
            }
        }
    }
    else {
        std::cout << RED << "not valid materia" << RESET << std::endl;
        std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
        return;
    }
}

void Character::unequip(int idx) {

    if ( idx >= 0 && idx < 4 && _inventory[idx] ) {

        std::cout << ORANGE << "***** UNEQUIP FUNCTION ************************" << RESET << std::endl;
        std::cout << GRAY << ITAL << "Called from '" << ORANGE << _name << GRAY << "'" << RESET << NORM << std::endl;
    
        std::cout << BLUE << ITAL << "Throwing materia " << _inventory[idx]->getType() << " from _inventory[" << idx << "]" << RESET << NORM << std::endl;

        this->_saveMatToFree( _inventory[idx] );

        _inventory[idx]->setEquiped( false );
        _inventory[idx] = NULL;

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
        _throwedMaterias[ 1 ] = NULL;
        _throwedInMemory++;
    }
    else  {
    
        int size = 0;
        while ( _throwedMaterias[size] ) {
            size++;
        }
        _throwedTmp = new AMateria*[size +2];
    
        for ( int i = 0; i < size; i++ ) {
            _throwedTmp[i] = _throwedMaterias[i];
        }
        _throwedTmp[size] = toSave;
        _throwedTmp[size +1] = NULL;
        delete[] _throwedMaterias;
        _throwedMaterias = _throwedTmp;
        _throwedInMemory++;
    }
    _throwedNb++;
}

void Character::_delMatThrowedTab( AMateria* unSave ) {

    int size = 0;
    while ( _throwedMaterias[size] ) {
        size++;
    }
    _throwedTmp = new AMateria*[size];
    
    for ( int i = 0, j = 0; i < size; i++, j++ ) {

        if ( _throwedMaterias[j] == unSave ) {
            j++;
        }
        _throwedTmp[i] = _throwedMaterias[j];
    }
    _throwedTmp[size -1] = NULL;
    delete[] _throwedMaterias;
    _throwedMaterias = _throwedTmp;
    _throwedInMemory--;
}

void Character::printInventory( void ) const {

    std::cout << ORANGE << "***** PRINT INVENTORY *************************" << RESET << std::endl;

    std::cout << B_GRAY << "Character : " << B_ORANGE << this->getName() << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        if ( _inventory[i] )
            std::cout << GRAY << "_inventory[" << i << "] -> " << B_ORANGE << std::setw(4) << std::right << _inventory[i]->getType() << RESET << GRAY << " " << _inventory[i] << std::endl;
        else
            std::cout << GRAY << "_inventory[" << i << "] -> " << ITAL << GRAY << "empty" << RESET << std::endl;
    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

}

void Character::printMatToFree( void ) {

    std::cout << ORANGE << "***** MATERIA'S SAVED IN MEMORY ***************" << RESET << std::endl;
    if ( _throwedMaterias ) {

        for ( int i = 0; _throwedMaterias[i]; i++ ) {

            std::cout << GRAY << "saved[" << i << "] -> " << _throwedMaterias[i] << " " << B_BLUE << _throwedMaterias[i]->getType() << RESET << std::endl;
        }
        std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
    }
    else {
        std::cout << B_RED << "No materia was thrown away" << RESET << std::endl;
    }
}

int             Character::_instanceCopy = 0;
int             Character::_throwedInMemory = 0;
AMateria**      Character::_throwedMaterias = NULL;
AMateria**      Character::_throwedTmp = NULL;