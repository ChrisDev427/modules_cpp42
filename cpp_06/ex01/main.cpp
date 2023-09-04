/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:14:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 11:03:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include "policeColor.hpp"

int main ( void ) {

    Data* dataPtrSend = new Data();

    dataPtrSend->c = 'A';
    dataPtrSend->i = 42;
    dataPtrSend->f = 21.89f;
    dataPtrSend->d = 42.56;

    std::cout << B_GRAY << "dataPtrSend address =   " << B_BLUE << dataPtrSend << std::endl;
    std::cout << B_GRAY << "dataPtrSend c =         " << dataPtrSend->c << std::endl;
    std::cout << B_GRAY << "dataPtrSend i =         " << dataPtrSend->i << std::endl;
    std::cout << B_GRAY << "dataPtrSend f =         " << dataPtrSend->f << std::endl;
    std::cout << B_GRAY << "dataPtrSend d =         " << dataPtrSend->d << std::endl;
    
    uintptr_t uintPtr = Serializer::serialize( dataPtrSend );
    Data* dataPtrReturn = Serializer::deserialize( uintPtr );
    std::cout << B_BLUE << "\n********************************************************************************\n" << RESET << std::endl;
    
    std::cout << B_GRAY << "dataPtrReturn address = " << B_BLUE << dataPtrReturn << std::endl;
    std::cout << B_GRAY << "dataPtrReturn c       = " << dataPtrReturn->c << std::endl;
    std::cout << B_GRAY << "dataPtrReturn i       = " << dataPtrReturn->i << std::endl;
    std::cout << B_GRAY << "dataPtrReturn f       = " << dataPtrReturn->f << std::endl;
    std::cout << B_GRAY << "dataPtrReturn d       = " << dataPtrReturn->d << std::endl;

    delete dataPtrSend;

    // system("leaks prog");
    return 0;
}