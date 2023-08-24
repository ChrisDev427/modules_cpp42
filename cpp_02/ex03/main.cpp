/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:39:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/24 07:45:09 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {
    
    Point a(-1, 1.5);
    Point b(0.5, 1.5);
    Point c(-0.5, 0.5);

    Point point( -1, 1 );
    
    std::cout << GREEN << "a" << a << std::endl;
    std::cout << B_CYAN << "b" << b << std::endl;
    std::cout << YELLOW << "c" << c << std::endl;
    std::cout << RED << "point" << point << RESET << std::endl;

    bool ret = bsp( a, b, c, point );
    
    std::cout << "---------------------------------" << std::endl;

    if ( ret == true )
        std::cout << B_GREEN << "[TRUE] point is inside triangle A, B, C" << RESET << std::endl;
    else
        std::cout << RED << "[FALSE] point is outside triangle A, B, C" << RESET << std::endl;

    return 0; 
}