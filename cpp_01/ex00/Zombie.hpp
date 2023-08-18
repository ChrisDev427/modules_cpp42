/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:59:18 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 15:21:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[32m"
# define B_CYAN    "\033[1;36m"

class Zombie {

public:

    Zombie( std::string name );
    ~Zombie( void );

    void announce( void );

private:

    std::string _name;

};

void    randomChump( std::string name );
Zombie* newZombie( std::string name );

#endif /*********************************************************** ZOMBIE_HPP*/