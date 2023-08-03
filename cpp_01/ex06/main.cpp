/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 11:28:44 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "Harl.hpp"

int main( int ac, char **av ) {
    
    if ( ac == 2 ) {

        Harl    inst;
        inst.complain( av[1] );
          
    }

    else
        error( "This program need one argument", NULL );
    
    return 0; 
}
