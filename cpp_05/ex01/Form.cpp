/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "policeColor.hpp"

Form::gradeExcept::gradeExcept( const char* type ) throw() : _errorType( type ) {}
Form::gradeExcept::~gradeExcept() throw() {}

Form::Form( void ) : _gradeSign(0), _gradeExec(0), _signed(0), _name( "default_Name" ) {

    std::cout << GREEN << "Form: Default Constructor called" << RESET << std::endl;
    
    return;
}

Form::Form( std::string const name, int const gradeSign, int const gradeExec ) : _gradeSign(gradeSign), _gradeExec(gradeExec), _signed( false ), _name( name ) {

    std::cout << GREEN << "Form: Parametric Constructor called" << RESET << std::endl;
    
    if ( gradeSign < 1 || gradeExec < 1)
        throw gradeExcept( RED "Form::GradeTooHighException" RESET );
    if ( gradeSign > 150 || gradeExec > 150)
        throw gradeExcept( RED "Form::GradeTooLowException" RESET );
    
    
    return;
}


Form::Form( Form const & src ) : _gradeSign(src._gradeSign), _gradeExec(src._gradeExec), _signed( src._signed ), _name( src._name ) {

    std::cout << GREEN << "Form: Copy Constructor called" << RESET << std::endl;

    return;
}

Form::~Form( void ) {

    std::cout << RED << "Form: Destructor called" << RESET << std::endl;

    return;
}


Form & Form::operator=( Form const & rhs ) {

    std::cout << GREEN << "Form: Assignment operator called" << RESET << std::endl;

    const_cast<std::string&>(_name) = rhs._name;
    const_cast<int&>(_gradeSign) = rhs._gradeSign;
    const_cast<int&>(_gradeExec) = rhs._gradeExec;
    _signed = rhs._signed;
    return *this;
}

std::string Form::getName( void ) const { return _name; }
int         Form::getGradeExec( void ) const { return _gradeExec; }
int         Form::getGradeSign( void ) const { return _gradeSign; }
bool        Form::getSigned( void ) const { return _signed; }
std::string Form::getFormState( bool state ) const {

    if ( state == true ) { return ( "Signed Form" ); }
    return ( "Unsigned Form" );
}

void  Form::beSigned( Bureaucrat & ref ) {
    
    if ( ref.getGrade() <= _gradeSign ) { _signed = true; }
    else { throw gradeExcept( RED "Form::GradeTooLowException" RESET ); }
}

const char* Form::gradeExcept::what() const throw() { return _errorType; }

std::ostream & operator<<( std::ostream & o, Form const & rhs ) {

    o << B_GRAY << " Form Name: " << B_BLUE << rhs.getName() << RESET << std::endl;
    o << B_GRAY << "Grade Sign: " << B_BLUE << rhs.getGradeSign() << RESET << std::endl;
    o << B_GRAY << "Grade Exec: " << B_BLUE << rhs.getGradeExec() << RESET << std::endl;
    o << B_GRAY << "     State: " << B_BLUE << rhs.getFormState( rhs.getSigned() ) << RESET << std::endl;
    return o;
}