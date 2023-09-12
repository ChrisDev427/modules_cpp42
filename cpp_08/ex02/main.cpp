/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 14:04:22 by chris             #+#    #+#             */
/*   Updated: 2023/09/11 07:42:01 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "MutantStack.hpp"

int main( void )
{
    // MutantStack<int> mstack;

    // mstack.push(5);
    // mstack.push(17);
    // std::cout << "top = " << mstack.top() << std::endl;
    // std::cout << "size = " << mstack.size() << std::endl;

    // mstack.pop();
    // std::cout << "size = " << mstack.size() << std::endl;
    
    // mstack.push(3); 
    // mstack.push(5); 
    // mstack.push(737);
    // std::cout << "top = " << mstack.top() << std::endl;
    // std::cout << "size = " << mstack.size() << std::endl;

    // MutantStack<int>::iterator it = mstack.begin(); 
    // MutantStack<int>::iterator ite = mstack.end();
    // ++it;
    // --it;
    // while (it != ite) {

    //     std::cout << *it << std::endl;
    //     ++it; 
    // }

    std::list<int> mstack;

    mstack.push_back(5);
    mstack.push_back(17);
    std::cout << "top = " << *mstack.begin() << std::endl;
    std::cout << "size = " << mstack.size() << std::endl;

    mstack.pop_back();
    std::cout << "size = " << mstack.size() << std::endl;
    
    mstack.push_back(3); 
    mstack.push_back(5); 
    mstack.push_front(737);
    std::cout << "top = " << *mstack.begin() << std::endl;
    std::cout << "size = " << mstack.size() << std::endl;

    std::list<int>::iterator it = mstack.begin(); 
    std::list<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {

        std::cout << *it << std::endl;
        ++it; 
    }
    
    // system("leaks prog");
    return 0;
}