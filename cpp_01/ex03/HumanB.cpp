/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:30:52 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 11:17:12 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB( std::string name ) : name( name ) {



}


HumanB::~HumanB( void ) {



}


void    HumanB::attack( void ) {

    std::cout << this->name << " ";
    std::cout << "attacks with their ";
    std::cout << weapon->getType() << std::endl;
}

void    HumanB::setWeapon( Weapon& ref ) {

    this->weapon = &ref;

}
