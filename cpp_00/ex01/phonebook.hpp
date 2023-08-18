/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:17 by chris             #+#    #+#             */
/*   Updated: 2023/08/18 07:18:50 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include "Contact.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include <unistd.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define B_GREEN   "\033[1;32m"
#define YELLOW  "\033[33m"
#define B_BLUE    "\033[1;34m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define B_CYAN    "\033[1;36m"
#define MAGENTA "\033[35m"
#define BOLDWHITE "\033[1;37m"
#define B_GRAY "\033[1;30m"

class PhoneBook {

public:

    PhoneBook(void);

    std::string cIn;
    int         choice;

    void    initChoice(void);
    void    initContact(void);
    void    searchContact(void);
    bool    errorEof( std::string& str );

private:

    void        ( Contact::*_ptrSetFunc[5] )( std::string str );
    std::string ( Contact::*_ptrGetFunc[5] )( void );
    int         _contactNb;
    int         _contactId;

    bool    fillForm(Contact *ptr);
    void    setContactToPrint(Contact *ptr);
    void    printContact(void);

    std::string _buffToPrint[3];
    Contact     _contactsTab[8];
    std::string _attributsTab[5];

};
#endif /******************************************************* PHONEBOOK_HPP */