/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:01:56 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 19:06:03 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

    std::cout << B_GREEN << "MateriaSource -> Default Constructor called" << RESET << std::endl;
    for ( int i = 0; i < 4; i++ ) {

        _materiaLearned[i] = nullptr;
        _materia[i] = nullptr;
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

    // for ( int i = 0; i < 4; i++ ) {
        
    //     if ( _materiaLearned[i] ) {
    //         delete _materiaLearned[i];
    //     }
        
    //     // if ( _materia[i] )
    //     //     delete _materia[i];
    // }
    return;

}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs ) {

    std::cout << B_GREEN << "MateriaSource -> Assignment operator called" << RESET << std::endl;
    
    for ( int i = 0; i < 4; i++ ) {

        this->_materiaLearned[i] = rhs._materiaLearned[i];
        if ( rhs._materia[i] )
            this->_materia[i] = rhs._materia[i]->clone();

    }
    
    return *this;

}

void    MateriaSource::learnMateria(AMateria* m) {

    std::cout << ORANGE << "***** LEARN MATERIA ***************************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {

        if ( !_materiaLearned[i] ) {

            _materiaLearned[i] = m;
    
            std::cout << ITAL << GREEN << "materia '" << m->getType() << "' learned in materiaLearned[" << i << "]" << RESET << NORM << std::endl;
            std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
            
            return;
        }
    }
    std::cout << ITAL << RED << "You cannot learn more materias" << RESET << NORM << std::endl;
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;


}

AMateria*   MateriaSource::createMateria(std::string const & type) {

    std::cout << ORANGE << "***** CREATE MATERIA **************************" << RESET << std::endl;

    if ( type != "ice" && type != "cure" ) {
        std::cout << RED << "Unknown materia type" << RESET << std::endl;
        return 0;
    }
    for ( int i = 0; i < 4; i++ ) {

        if ( !_materia[i] ) {

            for ( int j = 0; j < 4; j++ ) {
                
                if ( _materiaLearned[j] && _materiaLearned[j]->getType() == type ) {

                    std::cout << GREEN << "materia " << type << " created" << RESET << std::endl;
                    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

                    
                    return _materia[i] = _materiaLearned[j]->clone();
                }
                if ( j == 3 ) {
                    
                    std::cout << RED << "materia's not learned !" << RESET << std::endl;
                    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
                    return 0;
                }
            }

        }
    }
    std::cout << RED << "4 materia's already created !" << RESET << std::endl;
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

    return 0;
}


void    MateriaSource::printLearnedMateria( void ) const {

    std::cout << ORANGE << "***** PRINT LEARNED MATERIA *******************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {
        
        if ( _materiaLearned[i] )
            std::cout << GREEN << "Learned [" << i << "] -> " << _materiaLearned[i]->getType() << RESET << std::endl;
        else
            std::cout << GRAY << "_______ [" << i << "] -> " << ITAL << "empty" << RESET << NORM << std::endl;
    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

}

void    MateriaSource::printCreatedMateria( void ) const {

    std::cout << ORANGE << "***** PRINT CREATED MATERIA *******************" << RESET << std::endl;

    for ( int i = 0; i < 4; i++ ) {
        
        if ( _materia[i] )
            std::cout << GREEN << "Created [" << i << "] -> " << _materia[i]->getType() << RESET << GRAY << " " << _materia[i] << RESET << std::endl;
        else
            std::cout << GRAY << "_______ [" << i << "] -> " << ITAL << "empty" << RESET << NORM << std::endl;
    }
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;

}
