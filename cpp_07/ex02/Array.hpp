/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:17:09 by chris             #+#    #+#             */
/*   Updated: 2023/09/05 14:12:48 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <stdexcept>
# include "policeColor.hpp"

template< typename T >
class Array {

    private:
        size_t _size;
        T*     _array;
    public:

        Array( void ) : _size( 0 ), _array(new T[0]) { std::cout << GREEN << "Default constructor called" << RESET << std::endl; };
        Array( unsigned int n ) : _size( n ), _array ( new T[n] ) { std::cout << GREEN << "Parametric constructor called" << RESET << std::endl; }
        Array( Array const & src ) {
            
            std::cout << GREEN << "Copy constructor called" << RESET << std::endl;

            _size = src._size;
            _array = new T[_size];
            for ( size_t i = 0; i < _size; i++ ) {
                
                _array[i] = src._array[i];
            }
        }

        ~Array() { 
            
            std::cout << GREEN << "Destructor called" << RESET << std::endl;
            delete[] _array;
        }

        Array & operator=( Array const & rhs ) {

            std::cout << GREEN << "Assignment operator called" << RESET << std::endl;
            if ( this != &rhs ) {
    
                delete[] _array;
                _size = rhs._size;
                _array = new T[_size];
    
                for ( size_t i = 0; i < _size; i++ ) {
                    
                    _array[i] = rhs._array[i];
                }
            }
            return *this;
        }

        T & operator[]( size_t i ) {

            std::cout << GREEN << "Access operator called" << RESET << std::endl;
            if ( i >= 0 && i < _size ) {
                return _array[i];
            }
            else {
                throw std::out_of_range (RED "Exception: Error: invalid indice" RESET);
            }
        }

        size_t size( void ) { return _size; }

        void print( void ) {
            for ( size_t i = 0; i < _size; i++ ) {
                std::cout << B_GRAY << "array [" << i << "] = ["<< _array[i] << "]" << RESET << std::endl;
            }
        }
};

#endif /*********************************************************** ARRAY_HPP */
