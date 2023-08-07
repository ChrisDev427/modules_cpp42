/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:40 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:42:32 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Cat.hpp"

Cat::Cat( void ) {

    std::cout << B_GREEN << "Cat -> Default Constructor called" << RESET << std::endl;
    type = "Cat";

    return;
}


Cat::Cat( Cat const & src ) {

    std::cout << B_GREEN << "Cat -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

Cat::~Cat( void ) {

    std::cout << B_RED << "Cat -> Destructor called" << RESET << std::endl;

    return;

}

Cat & Cat::operator=( Cat const & rhs ) {

    std::cout << B_GREEN << "Cat -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string Cat::getType( void ) const {

    return this->type;
}

void Cat::makeSound() const{

    std::cout << B_CYAN << "Miaouuuuuuu..." << RESET << std::endl;

}


// std::ostream & operator<<( std::ostream & o, Cat const & rhs ) {

//     o << rhs.getType();
//     return o;

// }

