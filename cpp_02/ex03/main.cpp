/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:39:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 11:47:41 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"


int main( void ) {
    

    Point a(2, 1);
    Point b(2.1, 1.2);
    Point c(-2.1, -1.2);
    
    std::cout << a << std::endl;
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    // Point a( 2, 1 );
    // Point b( 0.0f, 2.2f );
    // Point c( 1.2f, 0.0f );

    // Point point( 1.4f, 1.2f );
    // std::cout << "\n---------------------------------" << std::endl;
    // std::cout << GREEN << "a" << a << std::endl;
    // std::cout << B_CYAN << "b" << b << std::endl;
    // std::cout << YELLOW << "c" << c << std::endl;
    // std::cout << RED << "p" << point << RESET << std::endl;

    // bool ret = bsp( a, b, c, point );
    
    // std::cout << "---------------------------------" << std::endl;

    // if ( ret == true )
    //     std::cout << B_GREEN << "\np is inside" << RESET << std::endl;
    // else
    //     std::cout << RED << "\np is outside" << RESET << std::endl;


    // Point::print(a, b, c, point, ret);

    return 0; 

}