/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:03:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/25 12:01:13 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
# include <iomanip>
# include <sstream>
# include <string>
# include "policeColor.hpp"

class Character : virtual public ICharacter {

public:

    Character( void );
    Character( std::string const & name );
    
    Character( Character const & src );
    virtual ~Character( void );

    Character & operator=( Character const & rhs );

    virtual std::string const & getName() const;
    virtual void equip(AMateria* m);
    virtual void unequip(int idx);
    virtual void use(int idx, ICharacter& target);

    virtual void    printInventory( void ) const;

    static void     printMatToFree( void );

private:

    int             _throwedNb;
    AMateria*      _inventory[4];
    std::string     _name;

    void _saveMatToFree( AMateria* toSave );
    void _delMatThrowedTab( AMateria* unSave );
    
    static int             _instanceCopy;
    static int             _throwedInMemory;
    static AMateria**      _throwedMaterias;
    static AMateria**      _throwedTmp;
    
};

#endif /****************************** CHARACTER_HPP */
