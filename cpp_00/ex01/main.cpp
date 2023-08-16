/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:11 by chris             #+#    #+#             */
/*   Updated: 2023/08/16 07:59:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

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

        while ( 1 ) {

            while ( true ) {

                std::cout << B_CYAN << "\nEnter 'ADD', 'SEARCH' or 'EXIT' : " << RESET;
                std::getline( std::cin, book.cIn );
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
                std::cout << GREEN << "\n       *** Goodbye Bro ***\n" << RESET <<std::endl;
                sleep( 2 );
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
