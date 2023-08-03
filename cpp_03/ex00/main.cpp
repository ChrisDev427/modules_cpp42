/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 17:22:05 by chris             #+#    #+#             */
/*   Updated: 2023/08/02 10:42:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main( void ) {

    ClapTrap chris( "Chris" );
    ClapTrap carol( "Carol" );
    ClapTrap joseph;
    // chris.attack( "Kian" );
    // chris.attack( "Emilien" );
    // chris.attack( "Emilien" );
   
    // chris.attack( "Emilien" );
    // chris.attack( "Emilien" );
    // chris.attack( "Emilien" );
    // chris.attack( "Palmi" );
    // chris.attack( "Tac" );

    

    // carol.attack( "chris");
    // joseph.attack( "Chris" );
    while ( 1 ) {

        chris.attack( "Kian" );
        chris.attack( "Emilien" );
        chris.attack( "Palmi" );
        chris.attack( "Tac" );

        chris.takeDamage( 1 );
        chris.beRepaired( 1 );
       
        chris.attack( "Rachid Abarki" );


        if ( chris.getValue( "_hit" ) == 0 || chris.getValue( "_energy" ) == 0 )
            break;

    }
    
    

    return 0;
}