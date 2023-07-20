/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:09 by chris             #+#    #+#             */
/*   Updated: 2023/07/20 18:13:40 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook(void) {

    PhoneBook::contactNb = 0;
    for (int i = 0; i < 8; i++)
        PhoneBook::contactsTab[i] = Contact();
    
    
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

void    PhoneBook::initContact(PhoneBook *ptr, int contNb) {
    
    ptr->fillForm(&(ptr->contactsTab[contNb]));
    ptr->contactNb++;
    
    return;
}

void    PhoneBook::fillForm(Contact *ptr) {

    std::cin.ignore();
    std::cout << "first name : ";
    std::getline(std::cin, ptr->firstName);
    std::cout << "last name : ";
    std::getline(std::cin, ptr->lastName);
    std::cout << "nick name : ";
    std::getline(std::cin, ptr->nickName);
    std::cout << "phone number : ";
    std::getline(std::cin, ptr->phoneNumber);
    std::cout << "dark secret : ";
    std::getline(std::cin, ptr->darkSecret);
    return;
}

void    PhoneBook::setContactToPrint(Contact *ptr) {

    size_t len;

    PhoneBook::_buffToPrint[0] = ptr->firstName;
    PhoneBook::_buffToPrint[1] = ptr->lastName;
    PhoneBook::_buffToPrint[2] = ptr->nickName;
    for (int i = 0; i < 3; i++) {

        len = PhoneBook::_buffToPrint[i].size();
        if (len < 10)
            PhoneBook::_buffToPrint[i].insert(0, 10 - len, ' ');
        else if (len > 10) {
            PhoneBook::_buffToPrint[i].replace(9, 1, ".");
            PhoneBook::_buffToPrint[i] = PhoneBook::_buffToPrint[i].substr(0, 10);
        }
    }
}

void    PhoneBook::searchContact(PhoneBook *ptr) {

    std::cout << "     index|first name| last name|  nickname" << std::endl;
           
    for (int i = 0; i < ptr->contactNb; i++) {

        std::cout << "         "<< i << "|";
        PhoneBook::setContactToPrint(&ptr->contactsTab[i]);
        std::cout << PhoneBook::_buffToPrint[0] << "|";
        std::cout << PhoneBook::_buffToPrint[1] << "|";
        std::cout << PhoneBook::_buffToPrint[2] << "|" << std::endl;
    
    }
    return;
}

// void    PhoneBook::printContact(Contact *ptr) {

    


//     return;
// }


