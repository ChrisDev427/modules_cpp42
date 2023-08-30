/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 11:57:29 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {

    ClapTrap chris( "Chris" );
   
    chris.attack( "Kian" );
    chris.attack( "Emilien" );
    chris.attack( "Emilien" );
    chris.attack( "Emilien" );
    chris.attack( "Emilien" );
    chris.attack( "Palmi" );
    chris.attack( "Tac" );

    chris.takeDamage( 8 );
    chris.printValues();

    std::cout << B_BLUE << "\n******* Copy ********************************************************************************\n" << RESET << std::endl;

    ClapTrap cpy(chris);
    cpy.printValues();
    
    std::cout << B_BLUE << "\n*********************************************************************************************\n" << RESET << std::endl;

    

    chris.beRepaired( 5 );

    chris.attack( "Tac" );
    chris.attack( "Axel" );
    chris.attack( "Axel" );
    
    chris.beRepaired( 5 );
    chris.takeDamage( 8 );
    chris.takeDamage( 8 );

    std::cout << B_BLUE << "\n******* Assign ******************************************************************************\n" << RESET << std::endl;

    cpy = chris;
    cpy.printValues();
    std::cout << B_BLUE << "\n*********************************************************************************************\n" << RESET << std::endl;



    return 0;
}