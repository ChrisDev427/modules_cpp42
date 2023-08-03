/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 15:59:05 by chris            ###   ########.fr       */
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
    carol.guardGate();
    alain.highFivesGuys();

    


    
    

    return 0;
}