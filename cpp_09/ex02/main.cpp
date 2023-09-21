/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/21 08:13:01 by chris            ###   ########.fr       */
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
        double vectorProceedTime, listProceedTime;
        std::list<unsigned int>     myList[3];
        std::vector<unsigned int>   myVector[3];

        start = clock();
        sortingLst( myList, av, ac );
        end = clock();
        listProceedTime = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
        
        start = clock();
        sortingVec( myVector, av, ac );
        end = clock();
        vectorProceedTime = 1000000.0 * (end - start) / CLOCKS_PER_SEC;
        
        print( av, ac, "Before: " );
        print( myVector[2], ac, "After:  " );
        // printLst( myList[2], "After:  " );
        std::cout << "Time to process a range of " << ac << " elements with std::vector : " << vectorProceedTime << " us" << std::endl;
        std::cout << "Time to process a range of " << ac << " elements with std::list : " << listProceedTime << " us" << std::endl;

    }
    else {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    return 0;
}