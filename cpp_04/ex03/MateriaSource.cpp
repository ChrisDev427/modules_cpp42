/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/08 09:01:56 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 10:03:42 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource( void ) {

    if (printConstDest){ std::cout << B_GREEN << "MateriaSource -> Default Constructor called" << RESET << std::endl; }

    for ( int i = 0; i < 4; i++ ) { _materiaLearned[i] = NULL; }
    return;

}

MateriaSource::MateriaSource( MateriaSource const & src ) {

    if (printConstDest){ std::cout << B_GREEN << "MateriaSource -> Copy Constructor called" << RESET << std::endl; }
    
    for ( int i = 0; i < 4; i++ ) {

        if ( src._materiaLearned[i] ) {

            /*if (printConstDest){*/ std::cout << GREEN << ITAL << "cloning learned Materia's[" << i << "]" << RESET << NORM; //}
            _materiaLearned[i] = src._materiaLearned[i]->clone();
        }
    }

    return;

}

MateriaSource::~MateriaSource( void ) {

    if (printConstDest){ std::cout << B_RED << "MateriaSource -> Destructor called" << RESET << std::endl; }

    for ( int i = 0; i < 4; i++ ) {
        
        if ( _materiaLearned[i] ) {
            delete _materiaLearned[i];
        }
        
    }
    return;

}

MateriaSource & MateriaSource::operator=( MateriaSource const & rhs ) {

    if (printConstDest){ std::cout << B_GREEN << "MateriaSource -> Assignment operator called" << RESET << std::endl; }
    
    for ( int i = 0; i < 4; i++ ) {

        if ( _materiaLearned[i] ) {
            
            /*if (printConstDest){*/ std::cout << RED << ITAL << "deleting _learned Materia's[" << i << "] of " << RESET << NORM << std::endl; //}
            delete _materiaLearned[i];
        }
    }

    for ( int i = 0; i < 4; i++ ) {

        if ( rhs._materiaLearned[i] ) {

            /*if (printConstDest){*/ std::cout << GREEN << ITAL << "cloning  _learned Materia's[" << i << "]" << RESET << NORM; //}
            _materiaLearned[i] = rhs._materiaLearned[i]->clone();
        }
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
    delete m;
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
        
        if ( _materiaLearned[i]->getType() == type ) {
            AMateria* ret = _materiaLearned[i]->clone();
            std::cout << GREEN << "materia " << type << " created" << RESET << std::endl;
            std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
            return (ret);
        }
    }
    std::cout << RED << "materia not learned !" << RESET << std::endl;
    std::cout << ORANGE << "***********************************************\n" << RESET << std::endl;
    return 0;
}
