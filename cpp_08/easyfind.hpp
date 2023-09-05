/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/04 18:17:09 by chris             #+#    #+#             */
/*   Updated: 2023/09/05 19:51:34 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
# define EASYFIND_HPP

# include <iostream>
# include <stdexcept>
# include <algorithm>
# include "policeColor.hpp"

template< typename T >

void easyfind( T array, int value ) {

    std::vector<int>::iterator it;

    it = find (array.begin(), array.end(), value);
    if (it == array.end())
        throw std::invalid_argument ("value not found");
    else
        std::cout << "First occurence of " << value << " is " << std::distance(array.begin(), it ) << std::endl;
    
}

#endif /*********************************************************** EASYFIND_HPP */
