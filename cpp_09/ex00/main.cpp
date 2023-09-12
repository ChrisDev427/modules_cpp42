/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/12 17:26:19 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
std::tm convDate( std::string str ) {
    
    std::tm when = {};
    std::istringstream iss(str);
    std::locale loc; 
    iss >> std::get_time(&when, "%y/%m/%d");
    // if ( iss.fail() ) { 
    //     puts("FAIL");
    //     when.tm_year = 1234;
    //     when.tm_mon = 1234;
    //     when.tm_mday = 1234;
    //     return when;
    // }
    
    std::time_t timestamp = std::mktime(&when);
    if (timestamp == -1) { throw std::invalid_argument("Error: bad input"); } 
       
    return when;
}
int main( int ac, char* av[] )
{

    t_data data;
    



    if ( ac == 2 ) {

        std::ifstream file( av[1] );
        if (!file.is_open()) {
            std::cerr << "Error: could not open file" << av[1] << std::endl;
            return -1;
        }
        fillMap( &data );
        getCompareInput( &data, file );
    
    }
    else {

        std::cerr << "Error: could not open file" << std::endl;
        return -1;
    }


    
    

    // system("leaks prog");
    return 0;
}