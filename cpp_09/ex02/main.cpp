/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 19:04:25 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

int main( int ac, char** av )
{

    av = &av[1];
    ac--;
    if ( ac >= 2 ) {

        try { parse( av ); }
        catch( std::exception& e ) { std::cerr << e.what() << std::endl; return -1; }

        clock_t start, end;
        double vectorProceedTime, dequeProceedTime;
        std::vector<unsigned int>   myVector[3];
        std::deque<unsigned int>    myDeque[3];

        start = clock();
        sorting( myDeque, av, ac );
        end = clock();
        dequeProceedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
        
        start = clock();
        sorting( myVector, av, ac );
        end = clock();
        vectorProceedTime = static_cast<double>(end - start) / CLOCKS_PER_SEC * 1000000;
        
        print( av, ac, "Before: " );
        print(myVector[2], ac, "After:  " );
        std::cout << "Time to process a range of " << ac << " elements with std::vector : " << vectorProceedTime << " us" << std::endl;
        std::cout << "Time to process a range of " << ac << " elements with std::deque : " << dequeProceedTime << " us" << std::endl;

    }
    else {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    return 0;
}