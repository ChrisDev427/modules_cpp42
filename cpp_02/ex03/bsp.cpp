/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:33:10 by chris             #+#    #+#             */
/*   Updated: 2023/08/24 07:29:16 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static float classifyPoint(const Point&  P, const Point & A, const Point & B) {

    float aX = A.getX().toFloat();
    float aY = A.getY().toFloat();

    float bX = B.getX().toFloat();
    float bY = B.getY().toFloat();

    float pX = P.getX().toFloat();
    float pY = P.getY().toFloat();

    return (bX - aX) * (pY - aY) - (bY - aY) * (pX - aX);
}

bool bsp( Point const a, Point const b, Point const c, Point const point ) {


    float sideAB = classifyPoint(point, a, b);
    float sideBC = classifyPoint(point, b, c);
    float sideCA = classifyPoint(point, c, a);

    std::cout << "---------------------------------" << std::endl;
    
    std::cout << GREEN << "a" << B_CYAN << "b" << RESET << " -> " << sideAB << std::endl;
    std::cout << B_CYAN<< "b" << YELLOW << "c" << RESET << " -> " << sideBC << std::endl;
    std::cout << YELLOW << "c" << GREEN << "a" << RESET << " -> " << sideCA << std::endl;
    
    // if ( sideAB > 0 && sideBC > 0 && sideCA > 0 )
    //     return ( true );
     if ((sideAB >= 0 && sideBC >= 0 && sideCA >= 0) || (sideAB <= 0 && sideBC <= 0 && sideCA <= 0))
        return true;
    return ( false );
}
