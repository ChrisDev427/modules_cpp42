/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:48:02 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 09:25:57 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.hpp"

void test1( void ) {

    const Animal a;
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    a.makeSound();
    a.printArray();
    a.setPtr( "Blublublu" );
    std::cout << "type -> " << a.getType() << std::endl;

    i->makeSound();
    std::cout << CYAN << "getType function -> " << i->getType() << RESET << std::endl;
    i->setPtr( "Array From Cat" );
    i->printArray();

    j->makeSound();
    std::cout << CYAN << "getType function -> " << j->getType() << RESET << std::endl;
    j->setPtr( "Array From Dog" );
    j->printArray();

    delete i;
    delete j;
}

//******************************************************************************


void test2( void ) {

    int size = 5;
    const Animal* tab[size];
    initTab( tab, size );
    initStrings( tab, size );
    tab[1]->printArray();
    freeClassArray( tab, size );

}

//******************************************************************************

void test3( void ) {

    const Cat* A = new Cat();

    A->setPtr( "Hello 42" );

    std::cout << B_CYAN << "** A ** " << RESET;
    A->printArray();

//---------------------------------------------

    const Cat* B = new Cat(*A);

    std::cout << B_CYAN << "** B ** " << RESET;
    B->printArray();

    delete A;
    delete B;

}

//******************************************************************************

void test4( void ) {

    const Dog* A = new Dog();

    A->setPtr( "Hello 42" );

    std::cout << B_CYAN << "** A ** " << RESET;
    A->printArray();
    
//---------------------------------------------

    const Dog* B = new Dog(*A);

    std::cout << B_CYAN << "** B ** " << RESET;
    B->printArray();

    delete A;
    delete B;

}

//******************************************************************************


void test5( void ) {

    Dog A;

    A.setPtr( "Hello 42" );

    std::cout << B_CYAN << "** A ** " << RESET;
    A.printArray();
    
//---------------------------------------------

    Dog B;

    B = A;

    std::cout << B_CYAN << "B type = " << B.getType() << RESET << std::endl;
    std::cout << B_CYAN << "** B ** " << RESET;
    B.printArray();


}


void test6( void ) {

    Cat* A = new Cat();

    A->setPtr( "Hello 42" );

    std::cout << B_CYAN << "** A ** " << RESET;
    A->printArray();
    
//---------------------------------------------

    Cat* B = new Cat();

    *B = *A;

    std::cout << B_CYAN << "B type = " << B->getType() << RESET << std::endl;
    std::cout << B_CYAN << "** B ** " << RESET;
    B->printArray();

    delete A;
    delete B;


}

int main() {

//******************************************************************************
    test1();
//******************************************************************************

//******************************************************************************
//    test2();
//******************************************************************************

//******************************************************************************
//    test3();
//******************************************************************************

//******************************************************************************
//    test4();
//******************************************************************************

//******************************************************************************
//    test5();
//******************************************************************************

//******************************************************************************
//    test6();
//******************************************************************************

    // system("leaks a.out");
    return 0; 
}