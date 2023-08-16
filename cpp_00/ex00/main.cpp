/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/15 17:42:49 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

int main(int ac, char **av)
{
    if ( ac == 1 )
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {   
        av = &av[1];
        ac -= 1;
        
        std::string args[ac];
        for ( int i = 0; av[i]; i++ )
            args[i] = av[i];
        
        Mega    instance;

        instance.megaphone( ac, args );
    }
    return 0;
}