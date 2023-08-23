/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 09:16:13 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "AForm.hpp"




void testShrubb1( void ) {

    ShrubberyCreationForm shrubb( "Garden" );
    std::cout << shrubb << std::endl;

    try {

        Bureaucrat franck( "Franck", 150 );
        std::cout << franck << std::endl;

        std::cout << YELLOW << "***** Try signForm *****************************" << RESET << std::endl;
        franck.signForm( shrubb );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;
        
        std::cout << shrubb << std::endl;

        std::cout << YELLOW << "***** Try executeForm **************************" << RESET << std::endl;
        franck.executeForm( shrubb );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;


    }
    catch ( Bureaucrat::gradeExcept& e ) { std::cerr << e.what() << std::endl; }        
}

void testShrubb2( void ) {

    AForm* AFptr = new ShrubberyCreationForm( "Garden" );
    std::cout << *AFptr << std::endl;

    try {

        Bureaucrat* Bptr = new Bureaucrat( "Franck", 137 );
        std::cout << *Bptr << std::endl;

        std::cout << YELLOW << "***** Try signForm *****************************" << RESET << std::endl;
        Bptr->signForm( *AFptr );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;

        std::cout << *AFptr << std::endl;

        std::cout << YELLOW << "***** Try executeForm **************************" << RESET << std::endl;
        Bptr->executeForm( *AFptr );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;

        delete Bptr;

    }
    catch ( Bureaucrat::gradeExcept& e ) { std::cerr << e.what() << std::endl; }

    delete AFptr;
}

void testRobot( void ) {

    AForm* AFptr = new RobotomyRequestForm( "Robotomying" );
    std::cout << *AFptr << std::endl;

    try {

        Bureaucrat* Bptr = new Bureaucrat( "Franck", 45 );
        std::cout << *Bptr << std::endl;

        std::cout << YELLOW << "***** Try signForm *****************************" << RESET << std::endl;
        Bptr->signForm( *AFptr );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;

        std::cout << *AFptr << std::endl;

        std::cout << YELLOW << "***** Try executeForm **************************" << RESET << std::endl;
        Bptr->executeForm( *AFptr );
        Bptr->executeForm( *AFptr );
        Bptr->executeForm( *AFptr );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;

        delete Bptr;
    }
    catch ( Bureaucrat::gradeExcept& e ) { std::cerr << e.what() << std::endl; }

    delete AFptr;
}

void testPardon( void ) {

    AForm* AFptr = new PresidentialPardonForm( "Pardon" );
    std::cout << *AFptr << std::endl;

    try {

        Bureaucrat* Bptr = new Bureaucrat( "Franck", 5 );
        std::cout << *Bptr << std::endl;

        std::cout << YELLOW << "***** Try signForm *****************************" << RESET << std::endl;
        Bptr->signForm( *AFptr );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;

        std::cout << *AFptr << std::endl;

        std::cout << YELLOW << "***** Try executeForm **************************" << RESET << std::endl;
        Bptr->executeForm( *AFptr );
        std::cout << YELLOW << "************************************************" << RESET << std::endl;

        delete Bptr;
    }
    catch ( Bureaucrat::gradeExcept& e ) { std::cerr << e.what() << std::endl; }

    delete AFptr;
}

void testCopyAssign( void ) {

    Bureaucrat franck( "Franck", 150 );
    ShrubberyCreationForm shrubb( "Garden" );
    RobotomyRequestForm robot( "Robotomying" );
    PresidentialPardonForm pardon( "Pardon" );

    std::cout << "-------------------------------------------------------------" << std::endl;

    Bureaucrat franckAss;
    ShrubberyCreationForm shrubbAss;
    RobotomyRequestForm robotAss;
    PresidentialPardonForm pardonAss;

    std::cout << "-------------------------------------------------------------" << std::endl;

    franckAss = franck;
    shrubbAss = shrubb;
    robotAss = robot;
    pardonAss = pardon;

    std::cout << "-------------------------------------------------------------" << std::endl;

    std::cout << "franck\n" << franck << std::endl;
    std::cout << "shrubb\n" << shrubb << std::endl;
    std::cout << "robot\n" << robot << std::endl;
    std::cout << "pardon\n" << pardon << std::endl;

    std::cout << "-------------------------------------------------------------" << std::endl;

    std::cout << "franckAss\n" << franckAss << std::endl;
    std::cout << "shrubbAss\n" << shrubbAss << std::endl;
    std::cout << "robotAss\n" << robotAss << std::endl;
    std::cout << "pardonAss\n" << pardonAss << std::endl;

    std::cout << "-------------------------------------------------------------" << std::endl;

    Bureaucrat franckCpy = Bureaucrat( franck );
    ShrubberyCreationForm shrubbCpy = ShrubberyCreationForm( shrubb );
    RobotomyRequestForm robotCpy = RobotomyRequestForm( robot );
    PresidentialPardonForm pardonCpy = PresidentialPardonForm( pardon );

    std::cout << "franckCpy\n" << franckCpy << std::endl;
    std::cout << "shrubbCpy\n" << shrubbCpy << std::endl;
    std::cout << "robotCpy\n" << robotCpy << std::endl;
    std::cout << "pardonCpy\n" << pardonCpy << std::endl;
}



int main() {

    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    
    // testShrubb1();
    // testShrubb2();

    testRobot();
    // testPardon();
    // testCopyAssign();
    
    
    
    // system("leaks prog");    
    return 0;
}