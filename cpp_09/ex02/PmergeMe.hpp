/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/20 12:00:48 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <cstring>
# include <sys/time.h>
# include <algorithm>
# include <stdexcept>
# include <vector>
# include <list>
# include <climits>

void parse( char** av );
bool checkAllIsDigit( char* str );
bool comp (int i,int j);
void sortingVec ( std::vector<unsigned int> *vec, char ** av, int size );
void sortingLst ( std::list<unsigned int> *lst, char ** av, int size );
void printLst( std::list<unsigned int>  lst, std::string when );

template< typename T >
void print( T & container, int size, std::string when ) {
    std::cout << when;
    for ( int i = 0; i < size; i++ ) {
        std::cout << container[i] << " ";
    }
    std::cout << std::endl;
}

#endif /************************************************************* PMERGEME_HPP*/