/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   A_Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:10:28 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef A_ANIMAL_HPP
# define A_ANIMAL_HPP

# include <iostream>
# include <string>
# include "policeColor.hpp"


class A_Animal {

public:

    A_Animal( void );
    
    A_Animal( A_Animal const & src );
    virtual ~A_Animal( void );

    A_Animal & operator=( A_Animal const & rhs );

    virtual std::string getType( void ) const = 0;
    virtual void makeSound() const = 0;
    
    virtual void setPtr( std::string str ) const = 0;
    virtual void printArray( void ) const = 0;


protected:

    std::string type;

};

#endif /************************************************* A_ANIMAL_HPP */