/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 18:31:02 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 10:50:10 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon( std::string type ) : _type( type ) {

}

Weapon::~Weapon( void ) {

}

const std::string &   Weapon::getType( void ) {
        
    return this->_type;

}

void    Weapon::setType( std::string value ) {

    this->_type = value;

}