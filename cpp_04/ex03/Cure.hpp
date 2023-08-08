/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:10:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CURE_HPP
# define CURE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>
# include <string>
# include "policeColor.hpp"

// class AMateria;
class ICharacter;


class Cure : virtual public AMateria {

public:

    Cure( void );
    // Cure( std::string const & type );
    
    Cure( Cure const & src );
    virtual ~Cure( void );

    Cure & operator=( Cure const & rhs );


    std::string const & getType() const;
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);

};

#endif /************************************************* CURE_HPP */