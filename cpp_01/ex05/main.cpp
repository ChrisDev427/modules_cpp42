/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 09:43:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Harl.hpp"
#include <ctime>
#include <thread>


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
            std::this_thread::sleep_for(std::chrono::microseconds(500000));
        }
    }
    else
        std::cout << RED << "This program need one argument\nHow many times do you want Harl to complain ?" << RESET << std::endl;
    return 0; 
}
