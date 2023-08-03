/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:29:48 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 14:56:25 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iomanip>

Fixed::Fixed( void ) : _integer( 0 ) {

    std::cout << "Default Constructor called" << std::endl;

    return;
}

Fixed::Fixed( int const n ) {

    std::cout << "Int Constructor called" << std::endl;
        
    _integer = static_cast<long>(n) * (1 << _fractional); //decalage de 8 bits ( revient a faire (2^8) = 256 )

    return;
}

Fixed::Fixed( float const n ) {

    std::cout << "Float Constructor called" << std::endl;

    _integer = roundf(static_cast<float>(n) * (1 << _fractional)); //decalage de 8 bits ( revient a faire (2^8) = 256 )

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
    
    return this->_integer;
}

void Fixed::setRawBits( int const raw ) {

    this->_integer = raw;
}

float Fixed::toFloat( void ) const {

    float fPoint = static_cast<double>(_integer) / (1 << _fractional);

    return fPoint;
}

int Fixed::toInt( void ) const {

    int long long integer = _integer / (1 << _fractional);
    return integer;
}


std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {

    o << rhs.toFloat();
    
    return o;
}

const int Fixed::_fractional = 8;
