/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/14 10:59:03 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main( int ac, char** av )
{

    if ( ac == 2 ) {
        
        try { RPN calculate( av[1] ); }
        catch( std::exception& e ) { std::cerr << e.what() << std::endl; }
      
    }
    
    else {
        std::cerr << "Error" << std::endl;
        return -1;
    }
    // system("leaks RPN");
    return 0;
}