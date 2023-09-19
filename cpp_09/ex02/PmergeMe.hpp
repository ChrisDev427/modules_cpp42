/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/18 10:47:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <iomanip>
# include <sstream>
# include <cctype>
# include <sys/time.h>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <deque>
# include <limits>

void parse( char** av );
bool checkAllIsDigit( char* str );
bool comp (int i,int j);

template< typename T >
void print( T & container, int size, std::string what ) {
    std::cout << what;
    for ( int i = 0; i < size; i++ ) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

template< typename T >
void sorting ( T *array, char ** av, int size ) {

    for ( int i = 0; av[i]; i++ ) {
        if ( i <= (size / 2) )
            array[0].push_back(std::atoi(av[i]));
        else
            array[1].push_back(std::atoi(av[i]));
    }
    
    std::sort( array[0].begin(), array[0].end(), comp );
    std::sort( array[1].begin(), array[1].end(), comp );
    array[2].resize( size );
    std::merge( array[0].begin(), array[0].end(), array[1].begin(), array[1].end(), array[2].begin() );
}

#endif /************************************************************* PMERGEME_HPP*/