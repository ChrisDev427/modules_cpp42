/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ICharacter.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:00:56 by chris             #+#    #+#             */
/*   Updated: 2023/08/23 19:04:45 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICHARACTER_HPP
# define ICHARACTER_HPP

# include "AMateria.hpp"
# include <iostream>
# include <string>
# include "policeColor.hpp"

class AMateria;



class ICharacter
{

public:

    // virtual ~ICharacter() {}
    virtual std::string const & getName() const = 0;
    virtual void equip(AMateria* m) = 0;
    virtual void unequip(int idx) = 0;
    virtual void use(int idx, ICharacter& target) = 0;


    virtual void printInventory( void ) const = 0;
    // virtual void printMatToFree( void ) const = 0;
    // virtual int getInstNb( void ) = 0;



};

// static int instanceNb = 0;


#endif /*************************** ICHARACTER_HPP */