/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:17 by chris             #+#    #+#             */
/*   Updated: 2023/07/21 16:57:09 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <vector>
# include <sstream>
# include <cstring>
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

class Contact {

public:

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkSecret;

};

class PhoneBook {

public:

    PhoneBook(void);
    ~PhoneBook(void);

    
    std::string cIn;
    int         choice;
    Contact     contactsTab[8];
    int         contactNb;
    int         contactId;


    void    initChoice(void);
    void    initContact(void);
    void    searchContact(PhoneBook *ptr);

private:

    void    fillForm(Contact *ptr);
    void    setContactToPrint(Contact *ptr);
    void    printContact(void);

    std::string _buffToPrint[3];

};
#endif