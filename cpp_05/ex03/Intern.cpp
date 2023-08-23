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

    _forms[0] = "shrubbery creation";
    _forms[1] = "robotomy request";
    _forms[2] = "presidential pardon";

   

    _formType = -1;

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

    for ( int i = 0; i < 3; i++ ) {
        _forms[i] = rhs._forms[i];
    }

    return *this;
}

AForm*  Intern::makeForm( std::string formName, std::string formTarget ) {

    for ( int i = 0; i < 3; i++ ) {

        if ( formName == _forms[i] )
            _formType = i;
    }

    AForm* ptr = nullptr;

    switch ( _formType )
    {
        case -1:
            std::cout << RED << "Intern::makeForm Unknown form: " << formName << RESET << std::endl;
            break;
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

    _formType = -1;
    return ptr;
}

