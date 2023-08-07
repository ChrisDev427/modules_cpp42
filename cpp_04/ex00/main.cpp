/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:48:02 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 10:12:55 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "WrongAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

static void test1( void ) {

    std::cout << B_CYAN << "************************************************************" << RESET << std::endl;
    std::cout << B_CYAN << "**********************   TEST 1   **************************" << RESET << std::endl;
    std::cout << B_CYAN << "************************************************************" << RESET << std::endl;
    
    const Animal* meta = new Animal(); 
    const Animal* i = new Cat();
    const Animal* j = new Dog();

    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    std::cout << B_ORANGE << "i is : " B_CYAN << i->getType() << RESET << std::endl; 
    std::cout << B_ORANGE << "j is : " << B_CYAN << j->getType() << RESET << std::endl;
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    std::cout << B_ORANGE << "i/Cat says -> " << RESET;
    i->makeSound(); //will output the cat sound! 
    std::cout << B_ORANGE << "j/Dog says -> " << RESET;
    j->makeSound();
    std::cout << B_ORANGE << "meta says -> " << RESET;
    meta->makeSound();
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;

    delete meta;
    delete i;
    delete j;

    std::cout << B_CYAN << "************************************************************\n\n" << RESET << std::endl;
}


static void test2( void ) {

    std::cout << B_CYAN << "************************************************************" << RESET << std::endl;
    std::cout << B_CYAN << "**********************   TEST 2   **************************" << RESET << std::endl;
    std::cout << B_CYAN << "************************************************************" << RESET << std::endl;

    const Animal* meta = new Animal(); 
    const WrongAnimal* i = new WrongCat();
    const Animal* j = new Dog();

    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    std::cout << B_ORANGE << "i is : " B_CYAN << i->getType() << RESET << std::endl; 
    std::cout << B_ORANGE << "j is : " << B_CYAN << j->getType() << RESET << std::endl;
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    std::cout << B_ORANGE << "i/Cat says -> " << RESET;
    i->makeSound(); //will output the cat sound! 
    std::cout << B_ORANGE << "j/Dog says -> " << RESET;
    j->makeSound();
    std::cout << B_ORANGE << "meta says -> " << RESET;
    meta->makeSound();
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;

    delete meta;
    delete i;
    delete j;

    std::cout << B_CYAN << "************************************************************\n\n" << RESET << std::endl;
}
int main() {

    
    test1();
    test2();
       
    return 0; 
}