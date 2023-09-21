/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/21 08:02:24 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

int main( int ac, char* av[] )
{
    if ( ac == 2 ) {

        try { 
            checkArgFile( av[1] );
            std::ifstream file ( av[1] );
            if (!file.is_open()) {
                std::cerr << RED "Error: could not open file." RESET << std::endl;
                return -1;
            }
            std::map<std::string, double> data;
            fillMap( data );
            getCompareInput( data, file );
            file.close();
        }
        catch ( std::exception& e ) {
            std::cerr << e.what() << RESET << std::endl;
            return -1;
        }
    }
    else {

        std::cerr << RED "Error: could not open file." RESET << std::endl;
        return -1;
    }
    return 0;
}