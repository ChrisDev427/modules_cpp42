/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 13:28:09 by chris             #+#    #+#             */
/*   Updated: 2023/07/20 14:32:31 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "phonebook.hpp"

Contact::Contact(void) {


    Contact::_nbInst += 1;


    return;

}

Contact::~Contact(void) {

    Contact::_nbInst -= 1;


    return;
    
}

int Contact::getNbInst(void) {

    return Contact::_nbInst;
}

int Contact::_nbInst = 0;


