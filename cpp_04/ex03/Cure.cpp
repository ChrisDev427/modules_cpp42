/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/05 18:38:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"

Cure::Cure( void ) {

    std::cout << B_GREEN << "Cure -> Default Constructor called" << RESET << std::endl;
    type = "cure";
    return;

}

// Cure::Cure( std::string const & type ) {

//     std::cout << B_GREEN << "Cure -> Parametric Constructor called" << RESET << std::endl;
    
//     return;

// }


Cure::Cure( Cure const & src ) {

    std::cout << B_GREEN << "Cure -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

Cure::~Cure( void ) {

    std::cout << B_RED << "Cure -> Destructor called" << RESET << std::endl;

    return;

}

Cure & Cure::operator=( Cure const & rhs ) {

    std::cout << B_GREEN << "Cure -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string const & Cure::getType() const {

    return type;

}

AMateria* Cure::clone() const {

    std::cout << ORANGE << "***** Cure CLONE FUNCTION ********************" << RESET << std::endl;

    return new Cure(*this);


}


void Cure::use(ICharacter& target) {

    std::cout << B_CYAN << "* heals " << target.getName() << "'s wounds * " << RESET << std::endl;
}


