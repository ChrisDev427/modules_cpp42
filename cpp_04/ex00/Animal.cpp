/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:42:40 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Animal.hpp"

Animal::Animal( void ) {

    std::cout << B_GREEN << "Animal -> Default Constructor called" << RESET << std::endl;
    type = "Animal";
    return;

}


Animal::Animal( Animal const & src ) {

    std::cout << B_GREEN << "Animal -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

Animal::~Animal( void ) {

    std::cout << B_RED << "Animal -> Destructor called" << RESET << std::endl;

    return;

}

Animal & Animal::operator=( Animal const & rhs ) {

    std::cout << B_GREEN << "Animal -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string Animal::getType( void ) const {

    return this->type;
}

void Animal::makeSound() const{

    std::cout << B_CYAN << "I'm the MetaClass Animal..." << RESET << std::endl;

}

// std::ostream & operator<<( std::ostream & o, Animal const & rhs ) {

//     o << rhs.getType();
//     return o;

// }

