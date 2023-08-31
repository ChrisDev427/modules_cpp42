/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:10:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef AMATERIA_HPP
# define AMATERIA_HPP
# include "ICharacter.hpp"
# include <iostream>
# include <string>
# include "policeColor.hpp"

class ICharacter;

class AMateria {

public:

    AMateria( void );
    AMateria( std::string const & type );
    
    AMateria( AMateria const & src );
    virtual ~AMateria( void );

    AMateria & operator=( AMateria const & rhs );


    std::string const & getType() const;
    virtual AMateria* clone() const = 0;
    virtual void use(ICharacter& target);

    bool                getEquiped( void ) const;
    void                setEquiped( bool param );

protected:

    bool        equiped;
    std::string type;

};

#endif /************************************************* AMATERIA_HPP */