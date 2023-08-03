/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 15:57:31 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef FRAGTRAP_HPP
# define FRAGTRAP_HPP

# include "ClapTrap.hpp"


class FragTrap : virtual public ClapTrap {

public:

    FragTrap( void );
    FragTrap( std::string name );
    FragTrap( FragTrap const & src );
    ~FragTrap( void ); virtual

    FragTrap & operator=( FragTrap const & rhs );

    // void attack(const std::string& target);
    int         getValue( std::string value ) const;
    void        printValues( void ) const;

    void highFivesGuys( void );
    
protected:

    int hitTmp; 
    int attackDamageTmp; 

};


#endif /**********************************************************FRAGTRAP_HPP*/