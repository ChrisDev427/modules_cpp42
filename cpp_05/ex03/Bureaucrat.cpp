/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 08:56:12 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::gradeExcept::gradeExcept( const char* type ) throw() : _errorType( type ) {}
Bureaucrat::gradeExcept::~gradeExcept() throw() {}

Bureaucrat::Bureaucrat( void ) : _grade(0), _name( "default_Name" ) {

    std::cout << GREEN << "Bureaucrat: Default Constructor called" << RESET << std::endl;
    
    return;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name( name ) {

    std::cout << GREEN << "Bureaucrat: Parametric Constructor called" << RESET << std::endl;

    if ( grade < 1 )
        throw gradeExcept( RED "Bureaucrat::GradeTooHighException\n" RESET );
    if ( grade > 150 )
        throw gradeExcept( RED "Bureaucrat::GradeTooLowException\n" RESET );
    else
        _grade = grade;
    return;
}


Bureaucrat::Bureaucrat( Bureaucrat const & src ) : _grade( src._grade ), _name( src._name ) {

    std::cout << GREEN << "Bureaucrat: Copy Constructor called" << RESET << std::endl;

    return;
}

Bureaucrat::~Bureaucrat( void ) {

    std::cout << RED << "Bureaucrat: Destructor called" << RESET << std::endl;

    return;

}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) {

    std::cout << GREEN << "Bureaucrat: Assignment operator called" << RESET << std::endl;
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

        throw gradeExcept( "Bureaucrat::GradeTooHighException" );  
    }
}

void Bureaucrat::decremGrade( void ) {
     
    if ( _grade < 150 ) {

        _grade++;
    }
    else {

        throw gradeExcept( "Bureaucrat::GradeTooLowException" );
    }
}

const char* Bureaucrat::gradeExcept::what() const throw() { return _errorType; }

void        Bureaucrat::signForm( AForm & ref ) {

    try {
        ref.beSigned( *this );
        std::cout << GREEN << _name << " signed " << ref.getName() << RESET << std::endl;
    }
    catch ( const AForm::gradeExcept& e) {

        std::cout << RED << _name << ", couldn’t sign " << ref.getName() << " because " << e.what() << RESET << std::endl;

    }

    return;

}

void   Bureaucrat::executeForm( AForm const & form ) {


    try { form.execute( *this ); std::cout << GREEN << _name << " executed " << form.getName() << RESET << std::endl;}
    catch ( AForm::gradeExcept& e ) { std::cerr << e.what(); }

}


std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs ) {

    o << B_ORANGE << rhs.getName() << B_GRAY << ", bureaucrat grade " << B_ORANGE << rhs.getGrade() << RESET;
    return o;

}

