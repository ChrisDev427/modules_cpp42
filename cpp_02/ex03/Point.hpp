/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:35:25 by chris             #+#    #+#             */
/*   Updated: 2023/08/24 07:43:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

class Point {

public:

    Point( void );
    Point( float const x, float const y );
    Point( Point const & src );
    ~Point( void ); virtual

    Point & operator=( Point const & rhs );

    Fixed getX( void ) const;
    Fixed getY( void ) const;

private:

    Fixed const _x;
    Fixed const _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream & operator<<( std::ostream & o, Point const & i );

#endif /******************************************************* POINT_HPP */