/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:17:09 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 19:55:10 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>

template< typename T >

class Array {

    public:

        Array( void ) : _size( 0 ), _array(new T[0]) {};
        Array( unsigned int n ) : _size( n ), _array ( new T[n] ) {
            
            for ( size_t i = 0; i < _size; i++ ) { 
                _array[i] = *new T();
            }
        };
        Array( Array const & src ) {

            _size = src._size;
            _array = new T[_size];

            for ( size_t i = 0; i < _size; i++ ) {
                
                _array[i] = new T(src._array[i]);
            }

        };
        ~Array() {};

        Array & operator=( Array const & rhs ) {
            
            _size = rhs._size;
            _array = new T[_size];

            for ( size_t i = 0; i < _size; i++ ) {
                
                _array[i] = new T(rhs._array[i]);
            }
            return *this;
        };

        size_t size( void ) { return _size; }


    private:
        size_t _size;
        T*     _array;
};


#endif /*********************************************************** ARRAY_HPP */

