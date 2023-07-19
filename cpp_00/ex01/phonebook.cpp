/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:09 by chris             #+#    #+#             */
/*   Updated: 2023/07/19 18:11:04 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void) {

    PhoneBook::contactNb = 0;
    return;
}

PhoneBook::~PhoneBook(void) {
    
    return;
}



void    PhoneBook::initChoice(char *cIn) {

    if (strcmp(cIn, "ADD") == 0)
        PhoneBook::choice = 1;
    else if (strcmp(cIn, "SEARCH") == 0)
        PhoneBook::choice = 2;
    else if (strcmp(cIn, "EXIT") == 0)
        PhoneBook::choice = 3;
    else
        PhoneBook::choice = 4;

    return;
}

void    PhoneBook::initContact(int contNb) {
    
    Contact instance;
    PhoneBook::contactsTab[contNb] = &instance;
    PhoneBook::fillForm(PhoneBook::contactsTab[contNb]);


    PhoneBook::contactNb++;
    
    return;
}

void    PhoneBook::fillForm(Contact *ptr) {
    
    std::cout << "first name : ";
    std::cin >> ptr->firstName;
    std::cout << "last name : ";
    std::cin >> ptr->lastName;
    std::cout << "nick name : ";
    std::cin >> ptr->nickName;
    std::cout << "phone number : ";
    std::cin >> ptr->phoneNumber;
    std::cout << "dark secret : ";
    std::cin >> ptr->darkSecret;
    
    return;
}

void    PhoneBook::searchContact(void) {

    std::cout << "     index|first name| last name|  nickname" << std::endl;
    
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    std::cout << "     index|first name| last name|  nickname" << std::endl;
    
    
    
    
   
    return;
}

// void    PhoneBook::printContact(Contact *ptr) {

    


//     return;
// }


