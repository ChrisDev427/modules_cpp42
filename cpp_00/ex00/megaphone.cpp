/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:15 by chris             #+#    #+#             */
/*   Updated: 2023/08/15 17:39:56 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

Mega::Mega( void ) {

   
    return;
}

Mega::~Mega(void) {
    
    return;
}

void    Mega::megaphone( int ac, std::string args[] ) {

    for ( int i = 0; i < ac; i++ ) {
        
        toUpper( args[i] );
        std::cout << args[i];
    }
    std::cout << std::endl;
}


void    Mega::toUpper(std::string & str) {
    
    for ( std::string::iterator it = str.begin(); it != str.end(); ++it ) {

        for ( std::size_t i = 0; i < str.length(); ++i ) {

            str[i] = std::toupper(str[i]);
        }
    }
}