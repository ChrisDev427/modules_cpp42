/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:14:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/11 11:51:32 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"
#include <string>

int main( void ) { 

    size_t size = 20;

    std::cout << "\n********* STRING TAB *************************************\n" << std::endl;
    
    std::string strs[size];
    for ( size_t i = 0; i < size; i++ ) {
        strs[i] = "Hello World";
    }
    iter( strs, size, print<std::string> );

    std::cout << "\n********* INT TAB    *************************************\n" << std::endl;

    int intTab[size];
    for ( size_t i = 0; i < size; i++ ) {
        intTab[i] = 2 * i;
    }
    iter( intTab, size, print<int> );
    
    std::cout << "\n********* FLOAT TAB  *************************************\n" << std::endl;

    float floatTab[size];
    for ( size_t i = 0; i < size; i++ ) {
        floatTab[i] = 2.89f * i;
    }
    iter( floatTab, size, print<float> );

   
    
    return 0; 
}
