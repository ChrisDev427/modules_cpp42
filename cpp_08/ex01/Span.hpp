/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 12:02:12 by chris             #+#    #+#             */
/*   Updated: 2023/09/08 18:27:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SPAN_HPP
# define SPAN_HPP

# include <iostream>
# include <vector>
# include <stdexcept>
# include <climits>
# include <algorithm>
# include "policeColor.hpp"


class Span {

private:
    unsigned int const  _n;
    std::vector<int>    _array;

    Span( void );
public:

    Span( unsigned int n );
    Span( Span const & src );
    ~Span( void ); virtual

    Span & operator=( Span const & rhs );

    void addNumber( int value );
    void addSequence( unsigned int n );
    int long longestSpan( void );
    int long shortestSpan( void );

    void arrayCheck( void );
    void clearArray( void );

    void print( std::string instName );


};

#endif /************************************************************* SPAN_HPP*/