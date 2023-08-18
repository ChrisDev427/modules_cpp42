/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 17:53:14 by chris             #+#    #+#             */
/*   Updated: 2023/08/17 19:33:43 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP
# include <string>


class Contact {

public:

    std::string getFirstName( void );
    std::string getLastName( void );
    std::string getNickName( void );
    std::string getPhoneNumber( void );
    std::string getDarkSecret( void );

    void        setFirstName( std::string str );
    void        setLastName( std::string str );
    void        setNickName( std::string str );
    void        setPhoneNumber( std::string str );
    void        setDarkSecret( std::string str );

private:

    std::string _firstName;
    std::string _lastName;
    std::string _nickName;
    std::string _phoneNumber;
    std::string _darkSecret;

};

#endif /******************************************************* CONTACT_HPP */
