/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:11 by chris             #+#    #+#             */
/*   Updated: 2023/07/20 18:15:02 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "phonebook.hpp"

int main(int ac, char **av)
{
    (void)av;
    PhoneBook   book;
    if (ac == 1){

        std::cout << "\n*** Welcome to PhoneBook ***\n" << std::endl;
        while (1) {

            std::cout << "Enter 'ADD', 'SEARCH' or 'EXIT' : ";
            std::cin >> book.cIn;
            book.initChoice(book.cIn);
            switch (book.choice)
            {
            case 1:
                book.initContact(&book, book.contactNb);
                
                break;
            case 2:
                book.searchContact(&book);
                break;
            case 3:
                std::cout << "Goodbye Bro\n" << std::endl;
                exit (0);
                break;
            default:
                std::cout << "Invalid choice !" << std::endl;
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