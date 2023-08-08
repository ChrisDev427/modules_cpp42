/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:33:10 by chris             #+#    #+#             */
/*   Updated: 2023/08/08 14:01:11 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

void print( Point const a, Point const b, Point const c, Point const point , bool inOut) {

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
    
    if ( sideAB > 0 && sideBC > 0 && sideCA > 0 )
        return ( true );
    return ( false );
}
