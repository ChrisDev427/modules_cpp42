/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 08:27:35 by chris             #+#    #+#             */
/*   Updated: 2023/09/05 08:15:16 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZER_HPP
# define SERIALIZER_HPP

# include <iostream>
# include "Data.hpp"

class Serializer {

private:
    Serializer( void );
    Serializer( Serializer const & src );
    ~Serializer( void );
    Serializer & operator=( Serializer const & rhs );
public:
    static uintptr_t    serialize( Data* ptr );
    static Data*        deserialize( uintptr_t raw );
};

#endif /************************************************** SERIALIZER_HPP*/