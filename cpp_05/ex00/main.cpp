/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 18:31:44 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 08:42:46 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
    }
    catch ( const Bureaucrat::gradeExcept& e) {

        std::cerr << e.what() << std::endl;
    }

    try {

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

    Bureaucrat tom( "Tom", 1 );
    
    std::cout << tom << std::endl;

    try {

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

int main() {

    
    // test1();
    // test2();
    // test3();
    // test4();
    test5();

    


    return 0;
}