/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:11 by chris             #+#    #+#             */
/*   Updated: 2023/07/19 10:58:09 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "megaphone.hpp"

static int strExist(char **tab)
{
    int strExist = 0;
    
    for (int i = 1; tab[i]; i++)
        if (strlen(tab[i]) > 0)
            strExist++;
    if (strExist == 0) {
        return 0;
    }
    return 1;
}

int main(int argc, char **av)
{
    if (argc == 1 || strExist(av) == 0)
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
    else
    {
        Mega    instance(argc, av);
        std::cout << instance.str << std::endl;
    }
    return 0;
}