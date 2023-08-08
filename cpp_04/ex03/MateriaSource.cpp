/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:01:56 by chris             #+#    #+#             */
/*   Updated: 2023/08/08 21:42:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

    std::cout << B_GREEN << "MateriaSource -> Default Constructor called" << RESET << std::endl;
    for ( int i = 0; i < 4; i++ ) {

        _materiaCpy[i] = nullptr;
    }
    return;

}

// MateriaSource::MateriaSource( std::string const & type ) {

//     std::cout << B_GREEN << "MateriaSource -> Parametric Constructor called" << RESET << std::endl;
    
//     return;

// }


MateriaSource::MateriaSource( MateriaSource const & src ) {

    std::cout << B_GREEN << "MateriaSource -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

MateriaSource::~MateriaSource( void ) {

    std::cout << B_RED << "MateriaSource -> Destructor called" << RESET << std::endl;

    return;

}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs ) {

    std::cout << B_GREEN << "MateriaSource -> Assignment operator called" << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        this->_materiaCpy[i] = rhs._materiaCpy[i];

    }
    
    return *this;

}

void    MateriaSource::learnMateria(AMateria* m) {

    std::cout << ORANGE << "********** LEARN MATERIA **********************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {

        if ( !_materiaCpy[i] ) {

            _materiaCpy[i] = m;
            std::cout << ITAL << GREEN << "materia '" << m->getType() << "' learned in materiaCpy [" << i << "]" << RESET << NORM << std::endl;
            std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
            
            return;
        }
    }
    std::cout << ITAL << RED << "You cannot learn more materias" << RESET << NORM << std::endl;
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;


}

AMateria*   MateriaSource::createMateria(std::string const & type) {

    std::cout << ORANGE << "********** CREATE MATERIA *********************" << RESET << std::endl;

    if ( type != "ice" && type != "cure" ) {
        std::cout << RED << "Unknown materia type" << RESET << std::endl;
        return 0;
    }
    for ( int i = 0; i < 4; i++ ) {

        if ( _materiaCpy[i] ) {
            
            if ( _materiaCpy[i]->getType() == type ) {

                std::cout << GREEN << "materia " << type << " created" << RESET << std::endl;
                std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

                return _materiaCpy[i]->clone();
            }
        }
    }
    std::cout << RED << "materia's type not found !" << RESET << std::endl;
    return 0;
}


void    MateriaSource::printLearnedMateria( void ) const {

    std::cout << ORANGE << "********** PRINT LEARNED MATERIA **************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {
        
        if ( _materiaCpy[i] )
            std::cout << GREEN << "Learned [" << i << "] -> " << _materiaCpy[i]->getType() << RESET << std::endl;
        else
            std::cout << GRAY << "_______ [" << i << "] -> " << ITAL << "empty" << RESET << NORM << std::endl;
    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

}
