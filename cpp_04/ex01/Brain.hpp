/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:18 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 09:29:52 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>
# include "policeColor.hpp"


class Brain {

public:

    Brain( void );
    
    Brain( Brain const & src );
    virtual ~Brain( void );

    Brain & operator=( Brain const & rhs );

    std::string  *ideas[100];

};

#endif /************************************************* BRAIN_HPP */