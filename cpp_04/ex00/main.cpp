/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 19:48:02 by chris             #+#    #+#             */
/*   Updated: 2023/08/29 17:00:04 by chris            ###   ########.fr       */
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
    std::cout << B_CYAN << "************************************************************\n" << RESET << std::endl;
    
    const Animal* animal = new Animal(); 
    const Animal* cat = new Cat();
    const Animal* dog = new Dog();

    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    std::cout << B_ORANGE << "animal is : " B_CYAN << animal->getType() << RESET << std::endl; 
    std::cout << B_ORANGE << "cat is : " B_CYAN << cat->getType() << RESET << std::endl; 
    std::cout << B_ORANGE << "dog is : " << B_CYAN << dog->getType() << RESET << std::endl;
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    
    cat->makeSound();
    dog->makeSound();
    animal->makeSound();

    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;

    delete animal;
    delete cat;
    delete dog;

    std::cout << B_CYAN << "************************************************************\n\n" << RESET << std::endl;
}


static void test2( void ) {

    std::cout << B_CYAN << "************************************************************" << RESET << std::endl;
    std::cout << B_CYAN << "**********************   TEST 2   **************************" << RESET << std::endl;
    std::cout << B_CYAN << "************************************************************\n" << RESET << std::endl;

    WrongAnimal* wrongAnimal = new WrongAnimal();
    WrongAnimal* wrongCat = new WrongCat();
    WrongCat* wrongCat2 = new WrongCat();
    

    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;
    std::cout << B_ORANGE << "wrongAnimal is : " B_CYAN << wrongAnimal->getType() << RESET << std::endl; 
    std::cout << B_ORANGE << "wrongCat is : " B_CYAN << wrongCat->getType() << RESET << std::endl; 
    std::cout << B_ORANGE << "wrongCat2 is : " B_CYAN << wrongCat2->getType() << RESET << std::endl; 
    
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;

    wrongAnimal->makeSound();
    wrongCat->makeSound();
    wrongCat2->makeSound();
    
    std::cout << B_GRAY << "-------------------------------------------------" << RESET << std::endl;

    
    delete wrongCat;
    delete wrongCat2;
    delete wrongAnimal;


    std::cout << B_CYAN << "************************************************************\n\n" << RESET << std::endl;
}
int main() {

    
    test1();
    test2();
       
    return 0; 
}