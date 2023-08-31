/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm( void ) {

    std::cout << GREEN << "PresPardonForm: Default Constructor called" << RESET << std::endl;

    setName( "PresidentialPardonForm" );
    setTarget( "Unknown" );
    setGradeSign( 25 );
    setGradeExec( 5 );
    
    return;
}

PresidentialPardonForm::PresidentialPardonForm( std::string const target ) {

    std::cout << GREEN << "PresPardonForm: Parametric Constructor called" << RESET << std::endl;

    setName( "PresidentialPardonForm" );
    setTarget( target );
    setGradeSign( 25 );
    setGradeExec( 5 );

    return;
}


PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const & src ) {

    std::cout << GREEN << "PresPardonForm: Copy Constructor called" << RESET << std::endl;

    setName(src.getName());
    setTarget(src.getTarget());
    setGradeSign(src.getGradeSign());
    setGradeExec(src.getGradeExec());
    setSigned(src.getSigned());

    return;
}

PresidentialPardonForm::~PresidentialPardonForm( void ) {

    std::cout << RED << "PresPardonForm: Destructor called" << RESET << std::endl;

    return;
}


PresidentialPardonForm & PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs ) {

    std::cout << GREEN << "PresPardonForm: Assignment operator called" << RESET << std::endl;

    setName(rhs.getName());
    setTarget(rhs.getTarget());
    setGradeSign(rhs.getGradeSign());
    setGradeExec(rhs.getGradeExec());
    setSigned(rhs.getSigned());

    return *this;
}

void        PresidentialPardonForm::execute( Bureaucrat const & executor ) const {

    checkAccess( executor );

    std::cout << GREEN << getTarget() << " has been forgiven from Zaphod Beeblebrox" << RESET << std::endl;

}
