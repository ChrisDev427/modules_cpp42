/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/21 08:13:47 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkAllIsDigit( char* str ) {
    
    for ( int i = 0; str[i]; i++ ) {
        if ( !isdigit(str[i]) ) {
            return false;
        }
    }
    return true;
}

void parse( char** av ) {
    
    for ( int i = 0; av[i]; i++ ) {
        if ( av[i][0] == '+' ) {
            av[i] = av[i] + 1;
        }
    }
    for ( int i = 0; av[i]; i++ ) {

        if ( static_cast<unsigned long long>(atoi(av[i])) > INT_MAX \
            || strlen(av[i]) > 10 \
            || !checkAllIsDigit( av[i] )) {
            throw std::invalid_argument("Error");
        }
    }
}

bool comp (int i,int j) {
    
    return (i<j);
}

void sortingVec ( std::vector<unsigned int> *vec, char ** av, int size ) {

    for ( int i = 0; av[i]; i++ ) {
        if ( i <= (size / 2) )
            vec[0].push_back(std::atoi(av[i]));
        else
            vec[1].push_back(std::atoi(av[i]));
    }
    
    std::sort( vec[0].begin(), vec[0].end(), comp );
    std::sort( vec[1].begin(), vec[1].end(), comp );
    vec[2].resize( size );
    std::merge( vec[0].begin(), vec[0].end(), vec[1].begin(), vec[1].end(), vec[2].begin() );
}

void sortingLst ( std::list<unsigned int> *lst, char ** av, int size ) {

    for ( int i = 0; av[i]; i++ ) {
        if ( i <= (size / 2) )
            lst[0].push_back(std::atoi(av[i]));
        else
            lst[1].push_back(std::atoi(av[i]));
    }
    lst[0].sort( comp );
    lst[1].sort( comp );
    lst[2].resize( size );
    std::merge( lst[0].begin(), lst[0].end(), lst[1].begin(), lst[1].end(), lst[2].begin() );
}

void printLst( std::list<unsigned int>  lst, std::string when ) {
    std::cout << when;
    std::list<unsigned int>::iterator it = lst.begin();
    std::list<unsigned int>::iterator ite = lst.end();
    for (; it != ite; it++ ) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}