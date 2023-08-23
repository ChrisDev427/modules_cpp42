/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:39:47 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 11:43:23 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

void comparisons( void ) {

    std::cout << B_CYAN << "*****************************************" << RESET << std::endl;
    std::cout << B_CYAN << "**********  Comparisons Tests  **********" << RESET << std::endl;
    std::cout << B_CYAN << "*****************************************\n" << RESET << std::endl;


    Fixed a( 5 );
    Fixed b( 3 );
    
    if (a < b )
        std::cout << B_CYAN << "INFERIOR" << RESET << std::endl;
    if (a > b )
        std::cout << B_CYAN << "SUPERIOR" << RESET << std::endl;
    if (a <= b) 
        std::cout << B_CYAN << "INFERIOR OR EQUAL" << RESET << std::endl;
    if (a >= b) 
        std::cout << B_CYAN << "SUPERIOR OR EQUAL" << RESET << std::endl;
    if (a == b) 
        std::cout << B_CYAN << "EQUALS" << RESET << std::endl;
    if (a != b) 
        std::cout << B_CYAN << "DIFFERENTS" << RESET << std::endl;

}

void arithmetics( void ) {

    std::cout << B_CYAN << "*****************************************" << RESET << std::endl;
    std::cout << B_CYAN << "**********  Arithmetics Tests  **********" << RESET << std::endl;
    std::cout << B_CYAN << "*****************************************\n" << RESET << std::endl;
    Fixed a( 2 );
    Fixed b( 0.8f );

    Fixed c = a + b;
    std::cout << c << std::endl;

    Fixed d= a - b;
    std::cout << d << std::endl;

    Fixed e = a * b;
    std::cout << e << std::endl;

    Fixed f = a / b;
    std::cout << f << std::endl;
    
}

void subjectTests( void ) {

    std::cout << B_CYAN << "*****************************************" << RESET << std::endl;
    std::cout << B_CYAN << "************  Subject Tests  ************" << RESET << std::endl;
    std::cout << B_CYAN << "*****************************************\n" << RESET << std::endl;

    Fixed intMax( INT_MAX );
    std::cout << "intMax -> " << intMax.toInt() << std::endl;

    Fixed a;
    Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );

    std::cout << a << std::endl;
    std::cout << ++a << std::endl;
    std::cout << a << std::endl;
    std::cout << a++ << std::endl;
    std::cout << a << std::endl;
    
    std::cout << b << std::endl;
    
    std::cout << BLUE << "Max Value is -> " << Fixed::max( a, b ) << RESET << std::endl;
    std::cout << BLUE << "Min Value is -> " << Fixed::min( a, b ) << RESET << std::endl;

}

int main( void ) {
    
    subjectTests();
    std::cout << B_CYAN << "_________________________________________\n\n" << RESET << std::endl;

    // arithmetics();
    // std::cout << B_CYAN << "_________________________________________\n\n" << RESET << std::endl;
    
    // comparisons();
    // std::cout << B_CYAN << "_________________________________________\n\n" << RESET << std::endl;
   
    return 0; 
}