/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:34 by chris             #+#    #+#             */
/*   Updated: 2023/08/05 18:38:37 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "A_Animal.hpp"

A_Animal::A_Animal( void ) {

    std::cout << B_GREEN << "A_Animal -> Default Constructor called" << RESET << std::endl;
    type = "A_Animal";
    return;

}


A_Animal::A_Animal( A_Animal const & src ) {

    std::cout << B_GREEN << "A_Animal -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;

}

A_Animal::~A_Animal( void ) {

    std::cout << B_RED << "A_Animal -> Destructor called" << RESET << std::endl;

    return;

}

A_Animal & A_Animal::operator=( A_Animal const & rhs ) {

    std::cout << B_GREEN << "A_Animal -> Assignment operator called" << RESET << std::endl;
    this->type = rhs.getType();
    return *this;

}
