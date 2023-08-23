/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/22 19:19:39 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"


void testIntern( void ) {

    Intern  someRandomIntern;
    Bureaucrat franck( "Franck", 1 );

    AForm*   scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
    AForm*   rrf = someRandomIntern.makeForm("robotomy request", "Bender");
    AForm*   ppf = someRandomIntern.makeForm("presidential pardon", "Paul");
    
    AForm*   fake = someRandomIntern.makeForm("fake", "Paul");

    if ( scf ) {

        std::cout << YELLOW << "***** AForm* scf *****\n" << *scf << RESET << std::endl;
        franck.signForm( *scf );
        franck.executeForm( *scf );
        delete scf;
    }

    if ( rrf ) {

        std::cout << YELLOW << "***** AForm* rrf *****\n" << *rrf << RESET << std::endl;
        franck.signForm( *rrf );
        franck.executeForm( *rrf );
        delete rrf;
    }

    if ( ppf ) {

        std::cout << YELLOW << "***** AForm* ppf *****\n" << *ppf << RESET << std::endl;
        franck.signForm( *ppf );
        franck.executeForm( *ppf );
        delete ppf;
    }

}

int main() {

    testIntern();
        
    system("leaks prog");    
    return 0;
}