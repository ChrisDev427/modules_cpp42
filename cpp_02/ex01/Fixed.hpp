/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:30:24 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 14:36:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>
# include <limits.h>

#define RESET   "\033[0m"
#define RED     "\033[1;31m"
#define GREEN   "\033[32m"
#define B_GREEN   "\033[1;32m"
#define YELLOW  "\033[33m"
#define B_BLUE    "\033[1;34m"
#define BLUE    "\033[34m"
#define CYAN    "\033[36m"
#define B_CYAN    "\033[1;36m"
#define MAGENTA "\033[35m"
#define BOLDWHITE "\033[1;37m"
#define B_GRAY "\033[1;30m"

class Fixed {

public:

    Fixed( void );
    Fixed( int const n );
    Fixed( float const n );
    
    Fixed( Fixed const & src );
    ~Fixed( void ); virtual

    Fixed & operator=( Fixed const & rhs );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw ) ;

    float   toFloat( void ) const;
    int     toInt( void ) const;

private:

    int long            _integer;
    static int const    _fractional;

};

std::ostream & operator<<( std::ostream & o, Fixed const & i );

#endif /********************************************************************  FIXED_HPP  */