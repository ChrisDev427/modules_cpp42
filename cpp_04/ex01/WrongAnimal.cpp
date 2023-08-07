/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:42:40 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal( void ) {

    std::cout << B_GREEN << "WrongAnimal -> Default Constructor called" << RESET << std::endl;
    type = "WrongAnimal";

    return;
}


WrongAnimal::WrongAnimal( WrongAnimal const & src ) {

    std::cout << B_GREEN << "WrongAnimal -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;
}

WrongAnimal::~WrongAnimal( void ) {

    std::cout << B_RED << "WrongAnimal -> Destructor called" << RESET << std::endl;

    return;
}

WrongAnimal & WrongAnimal::operator=( WrongAnimal const & rhs ) {

    std::cout << B_GREEN << "WrongAnimal -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();

    return *this;
}

std::string WrongAnimal::getType( void ) const {

    return this->type;
}

void WrongAnimal::makeSound() const{

    std::cout << B_RED << "I'm the MetaClass WrongAnimal..." << RESET << std::endl;
}

