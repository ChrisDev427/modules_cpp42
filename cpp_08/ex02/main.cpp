/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 09:45:50 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

void stackTest( void ) {

    MutantStack<int> mstack;

    mstack.push(5);
    mstack.push(17);
    std::cout << B_BLUE << "size = " << mstack.size() << RESET << std::endl;
    std::cout << B_YELLOW << "top =  " << mstack.top() << RESET << std::endl;

    std::cout << std::endl;

    mstack.pop();
    std::cout << B_BLUE << "size = " << mstack.size() << RESET << std::endl;
    std::cout << B_YELLOW << "top =  " << mstack.top() << RESET << std::endl;
    
    std::cout << std::endl;
    
    mstack.push(3); 
    mstack.push(5); 
    mstack.push(737);
    std::cout << B_BLUE << "size = " << mstack.size() << RESET << std::endl;
    std::cout << B_YELLOW << "top =  " << mstack.top() << RESET << std::endl;

    std::cout << std::endl;
    
    MutantStack<int>::iterator it = mstack.begin(); 
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    std::cout << B_CYAN << "*** print stack ***" << RESET << std::endl;
    while (it != ite) {

        std::cout << B_GRAY << *it << RESET << std::endl;
        ++it; 
    }

    std::cout << B_BLUE "\nCopy from mstack to new std::stack<int> s(mstack);" << RESET << std::endl;
    std::stack<int> s(mstack);
    std::cout << B_YELLOW << "s.top() = " << s.top() << RESET << std::endl;

    std::cout << B_BLUE "Copy from mstack to new MutantStack<int> copy(mstack);" << RESET << std::endl;
    MutantStack<int> copy(mstack);
    std::cout << B_YELLOW << "copy.top() = " << copy.top() << RESET << std::endl;

    std::cout << B_BLUE "Assign from mstack to new MutantStack<int> assign(mstack);" << RESET << std::endl;
    MutantStack<int> assign;
    assign = mstack;
    std::cout << B_YELLOW << "assign.top() = " << assign.top() << RESET << std::endl;

}

void listTest( void ) {

    std::list<int> mlist;

    mlist.push_back(5);
    mlist.push_back(17);
    std::cout << B_BLUE << "size = " << mlist.size() << RESET << std::endl;
    std::cout << B_YELLOW << "top  = " << mlist.back() << RESET << std::endl;

    std::cout << std::endl;

    mlist.pop_back();
    std::cout << B_BLUE << "size = " << mlist.size() << RESET << std::endl;
    std::cout << B_YELLOW << "top  = " << mlist.back() << RESET << std::endl;

    std::cout << std::endl;
    
    mlist.push_back(3); 
    mlist.push_back(5); 
    mlist.push_back(737);
    std::cout << B_BLUE << "size = " << mlist.size() << RESET << std::endl;
    std::cout << B_YELLOW << "top  = " << mlist.back() << RESET << std::endl;
    
    std::cout << std::endl;

    std::list<int>::iterator it = mlist.begin(); 
    std::list<int>::iterator ite = mlist.end();
    ++it;
    --it;
    std::cout << B_CYAN << "*** print list ***" << RESET << std::endl;
    while (it != ite) {

        std::cout << B_GRAY << *it << RESET << std::endl;
        ++it; 
    }
}

int main( int ac, char** av ) {

    (void)av;
    if ( ac == 1 ) {

        stackTest();

        std::cout << B_GRAY "\n******************************************************************************************\n" << RESET << std::endl;
    
        listTest();
    }
    else {
        std::cerr << RED "Error: no args needed" << RESET << std::endl;
        return -1;
    }
    // system("leaks prog");
    return 0;
}