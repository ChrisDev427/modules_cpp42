/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:11:58 by chris             #+#    #+#             */
/*   Updated: 2023/08/24 19:09:19 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character( void ) {

   if (constDesPrint == true ){ std::cout << B_GREEN << "Character -> Default Constructor called" << RESET << std::endl; }
    
    _name = "default_Name";
    _inventory = new AMateria*[4];
    _throwedNb = 0;

    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = nullptr;
    }
    
    return;
}

Character::Character( std::string const & name ) : _name( name ) {

    if (constDesPrint == true ){ std::cout << B_GREEN << "Character -> Parametric Constructor called" << RESET << std::endl; }
    
    _inventory = new AMateria*[4];
    _throwedNb = 0;

    for ( int i = 0; i < 4; i++ ) {

        _inventory[i] = NULL;
    }

    return;
}

Character::Character( Character const & src ) {

    if (constDesPrint == true ){ std::cout << B_GREEN << "Character -> Copy Constructor called" << RESET << std::endl; }

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

    if (constDesPrint == true ){ std::cout << B_RED << "Character -> Destructor called" << RESET << std::endl; }

    for ( int i = 0; i < 4; i++ ) {

        if ( _inventory[i] ) {
            
            delete _inventory[i];
        }
    }
    delete[] _inventory;


    if ( _throwedInMemory > 0 ) {

        for ( int i = 0; _throwedMaterias[i]; i++ ) {
        
        
            delete _throwedMaterias[i];
            _throwedInMemory--;
        }
        delete[] _throwedMaterias;
    }

    return;
}

Character & Character::operator=( Character const & rhs ) {

     if (constDesPrint == true ){ std::cout << B_GREEN << "Character -> Assignment operator called" << RESET << std::endl; }
    
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

void Character::equip(AMateria* m) {

    std::cout << ORANGE << "***** EQUIP FUNCTION **************************" << RESET << std::endl;

    if ( m ) {

        if ( m->getEquiped() ) {
            std::cout << B_RED << "Materia [" << m << " " << &m << "] already equiped" << RESET << std::endl;
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