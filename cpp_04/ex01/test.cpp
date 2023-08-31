/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/05 07:45:35 by chris             #+#    #+#             */
/*   Updated: 2023/08/30 09:18:47 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void initTab(  const Animal* tab[], int size ) {

    std::cout << B_ORANGE << "\n************************************************************" << RESET << std::endl;
    std::cout << B_ORANGE << "***********************   INIT TAB   ***********************" << RESET << std::endl;
    std::cout << B_ORANGE << "************************************************************\n" << RESET << std::endl;
    
    for ( int k = 0; k < size; k++ ) {

        std::cout << B_BLUE << "tab[" << k << "]" << "----------------------------------------" << RESET << std::endl;
        if ( k < (size / 2) )
            tab[k] = new Cat();
        else
            tab[k] = new Dog();

    }
    std::cout << std::endl;

    std::cout << B_ORANGE << "************************************************************\n\n" << RESET << std::endl;
}

void initStrings( const Animal* tab[], int size ) {

    std::cout << B_ORANGE << "\n************************************************************" << RESET << std::endl;
    std::cout << B_ORANGE << "*********************   INIT STRINGS   *********************" << RESET << std::endl;
    std::cout << B_ORANGE << "************************************************************\n" << RESET << std::endl;

    std::cout << B_BLUE << "Initialising each objet of tab"<< RESET << std::endl;

    std::string str = "Hello 42";

    for ( int i = 0; i < size; i++ ) {

        std::cout << B_BLUE << "[" << i << "] " << RESET;
        tab[i]->setPtr( str );
    }

}

void freeClassArray( const Animal* tab[], int size ) {

    for ( int k = 0; k < size; k++ ) {

        std::cout << B_BLUE << "tab[" << k << "]" << "----------------------------------------" << RESET << std::endl;

        delete tab[k];
    }
    std::cout << B_BLUE << "-----------------------------------------------" << RESET << std::endl;
}
