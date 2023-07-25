/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:31:02 by chris             #+#    #+#             */
/*   Updated: 2023/07/24 18:51:31 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon() {

}

Weapon::~Weapon() {

}

std::string&    Weapon::getType( void ) {
        
    return this->_type;

}


void    Weapon::setType( std::string value ) {

    this->_type = value;

}