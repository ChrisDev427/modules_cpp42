/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phonebook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/18 16:08:17 by chris             #+#    #+#             */
/*   Updated: 2023/07/19 18:08:10 by chris            ###   ########.fr       */
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

    char firstName[256];
    char lastName[256];
    char nickName[256];
    char phoneNumber[256];
    char darkSecret[256];

    
    static int  getNbInst(void);

private:

    static int  _nbInst;


    
};
class PhoneBook {

public:

    PhoneBook(void);
    ~PhoneBook(void);

    char    cIn[128];
    int     choice;
    Contact     *contactsTab[8];
    int     contactNb;



    void    initChoice(char *cIn);
    void    initContact(int contNb);
    void    fillForm(Contact *ptr);
    void    searchContact(void);
    // void    printContact(Contact *ptr);
    

private:

    
};
#endif