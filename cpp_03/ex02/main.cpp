/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 14:46:36 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {

    ClapTrap chris( "Chris" );
    ScavTrap carol( "Carol" );
    FragTrap alain( "Alain" );

    chris.attack( "Bouba" );
    carol.attack( "Bouba" );
    alain.attack( "Bouba" );

    chris.takeDamage( 20 );
    carol.takeDamage( 15 );
    alain.takeDamage( 30 );
    carol.guardGate();
    alain.highFivesGuys();
    
    return 0;
}