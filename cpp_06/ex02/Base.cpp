/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:53:32 by chris             #+#    #+#             */
/*   Updated: 2023/09/02 11:18:19 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base::~Base( void ) {}

Base * generate(void) {

    std::cout << B_BLUE "***** Generate function ********************" RESET << std::endl;;

    Base* ptr;

    int randomIndex = std::rand() % 3;
    std::cout << B_GRAY <<  "randomIndex = " << randomIndex << RESET << std::endl;
    switch ( randomIndex )
    {
    case 0:
        ptr = new A();
        std::cout << B_GRAY "Creating new object 'A' -> " << ptr << RESET << std::endl;
        break;
    case 1:
        ptr = new B();
        std::cout << B_GRAY "Creating new object 'B' -> " << ptr << RESET << std::endl;
        break;
    case 2:
        ptr = new C();
        std::cout << B_GRAY "Creating new object 'C' -> " << ptr << RESET << std::endl;
        break;
    }
    std::cout << B_BLUE "********************************************\n" RESET << std::endl;;
    return ptr;
}

void   identify(Base* p) {

    std::cout << B_BLUE << "***** Identify ptr* function ***************" RESET << std::endl;

    if (dynamic_cast<A*>(p) != NULL) {
        std::cout << B_GREEN << "Base* p is type = A" << RESET << std::endl;
    }
    else if (dynamic_cast<B*>(p) != NULL) {
        std::cout << B_GREEN << "Base* p is type = B" << RESET << std::endl;
    } 
    else if (dynamic_cast<C*>(p) != NULL) {
        std::cout << B_GREEN << "Base* p is type = C" << RESET << std::endl;
    }
    std::cout << B_BLUE << "********************************************\n" RESET << std::endl;
}

void   identify(Base& p) {

    std::cout << B_BLUE << "***** Identify ref& function ***************" RESET << std::endl;

    try { 
        
        A& classA = dynamic_cast<A&>(p);
        (void)classA;
        std::cout << B_GREEN << "Base& p is type = A" << RESET << std::endl;
    }
    catch ( std::bad_cast& bc ) {}
    try { 
        
        B& classB = dynamic_cast<B&>(p);
        (void)classB;
        std::cout << B_GREEN << "Base& p is type = B" << RESET << std::endl;
    }
    catch ( std::bad_cast& bc ) {}
    try { 
        
        C& classC = dynamic_cast<C&>(p);
        (void)classC;
        std::cout << B_GREEN << "Base& p is type = C" << RESET << std::endl;
    }
    catch ( std::bad_cast& bc ) {}

    std::cout << B_BLUE << "********************************************\n" RESET << std::endl;
}