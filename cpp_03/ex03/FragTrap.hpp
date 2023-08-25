/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/25 16:40:06 by chris            ###   ########.fr       */
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

    void        highFivesGuys( void );
    void        printValues( void ) const;

protected:

    int hitTmp; 
    int attackDamageTmp; 

};

#endif /**********************************************************FRAGTRAP_HPP*/