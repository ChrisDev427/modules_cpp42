/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:40 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:42:32 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "WrongCat.hpp"

WrongCat::WrongCat( void ) {

    std::cout << B_GREEN << "WrongCat -> Default Constructor called" << RESET << std::endl;
    type = "WrongCat";

    return;
}


WrongCat::WrongCat( WrongCat const & src ) {

    std::cout << B_GREEN << "WrongCat -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

WrongCat::~WrongCat( void ) {

    std::cout << B_RED << "WrongCat -> Destructor called" << RESET << std::endl;

    return;

}

WrongCat & WrongCat::operator=( WrongCat const & rhs ) {

    std::cout << B_GREEN << "WrongCat -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}

std::string WrongCat::getType( void ) const {

    return this->type;
}

void WrongCat::makeSound() const{

    std::cout << B_RED << "Wrong Cat Miaouuuuuuu..." << RESET << std::endl;

}


// std::ostream & operator<<( std::ostream & o, WrongCat const & rhs ) {

//     o << rhs.getType();
//     return o;

// }

