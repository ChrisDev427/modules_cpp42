/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:11 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 11:51:51 by chris            ###   ########.fr       */
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

		if (std::cin.eof())
			exit (1);
            
            std::cout << B_CYAN << "Enter 'ADD', 'SEARCH' or 'EXIT' : " << GREEN;
            std::getline( std::cin, book.cIn );

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
                exit ( 0 );
                break;
            default:
                std::cout << RED << "Invalid choice !" << RESET << std::endl;
                break;
            }
        }
    }
    else {

        std::cout << "Error: phonebook don't need any argument" << std::endl;
        return -1;
    }

    return 0;
}
