/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:29:48 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 11:41:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/*****************************************************************************/
/*****************       CONSTRUCTORS        *********************************/
/*****************************************************************************/

Fixed::Fixed( void ) : _integer( 0 ) {

    std::cout << GREEN << "Default Constructor called" << RESET << std::endl;

    return;
}

Fixed::Fixed( int const n ) {

    std::cout << GREEN << "Int Constructor called" << RESET << std::endl;
    
    _integer = static_cast<int long>(n) * (1 << _fractional); //decalage de 8 bits ( revient a faire (2^8) = 256 )

    return;
}

Fixed::Fixed( float const n ) {

    std::cout << GREEN << "Float Constructor called" << RESET << std::endl;

    _integer = roundf(static_cast<double>(n) * (1 << _fractional)); //decalage de 8 bits ( revient a faire (2^8) = 256 )

    return;
}

Fixed::Fixed( Fixed const & src ) {

    std::cout << GREEN << "Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;
}

Fixed::~Fixed( void ) {

    std::cout << RED << "Destructor called" << RESET << std::endl;

    return;
}

/*****************************************************************************/
/************       OVERLOAD OPERATORS FUNCTIONS       ***********************/
/*****************************************************************************/

/***************   Insert   **************************************************/
std::ostream & operator<<( std::ostream & o, Fixed const & rhs ) {

    o << rhs.toFloat();
    
    return o;
}

/***************   Assign   **************************************************/
Fixed & Fixed::operator=( Fixed const & rhs ) {

    std::cout << GREEN << "Copy assignment operator called" << RESET << std::endl;
    this->_integer = rhs.getRawBits();

    return *this;
}

/***************   Comparison   **********************************************/

int   Fixed::operator>( Fixed const & rhs ) const {

    if ( this->toFloat() > rhs.toFloat() )
        return 1;

    return 0;
}

int   Fixed::operator<( Fixed const & rhs ) const {

    if ( this->toFloat() < rhs.toFloat() )
        return 1;

    return 0;
}

int   Fixed::operator>=( Fixed const & rhs ) const {

    if ( this->toFloat() >= rhs.toFloat() )
        return 1;

    return 0;
}

int   Fixed::operator<=( Fixed const & rhs ) const {

    if ( this->toFloat() <= rhs.toFloat() )
        return 1;

    return 0;
}

int   Fixed::operator==( Fixed const & rhs ) const {

    if ( this->toFloat() == rhs.toFloat() )
        return 1;

    return 0;
}

int   Fixed::operator!=( Fixed const & rhs ) const {

    if ( this->toFloat() != rhs.toFloat() )
        return 1;

    return 0;
}

/***************   Arithmetic   **********************************************/
Fixed Fixed::operator+( Fixed const & rhs ) const {

    std::cout << YELLOW << "Addition operator called from " << this->toFloat();
    std::cout << " and " << rhs.toFloat() << RESET << std::endl;
    
    return Fixed( this->toFloat() + rhs.toFloat() );
}

Fixed Fixed::operator-( Fixed const & rhs ) const {

    std::cout << YELLOW << "Substraction operator called from " << this->toFloat();
    std::cout << " and " << rhs.toFloat() << RESET << std::endl;

    return Fixed( this->toFloat() - rhs.toFloat() );
}

Fixed Fixed::operator*( Fixed const & rhs ) const {

    std::cout << YELLOW << "Multiplication operator called from " << this->toFloat();
    std::cout << " and " << rhs.toFloat() << RESET << std::endl;

    return Fixed( this->toFloat() * rhs.toFloat() );
}

Fixed Fixed::operator/( Fixed const & rhs ) const {

    std::cout << YELLOW << "Division operator called from " << this->toFloat();
    std::cout << " and " << rhs.toFloat() << RESET << std::endl;

    return Fixed( this->toFloat() / rhs.toFloat() );
}

/***************   Increment/Decrement   *************************************/
Fixed & Fixed::operator++( void ) {

    _integer++;

    return *this;
}

Fixed Fixed::operator++( int ) {

    Fixed tmp = *this;
    _integer++;

    return tmp;
}

Fixed & Fixed::operator--( void ) {

    _integer--;

    return *this;
}

Fixed Fixed::operator--( int ) {

    Fixed tmp = *this;
    _integer--;

    return tmp;
}

/*****************************************************************************/
/**********************  ACCESSORS  ******************************************/
/*****************************************************************************/
int Fixed::getRawBits( void ) const {
    
    return this->_integer;
}

void Fixed::setRawBits( int const raw ) {

    this->_integer = raw;
}

/*****************************************************************************/
/**********************   MEMBERS FUNCTIONS    *******************************/
/*****************************************************************************/
float Fixed::toFloat( void ) const {

    float fPoint = static_cast<float>(_integer) / (1 << _fractional);

    return fPoint;
}

int Fixed::toInt( void ) const {

    int integer = _integer / (1 << _fractional);
    return integer;
}

/*****************************************************************************/
/******************   STATIC MEMBERS FUNCTIONS    ****************************/
/*****************************************************************************/

float Fixed::min( Fixed & a, Fixed & b ) {

    if ( a.toFloat() < b.toFloat() )
        return a.toFloat();

    return b.toFloat();
}

float Fixed::min( Fixed const & a, Fixed const & b ) {

    if ( a.operator<(b))
        return a.toFloat();

    return b.toFloat();
}

float Fixed::max( Fixed & a, Fixed & b ) {

    if ( a.operator>(b))
        return a.toFloat();
        
    return b.toFloat();
}

float Fixed::max( Fixed const & a, Fixed const & b ) {

    if ( a.operator>(b))
        return a.toFloat();
        
    return b.toFloat();
}

/***************   Init Static   *********************************************/
const int Fixed::_fractional = 8;
