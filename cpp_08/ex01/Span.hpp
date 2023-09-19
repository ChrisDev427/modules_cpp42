/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 09:39:39 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <deque>
# include <stdexcept>
# include <climits>
# include <algorithm>
# include "policeColor.hpp"

class Span {

private:
    Span( void );
    unsigned int const  _n;
    std::vector<int>    _array;
public:

    Span( unsigned int n );
    Span( Span const & src );
    ~Span( void ); virtual
    Span & operator=( Span const & rhs );

    void        addNumber( int value );
    int long    longestSpan( void ) const;
    int long    shortestSpan( void ) const;
    void        arrayCheck( void ) const;
    void        arrayClear( void );
    size_t      arraySize( void ) const;
    void        print( std::string instName ) const;
    
    template< typename T >
    void addSequence( T it, T ite ) {

        std::vector<int>::iterator start = _array.end();
        size_t sizeLeft = _n - _array.size();
        size_t sizeToAdd = ite - it;
    
        if ( sizeToAdd > sizeLeft ) { throw std::logic_error( RED "Error: addSequence: overflow" RESET ); }
        else { _array.insert( start,  it, ite ); }
    }
};

#endif /************************************************************* SPAN_HPP*/