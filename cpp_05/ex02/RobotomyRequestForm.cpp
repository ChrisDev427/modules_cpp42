/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm( void ) {

    std::cout << GREEN << "RobotRequForm: Default Constructor called" << RESET << std::endl;

    setName( "RobotomyRequestForm" );
    setTarget( "Unknown" );
    setGradeSign( 72 );
    setGradeExec( 45 );
    
    
    return;
}

RobotomyRequestForm::RobotomyRequestForm( std::string const target ) {

    std::cout << GREEN << "RobotRequForm: Parametric Constructor called" << RESET << std::endl;

    setName( "RobotomyRequestForm" );
    setTarget( target );
    setGradeSign( 72 );
    setGradeExec( 45 );
    
    
    
    return;
}


RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const & src ) {

    std::cout << GREEN << "RobotRequForm: Copy Constructor called" << RESET << std::endl;

    setName(src.getName());
    setTarget(src.getTarget());
    setGradeSign(src.getGradeSign());
    setGradeExec(src.getGradeExec());
    setSigned(src.getSigned());

    return;
}

RobotomyRequestForm::~RobotomyRequestForm( void ) {

    std::cout << RED << "RobotRequForm: Destructor called" << RESET << std::endl;

    return;
}


RobotomyRequestForm & RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs ) {

    std::cout << GREEN << "RobotRequForm: Assignment operator called" << RESET << std::endl;

    setName(rhs.getName());
    setTarget(rhs.getTarget());
    setGradeSign(rhs.getGradeSign());
    setGradeExec(rhs.getGradeExec());
    setSigned(rhs.getSigned());

    return *this;
}

void        RobotomyRequestForm::execute( Bureaucrat const & executor ) const {

    checkAccess( executor );

    std::cout << RED << "(!(!(! VrrrrrBrrrrrZzzzzzGrrrrrSrrrrr !)!)!)" << RESET << std::endl;

    // std::srand(static_cast<unsigned int>(std::time(nullptr)));
    int randomIndex = std::rand() % 50;

    if ( randomIndex > 25 )
        std::cout << GREEN <<  getTarget() << " has been robotomised with success !" << RESET << std::endl;
    else
        std::cout << RED <<  getTarget() << " failed robotomization !" << RESET << std::endl;

}
