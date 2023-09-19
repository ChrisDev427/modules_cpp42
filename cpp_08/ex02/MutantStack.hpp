/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/08 18:27:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
# define MUTANTSTACK_HPP

# include <iostream>
# include <stack>
# include <deque>
# include <list>
# include "policeColor.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() { std::cout << GREEN "Default constructor called" << RESET << std::endl; }
        MutantStack(MutantStack const & src) : std::stack<T>(src) {
            std::cout << GREEN "Copy constructor called" << RESET << std::endl;
        }
        MutantStack & operator=(MutantStack const & rhs) { 
            std::cout << GREEN "Assign operator called" << RESET << std::endl;
            std::stack<T>::operator=(rhs);
            return *this;
        }
        virtual ~MutantStack() {}

        typedef typename std::deque<T>::iterator iterator;
        iterator begin() {
            return this->c.begin();
        }

        iterator end() {
            return this->c.end();
        }
};

#endif /****************************************************** MUTANTSTACK_HPP*/