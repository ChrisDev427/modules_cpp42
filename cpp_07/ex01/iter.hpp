/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 11:29:35 by chris             #+#    #+#             */
/*   Updated: 2023/09/11 11:51:07 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef iter_HPP
# define iter_HPP

# include <iostream>

template< typename T, typename U >
void iter ( T tab[], size_t size, U func ) {

    for ( size_t i = 0; i < size; i++ ) {
        func(tab[i]);
    }

}

template< typename T >
void print( T & value ) {

    std::cout << "[" << value << "]" << std::endl;
    
}

#endif /************************************************** iter_HPP*/

