/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 14:31:27 by chris             #+#    #+#             */
/*   Updated: 2023/07/25 16:30:15 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.hpp"
#include "FileCopy.hpp"

void    error(std::string  const s1, const char *s2) {

    std::cout << "Error: ";
    std::cout << s1 << " ";
    if ( s2 )
        std::cout << s2;
    std::cout << std::endl;
    exit (EXIT_FAILURE); 
}
