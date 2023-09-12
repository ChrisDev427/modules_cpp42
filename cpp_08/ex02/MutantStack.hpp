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
# include <list>
# include <deque>
# include "policeColor.hpp"

template <typename T>
class MutantStack : public std::stack<T>
{
    public:
        MutantStack() : std::stack<T>() {}
        MutantStack(MutantStack const & src) : std::stack<T>(src) {}
        virtual ~MutantStack() {}

        typedef typename std::deque<T>::iterator iterator;
        iterator begin()
        {
            return this->c.begin();
        }

        iterator end()
        {
            return this->c.end();
        }

};

// template< typename T >
// class MutantStack {

//     public:
    
//         class iterator {
//         public:
//             iterator(typename std::stack<T>::container_type::iterator it) : it(it) {}

//             // Implémenter les méthodes d'itérateur nécessaires
//             iterator& operator++() { ++it; return *this; }
//             iterator& operator--() { --it; return *this; }
//             T& operator*() { return *it; }
//             bool operator==(const iterator& other) const { return it == other.it; }
//             bool operator!=(const iterator& other) const { return it != other.it; }

//         private:
//             typename std::stack<T>::container_type::iterator it;
//         };

//     MutantStack( void ) {}
//     MutantStack( MutantStack const & src ) : stk(src.stk) {}
//     ~MutantStack( void ) {}
//     MutantStack & operator=( MutantStack const & rhs ) {
//         if (this != &rhs) {
//             stk = rhs.stk;  
//         }
//         return *this;
//     }

//     // Définir les méthodes begin() et end() pour créer des itérateurs
//     iterator begin() { return stk.top(); }
//     iterator end() { return iterator(stk.end()); }

//     void    push( T const & n ) { stk.push( n ); }
//     void    pop( void ) { stk.pop(); }
//     T       top( void ) { return stk.top(); }
//     size_t  size( void ) { return stk.size(); }

//     std::stack< T >    stk;
    

    


// };


#endif /****************************************************** MUTANTSTACK_HPP*/