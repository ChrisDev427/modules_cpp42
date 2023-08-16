/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:36:15 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 10:08:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include "color.hpp"


Harl::Harl( void ) {

    levels[0] = "DEBUG";
    levels[1] = "INFO";
    levels[2] = "WARNING";
    levels[3] = "ERROR";
    
    _ptr[0] = &Harl::debug;
    _ptr[1] = &Harl::info;
    _ptr[2] = &Harl::warning;
    _ptr[3] = &Harl::error;
    
}

Harl::~Harl( void ) {

}

void Harl::debug( void ) {

    std::cout << YELLOW << "[ DEBUG ]\n" << B_CYAN << "I love having extra bacon for my double cheese\n" << RESET << std::endl;

}

void Harl::info( void ) {

    std::cout << GREEN << "[ INFO ]\n" << B_CYAN << "I cannot believe adding extra bacon costs more money !\n" << RESET << std::endl;                                                            
}

void Harl::warning( void ) {

    std::cout << MAGENTA << "[ WARNING ]\n" << B_CYAN << "I think I deserve to have some extra bacon for free.\n" << RESET << std::endl;

}

void Harl::error( void ) {

    std::cout << B_BLUE << "[ ERROR ]\n" << B_CYAN << "This is unacceptable ! I want to speak to the manager now.\n" << RESET << std::endl;

}

void    Harl::complain( std::string level ) {

    int iTmp = 4;
    for ( int i = 0; i < 4; i++ ) {
        if ( this->levels[i] == level )
            iTmp = i;
    }

    switch (iTmp)
    {
    case 0:
        ( this->*_ptr[0] )();
    case 1:
        ( this->*_ptr[1] )();
    case 2:
        ( this->*_ptr[2] )();
    case 3:
        ( this->*_ptr[3] )();
        break;
    case 4:
        std::cout << B_CYAN << "[ Probably complaining about insignificant problems ]" << RESET << std::endl;
        break;
    }

}
