/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 14:59:55 by chris            ###   ########.fr       */
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

    ScavTrap maurice( "Maurice" );
    maurice = carol;

    std::cout << maurice.getValue( "enerfgy" ) << std::endl;


    
    

    return 0;
}