/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:14:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 12:32:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main ( int ac, char** av ) {

    if ( ac == 2 ) {

        std::string param = av[1];
        ScalarConverter::convert( param );

    }
    else { std::cout << "Error: convert need one argument !" << std::endl; }

    return 0;
}