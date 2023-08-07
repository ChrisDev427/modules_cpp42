/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 21:14:13 by chris             #+#    #+#             */
/*   Updated: 2023/08/04 10:02:57 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

# define RESET   "\033[0m"
# define B_RED     "\033[1;31m"
# define B_GREEN   "\033[1;32m"
# define B_ORANGE  "\033[1;38;5;166m"
# define B_YELLOW  "\033[1;33m"
# define B_BLUE    "\033[1;34m"
# define B_CYAN    "\033[1;36m"
# define B_GRAY "\033[1;30m"
# define ITAL "\e[3m"
# define NORM "\e[0m"


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

// std::ostream & operator<<( std::ostream & o, Animal const & i );

#endif /************************************************* WRONGANIMAL_HPP */