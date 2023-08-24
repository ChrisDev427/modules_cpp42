/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:10:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ICE_HPP
# define ICE_HPP

# include "AMateria.hpp"
# include "ICharacter.hpp"
# include <iostream>
# include <string>
# include "policeColor.hpp"

// class AMateria;
class ICharacter;



class Ice : virtual public AMateria {

public:

    Ice( void );
    // Ice( std::string const & type );
    
    Ice( Ice const & src );
    virtual ~Ice( void );

    Ice & operator=( Ice const & rhs );


    std::string const & getType() const;
    virtual AMateria* clone() const;
    virtual void use(ICharacter& target);


};

#endif /************************************************* ICE_HPP */