/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Phonebook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:09 by chris             #+#    #+#             */
/*   Updated: 2023/08/17 19:37:40 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"


PhoneBook::PhoneBook( void ) {

    choice = 0;
    
    _contactNb = 0;
    _contactId = 0;

    _attributsTab[0] = "  First Name: ";
    _attributsTab[1] = "   Last Name: ";
    _attributsTab[2] = "   Nick Name: ";
    _attributsTab[3] = "Phone Number: ";
    _attributsTab[4] = " Dark Secret: ";
    
    _ptrSetFunc[0] = &Contact::setFirstName;
    _ptrSetFunc[1] = &Contact::setLastName;
    _ptrSetFunc[2] = &Contact::setNickName;
    _ptrSetFunc[3] = &Contact::setPhoneNumber;
    _ptrSetFunc[4] = &Contact::setDarkSecret;

    _ptrGetFunc[0] = &Contact::getFirstName;
    _ptrGetFunc[1] = &Contact::getLastName;
    _ptrGetFunc[2] = &Contact::getNickName;
    _ptrGetFunc[3] = &Contact::getPhoneNumber;
    _ptrGetFunc[4] = &Contact::getDarkSecret;
    
    return;
}

void    PhoneBook::initChoice( void ) {

    if ( cIn == "ADD" ) {

        choice = 1;
    }
    else if ( cIn == "SEARCH" ) {

        choice = 2;
    }
    else if ( cIn == "EXIT" ) {

        choice = 3;
    }
	cIn.clear();
    
}

void    PhoneBook::initContact( void ) {
    
    if (fillForm( &( _contactsTab[_contactId] ) ) == true ) {
        
        if ( _contactNb <= 7 ) {

            _contactNb++;
        }
        _contactId++;
        if ( _contactId == 8 ) {

            _contactId = 0;
        }
        return;
    }
    
}

bool    PhoneBook::fillForm( Contact *ptr ) {

    std::string tmp;

    for ( int i = 0; i < 5; i++ ) {

        std::cout << B_GRAY << _attributsTab[i] << B_CYAN;
        std::getline( std::cin, tmp );
        ( ptr->*_ptrSetFunc[i] )( tmp );
        tmp.clear();
        if ( errorEof( tmp ) == true ) {
            return false;
        }
    }

    return true;
}

void    PhoneBook::setContactToPrint( Contact *ptr ) {

    size_t len;

    for ( int i = 0; i < 3; i++ ) {

        _buffToPrint[i] = ( ptr->*_ptrGetFunc[i] )();
    }

    for ( int i = 0; i < 3; i++ ) {

        len = _buffToPrint[i].size();
    
        if ( len > 10 ) {
            _buffToPrint[i].replace( 9, 1, "." );
            _buffToPrint[i] = _buffToPrint[i].substr( 0, 10 );
        }
    }
}

void    PhoneBook::searchContact( void ) {

    if ( _contactNb == 0 ) {
        std::cout << RED << "Empty PhoneBook..." << RESET << std::endl;
        return;
    }
    
    std::cout << B_GRAY << "\n|";
    std::cout << B_BLUE << std::right << std::setw(10) << "Index" << B_GRAY << "|";
    std::cout << B_BLUE << std::right << std::setw(10) << "First Name" << B_GRAY << "|";
    std::cout << B_BLUE << std::right << std::setw(10) << "Last Name" << B_GRAY << "|";
    std::cout << B_BLUE << std::right << std::setw(10) << "Nick Name" << B_GRAY << "|" << std::endl;

    for ( int i = 0; i < _contactNb; i++ ) {

        std::cout << "|" << YELLOW << std::right << std::setw(10) << i+1 << B_GRAY << "|";
        setContactToPrint( &_contactsTab[i] );
        std::cout << YELLOW << std::right << std::setw(10) << _buffToPrint[0] << B_GRAY << "|";
        std::cout << YELLOW << std::right << std::setw(10) << _buffToPrint[1] << B_GRAY << "|";
        std::cout << YELLOW << std::right << std::setw(10) << _buffToPrint[2] << B_GRAY << "|" << std::endl;
    }
    std::cout << std::endl << RESET;
    this->printContact();

    return;
}

void    PhoneBook::printContact( void ) {

    int choice;
    std::string input;

    while ( true ) {

        while ( true ) {
            
            std::cout << GREEN << "Enter the contact number you want to see or 0 to go back " << B_BLUE;
            
            std::getline(std::cin, input);

            if (errorEof( input ) == true ) {
                
                continue;
            }
            
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
        if ( choice >= 0 && choice < _contactNb ) {
            
            for ( int i = 0; i < 5; i++ ) {

                std::cout << B_GRAY << _attributsTab[i] << YELLOW << ( _contactsTab[choice].*_ptrGetFunc[i] )() << std::endl;
            }
        }
        else
            std::cout << RED << "Invalid input." << RESET << std::endl;
    }
}

bool    PhoneBook::errorEof( std::string& str ) {

    if ( std::cin.eof() ) {

        str.clear();
        std::cin.clear();
        std::clearerr( stdin );
        std::cout << RED << "\nInvalid input." << RESET << std::endl;
        return true;
    }
    return false;
}
