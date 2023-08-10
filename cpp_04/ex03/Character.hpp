/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:03:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/10 18:07:34 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
# define CHARACTER_HPP

# include "ICharacter.hpp"
# include "AMateria.hpp"
# include <iostream>
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

    virtual void printInventory( void ) const;

    
private:

   
    
    int         _throwedNb;
    int         _throwedInMemory;
    AMateria**  _inventory;
   
    AMateria**   _throwedMaterias;
    AMateria**   _throwedTmp;
    std::string _name;

    void _saveMatToFree( AMateria* toFree );
    void _dupThrowedTab( AMateria**  & dst, AMateria** & src );
    bool _checkDblPtr( AMateria** tab, AMateria* src ) const;

    
};


#endif /****************************** CHARACTER_HPP */
