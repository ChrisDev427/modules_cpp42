/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:58:57 by chris             #+#    #+#             */
/*   Updated: 2023/07/24 17:31:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(int ac, char **av) {

    if (ac == 3) {

        int nbZombies = atoi(av[1]);
        std::string name = av[2];

        Zombie* ptr = zombieHorde( nbZombies, name );

        for ( int i = 0; i < nbZombies; i++) {

            std::cout << "Zombie number : " << i+1 << " ";
            ptr[i].announce();
        }

        delete[] ptr;
        }
    else {
        std::cout << "need two args: number of zombies / name" << std::endl;
        return 1;
    }

    return 0;
}