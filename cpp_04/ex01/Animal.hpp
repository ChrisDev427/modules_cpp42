/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:04:33 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>
# include "policeColor.hpp"

class Animal {

public:

    Animal( void );
    
    Animal( Animal const & src );
    virtual ~Animal( void );

    Animal & operator=( Animal const & rhs );

    virtual std::string getType( void ) const;

    virtual void makeSound() const;
    virtual void setPtr( std::string str ) const;
    virtual void printArray( void ) const;

protected:

    std::string type;

};

#endif /************************************************* ANIMAL_HPP */