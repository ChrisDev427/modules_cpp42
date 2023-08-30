/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 14:54:02 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"

int main( void ) {

    ClapTrap chris( "Chris" );
    ScavTrap carol( "Carol" );
    FragTrap alain( "Alain" );
    DiamondTrap john( "John" );

    chris.printValues();
    carol.printValues();
    alain.printValues();
    john.printValues();

    chris.attack( "tom" );
    carol.attack( "tom" );
    alain.attack( "tom" );
    alain.takeDamage( 20 );
    alain.takeDamage( 20 );
    alain.beRepaired( 25 );
    alain.takeDamage( 40 );
    alain.takeDamage( 40 );
    alain.takeDamage( 40 );
    alain.attack( "tom" );

   
    john.attack( "tom" );
    john.attack( "tom" );
    john.attack( "tom" );
    john.attack( "tom" );
    john.attack( "tom" );
    john.attack( "tom" );
    john.takeDamage( 20 );
    carol.beRepaired( 25 );
    chris.beRepaired( 25 );
    john.beRepaired( 25 );

    chris.printValues();
    carol.printValues();
    alain.printValues();
    john.printValues();
    
    std::cout << BLUE << "\n********************************************************************" << RESET << std::endl;
    std::cout << BLUE << "********************** Special Function ****************************" << RESET << std::endl;
    std::cout << BLUE << "********************************************************************\n" << RESET << std::endl;

    carol.guardGate();
    alain.highFivesGuys();
    john.guardGate();
    john.highFivesGuys();
    john.whoAmI();

    std::cout << BLUE << "\n********************************************************************" << RESET << std::endl;
    std::cout << BLUE << "************************** Copy ************************************" << RESET << std::endl;
    std::cout << BLUE << "********************************************************************\n" << RESET << std::endl;

   
    ScavTrap    carolCpy(carol);
    DiamondTrap johnCpy(john);

    carolCpy.printValues();
    johnCpy.printValues();

    std::cout << BLUE << "\n********************************************************************" << RESET << std::endl;
    std::cout << BLUE << "************************** Assign **********************************" << RESET << std::endl;
    std::cout << BLUE << "********************************************************************\n" << RESET << std::endl;
    
    FragTrap mike( "Mike" );
    DiamondTrap  kian( "Kian" );

    mike.printValues();
    kian.printValues();

    mike = alain;
    kian = john;

    mike.printValues();
    kian.printValues();
    
    std::cout << BLUE << "\n********************************************************************\n" << RESET << std::endl;

    chris.printValues();
    carol.printValues();
    alain.printValues();
    john.printValues();


    return 0;
}