/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::gradeExcept::gradeExcept( const char* type ) throw() : _errorType( type ) {}
Bureaucrat::gradeExcept::~gradeExcept() throw() {}

Bureaucrat::Bureaucrat( void ) : _grade(0), _name( "default_Name" ) {

    // std::cout << "Default Constructor called" << std::endl;
    
    return;
}

Bureaucrat::Bureaucrat( std::string const name, int grade ) : _name( name ) {

    // std::cout << "Parametric Constructor called" << std::endl;

    if ( grade < 1 )
        throw gradeExcept( "Bureaucrat::GradeTooHighException" );
    if ( grade > 150 )
        throw gradeExcept( "Bureaucrat::GradeTooLowException" );
    else
        _grade = grade;
    return;
}


Bureaucrat::Bureaucrat( Bureaucrat const & src ) {

    std::cout << "Copy Constructor called" << std::endl;
    *this = src;

    return;
}

Bureaucrat::~Bureaucrat( void ) {

    // std::cout << "Destructor called" << std::endl;

    return;

}

Bureaucrat & Bureaucrat::operator=( Bureaucrat const & rhs ) {

    std::cout << "Assignment operator called" << std::endl;
    static_cast<std::string>(_name) = rhs._name;
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

const char* Bureaucrat::gradeExcept::what() const throw() {

    return _errorType;
    

}


std::ostream & operator<<( std::ostream & o, Bureaucrat const & rhs ) {

    o << rhs.getName() << ", bureaucrat grade " << rhs.getGrade();
    return o;

}

