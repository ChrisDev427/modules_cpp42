/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 07:35:25 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 16:07:33 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include <iostream>
# include "Fixed.hpp"

struct t_coord {

    int x;
    int y;

};

class Point {

public:

    Point( void );
    Point( float const x, float const y );
    Point( Point const & src );
    ~Point( void ); virtual

    Point & operator=( Point const & rhs );

    Fixed getX( void ) const;
    Fixed getY( void ) const;

    // void    setX( Point const & src );
    static void print( Point const a, Point const b, Point const c, Point const point , bool inOut);

    

private:

    Fixed const _x;
    Fixed const _y;

};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream & operator<<( std::ostream & o, Point const & i );

#endif /******************************************************* POINT_HPP */