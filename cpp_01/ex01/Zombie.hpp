/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:59:18 by chris             #+#    #+#             */
/*   Updated: 2023/07/24 17:13:12 by chris            ###   ########.fr       */
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

    Zombie( void );
    ~Zombie( void );

    void announce( void );
    void setName( std::string name );

private:

    std::string _name;

};


Zombie* zombieHorde( int N, std::string name );





#endif /*ZOMBIE_HPP*/