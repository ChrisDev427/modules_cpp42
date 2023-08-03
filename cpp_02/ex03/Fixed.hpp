/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:30:24 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 14:55:17 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <limits.h>

# define RESET   "\033[0m"
# define RED     "\033[1;31m"
# define GREEN   "\033[32m"
# define B_GREEN   "\033[1;32m"
# define YELLOW  "\033[33m"
# define B_YELLOW  "\033[1;33m"
# define B_BLUE    "\033[1;34m"
# define BLUE    "\033[34m"
# define CYAN    "\033[36m"
# define B_CYAN    "\033[1;36m"
# define MAGENTA "\033[35m"
# define B_MAGENTA "\033[1;35m"
# define BOLDWHITE "\033[1;37m"
# define B_GRAY "\033[1;30m"

class Fixed {

public:

//********* CONSTRUCT/DESTRUCT ************************************************

    Fixed( void );
    Fixed( int const n );
    Fixed( float const n );
    Fixed( Fixed const & src );
    ~Fixed( void ); virtual

//********* ASSIGNATION OVERLOAD **********************************************

    Fixed & operator=( Fixed const & rhs );

//********* COMPARISON OVERLOAD ***********************************************

    int     operator>( Fixed const & rhs ) const;
    int     operator<( Fixed const & rhs ) const;
    int     operator>=( Fixed const & rhs ) const;
    int     operator<=( Fixed const & rhs ) const;
    int     operator==( Fixed const & rhs ) const;
    int     operator!=( Fixed const & rhs ) const;

//********* ARITHMETIC OVERLOAD ***********************************************
    
    Fixed   operator+( Fixed const & rhs ) const;
    Fixed   operator-( Fixed const & rhs ) const;
    Fixed   operator*( Fixed const & rhs ) const;
    Fixed   operator/( Fixed const & rhs ) const;

//********* INCREMENT/DECREMENT OVERLOAD **************************************
    Fixed & operator++( void );
    Fixed   operator++( int );
    Fixed & operator--( void );
    Fixed   operator--( int );

//********* ACCESSORS *********************************************************

    int     getRawBits( void ) const;
    void    setRawBits( int const raw ) ;

//********* MEMBERS FUNCTIONS *************************************************

    float   toFloat( void ) const;
    int     toInt( void ) const;

//********* STATIC MEMBERS FUNCTIONS ******************************************

    static float min( Fixed & a, Fixed & b );
    static float min( Fixed const & a, Fixed const & b );
    static float max( Fixed & a, Fixed & b );
    static float max( Fixed const & a, Fixed const & b );
    
//*****************************************************************************

private:

    int long            _integer;
    static int const    _fractional;

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif /********************************************************************  FIXED_HPP  */