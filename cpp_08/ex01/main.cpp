/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 09:47:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

void test1( void ) {

    Span sp(100);
    try {
        sp.addNumber(10);
        sp.addNumber(20);
        sp.addNumber(-30);
        sp.addNumber(40);
        sp.addNumber(50);
        sp.addNumber(50);
    }
    catch ( std::exception& e) { std::cerr << B_RED << e.what() << RESET << std::endl; }
    
    sp.print( "sp" );
    std::cout << B_CYAN "shortestSpan -> " << sp.shortestSpan() << RESET << std::endl;
    std::cout << B_CYAN "longestSpan  -> " << sp.longestSpan() << RESET << std::endl;

    std::cout << std::endl;
    
    std::vector<int> vec;
    for ( int i = 0; i < 80; i++ ) {
        vec.push_back( rand() % 5000 - 2500 );
    }

    try { sp.addSequence( vec.begin(), vec.end() ); }
    catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

    sp.print( "sp" );
    std::cout << B_CYAN "shortestSpan -> " << sp.shortestSpan() << RESET << std::endl;
    std::cout << B_CYAN "longestSpan  -> " << sp.longestSpan() << RESET << std::endl;


    std::cout << std::endl;
    
    Span cpy(sp);
    cpy.print( "cpy" );

    sp.arrayClear();
    sp.print( "sp" );
    try {
        sp.addNumber(42);
        sp.addNumber(84);
        sp.addNumber(-42);
    }
    catch ( std::exception& e) { std::cerr << B_RED << e.what() << RESET << std::endl; }

    sp.print( "sp" );

    cpy = sp;
    cpy.print( "cpy" );

}

void test2 ( void ) {

    Span sp( 20010 );

    std::deque<int> dec;
    for ( int i = 0; i < 20000; i++ ) {
        dec.push_back( rand() % 5000 - 2500 );
    }

    try { sp.addSequence( dec.begin(), dec.end() ); }
    catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }

    try {
        sp.addNumber(42);
        sp.addNumber(84);
        sp.addNumber(INT_MAX);
        sp.addNumber(INT_MIN);
    }
    catch ( std::exception& e) { std::cerr << B_RED << e.what() << RESET << std::endl; }
    sp.print( "sp" );
    std::cout << B_CYAN "size = " << sp.arraySize() << RESET << std::endl;
    std::cout << B_CYAN "shortestSpan -> " << sp.shortestSpan() << RESET << std::endl;
    std::cout << B_CYAN "longestSpan  -> " << sp.longestSpan() << RESET << std::endl;

}

int main( int ac, char** av ) {

    (void)av;
    if ( ac == 1 ) {

        std::srand(time(0));

        test1();
        // test2();
    }
    else {
        std::cerr << RED "Error: no args needed" << RESET << std::endl;
        return -1;
    }

    // system("leaks prog");
    return 0;
}