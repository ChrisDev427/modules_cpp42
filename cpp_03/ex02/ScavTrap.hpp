/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chris <chris@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 10:38:27 by chris             #+#    #+#             */
/*   Updated: 2023/08/01 14:56:54 by chris            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef SCAVTRAP_HPP
# define SCAVTRAP_HPP

# include "ClapTrap.hpp"
# include <iostream>
# include <thread>

class ScavTrap : ClapTrap {

public:

    ScavTrap( void );
    ScavTrap( std::string sName );
    ScavTrap( ScavTrap const & src );
    ~ScavTrap( void ); virtual

    ScavTrap & operator=( ScavTrap const & rhs );

    void attack(const std::string& target);
    void guardGate( void );

    int getValue( std::string value ) const;


};


#endif /**********************************************************SCAVTRAP_HPP*/