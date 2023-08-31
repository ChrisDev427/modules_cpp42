/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

Intern::Intern( void ) {

    std::cout << GREEN << "Intern: Default Constructor called" << RESET << std::endl;

    return;
}


Intern::Intern( Intern const & src ) {

    std::cout << GREEN << "Intern: Copy Constructor called" << RESET << std::endl;

    *this = src;

    return;
}

Intern::~Intern( void ) {

    std::cout << RED << "Intern: Destructor called" << RESET << std::endl;

    return;
}


Intern & Intern::operator=( Intern const & rhs ) {

    std::cout << GREEN << "Intern: Assignment operator called" << RESET << std::endl;

    if ( this != &rhs ) {}

    return *this;
}

AForm*  Intern::makeForm( std::string formName, std::string formTarget ) {

    std::string forms[3] = { "shrubbery creation", "robotomy request", "presidential pardon"};
    AForm*      ptr = NULL;
    int         formType = -1;
    
    for ( int i = 0; i < 3; i++ ) {

        if ( formName == forms[i] )
            formType = i;
    }

    switch ( formType )
    {
        case -1:
            std::cout << RED << "Intern cannot create: " << B_GRAY << formName << RESET << std::endl;
            return ( NULL );
        case 0:
            ptr = new ShrubberyCreationForm( formTarget );
            break;
        case 1:
            ptr = new RobotomyRequestForm( formTarget );
            break;
        case 2:
            ptr = new PresidentialPardonForm( formTarget );
            break;
    }
    std::cout << GREEN << "Intern creates: " << B_GRAY << formName << RESET << std::endl;
    return ptr;
}

