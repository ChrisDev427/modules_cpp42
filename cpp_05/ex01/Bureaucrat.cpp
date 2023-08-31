/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/31 08:36:02 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "policeColor.hpp"


Bureaucrat::gradeExcept::gradeExcept( const char* type ) throw() : _errorType( type ) {}
Bureaucrat::gradeExcept::~gradeExcept() throw() {}

Bureaucrat::Bureaucrat( void ) : _grade(0), _name( "default_Name" ) {

    std::cout << GREEN <<"Bureaucrat: Default Constructor called" << RESET << std::endl;
    
    return;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name( name ) {

    std::cout << GREEN <<"Bureaucrat: Parametric Constructor called" << RESET << std::endl;

    if ( grade < 1 )
        throw gradeExcept( RED "Bureaucrat::GradeTooHighException" RESET );
    if ( grade > 150 )
        throw gradeExcept( RED "Bureaucrat::GradeTooLowException" RESET );
    else
        _grade = grade;
    return;
}


Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _grade( src._grade ), _name( src._name ) {

    std::cout << GREEN <<"Bureaucrat: Copy Constructor called" << RESET << std::endl;

    return;
}

Bureaucrat::~Bureaucrat( void ) {

    std::cout << RED << "Bureaucrat: Destructor called" << RESET << std::endl;

    return;

}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) {

    std::cout << GREEN <<"Bureaucrat: Assignment operator called" << RESET << std::endl;
    
    const_cast<std::string&>(_name) = rhs._name;
    _grade = rhs._grade;
    return *this;

}

std::string Bureaucrat::getName( void ) const {

    return _name;
}

int         Bureaucrat::getGrade( void ) const {
    
    return _grade;
}

void Bureaucrat::incremGrade( void ) {

    if ( _grade > 1 ) {

        _grade--;
    }
    else {

        throw gradeExcept( RED "Bureaucrat::GradeTooHighException" RESET );  
    }
}

void Bureaucrat::decremGrade( void ) {
     
    if ( _grade < 150 ) {

        _grade++;
    }
    else {

        throw gradeExcept( RED "Bureaucrat::GradeTooLowException" RESET );
    }
}

const char* Bureaucrat::gradeExcept::what() const throw() { return _errorType; }

void        Bureaucrat::signForm( Form & ref ) {

    if ( ref.getSigned() == true ) { return; }
    
    try {
        ref.beSigned( *this );
        std::cout << GREEN << _name << " signed " << ref.getName() << RESET << std::endl;
    }
    catch ( const Form::gradeExcept& e) {

        std::cout << RED << _name << " couldn’t sign " << ref.getName() << " because " << e.what() << RESET << std::endl;

    }

    return;

}

std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs ) {

    o << B_GRAY << rhs.getName() << B_BLUE << ", bureaucrat grade " << rhs.getGrade() << RESET;
    return o;

}


