/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/07 10:16:33 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>
# include "policeColor.hpp"

class WrongAnimal {

public:

    WrongAnimal( void );
    
    WrongAnimal( WrongAnimal const & src );
    virtual ~WrongAnimal( void );

    WrongAnimal & operator=( WrongAnimal const & rhs );

    std::string getType( void ) const;
    void makeSound() const;

protected:

    std::string type;

};

#endif /************************************************* WRONGANIMAL_HPP */