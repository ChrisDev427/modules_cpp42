/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/05 18:38:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"

AMateria::AMateria( void ) {

    std::cout << B_GREEN << "AMateria -> Default Constructor called" << RESET << std::endl;
    
    type = "AMateria";
    return;

}

AMateria::AMateria( std::string const & type ) : type( type ) {

    std::cout << B_GREEN << "AMateria -> Parametric Constructor called" << RESET << std::endl;
    
    return;

}


AMateria::AMateria( AMateria const & src ) {

    std::cout << B_GREEN << "AMateria -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

AMateria::~AMateria( void ) {

    std::cout << B_RED << "AMateria -> Destructor called" << RESET << std::endl;

    return;

}

AMateria & AMateria::operator=( AMateria const & rhs ) {

    std::cout << B_GREEN << "AMateria -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string const & AMateria::getType() const {

    return type;

}

void AMateria::use(ICharacter& target) {

    std::cout << "AMateria use function " << target.getName() << std::endl;

}




