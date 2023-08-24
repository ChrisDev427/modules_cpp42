/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/05 18:38:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"

Ice::Ice( void ) {

    std::cout << B_GREEN << "Ice -> Default Constructor called" << RESET << std::endl;
    type = "ice";
    return;

}

// Ice::Ice( std::string const & type ) {

//     std::cout << B_GREEN << "Ice -> Parametric Constructor called" << RESET << std::endl;
    
//     return;

// }


Ice::Ice( Ice const & src ) {

    std::cout << B_GREEN << "Ice -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

Ice::~Ice( void ) {

    std::cout << B_RED << "Ice -> Destructor called" << RESET << std::endl;

    return;

}

Ice & Ice::operator=( Ice const & rhs ) {

    std::cout << B_GREEN << "Ice -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string const & Ice::getType() const {

    return type;

}

AMateria* Ice::clone() const {

    std::cout << ORANGE << "***** Ice CLONE FUNCTION **********************" << RESET << std::endl;
    AMateria* ret = new Ice();
    return (ret);

}



void Ice::use(ICharacter& target) {

    std::cout << B_CYAN << "* shoots an ice bolt at " << target.getName() << " * " << RESET << std::endl;
}


