/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:17 by chris             #+#    #+#             */
/*   Updated: 2023/07/20 18:15:23 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP
# include <iostream>
# include <vector>
# include <sstream>
# include <cstring>
# include <string>

# define ADD "ADD"
# define SEARCH "SEARCH"
# define EXIT "EXIT"


class Contact {

public:

    Contact(void);
    ~Contact(void);

    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkSecret;
    
    static int  getNbInst(void);

private:

    static int  _nbInst;


    
};
class PhoneBook {

public:

    PhoneBook(void);
    ~PhoneBook(void);

    char        cIn[128];
    int         choice;
    Contact     contactsTab[8];
    int         contactNb;



    void    initChoice(char *cIn);
    void    initContact(PhoneBook *ptr, int contNb);
    void    fillForm(Contact *ptr);
    void    searchContact(PhoneBook *ptr);
    // void    printContact(Contact *ptr);
    

private:


    void    setContactToPrint(Contact *ptr);
    std::string _buffToPrint[3];

    
};
#endif