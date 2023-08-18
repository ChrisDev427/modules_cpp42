/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/16 12:31:31 by chris             #+#    #+#             */
/*   Updated: 2023/08/17 19:35:11 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"

std::string Contact::getFirstName( void ) { return _firstName; }

std::string Contact::getLastName( void ) { return _lastName; }

std::string Contact::getNickName( void ) { return _nickName; }

std::string Contact::getPhoneNumber( void ) { return _phoneNumber; }

std::string Contact::getDarkSecret( void ) { return _darkSecret; }

void Contact::setFirstName( std::string str ) { _firstName = str; }

void Contact::setLastName( std::string str ) { _lastName = str; }

void Contact::setNickName( std::string str ) { _nickName = str; }

void Contact::setPhoneNumber( std::string str ) { _phoneNumber = str; }

void Contact::setDarkSecret( std::string str ) { _darkSecret = str; }
