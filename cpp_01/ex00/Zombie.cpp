/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 08:59:14 by chris             #+#    #+#             */
/*   Updated: 2023/07/24 16:29:23 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"


Zombie::Zombie( std::string name ) : _name( name ) {



}
Zombie::~Zombie( void ) {

    std::cout << B_CYAN << this->_name << ":" << RED << "   died" << RESET << std::endl;


}


void Zombie::announce( void ) {

    std::cout << B_CYAN << this->_name << ":" << GREEN << " BraiiiiiiinnnzzzZ..." << RESET << std::endl;

}

