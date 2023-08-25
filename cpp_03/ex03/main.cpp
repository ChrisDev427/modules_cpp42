/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/25 17:08:54 by chris            ###   ########.fr       */
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
    alain.takeDamage( 20 );
    alain.takeDamage( 20 );
    alain.takeDamage( 20 );
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

    carol.guardGate();
    alain.highFivesGuys();
    john.guardGate();
    john.highFivesGuys();
    john.whoAmI();

    chris.printValues();
    carol.printValues();
    alain.printValues();
    john.printValues();


    

    // john.attack("sd");
    // john.whoAmI();
    
    // john.highFivesGuys();
    // alain.highFivesGuys();
    // carol.guardGate();
    // // alain.highFivesGuys();
    // // chris.attack( "Bouba" );
    // // carol.attack( "Bouba" );
    // // alain.attack( "Bouba" );
    // // carol.guardGate();
    // // alain.highFivesGuys();
    // chris.printValues();
    // carol.printValues();
    // alain.printValues();
    // john.printValues();

    


    
    

    return 0;
}