/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 10:09:51 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "color.hpp"
#include "Harl.hpp"

int main( int ac, char **av ) {
    
    if ( ac == 2 ) {

        Harl    inst;
        inst.complain( av[1] );
          
    }

    else
        std::cout << RED << "This program need one argument" << RESET << std::endl;
    
    return 0; 
}
