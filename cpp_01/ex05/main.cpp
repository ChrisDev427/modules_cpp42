/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/07/26 08:46:02 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Harl.hpp"


int main( int ac, char **av ) {
    
    if ( ac == 2 ) {

        system( "clear" );
        int nbComplains = atoi( av[1] );
        Harl    inst;
        std::srand( static_cast<unsigned int>( std::time(0) ) );

        for ( int i = 0; i < nbComplains; i++) {
        
            int randomIndex = std::rand() % 4;
            inst.complain( inst.levels[randomIndex] );
            std::cout << std::endl;
            usleep(300000);

        }

    }
    else
        error( "This program need one argument\nHow many times do you want Harl to complain?", NULL );
    
    return 0; 
}
