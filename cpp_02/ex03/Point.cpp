/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:35:21 by chris             #+#    #+#             */
/*   Updated: 2023/08/24 06:23:23 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 ) {

    // std::cout << "Point: Default Constructor called" << std::endl;

    return;
}

Point::Point( float const x, float const y ) : _x( x ), _y( y ) {

    // std::cout << "Point: Parametric Constructor called" << std::endl;

    return;
}

Point::Point( Point const & src ) {

    // std::cout << "Point: Copy Constructor called" << std::endl;
    *this = src;

    return;
}

Point::~Point( void ) {

    // std::cout << "Point: Destructor called" << std::endl;

    return;
}

Point & Point::operator=( Point const & rhs ) {

    // std::cout << "Point: Assignment operator called" << std::endl;
    const_cast<Fixed&>(_x) = rhs._x;
    const_cast<Fixed&>(_y) = rhs._y;

    return *this;
}

Fixed Point::getX( void ) const {

    return this->_x;
}

Fixed Point::getY( void ) const {

    return this->_y;
}



std::ostream & operator<<( std::ostream & o, Point const & rhs ) {

    o << "( x = " << rhs.getX() << ", y = " << rhs.getY() << " )";

    return o;
}