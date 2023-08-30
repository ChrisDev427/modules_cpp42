/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:37:08 by chris             #+#    #+#             */
/*   Updated: 2023/08/27 20:11:58 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef CLAPTRAP_HPP
# define CLAPTRAP_HPP
# define RESET   "\033[0m"
# define RED     "\033[31m"
# define B_RED     "\033[1;31m"
# define GREEN   "\033[32m"
# define B_GREEN   "\033[1;32m"
# define YELLOW  "\033[33m"
# define ORANGE  "\033[38;5;166m"
# define B_ORANGE  "\033[1;38;5;166m"
# define B_YELLOW  "\033[1;33m"
# define B_BLUE    "\033[1;34m"
# define BLUE    "\033[34m"
# define CYAN    "\033[36m"
# define B_CYAN    "\033[1;36m"
# define MAGENTA "\033[35m"
# define B_MAGENTA "\033[1;35m"
# define BOLDWHITE "\033[1;37m"
# define B_GRAY "\033[1;30m"
# define ITAL "\e[3m"
# define NORM "\e[0m"


# include <iostream>
# include <thread>

class ClapTrap {

public:

    ClapTrap( void );
    ClapTrap( std::string nane );
    ClapTrap( ClapTrap const & src );
    virtual ~ClapTrap( void );

    ClapTrap & operator=( ClapTrap const & rhs );

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);
    void printValues( void ) const;

protected:

    std::string name;
    int         hit; 
    int         energy; 
    int         attackDamage;
};


#endif /**********************************************************CLAPTRAP_HPP*/