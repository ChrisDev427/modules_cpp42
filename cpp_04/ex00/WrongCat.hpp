/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:18 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 10:03:08 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

# include "WrongAnimal.hpp"
# include <iostream>
# include <string>


class WrongCat : virtual public WrongAnimal {

public:

    WrongCat( void );
    
    WrongCat( WrongCat const & src );
    virtual ~WrongCat( void );

    WrongCat & operator=( WrongCat const & rhs );

    std::string getType( void ) const;

    void makeSound() const;


};

#endif /************************************************* WRONGCAT_HPP */