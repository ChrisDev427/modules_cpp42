/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 14:30:24 by chris             #+#    #+#             */
/*   Updated: 2023/07/31 14:51:05 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>

class Fixed {

public:

    Fixed( void );
    
    Fixed( Fixed const & src );
    ~Fixed( void ); virtual

    Fixed & operator=( Fixed const & rhs );

    int     getRawBits( void ) const;
    void    setRawBits( int const raw ) ;

private:

    int                _integer;
    static const int   _fractional;

};

#endif /*FIXED_HPP*/