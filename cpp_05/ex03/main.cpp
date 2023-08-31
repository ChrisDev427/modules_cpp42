/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/31 12:23:36 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

     try {

        Intern  someRandomIntern;
        Bureaucrat franck( "Franck", 5 );

        AForm*   scf = someRandomIntern.makeForm("shrubbery creation", "Garden");
        AForm*   rrf = someRandomIntern.makeForm("robotomy request", "Bender");
        AForm*   ppf = someRandomIntern.makeForm("presidential pardon", "Paul");

        AForm*   fake = someRandomIntern.makeForm("fake", "Paul");
        std::cout << fake << std::endl;

        std::cout << YELLOW << "***** AForm* scf ********************************************" << RESET << std::endl;
        std::cout << *scf << std::endl;
        franck.signForm( *scf );
        std::cout << *scf;
        franck.executeForm( *scf );
        std::cout << YELLOW << "*************************************************************\n" <<  RESET << std::endl;
    
        std::cout << YELLOW << "***** AForm* rrf ********************************************" << RESET << std::endl;
        std::cout << *rrf << std::endl;
        franck.signForm( *rrf );
        std::cout << *rrf;
        franck.executeForm( *rrf );
        std::cout << YELLOW << "*************************************************************\n" << RESET << std::endl;
    
        std::cout << YELLOW << "***** AForm* ppf ********************************************" << RESET << std::endl;
        std::cout << *ppf << std::endl; 
        franck.signForm( *ppf );
        std::cout << *ppf; 
        franck.executeForm( *ppf );
        std::cout << YELLOW << "*************************************************************\n" << RESET << std::endl;

        delete ppf;
        delete rrf;
        delete scf;
    }
    catch ( std::exception& e ) { std::cerr << e.what() << std::endl; }
    
    // system("leaks prog");    
    return 0;
}