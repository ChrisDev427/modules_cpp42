/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/31 08:48:10 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "policeColor.hpp"

int main() {

    
    try {

        std::cout << BLUE << "***** Init Bureaucrat: franck *****" << RESET << std::endl;
        Bureaucrat franck( "Franck", 26 );
        std::cout << franck << std::endl;


        std::cout << BLUE << "***** Init Form: form1 *****" << RESET << std::endl;
        Form form1( "Form1", 25, 58 );
        std::cout << form1 << std::endl;

        std::cout << BLUE << "\n***********************************************************\n" << RESET << std::endl;


        std::cout << BLUE << "***** signForm *****" << RESET << std::endl;
        franck.signForm( form1 );

        std::cout << BLUE << "***** Increment grade  *****" << RESET << std::endl;
        franck.incremGrade();
        std::cout << franck << std::endl;

        std::cout << BLUE << "***** signForm *****" << RESET << std::endl;
        franck.signForm( form1 );
        std::cout << form1 << std::endl;


        std::cout << BLUE << "\n***********************************************************\n" << RESET << std::endl;


        std::cout << BLUE << "***** Copy *****" << RESET << std::endl;
        Form form2( form1 );

        std::cout << form2 << std::endl;


        std::cout << BLUE << "\n***********************************************************\n" << RESET << std::endl;



        std::cout << BLUE << "***** Assign *****" << RESET << std::endl;
        Form form3;
        form3 = form1;
        std::cout << form3 << std::endl;
    
    }
    catch( std::exception& e ) { std::cerr << e.what() << std::endl; }

    return 0;
}