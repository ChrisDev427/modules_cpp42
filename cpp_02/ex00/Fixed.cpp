/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:29:48 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 14:43:38 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Fixed.hpp"

Fixed::Fixed( void ) : _integer( 0 ) {

    
    std::cout << "Default Constructor called" << std::endl;

    return;

}

Fixed::Fixed( Fixed const & src ) {

    std::cout << "Copy Constructor called" << std::endl;
    *this = src;

    return;

}

Fixed::~Fixed( void ) {

    std::cout << "Destructor called" << std::endl;

    return;

}

Fixed & Fixed::operator=( Fixed const & rhs ) {

    std::cout << "Copy assignment operator called" << std::endl;
    this->_integer = rhs.getRawBits();
    return *this;

}

int Fixed::getRawBits( void ) const {
    
    std::cout << "getRawBits member function called" << std::endl;

    return this->_integer;
}

void Fixed::setRawBits( int const raw ) {

    this->_integer = raw;

}

const int Fixed::_fractional = 8;
