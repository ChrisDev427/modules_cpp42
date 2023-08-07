/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:23 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:42:24 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Dog.hpp"

Dog::Dog( void ) {

    std::cout << B_GREEN << "Dog -> Default Constructor called" << RESET << std::endl;
    type = "Dog";

    return;
}


Dog::Dog( Dog const & src ) {

    std::cout << B_GREEN << "Dog -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

Dog::~Dog( void ) {

    std::cout << B_RED << "Dog -> Destructor called" << RESET << std::endl;

    return;

}

Dog & Dog::operator=( Dog const & rhs ) {

    std::cout << B_GREEN << "Dog -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string Dog::getType( void ) const {

    return this->type;
}

void Dog::makeSound() const{

    std::cout << B_CYAN << "Wouaf Wouaf Wouaf..." << RESET << std::endl;

}


// std::ostream & operator<<( std::ostream & o, Dog const & rhs ) {

//     o << rhs.getType();
//     return o;

// }

