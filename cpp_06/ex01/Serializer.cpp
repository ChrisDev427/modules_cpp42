/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:32 by chris             #+#    #+#             */
/*   Updated: 2023/09/02 11:18:19 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

Serializer::Serializer( void ) {

    std::cout << "Default Constructor called" << std::endl;
    return;
}

Serializer::Serializer( Serializer const & src ) {

    std::cout << "Copy Constructor called" << std::endl;
    *this = src;
    return;
}

Serializer::~Serializer( void ) {

    std::cout << "Destructor called" << std::endl;

    return;
}

Serializer & Serializer::operator=( Serializer const & rhs ) {

    std::cout << "Assignment operator called" << std::endl;
    if ( this != &rhs ) {}
    return *this;
}

uintptr_t    Serializer::serialize( Data* ptr ) {

    uintptr_t   ret;
    return ( ret = reinterpret_cast<uintptr_t>(ptr) );
}

Data*        Serializer::deserialize( uintptr_t raw ) {

    Data* ptr;
    return ( ptr = reinterpret_cast<Data*>(raw) );
}
