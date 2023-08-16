/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:09 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 07:46:46 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

PhoneBook::PhoneBook( void ) {

    PhoneBook::contactNb = 0;
    PhoneBook::contactId = 0;
    PhoneBook::choice = 0;
    for (int i = 0; i < 8; i++)
        PhoneBook::contactsTab[i] = Contact();
    return;
}

PhoneBook::~PhoneBook( void ) {
    
    return;
}


void    PhoneBook::initChoice( void ) {

    if ( this->cIn == "ADD" )
        this->choice = 1;
    else if ( this->cIn == "SEARCH" )
        this->choice = 2;
    else if ( this->cIn == "EXIT" )
        this->choice = 3;
	this->cIn.clear();
    
}

void    PhoneBook::initContact( void ) {
    
    this->fillForm( &( this->contactsTab[this->contactId] ) );
    if ( this->contactNb <= 7 )
        this->contactNb++;
    this->contactId++;
    if ( this->contactId == 8 )
        this->contactId = 0;
    
    return;
}

void    PhoneBook::fillForm( Contact *ptr ) {

    std::cout << B_GRAY << "first name : " B_CYAN;
    std::getline( std::cin, ptr->firstName );
    std::cout << B_GRAY << "last name : " B_CYAN;
    std::getline( std::cin, ptr->lastName );
    std::cout << B_GRAY << "nick name : " B_CYAN;
    std::getline( std::cin, ptr->nickName );
    std::cout << B_GRAY << "phone number : " B_CYAN;
    std::getline( std::cin, ptr->phoneNumber );
    std::cout << B_GRAY << "dark secret : " B_CYAN;
    std::getline( std::cin, ptr->darkSecret );
	
    return;
}

void    PhoneBook::setContactToPrint( Contact *ptr ) {

    size_t len;

    PhoneBook::_buffToPrint[0] = ptr->firstName;
    PhoneBook::_buffToPrint[1] = ptr->lastName;
    PhoneBook::_buffToPrint[2] = ptr->nickName;
    for ( int i = 0; i < 3; i++ ) {

        len = PhoneBook::_buffToPrint[i].size();
        if ( len < 10 )
            PhoneBook::_buffToPrint[i].insert( 0, 10 - len, ' ' );
        else if ( len > 10 ) {
            PhoneBook::_buffToPrint[i].replace( 9, 1, "." );
            PhoneBook::_buffToPrint[i] = PhoneBook::_buffToPrint[i].substr( 0, 10 );
        }
    }
}

void    PhoneBook::searchContact( void ) {

    if ( this->contactNb == 0 ) {
        std::cout << RED << "       PhoneBook is empty\n      Please ADD a contact" << RESET << std::endl;
        return;
    }
    std::cout << YELLOW << "\n|     index|first name| last name|  nickname" << "|" << std::endl;
           
    for ( int i = 0; i < this->contactNb; i++ ) {

        std::cout << "|         "<< i+1 << "|";
        this->setContactToPrint( &this->contactsTab[i] );
        std::cout << this->_buffToPrint[0] << "|";
        std::cout << this->_buffToPrint[1] << "|";
        std::cout << this->_buffToPrint[2] << "|" << std::endl;
    }
    std::cout << std::endl;
    this->printContact();

    return;
}

void    PhoneBook::printContact( void ) {

    int choice;
    std::string input;

    while ( true ) {

        while ( true ) {
            
            std::cout << GREEN << "Enter the contact number you want to see or 0 to go back " << RESET;
            std::getline(std::cin, input);

            if (input.empty()) {

                std::cout << RED << "No input provided." << RESET << std::endl;
                continue;
            }

            std::istringstream iss(input);
            if (iss >> choice) {
                if (choice >= 0 )
                    break;
                else
                    std::cout << RED << "Invalid input." << RESET << std::endl;
            } 
            else
                std::cout << RED << "Invalid input. Numeric value is needed" << RESET << std::endl;
        }
		if ( choice == 0 )
			return;
        choice -= 1;
        if ( choice >= 0 && choice < this->contactNb ) {
            std::cout << B_GRAY << "  First Name:    " << YELLOW << PhoneBook::contactsTab[choice].firstName << std::endl;
            std::cout << B_GRAY << "   Last Name:    " << YELLOW << PhoneBook::contactsTab[choice].lastName << std::endl;
            std::cout << B_GRAY << "   Nick Name:    " << YELLOW << PhoneBook::contactsTab[choice].nickName << std::endl;
            std::cout << B_GRAY << "Phone Number:    " << YELLOW << PhoneBook::contactsTab[choice].phoneNumber << std::endl;
            std::cout << B_GRAY << " Dark Secret:    " << YELLOW << PhoneBook::contactsTab[choice].darkSecret << RESET << std::endl;
        }
        else
            std::cout << RED << "Invalid input." << RESET << std::endl;

    }
}
