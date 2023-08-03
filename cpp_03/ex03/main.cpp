/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 16:16:26 by chris            ###   ########.fr       */
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
    
    // std::cout << "ClapTrap chris -> " << " " << chris.getValue("hit") << " " << chris.getValue("energy") << " " << chris.getValue("attackDamage") << std::endl;
    // std::cout << "ScavTrap carol -> " << " " << carol.getValue("hit") << " " << carol.getValue("energy") << " " << carol.getValue("attackDamage") << std::endl;
    // std::cout << "FragTrap alain -> " << " " << alain.getValue("hit") << " " << alain.getValue("energy") << " " << alain.getValue("attackDamage") << std::endl;
    // std::cout << "johnondTrap john -> " << " " << john.getValue("hit") << " " << john.getValue("energy") << " " << john.getValue("attackDamage") << std::endl;

    
    chris.attack( "toi" );
    carol.attack( "toi" );
    alain.attack( "toi" );
    alain.takeDamage(carol.getValue("attackDamage"));
    alain.takeDamage(carol.getValue("attackDamage"));
    alain.takeDamage(carol.getValue("attackDamage"));
    alain.takeDamage(carol.getValue("attackDamage"));
    alain.takeDamage(carol.getValue("attackDamage"));
    alain.attack( "toi" );

   
    john.attack( "toi" );
    john.attack( "toi" );
    john.attack( "toi" );
    john.attack( "toi" );
    john.attack( "toi" );
    john.attack( "toi" );
    john.takeDamage(carol.getValue("attackDamage"));

    // std::cout << "ClapTrap chris -> " << " " << chris.getValue("hit") << " " << chris.getValue("energy") << " " << chris.getValue("attackDamage") << std::endl;
    // std::cout << "ScavTrap carol -> " << " " << carol.getValue("hit") << " " << carol.getValue("energy") << " " << carol.getValue("attackDamage") << std::endl;
    // std::cout << "FragTrap alain -> " << " " << alain.getValue("hit") << " " << alain.getValue("energy") << " " << alain.getValue("attackDamage") << std::endl;
    // std::cout << "johnondTrap john -> " << " " << john.getValue("hit") << " " << john.getValue("energy") << " " << john.getValue("attackDamage") << std::endl;


    // chris.attack("toi");
    // carol.attack("toi");

    john.attack("sd");
    john.whoAmI();
    
    john.highFivesGuys();
    alain.highFivesGuys();
    carol.guardGate();
    // alain.highFivesGuys();
    // chris.attack( "Bouba" );
    // carol.attack( "Bouba" );
    // alain.attack( "Bouba" );
    // carol.guardGate();
    // alain.highFivesGuys();
    chris.printValues();
    carol.printValues();
    alain.printValues();
    john.printValues();

    


    
    

    return 0;
}