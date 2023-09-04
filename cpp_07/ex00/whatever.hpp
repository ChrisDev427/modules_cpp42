/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:29:35 by chris             #+#    #+#             */
/*   Updated: 2023/09/04 13:36:47 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef whatever_HPP
# define whatever_HPP

# include <iostream>

template< typename T >
void        swap( T & x, T & y ) {

    if ( x != y ) {

        T tmp = x;
        x = y;
        y = tmp;
    }
}

template< typename T >
T const &   min( T const & x, T const & y ) {

    return ( (x<y) ? x : y );
}

template< typename T >
T const &   max( T const & x, T const & y ) {

    return ( (x>y) ? x : y );
}

#endif /************************************************** whatever_HPP*/

