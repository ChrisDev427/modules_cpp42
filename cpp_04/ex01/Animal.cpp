/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 08:52:19 by chris            ###   ########.fr       */
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

void Animal::makeSound() const{

    std::cout << B_CYAN << "I'm the MetaClass Animal..." << RESET << std::endl;

}

std::string Animal::getType( void ) const {

    return this->type;
}

void Animal::setPtr( std::string str ) const{

    std::cout << B_ORANGE << "Animal -> setPtr function with param: " << str << RESET << std::endl;
    
}

void Animal::printArray( void ) const {

    std::cout << B_ORANGE << "Animal printArray function" << RESET << std::endl;
    std::cout << GRAY << ITAL << "There is no array to print" << RESET << NORM << std::endl;


}
