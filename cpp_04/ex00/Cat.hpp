/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:18 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 09:19:22 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include <iostream>
# include <string>


class Cat : virtual public Animal {

public:

    Cat( void );
    
    Cat( Cat const & src );
    virtual ~Cat( void );

    Cat & operator=( Cat const & rhs );

    std::string getType( void ) const;

    virtual void makeSound() const;


};

// std::ostream & operator<<( std::ostream & o, Cat const & i );

#endif /************************************************* CAT_HPP */