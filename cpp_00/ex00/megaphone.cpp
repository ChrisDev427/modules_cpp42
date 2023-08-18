/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:15 by chris             #+#    #+#             */
/*   Updated: 2023/08/17 20:29:05 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

void    toUpper(std::string & str) {
    
    for ( std::string::iterator it = str.begin(); it != str.end(); ++it ) {

        for ( std::size_t i = 0; i < str.length(); ++i ) {

            str[i] = std::toupper(str[i]);
        }
    }
}

void    megaphone( int ac, std::string args[] ) {

    for ( int i = 0; i < ac; i++ ) {
        
        toUpper( args[i] );
        std::cout << args[i];
    }
    std::cout << std::endl;
}



int main(int ac, char **av)
{
    if ( ac == 1 )
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {   
        av = &av[1];
        ac -= 1;
        
        std::string args[ac];
        for ( int i = 0; av[i]; i++ ) {

            args[i] = av[i];
        }
        
        megaphone( ac, args );
    }
    return 0;
}