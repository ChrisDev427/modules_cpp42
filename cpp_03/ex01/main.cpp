/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/28 14:31:23 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main( void ) {

    ClapTrap chris( "Chris" );
    ScavTrap carol( "Carol" );

    chris.attack( "Bouba" );
    carol.attack( "Bouba" );
    carol.guardGate();

    carol.takeDamage( 30 );

    ScavTrap maurice( "Maurice" );
    maurice.printValues();
    maurice = carol;
    maurice.printValues();

    return 0;
}