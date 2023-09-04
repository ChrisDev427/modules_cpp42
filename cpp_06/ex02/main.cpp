/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 13:14:45 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 12:34:43 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "policeColor.hpp"

int main ( void ) {

    std::srand((std::time(0)));

    Base* ptr = NULL;
    ptr = generate();
    std::cout << B_ORANGE << "ptr after generate function  = " << ptr << RESET << std::endl << std::endl;
    identify(ptr);
    identify(*ptr);
   
    delete ptr;
    // system("leaks prog");
    return 0;
}