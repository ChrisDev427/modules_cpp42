/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 17:51:07 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:43:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( void ) {

    std::cout << GREEN << "Shrubbery: Default Constructor called" << RESET << std::endl;

    setName( "ShrubberyCreationForm" );
    setTarget( "Unknown" );
    setGradeSign( 145 );
    setGradeExec( 137 );
    
    
    return;
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const target ) {

    std::cout << GREEN << "Shrubbery: Parametric Constructor called" << RESET << std::endl;

    setName( "ShrubberyCreationForm" );
    setTarget( target );
    setGradeSign( 145 );
    setGradeExec( 137 );
    
    
    return;
}


ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const & src ) {

    std::cout << GREEN << "Shrubbery: Copy Constructor called" << RESET << std::endl;

    setName(src.getName());
    setTarget(src.getTarget());
    setGradeSign(src.getGradeSign());
    setGradeExec(src.getGradeExec());
    setSigned(src.getSigned());

    return;
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ) {

    std::cout << RED << "Shrubbery: Destructor called" << RESET << std::endl;

    return;
}


ShrubberyCreationForm & ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs ) {

    std::cout << "Assignment operator called" << std::endl;

    setName(rhs.getName());
    setGradeSign(rhs.getGradeSign());
    setGradeExec(rhs.getGradeExec());
    setSigned(rhs.getSigned());

    return *this;
}

void        ShrubberyCreationForm::execute( Bureaucrat const & executor ) const {

    checkAccess( executor );
    std::string const target = getTarget();
    std::cout  << getName() << std::endl;
    // target += "_shrubbery";

    std::ofstream  outFile( target , std::ios::app );
    if ( outFile.is_open() ) {
   
        int height = 11;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < height - i - 1; ++j) {
                outFile << " ";
            }
            for (int j = 0; j < 2 * i + 1; ++j) {
                outFile <<  "*";
            }
            outFile << std::endl;
        }
        for (int i = 0; i < height - 2; ++i) {
            outFile << " ";
        }
        outFile << "|||\n" << std::endl;
        outFile.close();
    }
    else {
        std::cout << "Unable to open the file to write" << std::endl;
    }
}
    