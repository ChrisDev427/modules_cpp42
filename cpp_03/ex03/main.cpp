/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 17:22:31 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"




int main( void ) {

    // ClapTrap chris( "Chris" );
    // ScavTrap carol( "Carol" );
    // FragTrap alain( "Alain" );
    // DiamondTrap john( "John" );

    ClapTrap a;
    ScavTrap b;
    FragTrap c;
    DiamondTrap d;

    a.printValues();
    b.printValues();
    c.printValues();
    d.printValues();

    a.attack("tom");
    b.attack("tom");
    c.attack("tom");
    d.attack("tom");

    a.takeDamage(50);

    c.beRepaired(20);

    c.highFivesGuys();

    b.guardGate();
    a.printValues();
    b.printValues();
    c.printValues();
    d.printValues();


    // chris.printValues();
    // carol.printValues();
    // alain.printValues();
    // john.printValues();
    
    
    // chris.attack( "tom" );
    // carol.attack( "tom" );
    // alain.attack( "tom" );
    // alain.takeDamage(carol.getValue("attackDamage"));
    // alain.takeDamage(carol.getValue("attackDamage"));
    // alain.beRepaired( 25 );
    // alain.takeDamage(carol.getValue("attackDamage"));
    // alain.takeDamage(carol.getValue("attackDamage"));
    // alain.takeDamage(carol.getValue("attackDamage"));
    // alain.attack( "tom" );

   
    // john.attack( "tom" );
    // john.attack( "tom" );
    // john.attack( "tom" );
    // john.attack( "tom" );
    // john.attack( "tom" );
    // john.attack( "tom" );
    // john.takeDamage(carol.getValue("attackDamage"));
    // carol.beRepaired( 25 );
    // chris.beRepaired( 25 );
    // john.beRepaired( 25 );

    

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