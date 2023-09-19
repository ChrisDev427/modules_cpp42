/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 10:27:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 19:12:44 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PmergeMe.hpp"

bool checkAllIsDigit( char* str ) {
    
    for ( int i = 0; str[i]; i++ ) {
        if ( !isdigit(str[i]) ) { return false; }
    }
    return true;
}

void parse( char** av ) {
    
    for ( int i = 0; av[i]; i++ ) {

        if ( static_cast<unsigned long long>(atoi(av[i])) > INT_MAX \
            || strlen(av[i]) > 10 \
            || !checkAllIsDigit( av[i] )) {
            throw std::invalid_argument("Error");
        }
    }
}

bool comp (int i,int j) { return (i<j); }
