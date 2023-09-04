/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:14:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 14:21:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "whatever.hpp"

int main( void ) { 

    std::cout << "********** EQUALS ***********\n" << std::endl;
    int x = 42;
    int y = 42;
    std::cout << "x: address -> " << &x << std::endl;
    std::cout << "y: address -> " << &y << std::endl;
    std::cout << "min( x, y ) = " << ::min( x, y ) << " | address -> " << &::min( x, y ) << std::endl;
    std::cout << "max( x, y ) = " << ::max( x, y ) << " | address -> " << &::max( x, y ) << std::endl;


    std::cout << "\n********** INT **************\n" << std::endl;
    int a = 2;
    int b = 3;

    ::swap( a, b );
    std::cout << "a = " << a << ", b = " << b << std::endl;
    std::cout << "min( a, b ) = " << ::min( a, b ) <<  std::endl;
    std::cout << "max( a, b ) = " << ::max( a, b ) <<  std::endl;


    std::cout << "\n********** FLOAT ************\n" << std::endl;
    float a1 = 42.56f;
    float b1 = 3.89f;

    ::swap( a1, b1 );
    std::cout << "a1 = " << a1 << ", b1 = " << b1 << std::endl;
    std::cout << "min( a1, b1 ) = " << ::min( a1, b1 ) << std::endl;
    std::cout << "max( a1, b1 ) = " << ::max( a1, b1 ) << std::endl;

    std::cout << "\n********** STRING ***********\n" << std::endl;
    std::string c = "chaine1";
    std::string d = "chaine2";

    ::swap(c, d);
    std::cout << "c = " << c << ", d = " << d << std::endl;
    std::cout << "min( c, d ) = " << ::min( c, d ) << std::endl;
    std::cout << "max( c, d ) = " << ::max( c, d ) << std::endl;
    
    return 0; 
}