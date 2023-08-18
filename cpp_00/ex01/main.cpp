/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/17 19:04:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Phonebook.hpp"
#include <cstdlib>

static void printTitle(void) {
    
    system("clear");
    std::cout << B_CYAN << "\n\n   ****************************" << std::endl;
    std::cout << "   *** Welcome To PhoneBook ***" << std::endl;
    std::cout << "   ****************************\n\n" << RESET << std::endl;
    
}

int main( int ac, char **av ) {

    ( void )av;
    PhoneBook   book;
    printTitle();
    
    if ( ac == 1 ){


        while ( true ) {

            while ( true ) {

                std::cout << B_CYAN << "\nEnter 'ADD', 'SEARCH' or 'EXIT' : " << RESET << GREEN;
                
                std::getline( std::cin, book.cIn );
                if ( book.errorEof( book.cIn ) == true ) {
                
                    continue;
                }
                if ( book.cIn != "ADD" && book.cIn != "SEARCH" && book.cIn != "EXIT" )
                    std::cout << RED << "Invalid choice !" << RESET << std::endl;
                else
                    break;
            }
            
            book.initChoice();
           
            switch ( book.choice )
            {
                
            case 1:
                book.initContact();
                break;
            case 2:
                book.searchContact ();
                break;
            case 3:
                system( "clear" );
                std::cout << B_BLUE << "\n  *** PhoneBook is turning off ! ***\n" << RESET <<std::endl;
                sleep( 1 );
                std::cout << B_BLUE << "        *** Goodbye Bro ***\n" << RESET <<std::endl;
                sleep( 3 );
                system( "clear" );
                return 0;
            }
        }
    }
    else {

        std::cout << "Error: phonebook don't need any argument" << std::endl;
        return -1;
    }

    return 0;
}
