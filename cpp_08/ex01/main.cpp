/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/08 18:34:22 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <algorithm>
#include <vector>
#include "policeColor.hpp"
#include "Span.hpp"

int main( void )
{
    std::srand(time(NULL));

    Span sp(100);
    sp.addNumber(10);
    sp.addNumber(20);
    sp.addNumber(-30);
    sp.addNumber(40);
    sp.addNumber(50);
    sp.addNumber(50);
    
    
    sp.print( "sp" );
    std::cout << B_CYAN "shortestSpan -> " << sp.shortestSpan() << RESET << std::endl;
    std::cout << B_CYAN "longestSpan  -> " << sp.longestSpan() << RESET << std::endl;


    
    sp.addSequence(16);
    std::cout << B_CYAN "shortestSpan -> " << sp.shortestSpan() << RESET << std::endl;
    std::cout << B_CYAN "longestSpan  -> " << sp.longestSpan() << RESET << std::endl;

    sp.print( "sp" );

    Span cpy(sp);
    cpy.print( "cpy" );

    sp.clearArray();
    sp.print( "sp" );

    sp.addNumber(42);
    sp.addNumber(84);
    sp.addNumber(-42);
    sp.addSequence(10);
    sp.print( "sp" );

    cpy = sp;
    cpy.print( "cpy" );

    



    
    // system("leaks prog");
    return 0;
}