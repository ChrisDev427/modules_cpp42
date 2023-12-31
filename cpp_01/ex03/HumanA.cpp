/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:30:41 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 11:00:39 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::HumanA( std::string name, Weapon& ref ) : weapon( ref ), name( name ) {



}


HumanA::~HumanA( void ) {



}


void    HumanA::attack( void ) {

    std::cout << this->name << " ";
    std::cout << "attacks with their ";
    std::cout << weapon.getType() << std::endl;
}

//<name> attacks with their <weapon type>