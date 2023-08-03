/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:35:21 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 10:51:56 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include "Point.hpp"
#include "Fixed.hpp"

Point::Point( void ) : _x( 0 ), _y( 0 ) {

    // std::cout << "Default Constructor called" << std::endl;

    return;
}

Point::Point( float const x, float const y ) : _x( x ), _y( y ) {

    // std::cout << "Parametric Constructor called" << std::endl;

    return;
}

Point::Point( Point const & src ) {

    // std::cout << "Copy Constructor called" << std::endl;
    *this = src;

    return;
}

Point::~Point( void ) {

    // std::cout << "Destructor called" << std::endl;

    return;
}

Point & Point::operator=( Point const & rhs ) {

    // std::cout << "Assignment operator called" << std::endl;
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

void Point::print( Point const a, Point const b, Point const c, Point const point , bool inOut) {

    t_coord pointsCoord[4];
    Point   points[4];

    points[0] = a;
    points[1] = b;
    points[2] = c;
    points[3] = point;

    int xMax = 0;
    int yMax = 0;
    int xMin = INT_MAX;
    int yMin = INT_MAX;

    for ( int i = 0; i < 4; i++) {

        pointsCoord[i].x = points[i].getX().getRawBits() /15;
        pointsCoord[i].y = points[i].getY().getRawBits() /15;
       
        if ( pointsCoord[i].x > xMax )
            xMax = pointsCoord[i].x;
        if ( pointsCoord[i].y > yMax )
            yMax = pointsCoord[i].y;

        if ( pointsCoord[i].x < xMin )
            xMin = pointsCoord[i].x;
        if ( pointsCoord[i].y < yMin )
            yMin = pointsCoord[i].y;
    }
    if ( xMax > 160 || yMax > 65 )
        return;
    for ( int y = (yMax +3); y >= yMin; y-- ) {

        for ( int x = 0; x <= xMax; x++ ) {
           
            if ( x == pointsCoord[0].x &&  y == pointsCoord[0].y )
                std::cout << GREEN << "*a" << RESET;
            else if ( x == pointsCoord[1].x &&  y == pointsCoord[1].y )
                std::cout << B_CYAN << "*b" << RESET;
            else if ( x == pointsCoord[2].x &&  y == pointsCoord[2].y )
                std::cout << B_YELLOW << "*c" << RESET;
            else if ( x == pointsCoord[3].x &&  y == pointsCoord[3].y )
                if ( inOut == 0 )
                    std::cout << RED << "*p" << RESET;
                else
                    std::cout << B_GREEN << "*p" << RESET;
            else
                std::cout << " ";

        }
        std::cout << std::endl;
    }
    std::cout << std::endl << std::endl << std::endl;

}




std::ostream & operator<<( std::ostream & o, Point const & rhs ) {

    o << "( x = " << rhs.getX() << ", y = " << rhs.getY() << " )";
    return o;

}

