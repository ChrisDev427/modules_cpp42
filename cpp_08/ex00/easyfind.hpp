/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:17:09 by chris             #+#    #+#             */
/*   Updated: 2023/09/19 09:07:26 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <vector>
# include "policeColor.hpp"
# include <algorithm>

template< typename T >
void easyfind( T array, int value ) {

    typename T::iterator it;
    
    it = find ( array.begin(), array.end(), value );
    if ( it == array.end() )
        throw std::invalid_argument (RED "value not found" RESET);
    else
        std::cout << B_CYAN << "First occurence of value[" << value << "] is " << std::distance(array.begin(), it ) << RESET << std::endl;
}
#endif /*********************************************************** EASYFIND_HPP */
