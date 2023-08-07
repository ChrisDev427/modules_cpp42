/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:40 by chris             #+#    #+#             */
/*   Updated: 2023/08/05 18:43:49 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain( void ) {

    std::cout << B_GREEN << "Brain -> Default Constructor called" << RESET << std::endl;
    
    return;
}

Brain::Brain( Brain const & src ) {

    std::cout << B_GREEN << "Brain -> Copy Constructor called" << RESET << std::endl;
    *this = src;

    return;
}

Brain::~Brain( void ) {

    std::cout << B_RED << "Brain -> Destructor called" << RESET << std::endl;

    return;
}

Brain & Brain::operator=( Brain const & rhs ) {

    std::cout << B_GREEN << "Brain -> Assignment operator called" << RESET << std::endl;

    *this->ideas = *rhs.ideas;
   
    return *this;
}
