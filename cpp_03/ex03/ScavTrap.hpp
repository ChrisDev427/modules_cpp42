/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/03 16:14:25 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"


class ScavTrap : virtual public ClapTrap {

public:

    ScavTrap( void );
    ScavTrap( std::string name );
    ScavTrap( ScavTrap const & src );
    ~ScavTrap( void ); virtual

    ScavTrap & operator=( ScavTrap const & rhs );


    virtual void    attack(const std::string& target);
    int             getValue( std::string value ) const;
    void            printValues( void ) const;
    void guardGate( void );
    
};


#endif /**********************************************************SCAVTRAP_HPP*/