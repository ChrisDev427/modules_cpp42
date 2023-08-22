// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   Form.cpp                                     :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
// /*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

// #include "Form.hpp"

// Form::Form( void ) {

//     std::cout << "Default Constructor called" << std::endl;

//     setName( "UnKnown" );
//     setGradeSign( 0 );
//     setGradeExec( 0 );
    
//     return;
// }

// Form::Form( std::string const name, int const gradeSign, int const gradeExec ) {

//     std::cout << "Parametric Constructor called" << std::endl;

//     if ( gradeSign < 1 || gradeExec < 1) { throw gradeExcept( "Form::GradeTooHighException" ); }
//     if ( gradeSign > 150 || gradeExec > 150) { throw gradeExcept( "Form::GradeTooLowException" ); }
//     setName( name );
//     setGradeSign( gradeSign );
//     setGradeExec( gradeExec );
    
//     return;
// }


// Form::Form( Form const & src ) {

//     std::cout << "Copy Constructor called" << std::endl;
//     setName(src.getName());
//     setGradeSign(src.getGradeSign());
//     setGradeExec(src.getGradeExec());
//     setSigned(src.getSigned());

//     return;
// }

// Form::~Form( void ) {

//     // std::cout << "Destructor called" << std::endl;

//     return;
// }


// Form & Form::operator=( Form const & rhs ) {

//     std::cout << "Assignment operator called" << std::endl;
//     setName(rhs.getName());
//     setGradeSign(rhs.getGradeSign());
//     setGradeExec(rhs.getGradeExec());
//     setSigned(rhs.getSigned());


//     return *this;
// }

// const char* Form::gradeExcept::what() const throw() { return _errorType; }

// std::ostream & operator<<( std::ostream & o, Form const & rhs ) {

//     o << "Form Name: " << rhs.getName();
//     o << ", Grade Sign: " << rhs.getGradeSign();
//     o << ", Grade Exec: " << rhs.getGradeExec();
//     o << ", State: " << rhs.getFormState( rhs.getSigned() );
//     return o;

// }

