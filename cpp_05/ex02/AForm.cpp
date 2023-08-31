/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"


AForm::gradeExcept::gradeExcept( const char* type ) throw() : _errorType( type ) {}
AForm::gradeExcept::~gradeExcept() throw() {}

AForm::AForm( void ) : _gradeSign(0), _gradeExec(0), _signed(false), _name( "Unknown" ) {

    std::cout << GREEN << "AForm: Default Constructor called" << RESET << std::endl;
    
    return;
}


AForm::AForm( AForm const & src ) : _gradeSign(src._gradeSign), _gradeExec(src._gradeExec), _signed( src._signed ), _name( src._name ) {

    std::cout << GREEN << "AForm: Copy Constructor called" << RESET << std::endl;

    return;
}

AForm::~AForm( void ) {

    std::cout << RED << "AForm: Destructor called" << RESET << std::endl;

    return;
}


AForm & AForm::operator=( AForm const & rhs ) {

    std::cout << GREEN << "AForm: Assignment operator called" << RESET << std::endl;

    setName(rhs.getName());
    setGradeSign(rhs.getGradeSign());
    setGradeExec(rhs.getGradeExec());
    setSigned(rhs.getSigned());

    return *this;
}

std::string AForm::getName( void ) const { return _name; }
std::string AForm::getTarget( void ) const { return _target; }
int         AForm::getGradeSign( void ) const { return _gradeSign; }
int         AForm::getGradeExec( void ) const { return _gradeExec; }
bool        AForm::getSigned( void ) const { return _signed; }
std::string AForm::getFormState( bool state ) const {

    if ( state == true ) {

        return ( "Signed Form" );
    }
    return ( "Unsigned Form" );
}

void AForm::setName( std::string name ) { const_cast<std::string&>( _name ) = name; }
void AForm::setTarget( std::string target ) { const_cast<std::string&>( _target ) = target; }
void AForm::setGradeSign( int sign ) { const_cast<int&>( _gradeSign) = sign; }
void AForm::setGradeExec( int exec ) { const_cast<int&>( _gradeExec) = exec; }
void AForm::setSigned( bool sign ) { _signed = sign; }

void AForm::beSigned( Bureaucrat & ref ) {

    if ( ref.getGrade() <= _gradeSign ) { _signed = true; }
    else { throw gradeExcept( RED "AForm::GradeTooLowException" RESET ); }
}

void        AForm::checkAccess( Bureaucrat const & executor ) const {

    if ( getSigned() == false ) { throw gradeExcept( RED "AForm::UnsignedFormException\n" RESET ); }
    if ( executor.getGrade() > getGradeExec() ) { throw gradeExcept( RED "AForm::GradeExecToLowException\n" RESET ); }

}

const char* AForm::gradeExcept::what() const throw() { return _errorType; }

std::ostream & operator<<( std::ostream & o, AForm const & rhs ) {

    o << B_GRAY << "      Name: " << B_BLUE << rhs.getName() << RESET << std::endl;
    o << B_GRAY << "    Target: " << B_BLUE << rhs.getTarget() << RESET << std::endl;
    o << B_GRAY << "Grade Sign: " << B_BLUE << rhs.getGradeSign() << RESET << std::endl;
    o << B_GRAY << "Grade Exec: " << B_BLUE << rhs.getGradeExec() << RESET << std::endl;
    o << B_GRAY << "     State: " << B_BLUE << rhs.getFormState( rhs.getSigned() ) << RESET << std::endl;
    return o;

}

