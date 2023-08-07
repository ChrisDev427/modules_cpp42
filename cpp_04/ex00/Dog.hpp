/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:28 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:18:18 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef DOG_HPP
# define DOG_HPP


# include "Animal.hpp"
# include <iostream>
# include <string>

class Dog  : virtual public Animal {

public:

    Dog( void );
    
    Dog( Dog const & src );
    virtual ~Dog( void );

    Dog & operator=( Dog const & rhs );

    std::string getType( void ) const;

    virtual void makeSound() const;


};

// std::ostream & operator<<( std::ostream & o, Dog const & i );

#endif /************************************************* DOG_HPP */