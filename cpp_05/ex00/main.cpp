/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/31 09:55:27 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "policeColor.hpp"

void test1( void ) {

    try {

        Bureaucrat chris( "Chris", 170 );
    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }

    try {

        Bureaucrat tom( "Tom", -170 );
    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }

}

void test2( void ) {

    try {

        Bureaucrat chris( "Chris", 130 );
        std::cout << chris << std::endl;
    
        Bureaucrat jean( "Jean", 5 );
        std::cout << jean << std::endl;
    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }
}

void test3( void ) {

    try {

        Bureaucrat chris( "Chris", 130 );
        std::cout << chris << std::endl;

        chris.decremGrade();
        std::cout << chris << std::endl;

        chris.incremGrade();
        std::cout << chris << std::endl;

    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }

}

void test4( void ) {

    try {
        
        Bureaucrat tom( "Tom", 1 );
        std::cout << tom << std::endl;

        tom.incremGrade();
        std::cout << tom << std::endl;
    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }
}

void test5( void ) {

    Bureaucrat marc( "Marc", 150 );
    
    std::cout << marc << std::endl;

    try {

        marc.decremGrade();
        std::cout << marc << std::endl;
    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }
}

void test6( void ) {

    Bureaucrat marc( "Marc", 150 );
    std::cout << marc << std::endl;

    Bureaucrat chris( marc );
    std::cout << chris << std::endl;

    Bureaucrat tom;

    tom = chris;
    std::cout << tom << std::endl;

}

int main() {

    std::cout << B_BLUE << "\n*** TEST 1 ****************************************************\n" << RESET << std::endl;
    test1();
    std::cout << B_BLUE << "\n*** TEST 2 ****************************************************\n" << RESET << std::endl;
    test2();
    std::cout << B_BLUE << "\n*** TEST 3 ****************************************************\n" << RESET << std::endl;
    test3();
    std::cout << B_BLUE << "\n*** TEST 4 ****************************************************\n" << RESET << std::endl;
    test4();
    std::cout << B_BLUE << "\n*** TEST 5 ****************************************************\n" << RESET << std::endl;
    test5();
    std::cout << B_BLUE << "\n*** TEST 6 ****************************************************\n" << RESET << std::endl;
    test6();

    return 0;
}