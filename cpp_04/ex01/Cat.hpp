/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:18 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:03:00 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"
# include <iostream>
# include <string>
# include "policeColor.hpp"


class Cat : virtual public Animal {

public:

    Cat( void );
    
    Cat( Cat const & src );
    virtual ~Cat( void );

    Cat & operator=( Cat const & rhs );

    std::string getType( void ) const;

    virtual void setPtr( std::string str ) const;
    virtual void printArray( void ) const;
    virtual void makeSound() const;

private:

    Brain* _ptr;

};

#endif /************************************************* CAT_HPP */